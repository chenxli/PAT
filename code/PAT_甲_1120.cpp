#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int friendId(int n)
{
  int sum=0;
  while(n!=0)
  {
    sum+=n%10;
    n/=10;
  }
  return sum;
}
int main()
{
  int n;
  cin>>n;
  vector<int> friendID;
  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    friendID.push_back(friendId(a));
  }
  sort(friendID.begin(),friendID.end());
  vector<int> v;
  v.push_back(friendID[0]);
  for(int i=1;i<friendID.size();i++)
  {
    if(friendID[i]!=friendID[i-1])
    v.push_back(friendID[i]);
  }
//  v.push_back(friendID[0]);
  cout<<v.size()<<endl<<v[0];
  for(int i=1;i<v.size();i++)
  {
    cout<<" "<<v[i];
  }
  return 0;
}
