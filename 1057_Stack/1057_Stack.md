

![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1057_Stack**
*/

 题目中 是模拟一个栈，但是增加了一个操作 取出 栈中元素的中位数。 最开始用遍历的办法去找一个双向链表来维护这个顺序表，然后寻找中位数，但是还是会超时。后来想到如下这种结构。中位数左边的是小于**mid**的数，用一个大根堆来表示，右边用个大根堆来表示。但是在模拟出栈的时候 堆结构定位到 需要删除的数据，因此 采用multilset 代替，**set**可以自己保持有序，切能快速查找并删除节点。

![](https://github.com/Sologala/PAT_OJ/blob/master/1057_Stack/1057_Stack.assets/0.png?raw=true)

​	当入栈和出栈的时候，把数据插入到这个结构，并且维护这两个set 的大小，因为每次操作都是一个数字，因此当在右侧插入一个6 引起中位数变化的时候 ，只需要将right_set中的 最小的数字 放到left_中即可。

![](https://github.com/Sologala/PAT_OJ/blob/master/1057_Stack/1057_Stack.assets/1.png?raw=true)



![](https://github.com/Sologala/PAT_OJ/blob/master/1057_Stack/1057_Stack.assets/2.png?raw=true)

​	下面是ac 代码



### **ac_code**
```c
           /*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1057_Stack
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define MAX 1000010
multiset<int> r_set;
multiset<int,greater<int> > l_set;
int mid=0;
int s[MAX];
int top=-1;
void adjust(){
    if(r_set.size()>l_set.size())
	{
		l_set.insert(*r_set.begin());
		r_set.erase(r_set.begin());
	} 
	else if(l_set.size()>r_set.size()+1)
	{
		r_set.insert(*l_set.begin());
		l_set.erase(l_set.begin());
	}
	mid=*l_set.begin();
}

void push(int num){
    s[++top] =num;
    if(num>mid)
        r_set.insert(num);
    else 
        l_set.insert(num);
    adjust();
}
void pop(){
    if(top==-1){
        printf("Invalid\n");
    }
    else{
        int num =s[top--];
        printf("%d\n",num);
        if(num>mid) r_set.erase(r_set.find(num));
        else  l_set.erase(l_set.find(num));
        adjust();
    }
}
void getMedian(){
    if(top==-1){
        printf("Invalid\n");
    }
    else{
        printf("%d\n",mid);
    }
}
int main(){
    int cnt;
    scanf("%d",&cnt);
    char cmd[15];
    for(int i = 0; i < cnt; i++){  
        scanf("%s",cmd);
        if(cmd[1]=='o'){
            pop();
        }
        else if(cmd[1]=='e'){
            getMedian();
        }
		else if(cmd[1]=='u'){
            int num;
            scanf("%d",&num);
            push(num);
        }	
    }
    return 0;
}

```