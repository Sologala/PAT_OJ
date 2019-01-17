#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct node{
    int num;
    int cnt;
    int idx;
};
map<int,int> M;
vector<node> Q;
map<int,int>::iterator it;

bool cmp(const node &a,const node &b){
    if(a.cnt!=b.cnt){return a.cnt<b.cnt;}
    else{ return a.idx<b.idx;}
}

int main(){
    int cnt;
    cin>>cnt;
    int idx=0;
    for(int i = 0; i < cnt; i++)
    {
        int num;
        cin>>num;
        it =M.find(num);
        if(it!=M.end()){
            Q[M[num]].cnt++;
        }
        else{
            node newnode;
            newnode.num=num;
            newnode.cnt =1;
            newnode.idx =idx;
            Q.push_back(newnode);
            M.insert(pair<int,int>(num,idx++));
        }
    }
    sort(Q.begin(),Q.end(),cmp);
    if(Q.size()==0||Q[0].cnt!=1){
        cout<<"None";
    }
    else{   
        cout<<Q[0].num;
    }
    return 0;
}