1043 Is It a Binary Search Tree

# **题意** 

 题目给出二叉树的前序序列判断是否是BST 是输出YES 并且输出改BST的后序序列

#  **思路**

​	通过前序和中序 来 求后序。

​	由于是BST 所有数据的中序一定是有序的。题目说给的前序序列可能是 左右交换过的BST 所以需要先判断一下，如果是镜像的 BST 那么他的前序的第二个一定是大于根节点也就是第一个。

``` c
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
```

​	而对应的中序序列 也需要 减序 排列。

此上 得到**中序序列。**

​	由前序和中序求 **后**序

```c
[ Pre]  8 6 5 7 10 8 11	
[ In ]  5 6 7 8 8 10 11	
[Post]  ? ? ? ? ? ? ?               	  
↓↓↓↓ //在In 里面查找根节点 pre[0]; 如果是非镜像的BST 则从前往后寻找，如果是镜像则从															//后往前
[ Pre]  8 6 5 7 10 8 11
	  [↑]-----//前序从根节点开始往后len =3 个结点是 8的左子树的前序序列
[ In ]  5 6 7 8 8 10 11
       ------[↑] //中序左边是bst 左边的 长度为3 的序列时  左子树的中序序列
[Post]  ? ? ? ? ? ?  8
    	   [↑]	 [↑]	//后序的根节点的位置以及右子数的根节点
   		    左    右
```

​	由上可知，反之得到右子数的前序和中序 。

​	这样就可以用递归的思想来计算 二叉树，每一次递归可以归位一个后序的根节点。

**如果不是BST 的情况呢？**

​	如果在对应的区域找不到当前的根节点 则可以说明不是BST前序序列。（具体原因  可以用题目给出的 样例3  推导一下。	

​	**AC代码**

```c 
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
Node S[1001];				//在这里我使用了自己模拟一个栈。在AC之前RE了
int top =-1;				//很久,当然你也可以把这些变量放在函数的参数里面
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
```

