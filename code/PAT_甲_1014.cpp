#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

#define CUSTOM_MAX 1005
#define INF 0x6fffffff

int n; //number of widows<=20
int m; //queue capacity<=10
int k; //customs<=1000
int q; //query times <=1000

int ProcessTime[CUSTOM_MAX];
queue<int> que[25];
int LeaveTime[CUSTOM_MAX] = {0};
int Timebase[25] = {0};

int main()
{
  cin>>n>>m>>k>>q;
  for(int i=0;i<k;i++)
  {
    cin>>ProcessTime[i];
  }
  int index;
  int top=0;
  for(int i=0;top<m*n && top<k;top++)
  {
    que[i].push(top);
    LeaveTime[top] = Timebase[i]+ProcessTime[top];
    Timebase[i] = LeaveTime[top];
    i = (i+1)%n;
  }
  for(;top<k;top++)
  {
    int min_wait = INF;
    int found = false;
    for(int j=0;j<n;j++)
    {
      int cus = que[j].front();
      if(min_wait > LeaveTime[cus])
      {
        min_wait = LeaveTime[cus];
        index = j;
        found = true;
      }
    }
    que[index].pop();
    que[index].push(top);
    LeaveTime[top] = Timebase[index]+ProcessTime[top];
    Timebase[index] = LeaveTime[top];
  }
  while(q--)
  {
    int qq;
    cin>>qq;
    qq--;
    if(LeaveTime[qq] - ProcessTime[qq] >= 60*9)
    {
      printf("Sorry\n");
    }
    else
    {
      int hour = LeaveTime[qq] / 60 + 8;
      int minute = LeaveTime[qq] % 60;
      printf("%02d:%02d\n",hour,minute);
    }
  }
  return 0;
}
