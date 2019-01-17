1049 Counting Ones （30 分）

The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

这道题没想出来,参考的 算法笔记上面的思想.从低位枚举到高位,计算每一位的出现1 的次数. 



参考代码

```c
#include <cstdio>
int res=0,num,i=1;
int left,right,now;
int main(){
    scanf("%d",&num);
    while(num/i){
        left =num/(i*10);
        now =num/i%10;
        right =num%i;
        if(now==0)  res+=left*i;
        else if(now ==1)  res+=left*i+1+right;
        else res+=(left+1)*i;
        i*=10;
    }
    printf("%d\n",res);
    return 0;
}
```

