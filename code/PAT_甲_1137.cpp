#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
struct stu
{
  char id[25];
  int gp,gmid,gfinal,g;
}a[10001];
bool cmp(struct stu a,struct stu b)
{
  if(a.g != b.g)
    return a.g > b.g;
  else
    return strcmp(a.id,b.id) < 0;
}
int main()
{
  int n,m,k;
  int num = 0;
  scanf("%d%d%d",&n,&m,&k);
  map<string,int> id2index;
  for(int i = 0; i < n; i++)
  {
    char name[25];
    int score;
    scanf("%s %d",name,&score);
    if(score >= 200)
    {
      strcpy(a[num].id,name);
      id2index[name] = num;
      a[num].gmid = -1;
      a[num].gp = score;
      num++;
    }
  }
  for(int i = 0; i < m; i++)
  {
    char name[25];
    int score;
    scanf("%s %d",name,&score);
    if(id2index.find(name) != id2index.end())
    {
       a[id2index[name]].gmid = score;
    }
  }
  for(int i = 0; i < k; i++)
  {
    char name[25];
    int score;
    scanf("%s %d",name,&score);
    if(id2index.find(name) != id2index.end())
    {
      int index = id2index[name];
      a[index].gfinal = score;
      if(a[index].gmid < a[index].gfinal)
        a[index].g = a[index].gfinal;
      else
        a[index].g = 0.4 * a[index].gmid + 0.6 * a[index].gfinal + 0.5;
    }
  }
  sort(a,a+num,cmp);
  for(int i = 0; i < num; i++)
  {
    if(a[i].g < 60)
       break;
    else
      printf("%s %d %d %d %d\n",a[i].id,a[i].gp,a[i].gmid,a[i].gfinal,a[i].g);
  }
  return 0;
}
