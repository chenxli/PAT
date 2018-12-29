#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string dec2radx(int x){
 string res;
 if(x / 13 < 10)
  res += static_cast<char>(x / 13 + '0');
  else
  res += static_cast<char>(x / 13 - 10 + 'A');
  if(x % 13 < 10)
  res += static_cast<char>(x % 13 + '0');
  else
  res += static_cast<char>(x % 13 - 10 + 'A');
  return res;
}
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  cout<<"#"<<dec2radx(a)<<dec2radx(b)<<dec2radx(c)<<endl;
  return 0;
}
