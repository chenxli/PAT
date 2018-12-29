#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Card
{
  string id;
  int position;
  Card(string i,int p):id(i),position(p){}
  bool operator<(struct Card b)
  {
    return position <b.position;
  }
};
int main()
{
  int n;
  cin>>n;
  vector<Card> v;
  vector<int> adjustment;
  int p = 0;
  for(int i = 1; i <= 13; i++)
  {
    string id = "S";
    if(i < 10)
      id = id + static_cast<char>(i + '0');
    else
      id = id + '1' + static_cast<char>(i % 10 + '0');
    v.push_back(Card(id,p++));
  }
  for(int i = 1; i <= 13; i++)
  {
    string id = "H";
    if(i < 10)
      id = id + static_cast<char>(i + '0');
    else
      id = id + '1' + static_cast<char>(i % 10 + '0');
    v.push_back(Card(id,p++));
  }
  for(int i = 1; i <= 13; i++)
  {
    string id = "C";
    if(i < 10)
      id = id + static_cast<char>(i + '0');
    else
      id = id + '1' + static_cast<char>(i % 10 + '0');
    v.push_back(Card(id,p++));
  }
  for(int i = 1; i <= 13; i++)
  {
    string id = "D";
    if(i < 10)
      id = id + static_cast<char>(i + '0');
    else
      id = id + '1' + static_cast<char>(i % 10 + '0');
    v.push_back(Card(id,p++));
  }
  v.push_back(Card("J1",p++));
  v.push_back(Card("J2",p));
  for(int i = 0; i < 54; i++)
  {
    int a;
    cin>>a;
    adjustment.push_back(a - 1);
  }
  while(n--)
  {
    for(int i = 0; i < 54; i++)
    {
      v[i].position = adjustment[i];
    }
    sort(v.begin(),v.end());
  }
  for(int i = 0; i < 54; i++)
  {
    if(i == 0)
     cout<<v[i].id;
    else
     cout<<" "<<v[i].id;
  }
  cout<<endl;
  return 0;
}
