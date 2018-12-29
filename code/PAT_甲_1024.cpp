#include <iostream>
#include <string>
using namespace std;
int isPalindromic(string s)
{
  for(int i = 0; i < s.size() / 2; i++)
  {
    if(s[i] != s[s.size() - i - 1])
     return 0;
  }
  return 1;
}
int main()
{
  int k;
  string n;
  cin>>n>>k;
  int count = 0;
  while(true)
  {
    if(isPalindromic(n) || k == 0)
    {
      cout<<n<<endl;
      cout<<count<<endl;
      break;
    }
    else
    {
      string r;
      string m;
      for(int i = 0; i < n.size(); i++)
       r = n[i] + r;
      int mod = 0;
      for(int i = n.size() - 1; i >= 0; i--)
      {
        int a = ((n[i] - '0') + (r[i] - '0') + mod) % 10;
        mod = ((n[i] - '0') + (r[i] - '0') + mod) / 10;
        m = static_cast<char>(a + '0') + m;
      }
      if(mod)
       m = static_cast<char>(mod + '0') + m;
      n = m;
      count++;
      k--;
    }
  }
  return 0;
}
