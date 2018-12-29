#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
  string s1,s2;
  cin>>s1>>s2;
  vector<int> vis(s1.size(),0);
  int match = 0;
  for(int i = 0; i < s2.size(); i++)
  {
    for(int j = 0; j < s1.size(); j++)
    {
      if(s1[j] == s2[i] && vis[j] == 0)
      {
        vis[j] = 1;
        match++;
        break;
      }
    }
  }
  if(match == s2.size())
    cout<<"Yes "<<s1.size()-s2.size()<<endl;
  else
    cout<<"No "<<s2.size()-match<<endl;
  return 0;
}
