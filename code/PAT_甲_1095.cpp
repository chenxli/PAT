#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
struct node
{
  char plate_number[10];
  int time;
  char status[5];
};
bool cmp(struct node a,struct node b)
{
  if(strcmp(a.plate_number,b.plate_number) != 0)
     return strcmp(a.plate_number,b.plate_number) < 0;
  else return a.time < b.time;
}
bool cmp1(struct node a,struct node b)
{
  return a.time < b.time;
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<node> v;
  vector<node> tmp;
  for(int i = 0; i < n; i++)
  {
    char s[10];
    int hh,mm,ss;
    char sta[5];
    scanf("%s %d:%d:%d %s",s,&hh,&mm,&ss,sta);
    node temp;
    strcpy(temp.plate_number,s);
    temp.time = hh * 3600 + 60 * mm + ss;
    strcpy(temp.status,sta);
    v.push_back(temp);
  }
  sort(v.begin(),v.end(),cmp);
  map<string,int> parktime;
  int maxtime = 0;
  for(int i = 0; i < v.size() - 1; i++)
  {
    if(strcmp(v[i].plate_number,v[i+1].plate_number) == 0 && strcmp(v[i].status,"in") == 0 && strcmp(v[i+1].status,"out") == 0)
    {
        tmp.push_back(v[i]);
        tmp.push_back(v[i+1]);
        parktime[v[i].plate_number] += v[i+1].time - v[i].time;
        maxtime = max(maxtime,parktime[v[i].plate_number]);
    }
  }
  sort(tmp.begin(),tmp.end(),cmp1);
  int count = 0;
  int now = 0;
  for(int i = 0; i < m; i++)
  {
    int hh,mm,ss;
    scanf("%d:%d:%d",&hh,&mm,&ss);
    while(now < tmp.size() && tmp[now].time <= 3600*hh + 60*mm + ss)
    {
      if(strcmp(tmp[now].status,"in") == 0)
      {
        count++;
      }
      else if(strcmp(tmp[now].status,"out") == 0)
        count--;
      now++;
    }
    printf("%d\n",count);
  }
  map<string,int>::iterator it = parktime.begin();
  for(; it != parktime.end(); it++)
  {
    if(it->second == maxtime)
      printf("%s ",it->first.c_str());
  }
  printf("%02d:%02d:%02d\n",maxtime/3600,maxtime%3600/60,maxtime%60);
  return 0;
}
