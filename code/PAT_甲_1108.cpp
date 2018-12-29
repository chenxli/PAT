#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
double str2double(string s)
{
  double res = 0;
  bool flag = false;
  bool point = false;
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] == '-')
    {
      flag = true;
      continue;
    }
    if(s[i] == '.')
    {
      point = true;
      continue;
    }
    if(!point)
    {
      res = res * 10 + static_cast<int>(s[i]-'0');
    }
    else
    {
      int index = s.find('.');
      res = res + static_cast<int>(s[i]-'0') * pow(0.1,i-index);
    }
  }
  if(flag)
   res = -1 * res;
  return res;
}
int main()
{
  int n;
  scanf("%d",&n);
  double sum = 0;
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    string num;
    cin >> num;
    bool legal = true;
    int point = 0;
    for(int j = 0; j < num.size(); j++)
    {
      if((num[j] >= 'a' && num[j] <= 'z') || (num[j] >= 'A' && num[j] <= 'Z'))
      {
        cout<<"ERROR: "<<num<<" is not a legal number"<<endl;
        legal = false;
        break;
      }
      if(num[j] == '.')
        point++;
      if(point > 1)
      {
        cout<<"ERROR: "<<num<<" is not a legal number"<<endl;
        legal = false;
        break;
      }
    }
    if(legal)
    {
      int index = num.find('.');
      if(index != -1 && num.size() - index - 1 > 2)
      {
        legal = false;
        cout<<"ERROR: "<<num<<" is not a legal number"<<endl;
      }
    }
    if(legal)
    {
      double number = str2double(num);
      if(number > 1000 || number < -1000)
      {
        legal = false;
        cout<<"ERROR: "<<num<<" is not a legal number"<<endl;
      }
      if(legal)
      {
        sum += number;
        count++;
      }
    }
  }
  if(count > 1)
    printf("The average of %d numbers is %.2lf\n",count,sum / count);
  else if(count == 0)
    printf("The average of 0 numbers is Undefined\n");
  else if(count == 1)
    printf("The average of 1 number is %.2lf\n",sum);
  return 0;
}
