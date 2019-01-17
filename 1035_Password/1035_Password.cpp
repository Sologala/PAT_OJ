#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Node{
    string name;
    string pwd;
};
int CNT;
vector<Node> res;
bool replace(string &s){
    bool ret =false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){s[i]='@';ret =true;}
        else if(s[i]=='0'){s[i]='%';ret =true;}
        else if(s[i]=='l'){s[i]='L';ret =true;}
        else if(s[i]=='O'){s[i]='o';ret =true;}
    }
    return ret;
}
int main(){

    cin>>CNT;
    string temp_name,temp_pwd;
    for(int i=0;i<CNT;i++){
        cin>>temp_name>>temp_pwd;
        if(replace(temp_pwd)){
            res.push_back(Node{temp_name,temp_pwd});
        }
    }
    if(res.size()){
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res[i].name<<" "<<res[i].pwd<<endl;
        }
    }
    else{
        if(CNT==1)
            cout<<"There is "<<CNT<<" account and no account is modified"<<endl;
        else{
            cout<<"There are "<<CNT<<" accounts and no account is modified"<<endl;
        }
    }
    return 0;
}
