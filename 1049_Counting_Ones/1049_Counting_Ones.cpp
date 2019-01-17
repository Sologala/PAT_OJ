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