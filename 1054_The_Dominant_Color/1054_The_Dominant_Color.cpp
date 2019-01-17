/*
    Sologala   @github    https://github.com/Sologala/PAT_OJ
    PAT_oj No.1054_The_Dominant_Color
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int,int> M;
map<int,int> ::iterator it;
#define MAx 225
int color_count[MAx]={0};
int main(int argc, char const *argv[]){
    int w,h;
    scanf("%d %d",&w,&h);
    long get,max_idx=0,maxval=0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
           scanf("%ld",&get);
            it =M.find(get);
            if(it==M.end()){
                M[get]=1;
            }
            else{
                M[get]++;
            }
            if(M[get]>maxval){
                max_idx =get;
            }
        }
    }
    printf("%d",max_idx);
    return 0;
}
