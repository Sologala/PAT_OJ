/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1055_The_World's_Richest
*/

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 201
#define MAX_PEOPLE 100010
struct Node{
    char name[9];
    int age;
    int w;
};
Node PeoPle[MAX_PEOPLE];
vector<Node*> P[201];
vector<Node*> buff;
int cnt,requst_cnt;
int g_low,g_high;
bool cmp( const  Node *a,const  Node *b){
    if(a->w!=b->w) return a->w>b->w;
    else if(a->age!=b->age) return a->age <b->age;
    else{
        int ret =strcmp(a->name,b->name);
        return ret<0;
    }
}
int main(int argc, char const *argv[]){
    scanf("%d%d",&cnt,&requst_cnt);
    for(int i = 0; i < cnt; i++){
        scanf("%s%d%d",PeoPle[i].name,&PeoPle[i].age,&PeoPle[i].w);
        P[PeoPle[i].age].push_back(&PeoPle[i]);
    }
    for(int k = 0; k <201; k++){
        sort(P[k].begin(),P[k].end(),cmp);
        if(P[k].size()>100){
            buff.insert(buff.end(),P[k].begin(),P[k].begin()+100);//去掉多余的 数据
        }
        else buff.insert(buff.end(),P[k].begin(),P[k].end());
    }
    sort(buff.begin(),buff.end(),cmp);
    for(int i = 1; i <=requst_cnt; i++){
        int M;
        scanf("%d%d%d",&M,&g_low,&g_high);
        printf("Case #%d:\n",i);
        int k = 0,count =0,size =buff.size();
        for(k=0; count< M&&k<size; k++){
            if(buff[k]->age>=g_low&&buff[k]->age<=g_high){
                printf("%s %d %d\n",buff[k]->name,buff[k]->age,buff[k]->w);
                count++;    
            }
        }
        if(count==0){
            printf("None\n");
        }
    }
    return 0;
}