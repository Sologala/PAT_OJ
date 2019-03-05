![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1130_Infix_Expression**
*/

Given a syntax tree (binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20) which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the *i*-th line corresponds to the *i*-th node) in the format:

```
data left_child right_child
```

where `data` is a string of no more than 10 characters, `left_child` and `right_child` are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by −1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.

| ![infix1.JPG](https://images.ptausercontent.com/4d1c4a98-33cc-45ff-820f-c548845681ba.JPG) | ![infix2.JPG](https://images.ptausercontent.com/b5a3c36e-91ad-494a-8853-b46e1e8b60cc.JPG) |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Figure 1                                                     | Figure 2                                                     |

### Output Specification:

For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators. Note that there must be no extra parentheses for the final expression, as is shown by the samples. There must be no space between any symbols.

### Sample Input 1:

```in
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
```

### Sample Output 1:

```out
(a+b)*(c*(-d))
```

### Sample Input 2:

```in
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
```

### Sample Output 2:

```out
(a*2.35)+(-(str%871))
```

##思路:

​	根据输入的数据建立 图. 因为是只有左右节点.直接中序遍历 并且输出顺序就好了.

​	但是有一个括号需要处理.如果该节点是单分支节点,并且该节点的子节点是叶子节点那么 `不需要`加上括号.

​	如果该节点是叶子节点  也不需要加上括号.

### **ac_code**
```c
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
 
```