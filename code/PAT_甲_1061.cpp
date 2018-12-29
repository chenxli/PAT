#include <iostream>
#include <string>
using namespace std;
int main()
{
  string day[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
  string s1,s2,s3,s4;
  cin>>s1>>s2>>s3>>s4;
  int count = 0;
  int tmp = 0;
  for(int i = 0, j = 0; i < s1.size() && j < s2.size() && count < 2; i++, j++)
  {
      if(s1[i] == s2[j] && s1[i] >= 'A' && s1[i] <= 'G' && count == 0)
      {
        cout<<day[s1[i]-'A']<<" ";
        count++;
        continue;
      }
      if(s1[i] == s2[j] && count == 1)
      {
        if(s1[i] >= '0' && s1[i] <= '9')
        {
          cout<<"0"<<s1[i]<<":";
          count++;
          break;
        }
        else if(s1[i] >= 'A' && s1[i] <= 'N')
        {
          cout<<static_cast<int>(s1[i] - 'A') + 10<<":";
          count++;
          break;
        }
      }
  }
  for(int i = 0; i < min(s3.size(),s4.size()); i++)
  {
    if(s3[i] == s4[i] && (s3[i] >= 'a' && s4[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))
    {
      if(i < 10)
        cout<<"0"<<i<<endl;
      else
        cout<<i<<endl;
    }
  }
  return 0;
}
