#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool less_cmp(const int &a, const int &b){
    return a<b;
}
bool greater_cmp(const int &a, const int &b){
    return a>b;
}
int main(int argc, char const *argv[])
{
    vector<int> s1_pos,s1_neg ,s2_pos,s2_neg;
    int coupon_cnt,product_cnt;
    cin>>coupon_cnt;
    int temp,get =0;
    for(int  i = 0; i < coupon_cnt; i++)
    {
        cin>>temp;
        if(temp>0){
            s1_pos.push_back(temp);
        }
        else{
            s1_neg.push_back(temp);
        }
    }
    cin>>product_cnt;
    for(int  i = 0; i < product_cnt; i++)
    {
       cin>>temp;
        if(temp>0){
            s2_pos.push_back(temp);
        }
        else{
            s2_neg.push_back(temp);
        }
    }
    sort(s1_pos.begin(),s1_pos.end(),greater_cmp);
    sort(s2_pos.begin(),s2_pos.end(),greater_cmp);
    sort(s1_neg.begin(),s1_neg.end(),less_cmp);
    sort(s2_neg.begin(),s2_neg.end(),less_cmp);
    int min_len =min(s1_pos.size(),s2_pos.size());
    int idx =0;
    //s1 增序 正数
    while(idx<min_len){
        get+=s1_pos[idx]*s2_pos[idx];
        idx++;
    }
    //s2 降序 复数
    min_len =min(s1_neg.size(),s2_neg.size());
    idx =0;
    //s1 增序 正数
    while(idx<min_len){
        get+=s1_neg[idx]*s2_neg[idx];
        idx++;
    }

    cout<<get<<endl;
    return 0;
}
