![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1059_Prime_Factors**
*/

1059 Prime Factors （25 分）

**思路**

​	把一个数字分解成质数的指数和形式。最开始先计算出 从2到num 的所有质数，然后从2开始拆解num 。但是第一个测试点会超时。

​      期间还发现有一个测试样例是 **num=1** 因此需要特判	

​      这样做的后果是当一个数字很大的时候，求他的所有质数，并不是所有的都能用上，我们**只需要求第一个质数**就行了。

![](https://github.com/Sologala/PAT_OJ/blob/master/1059_Prime_Factors/1059_Prime_Factors.assets/0.png?raw=true)

### ** ac_code**
```c
        /*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1059_Prime_Factors
*/
#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long int UL;
UL num;
vector<int> res;
UL calfirstPrime(UL num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){return i;}
    }
    return num;
}
int main(){
    cin>>num;
    cout<<num<<"=";
    if(num==1){cout<<1<<endl;return 0;}
       
    while(num>1){
        UL pr =calfirstPrime(num);
        res.push_back(pr);
        num/=pr;
    }
    UL last =res[0];
    for(int i=0;i<res.size();){
        cout<<res[i++];
        int count =1;
        while(i<res.size()&&res[i]==last){
            i++;
            count++;
        }
        if(count!=1){
            cout<<"^"<<count;
        }
        if(i!=res.size())
            cout<<"*";
        last =res[i];
    }
    return 0;
}
   
```