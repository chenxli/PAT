#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
  string mars[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
  string higher[12] = {"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
  int n;
  scanf("%d",&n);
  getchar();
  for(int i = 0 ; i < n; i++)
  {
    string s;
    getline(cin,s);
    if(s[0] >= '0' && s[0] <= '9')
    {
      int num = 0;
      for(int j = 0; j < s.size(); j++)
      {
        num = num * 10 + s[j] - '0';
      }
      int a = num / 13;
      int b = num % 13;
      if(a == 0)
         cout<<mars[b]<<endl;
      else if(b != 0)
         cout<<higher[a-1]<<" "<<mars[b]<<endl;
      else if(b == 0)
        cout<<higher[a-1]<<endl;
    }
    else
    {
      string a,b;
      int res = 0;
      a = s.substr(0,3);
      if(s.size() > 3)
      {
        b = s.substr(4,3);
        for(int j = 0; j < 12; j++)
        {
          if(higher[j] == a)
          {
            res = 13 * (j+1);
            break;
          }
        }
        for(int j = 0; j < 13; j++)
        {
          if(mars[j] == b)
          {
            res += j;
            break;
          }
        }
        cout<<res<<endl;
      }
      else
      {
        for(int j = 0; j < 13; j++)
          if(mars[j] == a)
          {
            res = j;
            break;
          }
        if(res == 0)
        {
          for(int j = 0; j < 12; j++)
          {
            if(higher[j] == a)
            {
              cout<< 13 * (j+1)<<endl;
              break;
            }
          }
        }
        else
          cout<<res<<endl;
      }
    }
  }
  return 0;
}
