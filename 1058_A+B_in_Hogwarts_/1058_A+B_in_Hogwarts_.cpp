/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1058_A+B_in_Hogwarts_
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Number{
    int G=0,S=0,K=0;
    Number(){};
    ~Number(){};
    Number(int a,int b,int c):G(a),S(b),K(c){

    }
    Number operator+(const Number &b){
        Number ret;
        ret.K =K+b.K;
        int add =0;
        if(ret.K>=29){ret.K%=29;add =1;}
        ret.S =S+b.S+add;
        add =0;
        if(ret.S>=17){ret.S %=17;add =1;}
        ret.G =G+b.G+add;
        if(ret.S>107){while(1);}
        return ret;
    }
};
int main(){
    int a,b,c;
    scanf("%d.%d.%d",&a,&b,&c);
    Number A(a,b,c);
    scanf("%d.%d.%d",&a,&b,&c);
    Number B(a,b,c);
    A=A+B;
    printf("%d.%d.%d\n",A.G,A.S,A.K);
    return 0;
}