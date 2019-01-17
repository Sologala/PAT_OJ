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
