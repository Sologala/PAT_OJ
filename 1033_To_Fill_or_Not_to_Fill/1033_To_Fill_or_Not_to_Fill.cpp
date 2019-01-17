#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Sta
{
    double dis;
    double price;
};
bool cmp(const Sta &a, const Sta &b)
{
    return a.dis < b.dis;
}
vector<Sta> S;
double Cmax;
double D, Davg;
int N;
double curGas = 0; //empty
int curStaidx = 0;

int main()
{
    scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &N);
    for (int i = 0; i < N; i++)
    {
        double p, d;
        scanf("%lf %lf", &p, &d);
        S.push_back(Sta{d, p});
    }
  
    sort(S.begin(), S.end(), cmp);
    if(S[0].dis!=0){
       printf("The maximum travel distance = 0.00\n");
       return 0;
    }
    else if(S[0].dis ==D){
      while(1);
    }
    double cost = 0;
    bool canNotReach = false;
    while (curStaidx < N - 1&&!canNotReach)
    {
        //寻找当前的油量能走到哪儿
        int Maxdis = S[curStaidx].dis + Cmax * Davg;
        int i = curStaidx;
        bool flag = false;
        while (i < N && S[i].dis <= Maxdis)
        {
            if (S[i].price < S[curStaidx].price)
            {
                flag = true; //find
                break;
            }
            i++;
        }
        
        if (flag)
        {
            double dis = S[i].dis - S[curStaidx].dis;
            double add = (((dis)*1.0 / Davg) - curGas) * S[curStaidx].price;
            cost += add;
            curStaidx = i; //移动到该站
            curGas = 0;
        }
        else
        {
            cost += ((Cmax - curGas) * 1.0) * S[curStaidx].price; //加满
            curGas = Cmax;
            double dis = S[i - 1].dis - S[curStaidx].dis;
            curGas -= (dis)*1.0 / Davg;
            if (i-1 == curStaidx)
            {   //当前加油站站加满也没有能到达的加油站站
                canNotReach = true;
            }
            curStaidx = i - 1; //移动到该站
        }
    }
    if (canNotReach)
    {
        double travelDis =S[curStaidx].dis;
        travelDis+=Cmax*Davg;
        printf("The maximum travel distance = %0.2lf\n", travelDis);
    }
    else
    {
        double dis =(D - S[curStaidx].dis);
        if(dis>Cmax * Davg){
            double travelDis =S[curStaidx].dis;
            travelDis+=Cmax*Davg;
            printf("The maximum travel distance = %0.2lf\n", travelDis);
        }
        else{
            cost += (( dis* 1.0 / Davg) - curGas) * S[curStaidx].price;
            printf("%0.2lf\n", cost);
        }
       
    }

    return 0;
}
