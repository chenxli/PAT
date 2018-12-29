#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
  string s;
  cin>>s;
  long long sum = 0;
  for(int i=0;i<s.size();i++)
  {
    sum+=s[i]-'0';
  }
  string  res[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
  vector<string> v;
  if(sum==0)
  {
    cout<<"zero"<<endl;
    return 0;
  }
  while(sum!=0)
  {
    v.push_back(res[sum%10]);
    sum/=10;
  }
  int cnt=0;
  for(int i=v.size()-1;i>=0;i--)
  {
    cnt++;
    if(cnt==v.size())
    cout<<v[i]<<endl;
    else
    cout<<v[i]<<" ";
  }
  return 0;
}
