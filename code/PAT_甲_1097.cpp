#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
  int val;
  int next;
  int address;
};
node res[100100];
int main()
{
  int start,k;
  vector<node> v1,v2;
  set<int> ss;
  scanf("%d%d",&start,&k);
  int address,value,next;
  for(int i = 0; i < k; i++)
  {
    scanf("%d%d%d",&address,&value,&next);
    res[address].val = value;
    res[address].next = next;
    res[address].address = address;
  }
  int nextNode = start;
  while(nextNode != -1)
  {
    int num = abs(res[nextNode].val);
    if(ss.count(num) != 0)
    {
      v2.push_back(res[nextNode]);
    }
    else
    {
      ss.insert(num);
      v1.push_back(res[nextNode]);
    }
    nextNode = res[nextNode].next;
  }
  for(int i = 0; i < v1.size() - 1; i++)
  {
    printf("%05d %d %05d\n",v1[i].address,v1[i].val,v1[i+1].address);
  }
  if(v1.size() > 0)
     printf("%05d %d %d\n",v1[v1.size()-1].address,v1[v1.size()-1].val,-1);
  for(int i = 0; i < v2.size()-1; i++)
  {
    printf("%05d %d %05d\n",v2[i].address,v2[i].val,v2[i+1].address);
  }
  if(v2.size() > 0)
    printf("%05d %d %d\n",v2[v2.size()-1].address,v2[v2.size()-1].val,-1);
  return 0;
}
