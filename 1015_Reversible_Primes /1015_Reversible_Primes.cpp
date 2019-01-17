
#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

//"reverse" in that number system 

bool isPrimeNumber(long number){
    if(number ==1){return false;}
    if(number ==2||number==3){
        return true;
    }
    long yush =number%6;
    if(yush!=5&&yush!=1){// 不在 6 的两侧的数字 一定不是质数.
        return false;
    }    
    else{
        int temp = sqrt(number);
        for(long i =5;i<=temp;i+=6){
            if(number%i==0||number%(i+2)==0)
            {
                return false;
            }
        }
        return true;
    }
}

long trans(long s,int radix){
    long ret =0;
    vector<char> v;
    while(s>0){
        v.push_back(s%radix);
        s/=radix;
    }
    for(int i= 0;i<v.size();i++){
        ret *=radix;
        ret+=v[i];
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    long get_s;
    int radix;
    while(true){
        cin>>get_s;
        if(get_s < 0){break;}
        cin>>radix;
        bool flag[2] ={false};
        flag[0]=isPrimeNumber(get_s);
        flag[1]=isPrimeNumber(trans(get_s,radix));
        if(flag[0]&&flag[1]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}



