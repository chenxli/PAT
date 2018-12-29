#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef struct
{
  double pos;
  double price;
}gasstation;
gasstation gasst[502];

bool cmp(gasstation a,gasstation b)
{
   return a.pos < b.pos;
}

int main()
{
  double Cmax,D,Davg;
  int N;
  scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
  int i;
  for(i = 0; i < N; i++)
    scanf("%lf%lf",&gasst[i].price,&gasst[i].pos);
  sort(gasst,gasst+N,cmp);
  if(D == 0)
  {
    printf("0.00\n");
    return 0;
  }
  if(gasst[0].pos != 0)
  {
    printf("The maximum travel distance = 0.00\n");
    return 0;
  }
  int curstnum = 0; //当前所处油站编号
  double curgas = 0; //当前油量
  double curcost = 0; //当前的花费
  bool flag = false; //是否到达目的地
  double maxrundis = Cmax * Davg; //油箱加满最远能到达的距离
  while(!flag)
  {
    bool tag = false; //最大距离内是否有加油站
    bool ifcheaper = false; //是否有便宜的
    double cheapestprice = 1000000; //找出最便宜的
    int cheapestnum; //没有更便宜的，找出最便宜的
    for(i = curstnum + 1; i < N; i++)
    {
      if((gasst[i].pos - gasst[curstnum].pos) <= maxrundis)
      {
        tag = true;
        if(gasst[i].price < gasst[curstnum].price)
        {
          ifcheaper = true;
          double dist = gasst[i].pos - gasst[curstnum].pos;
          double needgas = dist / Davg - curgas;
          curgas = 0;
          curcost += (needgas * gasst[curstnum].price);
          curstnum = i;
          break;
        }
        if(gasst[i].price < cheapestprice)
        {
          cheapestprice = gasst[i].price;
          cheapestnum = i;
        }
      }
      else
        break;
    }
    if(!ifcheaper && (maxrundis >= D - gasst[curstnum].pos))
    {
      double dist = D - gasst[curstnum].pos;
      double needgas = dist / Davg - curgas;
      curcost += needgas * gasst[curstnum].price;
      printf("%.2lf\n",curcost);
      return 0;
    }
    if(tag && !ifcheaper)
    {
      double needgas = Cmax - curgas;
      curcost += (needgas * gasst[curstnum].price);
      double dist = gasst[cheapestnum].pos - gasst[curstnum].pos;
      curgas = Cmax - dist / Davg;
      curstnum = cheapestnum;
    }
    else if(!tag)
    {
      printf("The maximum travel distance = %.2lf\n",gasst[curstnum].pos + maxrundis);
      return 0;
    }
  }
  return 0;
}
