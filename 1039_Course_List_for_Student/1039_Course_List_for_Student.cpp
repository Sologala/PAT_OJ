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
