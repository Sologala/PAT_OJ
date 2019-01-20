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
