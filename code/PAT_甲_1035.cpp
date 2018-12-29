#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
struct user
{
  string name;
  string pwd;
  user(string name,string pwd):name(name),pwd(pwd){}
};
int main()
{
  int n;
  cin>>n;
  vector<user> v;
  for(int i = 0; i < n; i++)
  {
    string name,pwd;
    cin>>name>>pwd;
    bool haschanged = false;
    for(int j = 0; j < pwd.size(); j++)
    {
      if(pwd[j] == '1')
        {
          pwd[j] = '@';
          haschanged = true;
        }
      else if(pwd[j] == 'l')
        {
          pwd[j] = 'L';
          haschanged = true;
        }
      else if(pwd[j] == '0')
        {
          pwd[j] = '%';
          haschanged = true;
        }
      else if(pwd[j] == 'O')
        {
          pwd[j] = 'o';
          haschanged = true;
        }
    }
    if(haschanged)
        v.push_back(user(name,pwd));
  }
  if(v.size() == 0)
  {
    if(n == 1)
      cout<<"There is 1 account and no account is modified"<<endl;
    else
      cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
  }
  else
    cout<<v.size()<<endl;
  for(int i = 0; i < v.size(); i++)
  {
    cout<<v[i].name<<" "<<v[i].pwd<<endl;
  }
  return 0;
}
