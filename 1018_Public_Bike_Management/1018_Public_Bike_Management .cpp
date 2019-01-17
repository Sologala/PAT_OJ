#include <vector>
#include <iostream>
using namespace std;
#define INF 999999
struct edge{
    int w =INF;
    int to;
};
struct vex{
    int cap;
    vector<edge> E;
};
struct Path{
    vector<int> path;
    int dis =INF;
    bool visit=false; 
    void addnewvec(int index){
        path.push_back(index);
    }
    bool operator<(const Path&b)const{
        return dis<b.dis;
    }
};
int MaxCap,StaCnt,Problem_Sta,RoadCnt;
int vexcnt;
vex *G;
Path *path;
vector <Path> shortestPath;
int *send,*back;
int cur_shortest_dis =INF;

void Dijkstra(int e){
    while (true)
    {
        int min = INF,min_index =-1;
        for (int i = 0; i < vexcnt; i++)
        {
            if (path[i].visit == false && path[i].dis < min)
            {
                min = path[i].dis;
                min_index = i;
            }
        }
        if (min_index == -1)
        {
            return;
        }
        path[min_index].visit = true;
        for (int i = 0; i < G[min_index].E.size(); i++)
        {
            int to = G[min_index].E[i].to;
            int newdis = G[min_index].E[i].w + path[min_index].dis;
            if (newdis <=path[to].dis)
            {
                path[to].dis = newdis;
                path[to].path = path[min_index].path;
                path[to].addnewvec(to);
                if (to == e)
                { //find
                    if(newdis<cur_shortest_dis)
                    {
                        shortestPath.clear();
                        cur_shortest_dis =newdis;
                    }
                    shortestPath.push_back(path[to]);
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    //构造图
    cin>>MaxCap>>StaCnt>>Problem_Sta>>RoadCnt;
    vexcnt =StaCnt+1;
    G =new vex[vexcnt];
    G[0].cap =0;
    for(int i=1;i<=StaCnt;i++){
        cin>>G[i].cap;
    }
    for(int i=0;i<RoadCnt;i++){
        int f,t,w;
        cin>>f>>t>>w;
        G[f].E.push_back(edge{w,t});
        G[t].E.push_back(edge{w,f});
    }
    path = new Path[vexcnt];
    path[0].dis =0;
    Dijkstra(Problem_Sta);
  
    send =new int[shortestPath.size()];
    back =new int[shortestPath.size()];
    for(int i=0 ;i<shortestPath.size();i++){
        int sum =0;
        send[i]=0;back[i]=0;
        for(int j=0;j<shortestPath[i].path.size();j++){
            int t=G[shortestPath[i].path[j]].cap-(MaxCap/2);
            if(t>=0){
                back[i] +=t;
            }
            else if(t <0) {
                if(back[i]>-t){
                    back[i]+=t;
                }
                else{
                    send[i]+=-t-back[i];
                    back[i]=0;
                }
            }
        }
    }
    int min_send_index=0;
    int min_send=INF;
    int min_back =INF;
    for(int i=0 ;i<shortestPath.size();i++){
        if(send[i]<min_send){
            min_send =send[i];
            min_send_index =i;
            min_back =back[i];
        }
        else if(send[i]==min_send){
            if(back[i]<min_back){
                min_send =send[i];
                min_send_index =i;
                min_back =back[i];
            }
        }
    }
        cout<<send[min_send_index]<<" "<<"0";
        for(int j=0;j<shortestPath[min_send_index].path.size();j++){
            cout<<"->"<<shortestPath[min_send_index].path[j];
        }
        cout<<" "<<back[min_send_index];
        cout<<endl;
        return 0;
}

