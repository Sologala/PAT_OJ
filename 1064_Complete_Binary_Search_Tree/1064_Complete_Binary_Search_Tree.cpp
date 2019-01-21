/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1064 Complete Binary Search Tree
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
bool tag=false;
vector<int> T;
int main(){
    int cnt;
    scanf("%d",&cnt);
    T.resize(cnt+1);
    for(int i = 1; i <= cnt; i++)
    {
        scanf("%d" ,&T[i]);
    }
    sort(T.begin()+1,T.end());
    //计算最后一层的数量。
    int h =log(cnt)/log(2)+1;    
    int a =cnt-pow(2,(h-1))+1;
    vector<int> last_level;
    for(int i =1;a>0;i++){
        last_level.push_back(T[i]);
        T.erase(T.begin()+i);
        a--;
    }
    //此时的T 是一个满二叉树  从中间位置开始读取就ok了。
    queue<int> Q;
    Q.push(1);
    Q.push(T.size()-1);
    while(!Q.empty()&&!T.empty()){
        //dequeue
        int low =Q.front();
        Q.pop();
        int high=Q.front();
        Q.pop();
        if(low>high) break;

        int r =(low+high)/2;

        //ourput
        if(!tag) {printf("%d",T[r]);tag=true;}
        else printf(" %d",T[r]);
        
        //push left_side
        Q.push(low);
        Q.push(r-1);
        //push right_side
        Q.push(r+1);
        Q.push(high);
    }
    //output the last_level
    for(vector<int>::iterator it=last_level.begin();it!=last_level .end();it++){
       //ourput
        if(!tag) {printf("%d",*it);tag=true;}
        else printf(" %d",*it);
    }
    return 0;
}