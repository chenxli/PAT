#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  vector<int> p(s.size(),0);
  int tot = 0;
  vector<int> t(s.size() + 1,0);
  for(int i = s.size() - 1; i >= 0; i--)
  {
    if(s[i] == 'T')
      t[i] = t[i+1] + 1;
    else
      t[i] = t[i+1];
  }
  for(int i = 0; i < s.size(); i++)
  {
    if(s[0] == 'P')
      p[0] = 1;
    if(s[i] == 'P' && i > 0)
      p[i] = p[i-1] + 1;
    else if(s[i] != 'P' && i > 0)
      p[i] = p[i-1];
    if(s[i] == 'A')
    {
      tot = (tot + t[i] * p[i]) % 1000000007;
    }
  }
  cout<<tot%1000000007<<endl;
  return 0;
}
