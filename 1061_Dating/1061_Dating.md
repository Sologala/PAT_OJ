![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1061_Dating**
*/

```c
Day     //第一个相等的。A-G
Hour    //接着 第一个相等的 A-N 或者0-9
Min		// 第一个相等的 A-z
```



### **ac_code**
```c
           /*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1061 Dating
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
char W[7][4]={"MON","TUE","WED","THU" ,"FRI", "SAT" ,"SUN"};
string s1,s2,s3,s4;
int main(){
    cin>>s1>>s2>>s3>>s4;
    int min_idx= min(s1.length(),s2.length());
    int i=0,Day=-1,hour=-1,Min=-1;
    for(;i<min_idx;i++){
        if(s1[i]>='A'&&s1[i]<='G'&&s2[i]>='A'&&s2[i]<='G'&&s1[i]==s2[i]){
            Day =s1[i]-'A';
            break;
        }
    }
    for(i++;i<min_idx;i++){
        if(s1[i]>='A'&&s1[i]<='N'&&s2[i]>='A'&&s2[i]<='N'&&s1[i]==s2[i]){
            hour =s1[i]-'A'+10;
            break;
        }
        else if(s1[i]>='0'&&s1[i]<='9'&&s2[i]>='0'&&s2[i]<='9'&&s1[i]==s2[i]){
            hour =s1[i]-'0';
            break;
        }
    }
    min_idx = min(s3.length(),s4.length());
    for(i=0;i<min_idx;i++){
        if(s3[i]>='A'&&s3[i]<='z'&&s4[i]>='A'&&s4[i]<='z'&&s3[i]==s4[i]){
            Min = i;
            break;
        }
    }
    printf("%s %02d:%02d\n",W[Day],hour,Min);
    return 0;
}

```