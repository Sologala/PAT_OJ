1051 Pop Sequence （25 分）

# **思路**

​	这道题想了半天 ,最开始觉得直接模拟会超时,推演了好久看时候有什么更快速的办法,后来无果,只好老老实实模拟.

​	将出栈 的序列的存储下来判断 

​	该数字与栈顶元素的大小,如果**大于** 则需要入栈.  如果超过栈的 最大值那么就 break 输出NO .

​	如果该数字**等于** 则出栈

​	如果小于 则不是在访问栈顶元素,break 输出NO



### AC代码:

```c

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

```

