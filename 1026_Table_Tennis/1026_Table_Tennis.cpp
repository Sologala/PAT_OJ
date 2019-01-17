#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define Maxtime 75600
#define Mintime 28800
typedef unsigned long _time;
void printf_time(_time t){
    int h,m,s;
    s =t%60;t/=60;m=t%60;h=t/60;
    printf("%02d:%02d:%02d",h,m,s);
}

struct Table{
    int index;
    bool Vip;
    _time curtime= Mintime;
    Table* next =NULL;
    bool operator<(const Table &b)const{
        if(curtime!=b.curtime)return curtime<b.curtime;
        else return index<b.index;
    }
};
struct People{
    _time arr;
    bool Vip;
    int peocessTime;
    People* next=NULL;
    bool operator<(const People &b)const{
        return arr>b.arr;
    }
};

struct Table_Queen{
    Table* front =new Table;
    int len =0;
    void Enqueue(Table* t){
        Table* p =front->next;
        Table* r =front;
        while(p&&(*p)<(*t)){
            r =p;p=p->next;
        }
        r->next =t;t->next =p;
        len++;
    }
    Table* Dequeue(){
        Table* ret = front->next;
        front->next =ret->next;
        len--;
        return ret;
    }
    Table *getHead(){
        return front->next;
    }
};

vector<People> wait_queen;
int have_Vip = 0;
priority_queue<People> comming_queen;
//wait_queue__Sort

struct Tennis{
    Table_Queen vip,nor;
    _time curtime =Mintime;// 当前时间;
    Table* getTable(){
        return NULL;
    }
    void returnTable(Table* t){
        if(t->Vip){vip.Enqueue(t);}
        else nor.Enqueue(t);
        curtime = nor.getHead()->curtime<vip.getHead()->curtime?nor.getHead()->curtime:vip.getHead()->curtime;
    }
};
Tennis T;
Table* g_Table; 
int main(){
    int Tablecnt,vipcnt,peoplecnt;
    cin>>peoplecnt;
    for(int i=0;i<peoplecnt;i++){
        int h,m,s,p,v;
        People temp;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&temp.peocessTime,&v);
        temp.arr =h*3600+m*60+s;temp.Vip=v==1?true:false;
        comming_queen.push(temp);
    }
    cin>>Tablecnt>>vipcnt;
    g_Table =new Table[Tablecnt];
    for(int i =0;i<Tablecnt;i++){
        g_Table[i].index =i+1;
        g_Table[i].Vip =false;
        g_Table[i].curtime =Mintime;
    }
    for(int i=0;i<vipcnt;i++){
        int vipindex;
        cin>>vipindex;
        g_Table[i].Vip =true;
    }
    for(int i =0;i<Tablecnt;i++){
        if(g_Table[i].Vip){T.vip.Enqueue(&g_Table[i]);}
        else T.nor.Enqueue(&g_Table[i]);
    }
    Table* curTable;
    People curPeople;
    while(1){
        //根据当前时间 来选择一个comm 队列里面的进入wait队列
        while(!comming_queen.empty()&&comming_queen.top().arr<=T.curtime){
            if(comming_queen.top().Vip){have_Vip++;}
            wait_queen.push_back(comming_queen.top());
            comming_queen.pop();
        }
        cout<<"当前队列中的元素"<<endl;
        for(int i=0;i<wait_queen.size();i++){
            printf_time(wait_queen[i].arr);
            cout<<" ["<<i<<"]"<<endl;
        }
        cout<<endl;
    //对wait队列排序，并且判断是否有 vip在等待
        if(have_Vip){
            if(T.vip.getHead()->curtime<T.curtime){
                int i=0;
                for(;i<wait_queen.size();i++){
                    if(wait_queen[i].Vip){
                        break;    
                    }
                }
                if(i==wait_queen.size()){

                }
                else{//找到vip 编号
                    curPeople =wait_queen[i];
                    curTable = T.vip.Dequeue();
                    wait_queen.erase(wait_queen.begin()+i);
                }
            }
            else{
                curTable =T.nor.Dequeue();
                curPeople =wait_queen[0];
                wait_queen.erase(wait_queen.begin());
            }
        }
        else{
            if(T.vip.getHead()->curtime<T.nor.getHead()->curtime){
                curTable =T.vip.Dequeue();
            }
            else{
                curTable =T.nor.Dequeue();
            }
            curPeople =wait_queen[0];
            wait_queen.erase(wait_queen.begin());
        }    
    // 1、队列中有vip  时间往后 查看是否有满足的 vip
    //                    有，给分配vip
    //                   没有给分配时间最早的普通
    //2.队中没有vip   给时间最早的桌子 任何都行，分配给最早的队中的人
        int wait_time;
        if(curTable->curtime<curPeople.arr){
            curTable->curtime =curPeople.arr;
        }
        wait_time =(curPeople.arr- curTable->curtime+30)/60;
        printf_time(curPeople.arr);
        cout<<" ";
        printf_time(curTable->curtime);
        cout<<" "<<wait_time<<endl;
        curTable->curtime +=curPeople.peocessTime*60;
        //从T，根据以上信息 拿到一张桌子
        T.returnTable(curTable);
    //计算时间

    }
    return 0;
}


