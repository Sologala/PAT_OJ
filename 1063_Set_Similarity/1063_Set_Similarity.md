![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.**1063_Set_Similarity**
*/

**题意** 

​	先给出 N 个set。然后 给出K个请求，计算给出的请求的两个set 的相似率是多少

​	简单的**set<int>** 的应用。

​	最开始我直接用一个新的set 来讲两个set合并来计算，但是这样多此一举，反而insert 的时间复杂度很高，不如find。 只需要遍历其中一个，然后在另一个中查询是否属于另一个，并且同时统计一下就行了。

​	

```c
float ratio =count*1.0*100/(s[a].size()+s[b].size()-count);//相似率
```



### **ac_code**
```c
/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1063 Set Similarity
*/
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
vector<set<int> > s;

int main(){
    int s_cnt;
    scanf("%d",&s_cnt);
    s.resize(s_cnt+1);
    for(int i =1;i<=s_cnt;i++){
        int cnt;
        scanf("%d",&cnt);
        for(int j =0;j<cnt;j++){
            int temp;
            scanf("%d",&temp);
            s[i].insert(temp);
        }
    }
    int q_cnt;
    scanf("%d",&q_cnt);
    for(int i=0;i<q_cnt;i++){
        int a,b,count=0;
        scanf("%d %d",&a,&b);
        for(set<int>::iterator it =s[b].begin();it!=s[b].end();it++){
            if(s[a].find(*it)!=s[a].end()) count++;
        }
        float ratio =count*1.0*100/(s[a].size()+s[b].size()-count);
        printf("%0.1f%%\n",ratio);
    }
    return 0;
}

```