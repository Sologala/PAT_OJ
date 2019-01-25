![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1068_Find_More_Coins**
*/

1068 Find More Coins （30 分）

Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 10^4 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: `N` (≤10^4, the total number of coins) and `M` (≤10^2, the amount of mobney Eva has to pay). The second line contains `N` face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in one line the face values *V*1≤*V*2≤⋯≤*V**k* such that *V*1+*V*2+⋯+*V**k*=`M`. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists *k*≥1 such that A[*i*]=B[*i*] for all *i*<*k*, and A[*k*] < B[*k*].

### Sample Input 1:

```in
8 9
5 9 8 7 2 3 4 1
```

### Sample Output 1:

```out
1 3 5
```

### Sample Input 2:

```
4 8
7 2 4 3

5 12
1 2 4 6 8 30

```

### Sample Output 2:

```
No Solution
```



# **思路**

​	最“**小**”的一组数据 使得刚好等于给定值。	采用贪心的方法来做，把给数据sort  从小到大排序，然后一个一个入栈，并记录栈中元素的总和，只要总和小于给定值，就全塞进来。然后从后面的一些数据中找是否有等于 ，如果大于就退出循环，将栈顶元素往后移动一位，在重复上述计算。 如果有等于的，就输出栈中所有的元素。就是最小的组合。如果当栈中只有一个元素，且一趟下来没有发现 比给定值等于或者大于的数，就判定No solution。

​	这样的代码会有两个测试点超时。

​	因此我们将每次的的查询改成二分查找。

​	最后还是有一个测试点错误

贪心code

```c
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1068 Find More Coins
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
#define MAX 10010
vector<int> A;
struct node{
    int sum;
    int idx;
};
node s[MAX];
int top =0;
int main(){
    int cnt,pay;
    scanf("%d %d",&cnt,&pay);
    int num;
    for(int i=0;i<cnt;i++){
        scanf("%d",&num);
        if(num<=pay){
            A.push_back(num);
        }
    }
    sort(A.begin(),A.end());
    s[0].sum =0;
    s[0].idx =-1;
    int i =0;
    while(i<A.size()&&s[top].sum+A[i]<=pay){
            s[++top].idx=i;
            s[top].sum =s[top-1].sum+A[i++];
    }
    top--;
    while(top!=-1){
        int l =s[top].idx+1,h =A.size()-1;
        while(l<h){
            int mid =(l+h)/2;
            if(A[mid]+s[top].sum==pay){
                l =mid;
                break;
            }
            else if(A[mid]+s[top].sum<pay){
                l=mid+1;
            }
            else if(A[mid]+s[top].sum>pay){
                h =mid-1;
            }
        }
        if(A[l]+s[top].sum==pay){
            for(int k =1;k<=top;k++){
                printf("%d ",A[s[k].idx]);
            }
            printf("%d",A[l]);
            printf("\n");
            return 0;
        }
        else{
            s[top].idx++;
            s[top].sum =s[top-1].sum+A[s[top].idx];
            if(s[top].sum>pay){
                top--;
                s[top].sum =s[top-1].sum+A[s[top].idx];
            }
        }
    }
    printf("No Solution\n");
    return 0;
}

```

在牛课网上 是能全部通过，但是pat 没有。自己试了一下，发现这道题贪心是不能得到最优解的

比如如下的 测试点

```
5 12
1 2 4 6 8 
```



### **ac_code**
```c
 
```





```c
#include <iostream>
#include <algorithm>

using namespace std;

int bags[101];
bool selected[10001][101];

bool cmp(const int &a, const int &b){
    return a > b;
}

int main(){
    int coins[10001];
    int n, m;// n coins, pay m
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> coins[i];
    }
    sort(coins + 1, coins + 1 + n, cmp);

    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){ //之所以要反着来，和背包问题的更新规则有关
            if(j - coins[i] >= 0 && bags[j-coins[i]] + coins[i] >= bags[j]){ //等号必须取到，否则输出的解是最大的sequence
                selected[i][j] = true; //跟踪哪个物品被选择了
                bags[j] = bags[j-coins[i]] + coins[i];
            }
        }
    }
    if(bags[m] != m){
        cout << "No Solution" << endl;
        return 0;
    }
   //下面是输出最优组合的过程，其实和背包问题的更新规则有关，就是沿着选出解的路径，反着走回去，就找到了所有被选择的数字。
    int j = m, i = n;
    while(1){
        if(selected[i][j] == true){
            cout << coins[i];
            j -= coins[i];
            if(j != 0)
                cout << " ";
        }
        i--;
        if(j == 0 || i == 0)
            break;
    }
    cout << endl;
    return 0;
}
```

