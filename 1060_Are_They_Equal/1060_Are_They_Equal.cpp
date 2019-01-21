/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1060 Are They Equal
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int c,ex1 =0,ex2 =0;
string N1,N2;
string R1,R2;
int main(){
    cin>>c>>N1>>N2;
    int i=0;    
    //清小数点前面的 0.
    for(i=0; i < N1.length()&&N1[i]=='0';)
    {
        N1.erase(N1.begin()+i);
    }
    for(i=0; i < N2.length()&&N2[i]=='0';)
    {
        N2.erase(N2.begin()+i);
    }
    //找小数点并且删除小数点.
    for(i =0; i < N1.length(); i++)
    {
        if(N1[i]=='.'){N1.erase(N1.begin()+i);break;}
    }
    ex1 =i;
    for(i=0; i < N2.length(); i++)
    {
        if(N2[i]=='.'){ N2.erase(N2.begin()+i);break;}
    }
    ex2 =i;
    //有可能 是小于的小数。 0.0000000001 这样需要把 剩余的0 清掉。
    for(i=0; i < N1.length()&&N1[i]=='0';)
    {
        N1.erase(N1.begin()+i);
        ex1--;
    }
    for(i=0; i < N2.length()&&N2[i]=='0';)
    {
        N2.erase(N2.begin()+i);
        ex2--;
    }
    //如果是0 N1 N2 会变成空穿
    if(N1.length()==0) ex1 =0;
    if(N2.length()==0) ex2 =0;
    //结果补充0
    for(i=0;i<c;i++){
        if(i<N1.length()&&N1[i]!='0'){
            R1.push_back(N1[i]);
        }
        else  R1.push_back('0');
    }    
    for(i=0;i<c;i++){
        if(i<N2.length()&&N2[i]!='0'){
            R2.push_back(N2[i]);
        }
        else  R2.push_back('0');
    }
    //输出
    if(R1==R2&&ex1==ex2){
        cout<<"YES ";
        cout<<"0";
        if(R1.length()){
            cout<<"."<<R1<<"*10^"<<ex1;
        }
    }
    else{
        cout<<"NO ";
        cout<<"0";
        if(R1.length()){
            cout<<"."<<R1<<"*10^"<<ex1;
        }
        cout<<" 0";
        if(R2.length()){
            cout<<"."<<R2<<"*10^"<<ex2;
        }
    }
    return 0;
}
