#include <iostream>
#include <set>
#include  <string>
#include <algorithm>
using namespace std;
struct Node{
    string name;
    char sex;
    string ID;
    int garde;
    bool operator<(const Node&b)const {
        return garde<b.garde;
    }
};

set<Node> M,F;
int cnt;
int main(){
    cin>>cnt;
    
    for(int  i = 0; i < cnt; i++)
    {
        Node temp;
        cin>>temp.name>>temp.sex>>temp.ID>>temp.garde;
        if(temp.sex=='M'){
            M.insert(temp);
        }
        else{
            F.insert(temp);
        }
    }
    bool flag[2]={false};
    set<Node>::reverse_iterator iF;
    set<Node>::iterator iM;
    if(F.size()==0){
        cout<<"Absent"<<endl;
    }else{
        iF =F.rbegin();
        cout<<iF->name<<" "<<iF->ID<<endl;
        flag[0]=true;
    }
    if(M.size()==0){
        cout<<"Absent"<<endl;
    }else{
        iM =M.begin();
        cout<<iM->name<<" "<<iM->ID<<endl;
        flag[1]=true;
    }
    if(flag[0]&&flag[1]){
        cout<<iF->garde-iM->garde<<endl;
    }
    else{
        cout<<"NA"<<endl;
    }
    return 0;
}