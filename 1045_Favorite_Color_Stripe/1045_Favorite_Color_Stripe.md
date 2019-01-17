1045 Favorite Color Stripe （30 分）

# **题意**

​	先给出 需要的颜色的序列顺序,然后给出一长串的颜色,从这些颜色中选出最长的 满足之前顺序的 串.

​	首先 这些颜色 必须要按照给出的顺序来计算,所以不必存储 颜色的色值 ,我们只需要把 这些颜色在 顺序串中的 位置存下来就行了.

​	这里用了一个map 来映射 某颜色 的在顺序 串中的 位置

```c
map<int,int> M;
```



```c 
6
5  2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
   1 1 x 3 4 4 5 2 3 3 4 5  //而 x 的数组 就可以不存储
   1 1 3 4 4 5 2 3 3 4 5  //得到一个顺序的 序列.部分单增加.这样问题就变成了求最长上升子序列长度.
    //于是用动态规划来做.
```

​	

```c
//设置dp[i] 为从S[1]到S[i] 的最长 上升子串长度
//有递推公式如下 

if(S[i]>=S[i-1]) dp[i]=dp[i-1]+1;//increase order
else {
    int j=i-1;
    while(j>=1&&S[j]>S[i]){// 如果逆序的情况下往前找第一个小于他的数字.
        j--;					//注意这里虽然是顺序的序列但是不能二分
    }							//这里的顺序序列只是部分的有序
    dp[i] =dp[j]+1;
}
```

​	最后记录一下在计算过程中的最大值 就是最长子串 也就是结果了 .

# **AC代码**

```c
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MAX 10010
int Cnt;
map<int,int> M;
map<int,int>::iterator it;
vector<int> S;
vector<int> dp;
int main(int argc, char const *argv[])
{
    scanf("%d",&Cnt);
    int temp;
    int c;
    scanf("%d",&c);
    for(int i = 1; i <=c; i++)
    {
        scanf("%d",&temp);
        M[temp] =i;
    }
    scanf("%d",&c);    
    S.push_back(0);//占位
    dp.push_back(0);
    for(int i = 1; i <=c; i++)
    {
        scanf("%d",&temp);
        it =M.find(temp);
        if(it!=M.end()){
            S.push_back(it->second);
            dp.push_back(0);
        }
    }
    //状态转移方程
    dp[1]=1;int max =dp[1];
    for(int i = 2; i < S.size(); i++)
    {
        if(S[i]>=S[i-1]) dp[i]=dp[i-1]+1;//increase order
        else {
            int j=i-1;
            while(j>=1&&S[j]>S[i]){// 寻找第一个小于等于他的梳子
              j--;
            }
            dp[i] =dp[j]+1;
        }
        if(dp[i]>max){max= dp[i];}
    }
    printf("%d" ,max);
    return 0;
}

```

