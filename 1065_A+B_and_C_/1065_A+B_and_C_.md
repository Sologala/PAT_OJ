![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1065_A+B_and_C_(64bit)**
*/



1065 A+B and C (64bit) （20 分）

Given three integers *A*, *B* and *C* in [−2^63,2^63], you are supposed to tell whether *A*+*B*>*C*.

### Input Specification:

The first line of the input gives the positive number of test cases, *T* (≤10). Then *T* test cases follow, each consists of a single line containing three integers *A*, *B* and *C*, separated by single spaces.

### Output Specification:

For each test case, output in one line `Case #X: true` if *A*+*B*>*C*, or `Case #X: false` otherwise, where *X* is the case number (starting from 1).

### Sample Input:

```in
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
```

### Sample Output:

```out
Case #1: false
Case #2: true
Case #3: false
```

两个大数 计算。 笨办法，字符串模拟计算 。

### **ac_code**
```c
         /*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1065 A+B and C (64bit)
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

struct Pos_num{
    int s[140];
    Pos_num operator+(const Pos_num&b)const {
        Pos_num ret;
        int add=0,i=139;
        for(;i>=0;i--){
            ret.s[i] =s[i]+b.s[i]+add;
            if(ret.s[i]>=10){ret.s[i] %=10;add =1;}
            else{ add =0;}
        }
        for(;i<=0;i++){
            ret.s[i] =0;
        }
        return ret;
    }
    Pos_num operator-(const Pos_num&b)const {//假设a>b
        Pos_num ret;
        int add=0,i=139;
        for(;i>=0;i--){
            ret.s[i] =s[i]-b.s[i]-add;
            if(ret.s[i]<0){ret.s[i]+=10;add =1;}
            else{ add =0;}
        }
        for(;i<=0;i++){
            ret.s[i] =0;
        }
        return ret;
    }
    bool operator>(const Pos_num &b)const {
        for(int i=0;i<140;){
            if(s[i]!=b.s[i]){return s[i]>b.s[i];}
            else i++;
        }
        return false;
    }
    void show(){
        int i=0;
        while(i<140&&s[i]==0){i++;}
        if(i==140)printf("0");
        else{
            for(;i<140;i++){
                printf("%d",s[i]);
            }
        }
    }
    void set(string str){
        memset(s,0,sizeof(s));
        int idx =str.length()-1,i =0;
        for(;idx>=0;idx--){
            s[139-i]=str[idx]-'0';
            i++;
        }
    }
};

struct Num{
    bool sig ;
    Pos_num num;
    void set(string str){
        if(str[0]=='-'){
            sig =false;
            str.erase(str.begin());
        }
        else sig =true;
        num.set(str);
    }
    void show(){
        if(!sig) printf("-");
        num.show();
    }
    Num operator+(const Num &b)const {
        Num ret;
        if(sig==b.sig){//都是正
            ret.sig =sig;
            ret.num =num+b.num;
        }
        else{//一个正一个负
            if(num>b.num){
                ret.num =num-b.num;
                ret.sig =sig;
            }
            else{
                ret.num =b.num-num;
                ret.sig =b.sig;
            }
        }
        return ret;
    }
    bool operator>(const Num&b)const{
        if(sig==true&&b.sig==false){return true;}
        else if(sig==false&&b.sig==true) return false;
        else{
            if(sig) return num>b.num;
            else    return !(num>b.num);
        }
    }
};


int main(){
    int cnt;
  
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++){
        Num a,b,c,d;
        string temp;
        cin>>temp;
        a.set(temp);
        cin>>temp;
        b.set(temp);
        cin>>temp;
        c.set(temp);
        d= a+b;
        printf("Case #%d: ",i+1);
        if(d>c) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
  
```