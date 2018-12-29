#include<iostream>
//#include<cstdio>
#include<iomanip>
using namespace std;
struct p
{
  int m;
  double a;
};
int main()
{
  double mi[2001]={0};
//  int n=2;
  int k1,k2;
  cin>>k1;
  struct p *p1=new struct p [k1];
  for(int i=0;i<k1;i++)
  {
    int x;
    double y;
    cin>>x>>y;
    p1[i].m=x;
    p1[i].a=y;
  }
  cin>>k2;
  struct p* p2 = new struct p [k2];
  for(int i=0;i<k2;i++)
  {
    int x;
    double y;
    cin>>x>>y;
    p2[i].m=x;
    p2[i].a = y;
  }
  int count=0;
  for(int i=0;i<k1;i++)
  {
    for(int j=0;j<k2;j++)
    {
      int l=p1[i].m+p2[j].m;
      double r=p1[i].a*p2[j].a;
      mi[l] += r;
    }
  }
  for(int i=0;i<2001;i++)
  {
    if(mi[i]!=0)
    count++;
  }
  cout<<count;
  for(int i=2000;i>=0;i--)
  {
    if(mi[i]!=0)
    cout<<" "<<i<<" "<<fixed<<setprecision(1)<<mi[i];
  }
//  system("pause");
  return 0;
}
