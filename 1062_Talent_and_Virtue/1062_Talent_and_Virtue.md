![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1062_Talent_and_Virtue**
*/

分类 排序 。

```c
 if(temp.V_grade>=Low&&temp.T_grade>=Low){//过滤掉 低分的
            if(temp.V_grade>=High&&temp.T_grade>=High){ //圣人两科都高分
                A.push_back(temp);
            }
            else if(temp.V_grade>=High&&temp.T_grade<High){//君子
                B.push_back(temp);
            }
            else if(temp.V_grade<temp.T_grade){//小人
                D.push_back(temp);
            }
            else 
                C.push_back(temp);//愚人
            count++;
        }
```

****

排序方法

```c
// 总分-> 德-> 才-> id
```

### **ac_code**
```c
   /*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1062 Talent and Virtue
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define MAX 100010
int cnt,Low,High;

struct People{
    int id;
    int T_grade;
    int V_grade;
    int sum;
    bool operator<(const People&b)const{
        if (sum!=b.sum) return sum>b.sum;
        else if(V_grade!=b.V_grade) return V_grade>b.V_grade;
        else if(T_grade !=b.T_grade) return T_grade>b.T_grade;
        else return id<b.id;
    }
};
vector<People> A,B,C,D;
void show(vector<People> &v){
    for(int i=0;i<v.size();i++){
        printf("%08d %d %d\n",v[i].id ,v[i].V_grade,v[i].T_grade);
    }
}
int main(){
    scanf("%d %d %d",&cnt,&Low,&High);
    int idx =0,count =0;
    for(int i = 0; i < cnt; i++)
    {
        People temp;
        scanf("%d %d %d",&temp.id,&temp.V_grade,&temp.T_grade);
        temp.sum =temp.V_grade+temp.T_grade;
        if(temp.V_grade>=Low&&temp.T_grade>=Low){
            if(temp.V_grade>=High&&temp.T_grade>=High){
                A.push_back(temp);
            }
            else if(temp.V_grade>=High&&temp.T_grade<High){
                B.push_back(temp);
            }
            else if(temp.V_grade<temp.T_grade){
                D.push_back(temp);
            }
            else 
                C.push_back(temp);
            count++;
        }
    }
    printf("%d\n",count);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    sort(D.begin(),D.end());
    show(A);
    show(B);
    show(C);
    show(D);
    return 0;
}        
```