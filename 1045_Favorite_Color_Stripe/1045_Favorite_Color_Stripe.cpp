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
