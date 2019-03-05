#include <vector>
#include <cstdio>
using namespace std;
int vex_cnt;
vector<int> *G;
bool *vis;
int v,e,k;
void DFS_check(int s,int unchk){
    if(s==unchk) return;
    if(vis[s]==true){
        return;
        }
    else{
        vis[s] =true;
        int size =G[s].size();
        for(int i= 0;i<size;i++){
            if(vis[G[s][i]]==false&&G[s][i]!=unchk){
                DFS_check(G[s][i],unchk);
            }
        }
    }
}
int Dfs(int unchk){
    int cnt = 0;
    for(int i = 1;i<=v;i++){
        vis[i]=false;
    }
    for(int i = 1;i<=v;i++){
        if(!vis[i]&&i!=unchk){
            DFS_check(i,unchk);
            cnt++;
        }
    }
    return cnt;
}    
int main()
{
   
    scanf("%d %d %d",&v,&e,&k);
    G = new vector<int> [v+1];
    vis = new bool[v+1];
    for(int i = 0;i<e;i++){
        int v0 ,v1;
       scanf("%d %d",&v0,&v1);
        (G[v0]).push_back(v1);
        (G[v1]).push_back(v0);
    }

    for(int i= 0;i<k;i++){
        int chk = 0;
         scanf("%d",&chk);
         printf("%d",Dfs(chk)-1);
    }
    return 0;
}
