c1034 Head of a Gang （30 point(s)）

# **题意**：	

​	警察通过查看通话记录把一些人分成一个一个的帮派。

![2CA04D641474FCFF11874F458ABC0EBA](F:\Pat_Obj\PTA\1034_Head_of_a_Gang\Input Specification.assets\2CA04D641474FCFF11874F458ABC0EBA.png)

​	判断是否是帮派的条件：

​		1.ALLcost> K

​		2.帮派成员大于2

​	于是这道题可以用 **有向图** 来存储题目给的数据，然后**DFS 遍历** 的同时 求得**连通分量（帮派个数)**,以及整个帮派的通话时间。

​	**由于题目给的每个顶点的信息是字符串。所以需要使用一个map<string,int> M;来映射name和G[ k ] 的k 的关系。**

```cpp
int dfs(int s){//dfs 遍历 head 和整个帮派的总通话时间
    if(vis[s]==true){return 0;}
    vis[s]=true;
    g_membercnt++;
    if(vex[s].cnt>g_Maxcost){
        g_Maxcost=vex[s].cnt;
        g_max_idx =s;
    }
    for(int i=0;i<peoplecnt;i++){
        g_allcost+=G[s][i];
        if(G[s][i]!=0&&vis[i]==false){
            dfs(i);
        }
    }
}
```

​	而每个帮派的头头（head）的计算，则是在读入数据的时候就将每个顶点的通话时间都计算出来。DFS 的时候选出最大的那个就Ok了。

​	最后输出的时候需要注意 是按照字典序输出所以sort 一下在输出。

**AC代码**



```c++
#include <vector>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 2001
int G[MAX][MAX]={0};
struct V{
    int cnt;
    string name;
};
V  vex[MAX];
vector<bool> vis;
map<string,int> M;//用map来映射 名字和 图中的序号的关系
map<string,int>::iterator g_it;

int peoplecnt =0;
int N,K;
int g_membercnt,g_Maxcost,g_max_idx,g_allcost;
//结果存储
struct res{
    const char* name;
    int member;
};
vector<res> head;
int dfs(int s);
bool cmp(const res&a,const res &b);
int main(int argc, char const *argv[])
{
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        string f,t;int cost;
        cin>>f>>t>>cost;
        g_it =M.find(f);
        if(g_it==M.end()){
            vex[peoplecnt].name=f;
            M[f] =peoplecnt;
            vis.push_back(false);
            peoplecnt++;
        }
        g_it =M.find(t);
        if(g_it==M.end()){
            vex[peoplecnt].name=t;
            vis.push_back(false);
            M[t] =peoplecnt;
            peoplecnt++;
        }
        G[M[f]][M[t]] =cost;
        vex[M[f]].cnt+=cost;
        vex[M[t]].cnt+=cost;
    }
    
    for(int i=0;i<peoplecnt;i++){
        if(vis[i]==false){
            g_membercnt =0;
            g_max_idx=i;
            g_Maxcost =0;
            g_allcost=0;
            dfs(i);
            if(g_membercnt>=3&&g_allcost>K){
                head.push_back(res{vex[g_max_idx].name.c_str(),g_membercnt});
            }
        }
    }
    sort(head.begin(),head.end(),cmp);
    printf("%d\n",head.size());
    for(int i=0;i<head.size();i++){
        printf("%s %d\n",head[i].name,head[i].member);
    }
    return 0;
}
int dfs(int s){//dfs 遍历 head 和整个帮派的总通话时间
    if(vis[s]==true){return 0;}
    vis[s]=true;
    g_membercnt++;
    if(vex[s].cnt>g_Maxcost){
        g_Maxcost=vex[s].cnt;
        g_max_idx =s;
    }
    for(int i=0;i<peoplecnt;i++){
        g_allcost+=G[s][i];
        if(G[s][i]!=0&&vis[i]==false){
            dfs(i);
        }
    }
}
bool cmp(const res&a,const res &b){
    return strcmp(a.name,b.name)<0?true:false;
}

```

