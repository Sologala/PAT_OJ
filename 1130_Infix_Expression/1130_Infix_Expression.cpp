/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1130 Infix Expression
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;
struct node{
    string sig;
    int left,right;
};
vector<node> G;
unordered_map<int,int> father;

string inorder(int r,bool tag){//tag 表示是否输出括号
    if(r==-1) return "";
    string ret1,ret2,ret;
    ret1=inorder(G[r].left,true);
    ret2=inorder(G[r].right,true);
    ret+=(ret1+G[r].sig+ret2);
    bool flag =true;
    if(G[r].left*G[r].right<0){//单边
        if(G[r].left!=-1&&ret1==G[G[r].left].sig){
            flag =false;
        }
        else if(G[r].right!=-1&&ret1==G[G[r].right].sig){
            flag =false;
        }
    }
    else if(G[r].left*G[r].right==1) flag =false;//叶子节点
    if(flag&&tag) ret = "("+ret+")";
    return ret;
}
int main(){
    int cnt;
    cin>>cnt;
    G.resize(cnt+1);
    for(int i =1;i<G.size();i++){
        cin>>G[i].sig>>G[i].left>>G[i].right;
        if(G[i].left!=-1) father[G[i].left]  =  i;
        if(G[i].right!=-1) father[G[i].right] = i;
    }
    int root =1;
    for(auto it =father.begin();it!=father.end();it++){//找寻最根节点
        int cur =it->second;
        while(father[cur]){
            cur =father[cur];
        }
        root =cur;
    }
    cout<<inorder(root,false);
    return 0;
}
