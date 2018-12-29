#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int> v;
  int time = n*5;
  v.push_back(0);
  for(int i=1;i<n+1;i++)
  {
    int a;
    cin>>a;
    v.push_back(a);
  }
  for(int i=1;i<n+1;i++)
  {
    if(v[i]-v[i-1]>0)
    time+=6*(v[i]-v[i-1]);
    else
    time+=4*(v[i-1]-v[i]);
  }
  cout<<time<<endl;
  return 0;
}
