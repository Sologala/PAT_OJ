1044 Shopping in Mars （25 point(s)）



# **题意**

 给一串 数字 找出大于 给定值 pay 的一些数字从I到j的组合

# **思路1**

​	动态规划的思路来做

​	

```c 
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100010
#define INF 1000000010
using namespace std ;
struct res{
    int i;
    int j;
    int cost;
};

int dp[MAX][MAX];
int Cnt,Pay;
vector<res> R,R_no;
int min_cost =INF;

int main(){
    scanf("%d %d",&Cnt,&Pay);
    for(int i = 1; i <=Cnt; i++){
       scanf("%d",&dp[i][i]);
    }
    bool flag =false;
    for(int i = 1; i <=Cnt; i++){
        for(int j = i; j <=Cnt; j++){
            dp[i][j]=dp[i][j-1]+dp[j][j];
            if(dp[i][j]==Pay){
                R.push_back(res{i,j,dp[i][j]});
                flag= true;
                break;
            }
            else if(!flag&&dp[i][j]>Pay){
                if(dp[i][j]<min_cost){
                    min_cost=dp[i][j];
                    R_no.clear();
                    R_no.push_back(res{i,j,dp[i][j]});
                }
                else if(dp[i][j]==min_cost){
                    R_no.push_back(res{i,j,dp[i][j]});
                }
                break;
            }
        }
    }
    if(flag){
        for(int i=0;i<R.size();i++){
            printf("%d-%d\n",R[i].i,R[i].j);
        }
    }
    else{
        for(int i=0;i<R_no.size();i++){
            printf("%d-%d\n",R_no[i].i,R_no[i].j);
        }
    }
    return 0;
}
```

O(n^2) 这道题 数据量很大 10w  会有两个点超时

# **思路2**

​	由于从s[i]到s[j] 的总和 是一个单调增数列 所以用二分法。

​	

```c 
	   5 13
	   2 4 5 7 9
    //0   1   2   3   4   5      
sum[1] 0   2   6  11  18  27   //二分法找出>=13的第一个数 18	[1-4]
sum[2] 2   0   4   9  16  25   //二分法找出>=13的第一个数 16  [2-4]
sum[3] 6  -4   0   5  12  21   //二分法找出>=13的第一个数 21	[3-5]
sum[4]11  -9  -5   0   7  16   //二分法找出>=13的第一个数 16	[4-5]
sum[5]18 -16 -12  -6   0  9    //二分法找出>=3的第一个数  9	[5-5]
           				//结果中大于13的最小数字是16 [2-4][4-5]
```

​	

AC 代码如下

```c++
    #include <cstdio>
    #include <cstring>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    #define MAX 100010
    #define INF 99999999
    using namespace std ;
    int Cnt,Pay;
    int sum[MAX];
    int temp;
    int find_the_min(int i,int j,int x){
        int mid;
        while(i<j){
            mid =(i+j)/2;
            if(sum[mid]-sum[0]>=x) j=mid;
            else i=mid+1;
        }
        return i;
    }
    struct res{
        int i,j;
    };
    vector<res> R;
    int main(){
        scanf("%d %d",&Cnt,&Pay);
        sum[0]=0;
        for(int i = 1; i <=Cnt; i++){
        scanf("%d",&temp);
        sum[i]=sum[i-1]+temp;
        }
        bool find =true;
        int min=INF;
        for(int i=1;i<=Cnt;i++){
            sum[0]=sum[i-1];
            int j=find_the_min(i,Cnt,Pay);
            if(sum[j]-sum[0]<Pay){break;}
            if(sum[j]-sum[0]<min){
                R.clear();
                R.push_back(res{i,j});
                min=sum[j]-sum[0];
            }
            else if(sum[j]-sum[0]==min){
            R.push_back(res{i,j});
            }
        }
        for(int i=0;i<R.size();i++){
            printf("%d-%d\n",R[i].i,R[i].j);
        }
        return 0;
    }
```

