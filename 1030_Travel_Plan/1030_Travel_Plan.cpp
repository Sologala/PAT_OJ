#include <iostream>
#include <vector>
using namespace std;
#define MAx 10001
#define INF 999999
struct E
{
    int to;
    int dis;
    int cost;
};
struct V
{
    vector<E> edge;
};
vector<V> G;
bool vis[MAx] ={false};
int dis[MAx];
int cost[MAx];
vector<int> g_P;//存放所有路径最短的路径
int g_Min_dis =INF;
int min_cost =INF,min_idx =-1;
vector<int> stack;

int Dfs(int s,int e){
    if(vis[s]) return 0;
    vis[s] =true;
    for(int i=0;i<G[s].edge.size();i++){
        if(vis[G[s].edge[i].to]==false){
            stack.push_back(G[s].edge[i].to);
            dis[G[s].edge[i].to] =G[s].edge[i].dis+dis[s];
            cost[G[s].edge[i].to]=G[s].edge[i].cost+cost[s];
            if(G[s].edge[i].to==e){//find
                if(dis[G[s].edge[i].to]<=g_Min_dis){
                    g_Min_dis =dis[G[s].edge[i].to];
                    if(cost[G[s].edge[i].to]<min_cost){
                        min_cost =cost[G[s].edge[i].to];
                        g_P =stack;
                    }
                }
            }
            else{
                Dfs(G[s].edge[i].to,e);
            }
            stack.pop_back();
        }
    }
}

int N,M,S,D;
int main(int argc, char const *argv[])
{
    cin>>N>>M>>S>>D;
    for(int i = 0; i < N; i++)
    {
        G.push_back(V());
        vis[i] =false;
        dis[i] =INF;
        cost[i]=0;
    }
    for(int i = 0;i<M;i++){
        int f,t,d,c;
        cin>>f>>t>>d>>c;
        G[f].edge.push_back(E{t,d,c});
        
        G[t].edge.push_back(E{f,d,c});
       
    }
    stack.push_back(S);
    dis[S] =0;
    Dfs(S,D);
        for(int j =0;j<g_P.size();j++){
            cout<<g_P[j]<<" ";
        }
        cout<<g_Min_dis<<" "<<min_cost;
    return 0;
}
