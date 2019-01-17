#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1010
int dp[MAX][MAX];
bool dp_b[MAX][MAX];
string s;
int main(int argc, char const *argv[])
{
    getline(cin,s);
    memset(dp,0,sizeof(dp));memset(dp_b,false,sizeof(dp_b));
    for(int i=0;i<s.length();i++){
         dp[i][i]=1; 
         dp_b[i][i]=true;     
    }
    for(int j =1;j<s.length();j++){
        for(int i =j-1;i>=0;i--){
            if(s[i]==s[j]&&i+1==j){
                    dp_b[i+1][j-1] =true;
                    dp_b[i][j]=true;
            }
            if(s[i]==s[j]&&dp_b[i+1][j-1]){
                    dp[i][j] =dp[i+1][j-1]+2;
                    dp_b[i][j]=true;
            }
            else{
                dp[i][j] =max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    cout<<dp[0][s.length()-1];
    return 0;
}
