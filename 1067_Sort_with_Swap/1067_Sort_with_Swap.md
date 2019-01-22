![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1067_Sort_with_Swap**
*/

1067 Sort with Swap(0, i) （25 分）

Given any permutation of the numbers {0, 1, 2,..., *N*−1}, it is easy to sort them in increasing order. But what if `Swap(0, *)` is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first *N* nonnegative integers.

### Input Specification:

Each input file contains one test case, which gives a positive *N* (≤105) followed by a permutation sequence of {0, 1, ..., *N*−1}. All the numbers in a line are separated by a space.

### Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

### Sample Input:

```in
10
3 5 7 2 6 4 9 0 8 1
```

### Sample Output:

```out
9
```

**思路**：	题目让求 用 `Swap(0, *)`  （**交换数字0和***）来排序最少需要多少次。先来看题目给出的例子。

​		**B**[ ] ={0, 1, 2, 3, 4}  最终排好序
​		**A**[ ] ={4, **0**, 2, 1, 3} 在B中对应的是1，所以和**A[3]=1**交换

Swap(0, 1) => {4, 1, 2, **0**, 3} 在B中对应的是3，所以和**A[4]=3**交换
Swap(0, 3) => {4, 1, 2, 3, **0**} 在B中对应的是4，所以和**A[0]=4**交换
Swap(0, 4) => {**0**, 1, 2, 3, 4}

 我们只需要通过一个hash 表来映射 **B**的值 与 在**A**中的下标的关系，就能快速的找到需要交换的两个数。

```c
map<int,int>  add;
```

 但是分析题目给的 眼样例 会出现以下情况

0 1 2 3 4 5 6 7 8 9
3 5 **7** 2 6 4 9 **0** 8 1

3 5 **0** **2** 6 4 9 7 8 1

**3** 5 2 **0** 6 4 9 7 8 1

**0** 5 2 3 6 4 9 7 8 1 //

当swap 到如下情况的时候，按照之前的规则0需要交换的是它本身。

因此我们需要找到一个还没有对齐的与之交换，这样就能继续的往下计算。

**5 0** 2 3 6 4 9 7 8 1 //

而同时我们也可以把找 第一个 没对齐的数字来作为循环出口条件。

```c
 while((start=find_first(start))!=-1)
```

### ac_code

```c
        /*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1067 Sort with Swap
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<int,int>  add;
vector<int> A,B;
int find_first(int start){
    for(int i=start;i<A.size();i++){
        if(A[i]!=B[i]) return i;
    }
    return -1;
}
int main(){
    int cnt,zero_add;
    scanf("%d",&cnt);
    A.resize(cnt);
    for(int i = 0; i < cnt; i++)
    {
        scanf("%d",&A[i]);
        if(A[i]==0){
            zero_add =i;
        }
        add[A[i]]=i;//建立地址映射
    }
    B = A;//拷贝一份排好序 作为参照
    sort(B.begin(),B.end());
    int i=zero_add,count=0,start =0;
    while((start=find_first(start))!=-1){//find_first找第一个没有对齐的下标
        int swap_add =add[B[i]];            //如果没有 返回-1，作为循环出口
        if(A[i]==B[i]){//处理 在对齐过程中 0先对齐的情况。
            add[A[i]] =start;
            add[A[start]] =i;
            swap(A[i],A[start]);
            count++;
            i =start;
            swap_add =add[B[i]];
        }
        else{
            swap(A[i],A[swap_add]); 
            i =swap_add;
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}   
```