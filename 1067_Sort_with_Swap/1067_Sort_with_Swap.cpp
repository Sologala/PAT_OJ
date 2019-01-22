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