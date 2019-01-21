![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1064_Complete_Binary_Search_Tree**
*/



 **思路**

​	题目时要求一个完全二叉搜索树（**CBT**）的层次便利序列

​	如果这样一个**CBT** 是满二叉树。那么就可以层次遍历快速的。

​	但是如果给出的二叉树是非满二叉树如下图所示，那么我们可以对该🌲 处理一下。先把最后一层的节点拆掉，这样留下来的必然是一颗满二叉树，通过数组可以快速的找到树根，然后层次便利。

**拆最底层节点**

​	既然是BST 那么 对节点信息**sort**之后必然是 该树的**中序序列**。而 树的遍历有一个性质就是 叶子结点在遍历中的相对位置不变，且这里是完全二叉树。如下图所示，可以发现一下规律。

中序序列 从第一个开始 没跳一个都是底层的叶子。

![](https://github.com/Sologala/PAT_OJ/blob/master/1064_Complete_Binary_Search_Tree/1064_Complete_Binary_Search_Tree.assets/0.png?raw=true)

而底层叶子结点的个数可以用下面的方法求，通过树的基本性质

```c
  	//计算最后一层的数量。
    int h =log(cnt)/log(2)+1;    
    int a =cnt-pow(2,(h-1))+1;
```

![](https://github.com/Sologala/PAT_OJ/blob/master/1064_Complete_Binary_Search_Tree/1064_Complete_Binary_Search_Tree.assets/1.png?raw=true)

这样就把底层叶子拆掉 ，保存起来，对剩下的完全满二叉树 层次遍历，最后在加上最后一层的叶子结点。

![](https://github.com/Sologala/PAT_OJ/blob/master/1064_Complete_Binary_Search_Tree/1064_Complete_Binary_Search_Tree.assets/2.png?raw=true)

而满二叉树的遍历在这里因为树用的数组来存储树，所以应该在队中存储 数组的开始和结束。以及子树的开始和结尾。而树根这是**（low+high）/2**（ps这里我的数组 是从1开始的，从0开始需要变化一下）

### **ac_code**
```c
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1064 Complete Binary Search Tree
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
bool tag=false;
vector<int> T;
int main(){
    int cnt;
    scanf("%d",&cnt);
    T.resize(cnt+1);
    for(int i = 1; i <= cnt; i++)
    {
        scanf("%d" ,&T[i]);
    }
    sort(T.begin()+1,T.end());
    //计算最后一层的数量。
    int h =log(cnt)/log(2)+1;    
    int a =cnt-pow(2,(h-1))+1;
    vector<int> last_level;
    for(int i =1;a>0;i++){
        last_level.push_back(T[i]);
        T.erase(T.begin()+i);
        a--;
    }
    //此时的T 是一个满二叉树  从中间位置开始读取就ok了。
    queue<int> Q;
    Q.push(1);
    Q.push(T.size()-1);
    while(!Q.empty()&&!T.empty()){
        //dequeue
        int low =Q.front();
        Q.pop();
        int high=Q.front();
        Q.pop();
        if(low>high) break;

        int r =(low+high)/2;

        //ourput
        if(!tag) {printf("%d",T[r]);tag=true;}
        else printf(" %d",T[r]);
        
        //push left_side
        Q.push(low);
        Q.push(r-1);
        //push right_side
        Q.push(r+1);
        Q.push(high);
    }
    //output the last_level
    for(vector<int>::iterator it=last_level.begin();it!=last_level .end();it++){
       //ourput
        if(!tag) {printf("%d",*it);tag=true;}
        else printf(" %d",*it);
    }
    return 0;
}           
```