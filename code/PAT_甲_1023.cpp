#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
  string num;
  vector<int> v;
  vector<int> v1;
  stack<int> s;
  cin>>num;
  for(int i = 0; i < num.size(); i++)
  {
    v.push_back(num[i] - '0');
  }
  int mod = 0;
  for(int i = v.size() - 1; i >= 0; i--)
  {
    s.push((v[i] * 2 + mod) % 10);
    mod = (v[i] * 2 + mod) / 10;
  }
  if(mod != 0)
   s.push(mod);
  string res;
  while(!s.empty())
  {
    res = res + static_cast<char>(s.top() + '0');
    v1.push_back(s.top());
    s.pop();
  }
  sort(v.begin(),v.end());
  sort(v1.begin(),v1.end());
  bool flag = true;
  if(v.size() != v1.size())
   flag = false;
  for(int i = 0; i < v.size(); i++)
    if(v[i] != v1[i])
    {
      flag = false;
      break;
    }
  if(flag)
   cout<<"Yes"<<endl;
  else
   cout<<"No"<<endl;
  cout<<res<<endl;
  return 0;
}
