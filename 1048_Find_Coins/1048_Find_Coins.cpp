#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int cnt,pay;
vector<int> C;
int find(int i,int j,int x){
    int mid;
    while(i<j){
        mid =(i+j)/2;
        if(x+C[i]==pay){return i;}
        else if(x+C[i]>pay){j =mid-1;}
        else{i=mid+1;}
    }
    return x+C[i]==pay?i:-1;
}
int main(){

    scanf("%d %d",&cnt,&pay);
    
    int tempnum;
    for(int i = 0; i < cnt; i++){
        scanf("%d",&tempnum);
        C.push_back(tempnum);
    }
    sort(C.begin(),C.end());
    
    for(int i = 0; i < C.size()-1; i++)
    {
        int j=find(i+1,C.size()-1,C[i]);
        if(j!=-1){
            printf("%d %d",C[i],C[j]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
