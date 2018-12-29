#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct people{
    int second;
    int process_time;
    people(int s, int pro):second(s),process_time(pro){}
    bool operator<(struct people b)
    {
        if(second < b.second)
          return true;
        return false;
    }
};
struct Stime{
    int second;
    bool operator<(Stime b)
    {
       if(second < b.second)
          return true;
        return false;
    }
};
int main()
{
    int N,K,n = 0;
    cin>>N>>K;
    vector<people> que;
    vector<Stime> win_serve(K);
    int h,m,s;
    int pro;
    double tot_wait_time = 0;
    for(int i = 0; i < N; i++)
    {
        scanf("%d:%d:%d %d",&h,&m,&s,&pro);
        int second = h * 3600 + m * 60 + s;
        if(second <= 17 * 3600)
        {
          que.push_back(people(second,pro));
          n++;
        }
    }
    sort(que.begin(),que.end());
    for(int i = 0; i < min(K,n); i++) //考虑人少的情况
    {
        if(que[i].second < 8 * 3600)
        {
           win_serve[i].second = 8 * 3600 + que[i].process_time * 60;
           tot_wait_time += 8 * 3600 - que[i].second;
        }
        else
        {
           win_serve[i].second = que[i].second + que[i].process_time * 60;
        }
    }
    for(int i = K; i < n; i++) //是n,不是N
    {
        sort(win_serve.begin(),win_serve.end());
        if(win_serve[0].second >= que[i].second)
        {
            tot_wait_time += win_serve[0].second - que[i].second;
            win_serve[0].second += que[i].process_time * 60;
        }
        else
            win_serve[0].second = que[i].second + que[i].process_time * 60;
    }
    printf("%.1lf\n",tot_wait_time * 1.0 / (60 * n));
    return 0;
}
