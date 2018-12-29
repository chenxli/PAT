#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct player
{
  int arrive,serve,wait,play,tag;
  player(int a,int s,int w,int p,int t):arrive(a),serve(s),wait(w),play(p),tag(t){}
  bool operator<(struct player b)
  {
    return arrive < b.arrive;
  }
};
struct table
{
  int empty_time;
  int id;
  bool operator<(struct table b)
  {
    return empty_time < b.empty_time;
  }
};
bool cmp(struct player a,struct player b)
{
  return a.arrive < b.arrive;
}
bool cmp1(struct player a,struct player b)
{
  if(a.serve == b.serve)
    return a.arrive < b.arrive;
  else
    return a.serve < b.serve;
}
bool cmp2(struct table a,struct table b)
{
  if(a.empty_time == b.empty_time)
    return a.id < b.id;
  else
    return a.empty_time < b.empty_time;
}
int main()
{
  int N;
  cin>>N;
  vector<player> v;
  for(int i = 0; i < N; i++)
  {
    int h,m,s,p,tag;
    scanf("%d:%d:%d%d%d",&h,&m,&s,&p,&tag);
    int second = h *3600 + m * 60 + s;
    if(p > 120)
     p = 120;
    v.push_back(player(second,0,0,p,tag));
  }
  int K,M;
  scanf("%d%d",&K,&M);
  vector<int> vip_t(K,0);
  vector<table> tb(K);
  vector<int> number(K,0);
  for(int i = 0; i < M; i++)
  {
    int a;
    cin>>a;
    vip_t[a - 1] = 1;
  }
  sort(v.begin(),v.end(),cmp);
  vector<bool> startplay(K,0);
  for(int i = 0; i < K && i < N; i++)
  {/*
      tb[i].empty_time = v[i].arrive + v[i].play * 60;
      tb[i].id = i;
      v[i].serve = v[i].arrive;
      v[i].wait = 0;
      if(v[i].serve < 21 * 3600)
        number[i]++;
        */
      int j;
      if(v[i].tag)
      {
        for(j = 0; j < K; j++)
        {
          if(vip_t[j] && !startplay[j])
          {
            tb[j].empty_time = v[i].arrive + v[i].play * 60;
            tb[j].id = j;
            v[i].serve = v[i].arrive;
            v[i].wait = 0;
            if(v[i].serve < 21 * 3600)
              number[j]++;
            startplay[j] = 1;
            break;
          }
        }
      }
      else if(v[i].tag == 0 || j == K)
      {
        for(j = 0; j < K; j++)
        {
          if(!startplay[j])
          {
            tb[j].empty_time = v[i].arrive + v[i].play * 60;
            tb[j].id = j;
            v[i].serve = v[i].arrive;
            v[i].wait = 0;
            if(v[i].serve < 21 * 3600)
              number[j]++;
            startplay[j] = 1;
            break;
          }
        }
      }
  }
  vector<bool> served(N,0);
  int i = K;
  while(i < N)
  {
    if(served[i] == 0)
    {
      sort(tb.begin(),tb.end(),cmp2);
      if(tb[0].empty_time <= v[i].arrive)
      {
        v[i].wait = 0;
        v[i].serve = v[i].arrive;
        tb[0].empty_time = v[i].arrive + v[i].play * 60;
        served[i] = 1;
        if(v[i].serve < 21 * 3600)
          number[tb[0].id]++;
      }
      else
      {
        if(vip_t[tb[0].id] == 0)
        {
          v[i].serve = tb[0].empty_time;
          v[i].wait = v[i].serve - v[i].arrive;
          served[i] = 1;
          tb[0].empty_time += v[i].play * 60;
          if(v[i].serve < 21 * 3600)
            number[tb[0].id]++;
        }
        else
        {
          bool flag = false;
          for(int j = i; j < N; j++)
          {
            if(v[j].tag == 1 && v[j].arrive <= tb[0].empty_time)
            {
              served[j] = 1;
              v[j].serve = tb[0].empty_time;
              v[j].wait = v[j].serve - v[j].arrive;
              tb[0].empty_time += v[j].play * 60;
              flag = true;
              if(v[j].serve < 21 * 3600)
                number[tb[0].id]++;
              break;
            }
          }
          if(!flag)
          {
            v[i].serve = tb[0].empty_time;
            v[i].wait = v[i].serve - v[i].arrive;
            served[i] = 1;
            tb[0].empty_time += v[i].play * 60;
            if(v[i].serve < 21 * 3600)
              number[tb[0].id]++;
          }
        }
      }
    }
    if(served[i] == 1)
     i++;
  }
  sort(v.begin(),v.end(),cmp1);
  for(int k = 0; k < N; k++)
  {
    if(v[k].serve >= 21 * 3600)
     break;
    else
    {
      int h1,m1,s1,h2,m2,s2,w;
      h1 = v[k].arrive / 3600;
      m1 = v[k].arrive % 3600 / 60;
      s1 = v[k].arrive % 3600 % 60;
      h2 = v[k].serve / 3600;
      m2 = v[k].serve % 3600 / 60;
      s2 = v[k].serve % 3600 % 60;
      w = v[k].wait / 60.0 + 0.5;
      printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",h1,m1,s1,h2,m2,s2,w);
    }
  }
  for(int k = 0; k < K; k++)
  {
    if(k == 0)
     cout<<number[k];
    else
      cout<<" "<<number[k];
  }
  return 0;
}
