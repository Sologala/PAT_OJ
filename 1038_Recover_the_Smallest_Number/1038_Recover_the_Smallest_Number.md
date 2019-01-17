**1038 Recover the Smallest Number** （30 point(s)）

# **思路1**

给定一串的数字 可以随意改变他们的顺序 求出最小的数字的组合

输出注意点，最前面没有0

正确思路 

​	a = 32 ;

​	b =321;

如上 两个字符串，如果构成数字可得到 1） 32-321 

​								2） 321-32

​						32321>32132;

​						故后者是相对比较小的数字。

​		于是本问题转化成为排序问题。数字的大小的比较 在字符串上可以用字典序来比较。

​		所以如果 string a =32; string b =321;

​				根据 a+b<b+a 即可判断正确的顺序

最后再处理一下输出字符串 的前面的0；

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a,const string &b){
    return a+b<b+a;
}

vector<string> N;
int main(){
    int Cnt =0;
    cin>>Cnt;
    
    for(int i = 0; i < Cnt; i++){
        string temp;
        cin>>temp;
        N.push_back(temp);
    }
    sort(N.begin(),N.end(),cmp);
    string res;
    for(int i=0;i<N.size();i++){
        res+=N[i];
    }
    int i= 0;
    for(i =0;i<res.length();i++){
        if(res[i]!='0'){break;}
    }
    if(i==res.length()){cout<<0;}
    else{
         for(;i<res.length();i++)
            cout<<res[i];
    }
    cout<<endl;
    return 0;
}
```

这个是大多数人的思路。也是十分简介的一种解法。

# **思路2**

​	这个是我自己的想法，将字符串转化成 数字来比较。 

​	可以想到 如果要一些数字组成的 数字要最小 那么在这些数字种，最小的数字一定是在最前面。

​	用以下结构存储数字 cal() 将得到的字符串转换成8位数字，后面用数字的最后一位补齐。例如 32=> 32222222   

​			 321=> 32111111

​			而32111111< 32222222

​			所以321 应该排在32 前面。

```c++
struct node{
    string num_s;
    unsigned long num;
    
    void cal(){
        int len =num_s.length();
        num=0;
        for(int i=0;i<8;i++){
            num*=10; 
            if(i<len){
                num+=num_s[i]-'0';            
            }
            else{
                num+=num_s[len-1]-'0';
            }
        }
    }
};
```

​	

​	Sample Input:

```in
5 32 321 3214 0229 87

过程如下
32222222
32111111
32144444 
02299999
87777777
排完序如下

```