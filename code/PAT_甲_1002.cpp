#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  float mi[1001] ={0};
  int a;
  cin>>a;
  for(int i=0;i<a;i++)
  {
    int m;
    double x;
    cin>>m>>x;
    mi[m]+=x;
  }
  int b;
  cin>>b;
  for(int i=0;i<b;i++)
  {
    int n;
    double y;
    cin>>n>>y;
    mi[n]+=y;
  }
  int count=0;
  for(int i=0;i<1001;i++)
  {
    if(mi[i]!=0)
    count++;
  }
  cout<<count;
  for(int i=1001;i>=0;i--)
  {
    if(mi[i]!=0)
    cout<<" "<<i<<" "<<fixed<<setprecision(1)<<mi[i];
  }
  return 0;
}
