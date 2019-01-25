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
