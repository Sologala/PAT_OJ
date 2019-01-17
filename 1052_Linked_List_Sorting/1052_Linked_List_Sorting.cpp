#include <cstdio>
#define MAX 100010
#define head 100009
struct node{
    int key;
    int next=-1;
};
node N[MAX];
int cnt,in_cnt =0;
int main(int argc, char const *argv[])
{
    scanf("%d %d",&cnt,&N[head].next);

    for(int i = 0; i < cnt; i++)
    {
        int add,k,nex;
        scanf("%d %d %d",&add,&k,&nex);
        N[add].key =k;
        N[add].next=nex;
    }
    //insert sort
    int s =N[head].next,q;
    if(s==-1){
        q=-1;
    }else{
        q=N[s].next;
        N[s].next =-1;
        in_cnt++;
    }
    while(q!=-1){
        int next =N[q].next;
        int p = N[head].next,r=head;
        while(p!=-1&&N[p].key<=N[q].key){
            r=p;
            p=N[p].next;
        }
        N[r].next = q;
        N[q].next =p;
        q=next;
        in_cnt++;
    }
    q=N[head].next;
    printf("%d ",in_cnt);
    if(q!=-1)
         printf("%05d\n",q);
         else
         printf("-1\n");
    while(q!=-1){
         printf("%05d %d ",q,N[q].key);
         if(N[q].next!=-1)
         printf("%05d\n",N[q].next);
         else
         printf("-1\n");
         q=N[q].next;
    }
    return 0;
}

