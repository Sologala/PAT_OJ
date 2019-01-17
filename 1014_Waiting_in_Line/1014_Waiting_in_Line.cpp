    #include <vector>
    #include <iostream>
    #include <algorithm>
    using namespace std;
    #define MaxTime 540 // min
    int N, M, K, Q;
   
    struct people
    {
        int cost_time;
        int index;
    };

    class _Windows
    {
    public:
        _Windows()
        {
            f = r = 0;
            init(M + 1);
        }
        ~_Windows()
        {
        }

    public:
        int curtime;
        int index;
        int f, r;
        int len;
        people *queen;

    public:
        void init(int queenlen)
        {
            len = queenlen;
            queen = new people[queenlen];
        }
        int insert(int prce_time, int index)
        {
            if ((r + 1) % len == f)
            {
                return 0;
            }
            else
            {
                queen[r] = people{prce_time, index};
                r = (r + 1) % len; //???????enqueen 不会写了 ?
            }
            return 0;
        }
        people delQueen()
        {
            people ret;
            if (f != r)
            {
                ret = queen[f];
                f = (f + 1) % len;
                return ret;
            }
            else
            {
                ret = people{-1, -1};
            }
            return ret;
        }
        int getPeople()
        {
            return (r - f + len) % len;
        }
    };
    _Windows *choose(int temp){
        int min = 0;
        for (int i = 1; i < N; i++)
        {
            if (win[i].getPeople() < win[min].getPeople())
            {
                min = i;
            }
        }
        if (win[min].getPeople() != win[min].len - 1)
        {
            return &win[min];
        }
        else
        {
            return NULL;
        }
    }
    void out(int &out_cnt)
    {
        // updata time
        int min_time = 2 * MaxTime;
        vector <int> min_v;
        for (int j = 0; j < N; j++)
        {
            if (win[j].getPeople() != 0)
            {
                int temp_time = win[j].curtime + win[j].queen[win[j].f].cost_time;
                if (temp_time < min_time)
                {
                    min_time = temp_time;
                    min_v.clear();
                    min_v.push_back(j);
                }   
                else if(temp_time == min_time){
                    min_v.push_back(j);
                }
            }
        }
        for(int i= 0;i<min_v.size();i++){
            people out = win[min_v[i]].delQueen();
            if(win[min_v[i]].curtime>=MaxTime){
                sor[out.index] =false;
            }
            win[min_v[i]].curtime += out.cost_time;
            t[out.index] = win[min_v[i]].curtime;
            out_cnt++;
        }
    }
    //---------------
    bool *sor; //是否显示sorry
    int *t; //记录出队时间
    _Windows *win;//窗口类
    //-------------------
    int main(int argc, char const *argv[])
    {
        cin >> N >> M >> K >> Q;
        win = new _Windows[N];
        t = new int[K];
        sor = new bool[K];
        for (int i = 0; i < K; i++)
        {
            t[i] = 0;
        }
        for (int i = 0; i < N; i++)
        {
            win[i].index = i;
        }
        int out_cnt = 0;
        int read_cnt = 0;
        while (out_cnt < K)
        {
            //insert
            int temppeople = 0;
            _Windows *chos_window = NULL;
            if (read_cnt < K)
            {
                cin >> temppeople;
                while (!chos_window)
                {
                    chos_window = choose(temppeople);
                    if (chos_window) //~~~~~
                    {
                        chos_window->insert(temppeople, read_cnt);
                        sor[read_cnt] =true;
                    }
                    else
                    {
                        out(out_cnt);
                    }
                }
                read_cnt++;
            }
            else
            {
                out(out_cnt);
            }
        }
        for (int i = 0; i < Q; i++)
        {
            int quire;
            cin >> quire;
            if (sor[quire-1]==false)
            {
                printf("Sorry\n");
            }
            else
            {
                int h = t[quire - 1] / 60 + 8;
                int m = t[quire - 1] % 60;
                printf("%02d:%02d\n", h, m);
            }
        }
        return 0;
    }
