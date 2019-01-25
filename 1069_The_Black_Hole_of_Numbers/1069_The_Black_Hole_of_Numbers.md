![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1069_The_Black_Hole_of_Numbers**
*/

1069 The Black Hole of Numbers （20 分）

数字 用string存储， 用减序 减去 增序 。

### Input Specification:

Each input file contains one test case which gives a positive integer *N* in the range (0,104).

### Output Specification:

If all the 4 digits of *N* are the same, print in one line the equation `N - N = 0000`. Else print each step of calculation in a line until `6174` comes out as the difference. All the numbers must be printed as 4-digit numbers.

### Sample Input 1:

```in
6767
```

### Sample Output 1:

```out
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
```





### **ac_code**
```c
 /*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1069 The Black Hole of Numbers
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct num{
    string s;
    num operator-(const num&a){
        int add =0;
        num ret;
        ret.s.resize(4);
        for(int i=3;i>=0;i--){
            ret.s[i]=(s[i])-(a.s[i])-add+'0';
            if(ret.s[i]<'0') {
                add =1;
                ret.s[i]+=10;
            }
            else add =0;
        }
        return ret;
    }
    num gethigh(){
        num ret;
        ret.s =s;
        sort(ret.s.begin(),ret.s.end(),greater<char>());
        return ret;   
    }
    num getlow(){
        num ret;
        ret.s =s;
        sort(ret.s.begin(),ret.s.end());
        return ret;   
    }
};
int main(){
    num n1,n2,n3;
    cin>>n1.s;
    while(n1.s.compare("6174")!=0&&n1.s.compare("0000")!=0){
        n2 =n1.gethigh();
        n3 =n1.getlow();
        n1 = n2-n3;
        printf("%s - %s = %s\n",n2.s.c_str(),n3.s.c_str(),n1.s.c_str());
    }
    return 0;
}

```