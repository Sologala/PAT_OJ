#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#define MAX 175,761
typedef unsigned long Name;


vector<vector<string> > C;
int std_cnt,c_cnt;
string temp_name;
int main(int argc, char const *argv[])
{
    scanf("%d %d",&std_cnt,&c_cnt);
    C.resize(c_cnt+1);
    for(int i=0;i<std_cnt;i++){
        cin>>temp_name;
        int cnt,c_idx;
        scanf("%d",&cnt);
        for(int j = 0; j < cnt; j++){
            scanf("%d",&c_idx);
            C[c_idx].push_back(temp_name);
        }
    }
    
    for(int i = 1; i <C.size(); i++){
        printf("%d %d\n",i,C[i].size());
        sort(C[i].begin(),C[i].end());
        for(int j = 0; j < C[i].size(); j++){
            printf("%s\n",C[i][j].c_str());
        }
    }
    
    return 0;
}
