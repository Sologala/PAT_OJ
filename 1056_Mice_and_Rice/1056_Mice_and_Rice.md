![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1056_Mice_and_Rice**
    2019-01-18 12:41:49
*/





![](https://github.com/Sologala/PAT_OJ/blob/master/1056_Mice_and_Rice/1056_Mice_and_Rice.assets/0.png?raw=true)

就Ok排序。


### **ac_code**
```c

#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 1010

int Dp,Dg;
int w[MAX],g_rank[MAX];
vector<int> order;
bool cmp(const int&a,const int &b){
    return w[a]>w[b];
}
vector<int> rankFunc(vector<int> & v){
    vector<int> ret;
    vector<int>::iterator i=v.begin(),j;
    int size =v.size();
    int C=ceil(size*1.0/Dg);
    for(int  idx = 0; idx < C; idx++)
    {
        j=i;
        for(int k=0;k<Dg-1&&j!=v.end();k++){
           j++;
        }
        if(j==v.end()) j--;
        sort(i,j+1,cmp);
        ret.push_back(*i);
        i++;
        for(;i<=j;i++){
            g_rank[(*i)]=C+1;
        }
    }
    return ret;
}

int main(int argc, char const *argv[]){
    scanf("%d%d",&Dp,&Dg);
    for(int i = 0; i < Dp; i++){ 
        scanf("%d",&w[i]);
    }
    int temp;
    for(int i = 0; i < Dp; i++){ 
        scanf("%d",&temp);
        order.push_back(temp);
    }
    while(order.size()!=1){
        order =rankFunc(order);
    }
    g_rank[order[0]]=1;
    printf("%d",g_rank[0]);
    for(int i=1;i<Dp;i++){
        printf(" %d",g_rank[i]);
    }
    return 0;
}
```
