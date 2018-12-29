#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct nodes{
  int data;
  vector<int> child;
}Node[100010];
int n;
double p,r;
double res = 0;
double price;
void dfs(int start)
{
  if(Node[start].child.size() == 0)
  {
    res = res + Node[start].data * price;
    return;
  }
  for(int i = 0; i < Node[start].child.size(); i++)
  {
    int index = Node[start].child[i];
    price *=  (1 + r / 100.0);
    dfs(index);
    price /= (1 + r / 100.0);
  }
}
int main()
{
  scanf("%d %lf %lf",&n,&p,&r);
  for(int i = 0; i < n; i++)
  {
    int num;
    scanf("%d",&num);
    if(num == 0)
    {
      int amount;
      scanf("%d",&amount);
      Node[i].data = amount;
    }
    else
    {
      for(int j = 0; j < num; j++)
      {
        int id;
        scanf("%d",&id);
        Node[i].child.push_back(id);
      }
    }
  }
  price = p;
  dfs(0);
  printf("%.1lf\n",res);
  return 0;
}
