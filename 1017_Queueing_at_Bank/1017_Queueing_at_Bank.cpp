#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
typedef unsigned long ulong;
struct people
{
    ulong arr;
    int p_time;
    ulong waittime =0;
    people(int h,int m,int s,int p){
        arr= h*60*60+m*60+s;
        p_time =p*60;
    }
    bool operator<(const people& b)const{
        return arr>b.arr;
    }
};
struct Window{
    ulong curtime;
    Window(ulong t){
        curtime =t;
    }
    bool operator<(const Window &w)const{
        return curtime>w.curtime;
    }
};
priority_queue<people> p;
priority_queue<Window> w;

int record_cnt;
int Windows_cnt;
int time_base = 28800;
int time_limit = 61201;
int cnt=0;
ulong g_wait =0;
int main(){
    scanf("%d %d",&record_cnt,&Windows_cnt);
    for(int i= 0;i<record_cnt;i++){
        int h,m,s,pp;
        scanf("%d:%d:%d %d",&h,&m,&s,&pp);
        people _p(h,m,s,pp);
        if(_p.arr>=time_limit){
            continue;
        }
        p.push(_p);
    }
    cnt =p.size();
    for(int i=0;i<Windows_cnt;i++){
        w.push(Window(8*60*60));
    }
    while(!p.empty()){
        people pp=p.top();
        Window win = w.top();
        if(pp.arr<win.curtime){
            g_wait += win.curtime-pp.arr;
            win.curtime +=pp.p_time;
        }
        else{
            win.curtime =pp.p_time+pp.arr;
        }
        p.pop();
        w.pop();
        w.push(win);
    }
    printf("%0.1f",g_wait / cnt / 60.0);
    return 0;
}