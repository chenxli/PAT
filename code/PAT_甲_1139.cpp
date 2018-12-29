#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<int,vector<int>> v;//同性好友
map<int,vector<int>> arr;//全部好友
struct people
{
  int x,y;
  people(int x,int y):x(x),y(y){}
};
void search(vector<people> &ans, int a,int b)
{
  for(int i = 0; i < v[a].size(); i++)//a的同性好友
  {
    for(int j = 0; j < v[b].size(); j++)//b的同性好友
    {
      if(v[a][i] == b || v[b][j] == a || v[a][i] == v[b][j]) continue;
      if(find(arr[v[a][i]].begin(),arr[v[a][i]].end(),v[b][j]) != arr[v[a][i]].end())
        ans.push_back(people(v[a][i],v[b][j]));
    }
  }
}
bool cmp(people a,people b)
{
  if(a.x != b.x)
    return a.x < b.x;
  else
    return a.y < b.y;
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 0; i < m; i++)
  {
    string a,b;
    cin>>a>>b;
    if(a.size() == b.size())//same gender
    {
      v[abs(stoi(a))].push_back(abs(stoi(b)));
      v[abs(stoi(b))].push_back(abs(stoi(a)));
    }
    arr[abs(stoi(a))].push_back(abs(stoi(b)));
    arr[abs(stoi(b))].push_back(abs(stoi(a)));
  }
  int k;
  cin>>k;
  while(k--)
  {
    int a,b;
    cin>>a>>b;
    vector<people> ans;
    search(ans,abs(a),abs(b));
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end(),cmp);
    for(auto w:ans)
    {
      printf("%04d %04d\n",w.x,w.y);
    }
  }
  return 0;
}
