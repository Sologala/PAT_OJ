#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Node{
    int add;
    char data;
    int next=-1;
};
map<int,Node> M;
int Add_cnt,S1,S2;
int main(int argc, char const *argv[])
{
    scanf("%d %d %d",&S1,&S2,&Add_cnt);
    for(int i=0;i<Add_cnt;i++){
        Node temp;
        scanf("%d %c %d",&temp.add,&temp.data,&temp.next);
        M.insert(pair<int ,Node>(temp.add,temp));
    }
    //statistic the string 1 len;   
    int len1=0,len2=0,p =S1;
    map<int,Node>::iterator it,it2;
    while(p!=-1){
        it =M.find(p);
        if(it==M.end()){break;}        
        p = it->second.next;
        len1++;
    }
    p =S2;
    while(p!=-1){
        it =M.find(p);
        if(it==M.end()){break;}        
        p = it->second.next;
        len2++;
    }
    if(len1<len2){swap(S1,S2);swap(len1,len2);}
    p =S1;
    while(len1!=len2){
       it =M.find(p);
        if(it==M.end()){break;}        
        p = it->second.next;
       len1--;
    }
    int q =S2;
    int idx =-1;bool flag =false;
    while(p!=-1&&q!=-1){
        it =M.find(p);
        if(it==M.end()){break;}        
        it2 =M.find(q);
        if(it2==M.end()){break;}        
        if (flag==false&&it2->second.add==it->second.add)
        {
            idx =p;flag =true;
        }
        if(flag==true&&it2->second.add!=it->second.add){
            flag =false;
        }
        q = it2->second.next;
        p = it->second.next;
    }
    if(idx==-1){
       printf("-1");
    }
    else{
        printf("%05d",M[idx].add);
        }
    return 0;
}
