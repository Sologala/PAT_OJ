#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct node{
    unsigned long id;
    string name;
    string author;
    vector<string> keyword;
    string publisher;
    unsigned int year ;
};
int Cnt;
vector<node> s;
int main(int argc, char const *argv[])
{
    /* code */
    std::ios::sync_with_stdio(false);
    cin>>Cnt;
    for(int i=0;i<Cnt;i++)
    {
        node temp;
        cin>>temp.id;
        getline(cin,temp.name);
        getline(cin,temp.author);
        string t;
        getline (cin,t);
        int l =0;
        for(int j=0;j<t.size();j++){
            if(t[j] ==' '){
                temp.keyword.push_back(string(t.begin()+l,t.begin()+l+j-1));
                l=j+1;
            }
        }
        
    }

    return 0;
}


