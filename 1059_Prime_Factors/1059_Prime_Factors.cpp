/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1059_Prime_Factors
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long int UL;
UL num;
vector<int> res;
vector<bool> P;
int g_i =11;
UL idx=2;
void calPrime(){
    bool find =false;
    while(!find){
        
    }    
}

int main(){
    cin>>num;
    P.resize(num/2);
    
    P[2]=true;
    P[3]=true;
    P[5]=true;
    P[7]=true;
    P[11]=true;
    while(num){
        if(num%idx==0){
            res.push_back(idx);
        }
        else{
            //next prime num
        }        
    }
    return 0;
}
