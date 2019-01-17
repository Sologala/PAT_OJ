#include<iostream>
#include<vector>
using namespace std;

typedef  int Lint;
Lint v[1000001];
int ii=0;
int main(int argc, char const *argv[])
{
    int size1,size2;

    scanf("%d",&size1);
    for(int  i = 0; i < size1; i++)
    {
        scanf("%d",&v[i]);
        ii=i+1;
    }
    scanf("%d",&size2);
    int mid =(size1+size2+1)/2;
    int cnt =0,idx =0;
    for(int i = 0;i<size2;i++){
        Lint temp;
        scanf("%d",&temp);
        if(temp<v[idx]){
            cnt++;
            if(cnt ==mid){
                printf("%d",temp);
                return 0;
            }
        }
        else{
            while (temp > v[idx] && idx < ii && cnt < mid)
            {
                cnt++;
                if (cnt == mid)
                {
                    printf("%d", v[idx]);
                    return 0;
                }
                idx++;
            }
            cnt++;
            if (cnt == mid)
            {
                printf("%d", temp);
                return 0;
            }
        }
    }
    if(cnt<mid)//还没有数完
    {
        while(idx<ii){
            cnt++;
            if(cnt ==mid){
                printf("%d",v[idx]);
                return 0;
            }
            idx++;
        }
    }
    return 0;
}


