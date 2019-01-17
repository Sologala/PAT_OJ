#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int p_low,p_high, i_low, i_high, post_pos;
    int len_l;
    int len_r;
    bool find =false;
};
Node S[1001];
int top =-1;
vector <int> Pre,In,Post;
int root,i;
int CNT;
bool ismirr =false;
bool isBST(){
    root =Pre[S[top].p_low];
    if(ismirr){
         for(i=S[top].i_high;i>=S[top].i_low;i--){
            if(In[i]==root){
              S[top].find =true;
              break;
            }
        }
    }
    else {
        for(i=S[top].i_low;i<=S[top].i_high;i++){
            if(In[i]==root){
               S[top]. find =true;
                break;
            }
        }
    }
    if(S[top].find){
        Post[S[top].post_pos] =In[i];
        S[top].len_l = i-S[top].i_low;
        S[top].len_r =S[top].i_high-i;
        bool ret_l =true,ret_r=true;
        if(S[top].len_l!=0){
            Node t;
            t.p_low =S[top].p_low+1;
            t.p_high =S[top].p_low+S[top].len_l;
            t.i_low =S[top].i_low;
            t.i_high =S[top].i_low+S[top].len_l-1;
            t.post_pos =S[top].post_pos-S[top].len_r-1;
            S[++top] =t;
            ret_l=isBST();
        }
        if(S[top].len_r!=0){
            Node t;
            t.p_low =S[top].p_high-S[top].len_r+1;
            t.p_high =S[top].p_high;
            t.i_low =S[top].i_high-S[top].len_r+1;
            t.i_high =S[top].i_high;
            t.post_pos =S[top].post_pos-1;
            S[++top] =t;
            ret_r =isBST();
        }
        --top;
        return ret_l&&ret_r;
    }
    else{
        --top;
        return false;
    }
    
}
int main(){
    cin>>CNT;
    Pre.resize(CNT);
    In.resize(CNT);
    Post.resize(CNT);
    for(int i=0;i<CNT;i++){
        cin>>Pre[i];
        In[i]=Pre[i];
    }
    if(CNT>1){
        if(Pre[1]>=Pre[0]) {
          ismirr =true;
          sort(In.begin(),In.end(),greater<int>());
        }
        else{
         ismirr =false;
         sort(In.begin(),In.end(),less<int>());
        }
    }
    S[++top] =Node{0,Pre.size()-1,0,In.size()-1,Post.size()-1};
    if(isBST()){
        cout<<"YES"<<endl;
        cout<<Post[0];
        for(int i =1;i<Post.size();i++){
            cout<<" "<<Post[i];
        }
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}