#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
 int rate[24]={0};
class _time
{
  public:
    _time(){};
    ~_time(){};
  public:
    int m, d, h, min;
    bool flag; //true ----on  false ---off
  public:
    void settime(int _m, int _d, int _h, int _min)  {
        m=_m; d=_d; h =_h; min= _min;
    };
    bool lessthan(_time &b) {
        if(m!=b.m) return m<b.m;
        else if(d!=b.d) return d<b.d;
        else if (h!=b.h) return h<b.h;
        else if(m!=b.min) return m<b.min;
        else return false;
    }
};
struct Record{
    vector<_time> record;
    string name;
};

//---------
int recore_cnt;

vector<Record> hh;
bool cmp_time( _time &a, _time &b){
    return a.lessthan(b);
}
bool cmp_name(Record &a,Record &b){
    int len1 =a.name.size();
    int len2 = b.name.size();
    int len = min(len1,len2);
    int i= 0;
    while(i<len){
        if(a.name[i]<b.name[i]){
           return true;
        }
        else if(a.name[i]==b.name[i]){
            i++;
        }
        else{
            return false;
        }
    }
    if(i==len){
        return len1<len2;
    } 
    else{
          return false;
    }
}
struct outdata{
    _time time1,time2;
    int sum;
    double fee;
};
void mysort(Record &r){
    //sort the time_record of R
    sort(r.record.begin(),r.record.end(),cmp_time);//按照时间顺序排好序
    int len = r.record.size();
    //排除 该名字的通话中 没有一个可以的通话记录/
    vector<outdata> vout;
    double total_fee =0;
    for (int i= 1; i <len; i++)
    {
        if (r.record[i].flag == false&&r.record[i-1].flag==true)
        {
            r.record.push_back(r.record[i-1]);
            r.record.push_back(r.record[i]);
            int sum =0;double fee =0;
            sum+=(r.record[i].d-r.record[i-1].d)*24*60;
            sum+=(r.record[i].h-r.record[i-1].h)*60;
            sum+=(r.record[i].min-r.record[i-1].min);
            int h1 =r.record[i-1].h,h2=r.record[i].h;
            int d1=r.record[i-1].d,d2=r.record[i].d;
            if(r.record[i].m>0){
                h1 =h1+1;
                if(h1%24==0)
                {
                    d1+=1;
                    h1=0;
                }
            }
            fee+=(60-r.record[i-1].min)*rate[r.record[i-1].h];
            while(d1!=d2||h1!=h2)       
            {
                fee+=60*rate[h1];
                h1++;
                if(h1%24==0)
                {
                    d1+=1;
                    h1=0;
                }
            }
            fee+=r.record[i].min*rate[r.record[i].h];
            fee /= 100;
            outdata temp;
            temp.time1 =r.record[i-1];
            temp.time2 =r.record[i];
            temp.fee =fee;
            temp.sum =sum;
            vout.push_back(temp);
            total_fee+=fee;
        }
    }
    if(vout.size()>0){ 
    printf("%s %02d\n",r.name.c_str(),r.record[0].m);
    for(int i= 0;i<vout.size();i++)
         printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
                vout[i].time1.d ,vout[i].time1.h,vout[i].time1.min,
                vout[i].time2.d,vout[i].time2.h, vout[i].time2.min,
                vout[i].sum, vout[i].fee
                );
    printf("Total amount: $%.2lf\n",total_fee);
    }
}
char name[20];
char getstr[20];
int main(int argc, char const *argv[])
{
    /* code */
    for(int i= 0;i<24;i++){
        scanf("%d",&rate[i]);
    }
    _time tt;
    scanf("%d",&recore_cnt);
    for(int i=0;i<recore_cnt;i++){
        _time temp_time;
        scanf("%s %d:%d:%d:%d %s",name, &temp_time.m, &temp_time.d, &temp_time.h, &temp_time.min,getstr);
        vector<Record>::iterator iter = hh.begin();
        for(;iter!=hh.end();iter++){
            if(strcmp(iter->name.c_str(),name)==0){
                break;
                }
        }
        if (getstr[1] == 'n')
        {
            temp_time.flag = true;
        }
        else if (getstr[1]== 'f')
        {
            temp_time.flag = false;
        }
        if(iter!=hh.end())//find 
        {
            iter->record.push_back(temp_time);//insert
        }
        else{
            Record temp_record;//new record ;
            temp_record.name=(name);
            temp_record.record.push_back(temp_time);
            hh.push_back(temp_record);
        }
    }
     //sort and cal
     vector<Record>::iterator it=hh.begin();
    //sort(hh.begin(),hh.end(),cmp_name);
     for(;it!=hh.end();it++){
         mysort(*it);
     }
    return 0;
}