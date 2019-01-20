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
