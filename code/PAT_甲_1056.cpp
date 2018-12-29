#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int np,ng;
  cin>>np>>ng;
  vector<int> weight,order,rank;
  weight.resize(np);
  order.resize(np);
  rank.resize(np);
  for(int i = 0; i < np; i++)
     cin>>weight[i];
  for(int i = 0; i < np; i++)
     cin>>order[i];
  int curRank = 0;
  while(order.size() > 1)
  {
    curRank = order.size()/ng + 1;
    if(order.size() % ng > 0)
      ++curRank;
    vector<int> next;
    next.clear();
    int n = 0;
    while(n < order.size())
    {
      int max = -1,index = 0;
      for(int i = 0; i < ng && n < order.size(); i++,n++)
      {
        rank[order[n]] = curRank;
        if(weight[order[n]] > max)
        {
          max = weight[order[n]];
          index = order[n];
        }
      }
      next.push_back(index);
    }
    order = next;
  }
  rank[order[0]] = 1;
  cout<<rank[0];
  for(int i = 1; i < np; i++)
     cout<<" "<<rank[i];
  cout<<endl;
  return 0;
}
