**1039 Course List for Student （25 point(s)）**

# **题意**

给出课程和该课程下面的学生信息建库，再给出请求查询的人名信息，来查询 该人名下面的所有课程，课程代码 增序输出

## 思路一：

用下面这种结构来存储。set 自动排序 map用来做人名映射。但是最后一个数据会超时。

```visual basic
map<string ,set<int>>
```

## 思路二：

由于题目给出了名字只有四个字符，前三个字符是A—Z 最后一个字符是数字0-9
$$
26 *26*26 *10=175761
$$
最大不超过以上175761中 人名。

所以为了不超时，使用下面的办法来做映射。

```c++
ulong trans(string &str){
    return (str[0] - 'A') * 6760 + (str[1] - 'A') * 260 + 
           (str[2] - 'A') * 10 + (str[3] - '0');
}
```

同时全局开一个大数组来存储

```vb
#define MAX 175761
vector<ulong> stds[MAX];
```



### Sample Input:

```in
11(学生数量) 5（课程数量）
4（课程编号） 7（已经选课的学生的名单）
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1（学生名单）
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
(查询序列)
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9

```



**AC代码**

```c++
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 175761
typedef unsigned long ulong;
vector<ulong> stds[MAX];
ulong N,K; string name;
ulong p_idx =0;
ulong trans(string &str){
    return (str[0] - 'A') * 6760 + (str[1] - 'A') * 260 + (str[2] - 'A') * 10 + (str[3] - '0');
}
int main(){
    scanf("%d %d",&N,&K);
    for(int i=0;i<K;i++){
        ulong c,cnt;
        scanf("%d %d",&c,&cnt);
        for(int j=0;j<cnt;j++){
            cin>>name;
            ulong idx =trans(name);
            stds[idx].push_back(c);
        }
    }
    for(int i =0;i<N;i++){
        cin>>name;
        printf("%s",name.c_str());
        ulong idx =trans(name);
        printf(" %d",stds[idx].size());
        sort(stds[idx].begin(),stds[idx].end());
            for(int j=0;j<stds[idx].size();j++){
                printf(" %d",stds[idx][j]);
            }
        printf("\n"); 
    }
    return 0;
}

```

