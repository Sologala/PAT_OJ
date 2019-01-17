#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
using namespace std;

struct Node{
    int Id;
    char name[10]={'\n'};
    int grade;
};
bool cmp1(const Node&a,const Node &b){
    return a.Id<b.Id;
}
bool cmp2(const Node&a,const Node &b){
    int res =strcmp(a.name,b.name);
    if(res!=0){
        return res<0?true:false;        
    }
    else{
        return cmp1(a,b);
    }
}
bool cmp3(const Node&a,const Node &b){
    if(a.grade!=b.grade)return a.grade<b.grade;
    else return cmp1(a,b);
}


int g_record_cnt,g_c;
vector<Node> V;
void show(){
    for(vector<Node>::iterator i =V.begin();i!=V.end();i++){
        printf("%06d %s %d\n",i->Id,i->name,i->grade);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d %d",&g_record_cnt,&g_c);
    for(int i = 0; i < g_record_cnt; i++)
    {
        Node temp;
        scanf("%d %s %d",&temp.Id,temp.name,&temp.grade);
        V.push_back(temp);
    }
    if(g_c==1)sort(V.begin(),V.end(),cmp1);
    else if(g_c==2){sort(V.begin(),V.end(),cmp2);}
    else if(g_c==3){sort(V.begin(),V.end(),cmp3);}
    show();
    return 0;
}
