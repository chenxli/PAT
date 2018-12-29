#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
  string s1,s2;
  getline(cin,s1,'\n');
  getline(cin,s2,'\n');
  map<char,int> m;
  for(int i = 0; i < s1.size(); i++){
    m[s1[i]] = 1;
  }
  for(int j = 0; j < s2.size(); j++){
    m[s2[j]] = 0;
  }
  for(int i = 0; i < s1.size(); i++){
    if(m[s1[i]])
      cout<<s1[i];
  }
  cout<<endl;
  return 0;
}
