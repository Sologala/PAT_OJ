#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#define MAX 10010
using namespace std;
map<char,int> M;
map<char,int>::iterator it;
string s1,s2,res;
int main(){
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s2.length();i++){
        M[s2[i]]=i;
    }
    
    for(int i = 0; i < s1.length(); i++)
    {
        it =M.find(s1[i]);
        if(it==M.end()){
            res.push_back(s1[i]);
        }
    }
    cout<<res;
    return 0;
}