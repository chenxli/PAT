#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin>>n;
  for(int k = 1; k <= n; k++)
  {
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3;
    vector<int> a,b;
    for(int i =s1.size()-1; i >= 0; i--)
      a.push_back(s1[i]-'0');
    for(int i = s2.size()-1; i >= 0; i--)
      b.push_back(s2[i]-'0');
    vector<int> c;
    int rest = 0;
    int i;
    for(i = 0; i < min(a.size(),b.size()); i++)
    {
      c.push_back((a[i]+b[i]+rest)%10);
      rest = (a[i]+b[i]+rest)/10;
    }
    for(; i < a.size(); i++)
    {
      c.push_back((a[i]+rest)%10);
      rest = (a[i]+rest)/10;
    }
    for(; i < b.size(); i++)
    {
      c.push_back((b[i]+rest)%10);
      rest = (b[i]+rest)/10;
    }
    if(rest != 0)
      c.push_back(rest);
    for(int j = c.size()-1; j >= 0; j--)
      s4 += static_cast<char>(c[j]+'0');
    while(s4.size() > s3.size()) s3 = '0' + s3;
    while(s3.size() > s4.size()) s4 = '0' + s4;
    if(s4 > s3)
      cout<<"Case #"<<k<<": true"<<endl;
    else
      cout<<"Case #"<<k<<": false"<<endl;
  }
  return 0;
}
