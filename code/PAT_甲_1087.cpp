#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int happy[201];
int dist[205][205];
map<string,int> city_id;
int vis[205];
int tot_dist = 1000000;
int now_dist = 0;
int tot_happy = 0;
int now_happy = 0;
int average_happy = 0;
vector<int> solution;
vector<int> temp;
int n,m;
int counts = 0;
void dfs(int start)
{
  if(start == city_id["ROM"])
  {
    if(tot_dist > now_dist)
    {
      counts = 1;
      tot_dist = now_dist;
      solution = temp;
      tot_happy = now_happy;
      average_happy = tot_happy / temp.size();
    }
    else if(tot_dist == now_dist)
    {
      counts++;
      if(now_happy > tot_happy)
      {
        solution = temp;
        tot_happy = now_happy;
        average_happy = tot_happy / temp.size();
      }
      else if(now_happy == tot_happy)
      {
        if(average_happy < tot_happy / temp.size())
        {
          average_happy = tot_happy / temp.size();
          solution = temp;
        }
      }
    }
    return;
  }
  for(int i = 0; i < n; i++)
  {
    if(dist[start][i] && vis[i] == 0)
    {
      now_dist += dist[start][i];
      now_happy += happy[i];
      vis[i] = 1;
      temp.push_back(i);
      dfs(i);
      now_dist -= dist[start][i];
      now_happy -= happy[i];
      vis[i] = 0;
      temp.pop_back();
    }
  }
}
int main()
{
  scanf("%d %d",&n,&m);
  string start_city;
  cin>>start_city;
  city_id[start_city] = 0;
  vector<string> cities;
  cities.push_back(start_city);
  for(int i = 1; i < n; i++)
  {
    string city;
    int happiness;
    cin>>city>>happiness;
    city_id[city] = i;
    cities.push_back(city);
    happy[i] = happiness;
  }
  for(int i = 0; i < m; i++)
  {
    string city1,city2;
    int dis;
    cin>>city1>>city2>>dis;
    dist[city_id[city1]][city_id[city2]] = dist[city_id[city2]][city_id[city1]] = dis;
  }
  vis[0] = 1;
  dfs(0);
  cout<<counts<<" "<<tot_dist<<" "<<tot_happy<<" "<<average_happy<<endl;
  cout<<start_city;
  for(int i = 0; i < solution.size(); i++)
  {
    cout<<"->"<<cities[solution[i]];
  }
  cout<<endl;
  return 0;
}
