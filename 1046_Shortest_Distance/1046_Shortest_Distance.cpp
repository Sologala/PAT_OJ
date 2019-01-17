#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;
vector<int> G;
int dp[MAX];
int cnt,sum;
int main(int argc, char const *argv[])
{
    scanf("%d",&cnt);
    int temp;
    sum =0;dp[1]=0;
    G.push_back(-1);
    for(int i=1;i<=cnt;i++){
        scanf("%d",&temp);
        G.push_back(temp);
        sum+=temp;
        dp[i+1] =dp[i]+temp;
    }
    
    scanf("%d",&cnt);
    
    for(int i = 0; i < cnt; i++)
    {
        int f,t,s=0;
        scanf("%d %d",&f,&t);
        if(f>t){swap(f,t);}
        s =dp[t]-dp[f];
        if(s>sum/2){s=sum-s;}
        printf("%d\n",s);
    }
    
    return 0;
}
