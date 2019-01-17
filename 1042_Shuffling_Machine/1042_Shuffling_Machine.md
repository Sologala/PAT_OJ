1042 Shuffling Machine （20 point(s)）

洗牌

原始牌 的顺序

```
S1, S2, ..., S13, 
H1, H2, ..., H13, 
C1, C2, ..., C13, 
D1, D2, ..., D13, 
J1, J2
```

通过给出的 洗牌顺序 洗牌K次



``` c
int trans[54];
```

​	通过一个数组来存储新的顺序 

​	洗牌的次数就在这个数组里面倒几次。

​	

``` c
int getnewIdx(int i){
    int ret =i;
    for(int i=0;i<times;i++){
        ret =trans[ret]-1;
    }
    return ret;
}
```

AC代码

​	

```c
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    char c;
    int idx;
    int newidx; 
};
node N[54];
int trans[54];
int times =0;
void init();
int getnewIdx(int i){
    int ret =i;
    for(int i=0;i<times;i++){
        ret =trans[ret]-1;
    }
    return ret;
}
bool cmp(const node&a,const node& b){
    return a.newidx<b.newidx;
}
int main(){
    cin>>times;
    for(int i=0;i<54;i++){
        cin>>trans[i];
    }
    init();
   
    for(int i=0;i<54;i++){
        if(i==53)
        {
            int a =0;
        }
        N[i].newidx =getnewIdx(i);
    }
    sort(N,N+54,cmp);
    cout<<N[0].c<<N[0].idx;
    for(int i=1;i<54;i++){
        cout<<" "<<N[i].c<<N[i].idx;
    }
    return 0;
}

void init(){
    for(int i=0;i<13;i++){
        N[i].c ='S';
        N[i].idx=i%13+1;
    }
    for(int i=13;i<26;i++){
        N[i].c ='H';
      N[i].idx=i%13+1;
    }
    for(int i=26;i<39;i++){
        N[i].c ='C';
        N[i].idx=i%13+1;
    }
    for(int i=39;i<52;i++){
        N[i].c ='D';
       N[i].idx=i%13+1;
    }
    for(int i=52;i<54;i++){
        N[i].c ='J';
        N[i].idx=i%13+1;
    }
}
```

