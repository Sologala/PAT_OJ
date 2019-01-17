    #include <cstdio>
    #include <cstring>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    #define MAX 100010
    #define INF 99999999
    using namespace std ;
    int Cnt,Pay;
    int sum[MAX];
    int temp;
    int find_the_min(int i,int j,int x){
        int mid;
        while(i<j){
            mid =(i+j)/2;
            if(sum[mid]-sum[0]>=x) j=mid;
            else i=mid+1;
        }
        return i;
    }
    struct res{
        int i,j;
    };
    vector<res> R;
    int main(){
        scanf("%d %d",&Cnt,&Pay);
        sum[0]=0;
        for(int i = 1; i <=Cnt; i++){
        scanf("%d",&temp);
        sum[i]=sum[i-1]+temp;
        }
        bool find =true;
        int min=INF;
        for(int i=1;i<=Cnt;i++){
            sum[0]=sum[i-1];
            int j=find_the_min(i,Cnt,Pay);
            if(sum[j]-sum[0]<Pay){break;}
            if(sum[j]-sum[0]<min){
                R.clear();
                R.push_back(res{i,j});
                min=sum[j]-sum[0];
            }
            else if(sum[j]-sum[0]==min){
            R.push_back(res{i,j});
            }
        }
        for(int i=0;i<R.size();i++){
            printf("%d-%d\n",R[i].i,R[i].j);
        }
        return 0;
    }