#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
string head;
int cnt,total;
map<string,int> weight;
map<string,bool> visited;
map<string,vector<string> > adjlist;
map<string,int> res;

void dfs(string start)
{
  visited[start] = 1;
  cnt++;
  total += weight[start];
  if(weight[start] > weight[head]) head = start;
  vector<string>::iterator it = adjlist[start].begin();

  for(;it != adjlist[start].end(); it++)
  {
    if(visited[*it] == 0)
     dfs(*it);
  }
}
int main()
{
  int N,K,T,i = 0;
  cin>>N>>K;
  string member1,member2;
  while(i < N)
  {
    cin>>member1>>member2>>T;
    weight[member1] += T;
    weight[member2] += T;
    adjlist[member1].push_back(member2);
    adjlist[member2].push_back(member1);
    visited[member1] = 0;
    visited[member2] = 0;
    i++;
  }

  map<string,bool>::iterator ite = visited.begin();
  for(;ite != visited.end(); ite++)
  {
    if(ite->second == 0)
    {
      total = 0;
      cnt = 0;
      head = ite->first;
      dfs(ite->first);
    }
    if(cnt > 2 && total / 2 > K)
      res[head] = cnt;
  }
  map<string,int>::iterator it = res.begin();
  cout<<res.size()<<endl;
  for(;it != res.end(); it++)
    cout<<it->first<<" "<<it->second<<endl;
  return 0;
}
