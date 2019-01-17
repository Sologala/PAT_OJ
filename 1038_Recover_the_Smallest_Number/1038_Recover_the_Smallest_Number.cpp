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