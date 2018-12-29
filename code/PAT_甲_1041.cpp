#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int> v(n);
  map<int,int> mp;
  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    v[i]=a;
    mp[a]++;
  }
  for(int i=0;i<n;i++)
  {
    if(mp[v[i]]==1)
    {
      cout<<v[i]<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
  return 0;
}
