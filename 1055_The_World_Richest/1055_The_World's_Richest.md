![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1055_The_World's_Richest**
    2019-01-18 03:48:16
*/

```c 
struct Node{
    char name[9];
    int age;
    int w;
};
Node PeoPle[MAX_PEOPLE];
vector<Node*> P[201];
vector<Node*> buff;
```

这里用 people 来存储总共的 人的信息，同时还把他们的指针存在相应的年龄的  数组中。

对每个年龄内不排序一次。然后数据量大于100 去掉后面的。 将每个年龄的人 的数据都汇总到buff 数组中，在排序一次。

然后对每次的请求 都便利buff一次 当数据的年龄 处于要求的 分段内，输出。如果没有输出none

### ***M* (≤100)** - the maximum number of outputs, and [`Amin`, `Amax`] which are the range of ages. All the numbers in a line are separated by a space.

注意上述的  M 小于等于100， 可以缩小数据的量。







### **ac_code**

```c

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
```