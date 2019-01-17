1040 Longest Symmetric String （25 point(s)）

Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given `Is PAT&TAP symmetric?`, the longest symmetric sub-string is `s PAT&TAP s`, hence you must output `11`.

给一个字符串 计算这个字符串内的最长的 回文串的长度。题目很简单，这道题首先想到的应该就是暴力解法。但是暴力解法 判断是否是回文O(n^2) 再加上整个串就是O(n^3) 可能会超时。

于是想到用动态规划来做，下面我将给出一个完整的思路过程，我也是这两天初学动态规划。思考了这个问题一些时间，希望能给到初学的同学一些帮助，同时也作为自己学习的一些笔记。

# **动态规划**



动态规划类似于递归，能使用动态规划来解决的问题需要满足 以下一些条件：

​	1。 能够分解成多个子问题，且在求解母问题的时候会需要子问题的解。

​		例如求斐波拉机数列的时候fib(7) 需要用到fib(6) 和fib(5)的解。

​	2。 满足子问题的解无后效果性质。

​		再如上述的斐波拉机数列的例子。在计算任何大于5 的数k的 fib(k)的值 都不会改变fib(4) 或者fib(3)的值。

​	3 。 合理的边界条件

​        唉~ 发现自己功底真的很弱，原理真的写不下去了。 啥也不懂的可以看看这个UP主 的视频，看完立马明白。。。。

```
 https://www.bilibili.com/video/av1654403
```

# **思路**

​	我们先来看一种最简单的情况。

​	如果有字符串**A-B-A** 那么这个字符串是回文串。

​	可以如何判断呢？ 如果是想C语言老师讲的方法 可以从两端往中间判断是否相等

```c
for(int i=0;i<len/2;i++)
	if(s[i]！=s[len-i-1])return false
```

​	这样就能判断出来**A-B-A** 是回文串。

​	如果该串变成 ***A*-A-B-A-*A***  。 

case 1： **两端加上的字符相等**   且 内部包含的 **A-B-A** **是回文串**

​	这时候就可以利用之前计算过的**A-B-A**  的结果。 ***A*-A-B-A-*A***  是回文串。且长度为3+2=5；

case 1： **两端加上的字符不相等**

​	例如***A*-A-B-A-*C***   这时候就需要判断 **A-A-B-A** 和**A-B-A-C** 中最大的那个结果就是***A*-A-B-A-*C*** 串的最大回文串！。



## ​**动规模型**

 	开辟一个大二维数组: 

```c 
#define MAX 1010
int dp[MAX][MAX]; //dp[ i ][ j ] 表示从i 到 j 的字符串中的最长的回文串 
bool dp_b[MAX][MAX];//dp[ i ][ j ] 表示从i 到 j 的字符串是否是回文串 
```

​	由上述的 关系得到 **递推式**  **状态转移方程**

![https://github.com/Sologala/PTA/blob/master/1040_Longest_Symmetric_String/1040_Longest_Symmetric_String.assets/QQ%E6%88%AA%E5%9B%BE20190115144132.jpg](F:\Pat_Obj\PTA\1040_Longest_Symmetric_String\1040_Longest_Symmetric_String.assets\QQ截图20190115144132.jpg)

​	**边界条件**

  1.   当i==j的时候 也就是只有一个字符的时候 长度是1 

  2.   同时我们默认是正序，所以 当i<j 的时候 是0

       **例如字符串ABCBA**

       ![https://github.com/Sologala/PTA/blob/master/1040_Longest_Symmetric_String/1040_Longest_Symmetric_String.assets/1547535732274.png]()

       我们对dp二维数组从左下到右上的遍历计算。

       ![https://github.com/Sologala/PTA/blob/master/1040_Longest_Symmetric_String/1040_Longest_Symmetric_String.assets/1547535744657.png]()

       当二维数组计算完成之后右上角的值就是整个字符串的最大回文数的结果**。**

       **AC代码**

       ```php
       #include <string>
       #include <cstring>
       #include <iostream>
       #include <algorithm>
       using namespace std;
       #define MAX 1010
       int dp[MAX][MAX];
       bool dp_b[MAX][MAX];
       string s;
       int main(int argc, char const *argv[])
       {
           getline(cin,s);
           memset(dp,0,sizeof(dp));memset(dp_b,false,sizeof(dp_b));
           for(int i=0;i<s.length();i++){ //初始化边界条件
                dp[i][i]=1; 
                dp_b[i][i]=true;     
           }
           for(int j =1;j<s.length();j++){//状态转移方程
               for(int i =j-1;i>=0;i--){
                   if(s[i]==s[j]&&i+1==j){//这个处理 当两个连在一起的相同字符
                           dp_b[i+1][j-1] =true;
                           dp_b[i][j]=true;
                   }
                   if(s[i]==s[j]&&dp_b[i+1][j-1]){//两端相等且内部是回文串
                           dp[i][j] =dp[i+1][j-1]+2;//长度加2
                           dp_b[i][j]=true;
                   }
                   else{
                       dp[i][j] =max(dp[i][j-1],dp[i+1][j]);//两端不会回文串计算
                   }                                        //左右两个子串
               }
           }
           cout<<dp[0][s.length()-1];//输出最终结果
           return 0;
       }
       
       ```

       ​	使用动规 可以将时间复杂度降到O(n^2)  。