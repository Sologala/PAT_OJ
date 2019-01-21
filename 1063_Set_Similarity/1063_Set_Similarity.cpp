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
