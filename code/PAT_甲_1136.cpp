#include <iostream>
#include <string>
using namespace std;
string reverseStr(string s)
{
  string res;
  for(int i = s.size()-1; i >= 0; i--)
  {
    res += s[i];
  }
  return res;
}
string StrAdd(string a,string b)
{
  string res;
  int size = a.size();
  int p = 0;
  for(int i = size - 1; i >= 0; i--)
  {
    int num1 = static_cast<int>(a[i]-'0');
    int num2 = static_cast<int>(b[i]-'0');
    int t = (num1 + num2 + p) % 10;
    p = (num1 + num2 + p) / 10;
    res = static_cast<char>(t+'0') + res;
  }
  if(p)
    res = static_cast<char>(p+'0') + res;
  return res;
}
bool isPalindromic(string s)
{
  for(int i = 0; i <= s.size() / 2; i++)
  {
    if(s[i] != s[s.size()-1-i])
      return false;
  }
  return true;
}
int main()
{
  string s;
  cin>>s;
  bool flag = false;
  string res = s;
  if(isPalindromic(res))
    flag = true;
  for(int i = 0; !flag && i < 10; i++)
  {
    string s1 = reverseStr(s);
    res = StrAdd(s,s1);
    cout<<s<<" + "<<s1<<" = "<<res<<endl;
    if(isPalindromic(res))
    {
      flag = true;
      break;
    }
    s = res;
  }
  if(flag)
    cout<<res<<" is a palindromic number."<<endl;
  else
    cout<<"Not found in 10 iterations."<<endl;
  return 0;
}
