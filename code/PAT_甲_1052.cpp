#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct node
{
  int address,key,next;
  //struct node(int a,int k,int n):address(a),key(k),next(n){}
  bool operator<(struct node b)
  {
    return key < b.key;
  }
};
node arr[100005];
int main()
{
  int n,start;
  scanf("%d%d",&n,&start);
  vector<struct node> v;
  map<int,struct node> arr;
  for(int k = 0; k < n; k++)
  {
     struct node tmp;
     scanf("%d%d%d",&tmp.address,&tmp.key,&tmp.next);//如果一开始就输入-1
      arr[tmp.address] = tmp;
  }
  int p = start;
  while(p!=-1)
  {
    v.push_back(arr[p]);
    p = arr[p].next;
  }
  if(v.empty())
  {
    if(start == -1)
     printf("0 -1\n");
    else
     printf("0 %05d\n",start);
    return 0;
  }
    sort(v.begin(),v.end());
    printf("%d %05d\n",v.size(),v[0].address);
    int i;
    for(i = 0; i < v.size() - 1; i++)
    {
      printf("%05d %d %05d\n",v[i].address,v[i].key,v[i+1].address);
    }
    printf("%05d %d -1\n",v[i].address,v[i].key);
  return 0;
}
