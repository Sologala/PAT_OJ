#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define MAx 1010
int M, N, K;
int s[MAx];
int top;
vector<int> num;
int main(){
    scanf("%d %d %d", &M, &N, &K);
   
    for (int cnt = 0; cnt < K; cnt++)
    {
        int max = 1, n;
        top=-1;
        s[++top] = 0;// 为了方便比较 s[0] =0; 实际存储从s[1]开始
        bool res =true;
        num.clear();
        for (int i = 0; i < N; i++){
            scanf("%d", &n);
            num.push_back(n);
        }
        for (int i=0; i < N; i++){
            if(num[i]>s[top]){
                while(max<=num[i]){
                    s[++top]=max++;
                }
                if(top>M){
                    res =false;
                    break;
                }
                top--;
            }
            else if(num[i]==s[top]){
                top--;
            }
            else {
                res =false;
                break;
            }
        } 
        if(res)
        cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
