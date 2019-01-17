#include <iostream>
#include <string>
using namespace std;
int main(){
    string get ;
    cin>>get;
    int n1 =(get.size()-1)/3;
    int space =get.size()-2*n1-2;
    for(int  i = 0; i < n1; i++)
    {
        cout<<get[i];
        for(int j = 0; j < space; j++)
        {
            cout<<" ";
        }
        cout<<get[get.size()-i-1]<<endl;
    }
    for(int i=n1;i<n1+2+space;i++){
        cout<<get[i];
    }
    cout<<endl;
    return 0;
}