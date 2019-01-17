1053 Path of Equal Weight （30 分）



![img](https://images.ptausercontent.com/212)

# **思路**:

​	题目给的数据建立图, 为了满足题目要求的  输出按照 节点的增序, 再 保存 节点的子节点的时候 对所有的子节点按照 节点的 权值 排序.

​	dfs 查找 满足条件的叶子节点.把结果保存,并输出就ok

### Sample Output:

```c
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAx 1010
using namespace std;

struct vexnode{
    vector<int> E;
    int W;
};
struct Res{
    vector<int> path;
};
vector<vexnode> G;
vector<Res> res;
bool vis[MAx]={false};
int  weight[MAx]={0};
int  stack[MAx];
int  top=-1;
int node_cnt,no_leaf,get_w;

void dfs(int s){
    if(vis[s]==true) return ;
    vis[s]=true;
    stack[++top]=s;
    if(G[s].E.size()==0&&weight[s]==get_w){//leaf
        int j = 0;
        Res newRes;
        while(j<=top){
            newRes.path.push_back(G[stack[j++]].W);
        }
        res.push_back(newRes);
    }
    for(int i=0;i<G[s].E.size();i++){
        if(vis[G[s].E[i]]==false){
            weight[G[s].E[i]] =weight[s]+G[G[s].E[i]].W;
            dfs(G[s].E[i]);
        }
    }
    top--;
}
bool cmp(const int& a,const int &b){
    return G[a].W>G[b].W;
}
int main(int argc, char const *argv[])
{
    scanf("%d %d %d",&node_cnt,&no_leaf,&get_w);
    G.resize(node_cnt);
    //creat the map
    for(int i = 0; i < node_cnt; i++){
        scanf("%d",&G[i].W);
    }
    for(int i=0;i<no_leaf;i++){
        int vex_idx,c,temp;
        scanf("%d %d",&vex_idx,&c);
        for(int j = 0; j < c; j++){
            scanf("%d",&temp);
            G[vex_idx].E.push_back(temp);
        }
        sort(G[vex_idx].E.begin(),G[vex_idx].E.end(),cmp);
    }
    weight[0]=G[0].W;

    dfs(0);
    
    for(int i=0;i<res.size();i++){
        printf("%d",res[i].path[0]);
        for(int j = 1;j < res[i].path.size(); j++)
        {
            printf(" %d",res[i].path[j]);
        }
         printf("\n");
    }
    return 0;
}
```