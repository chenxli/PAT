#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
struct cake
{
  double weight;
  double money;
  double price;
  cake(double w,double m)
  {
    weight = w;
    money = m;
    price = 1.0*money/weight;
  }
};
bool cmp(cake a,cake b)
{
  return a.price > b.price;
}
int main()
{
  int n;
  double m;
  cin>>n>>m;
  vector<cake> v;
  for(int i = 0; i < n; i++)
  {
    double a;
    cin>>a;
    v.push_back(cake(a,0));
  }
  for(int i = 0; i < n; i++)
  {
    double p;
    cin>>p;
    v[i].money = p;
    v[i].price = v[i].money*1.0/v[i].weight;
  }
  sort(v.begin(),v.end(),cmp);
  double maxProfit = 0;
  for(int i = 0; i < n && m > 0; i++)
  {
    if(v[i].weight < m)
    {
      maxProfit += v[i].money;
      m = m - v[i].weight;
    }
    else
    {
      maxProfit += m * v[i].price;
      m = 0;
    }
  }
  printf("%.2lf\n",maxProfit);
  return 0;
}
