1048 Find Coins （25 分）

# **思路**

​	题目给出一些数字,并 从这些数字中找出两个 数字 刚好组合的到pay.

​	可以暴力,但是 暴力不知道会不会超时没有试.

​	思路:

​		给的数据先 排序

```c 
  8 15
  1 2 8 7 2 4 11 15
  1 2 2 4 7 8 11 15   C[i]
//+ ---------------
//在C[i] 的后面的  数组中二分查找是否有 C[i] +C[j] =pay,有就输出.没有继续.
```

## AC代码

```c
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int cnt,pay;
vector<int> C;
int find(int i,int j,int x){
    int mid;
    while(i<j){
        mid =(i+j)/2;
        if(x+C[i]==pay){return i;}
        else if(x+C[i]>pay){j =mid-1;}
        else{i=mid+1;}
    }
    return x+C[i]==pay?i:-1;
}
int main(){

    scanf("%d %d",&cnt,&pay);
    
    int tempnum;
    for(int i = 0; i < cnt; i++){
        scanf("%d",&tempnum);
        C.push_back(tempnum);
    }
    sort(C.begin(),C.end());
    
    for(int i = 0; i < C.size()-1; i++)
    {
        int j=find(i+1,C.size()-1,C[i]);
        if(j!=-1){
            printf("%d %d",C[i],C[j]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}

```

