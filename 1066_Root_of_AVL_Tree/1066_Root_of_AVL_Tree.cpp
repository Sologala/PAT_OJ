/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1066 Root of AVL Tree
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct node{
    int data,h=1;
    node* left=NULL,*right=NULL;
};
int getheight(node* r){
    return r==NULL?0:r->h;
}
int calBalance_factor(node* r){
    return r==NULL?0:getheight(r->left)-getheight(r->right);
}
void R(node* &r){
    node* temp =r->left;
    r->left =temp->right;
    temp->right =r;
    //更新两个变动节点的高
    r->h =1+max(getheight(r->left),getheight(r->right));
    temp->h =1+max(getheight(temp->left),getheight(temp->right));
    r =temp;
}
void L(node* &r){
    node* temp =r->right;
    r->right =temp->left;
    temp->left =r;
    //更新两个变动节点的高
    r->h =1+max(getheight(r->left),getheight(r->right));
    temp->h =1+max(getheight(temp->left),getheight(temp->right));
    r =temp;
}
int insert(node* &r,int num){
    if(!r){
        r=new node();
        r->data =num;
    }
    else{
        int child_h;
        if(num>=r->data) child_h=insert(r->right,num);
        else child_h=insert(r->left,num);
        if(child_h+1>r->h){                     
                r->h =child_h+1;
        }       
    }
    //check if curNode is unBalanced
    int bal_fac =calBalance_factor(r);
    if(bal_fac==2){//L
        int child_bal_fac =calBalance_factor(r->left);
        if(child_bal_fac==1){//LL
            R(r);
        }
        else if(child_bal_fac==-1){//LR
            L(r->left);
            R(r);
        }
    }
    else if(bal_fac==-2){//R
        int child_bal_fac =calBalance_factor(r->right);
        if(child_bal_fac==1){//RL
            R(r->right);
            L(r);
        }
        else if(child_bal_fac==-1){//RR
            L(r);
        }
    }
    return r->h;
}
int main(){
    int cnt;
    scanf("%d",&cnt);
    node* ROOT;
    for(int i=0;i<cnt;i++){
        int num;
        scanf("%d",&num);
        insert(ROOT,num);
    }
    printf("%d\n",ROOT->data);
    return 0;
}