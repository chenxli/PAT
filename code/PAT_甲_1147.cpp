#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> arr(1001,0);
vector<int> res;
int n,m;
bool isMinHeap()
{
  for(int i = 1; i <= m/2; i++)
  {
    if(2*i <= m )
    {
      if(arr[2*i] < arr[i])
        return false;
    }
    if(2*i+1 <= m)
    {
      if(arr[2*i+1] < arr[i])
        return false;
    }
  }
  return true;
}
bool isMaxHeap()
{
  for(int i = 1; i <= m/2; i++)
  {
    if(2 * i <= m)
    {
      if(arr[2*i] > arr[i])
        return false;
    }
    if(2 * i + 1 <= m)
    {
      if(arr[2*i+1] > arr[i])
        return false;
    }
  }
  return true;
}
void postorder(int i)
{
  if(i <= m)
  {
    postorder(2*i);
    postorder(2*i+1);
    res.push_back(arr[i]);
  }
}
int main()
{
  scanf("%d%d",&n,&m);
  while(n--)
  {
    for(int i = 1; i <= m; i++)
    {
      scanf("%d",&arr[i]);
    }
    if(isMaxHeap())
      printf("Max Heap\n");
    else if(isMinHeap())
      printf("Min Heap\n");
    else
      printf("Not Heap\n");
    res.clear();
    postorder(1);
    for(int j = 0; j < res.size()-1; j++)
    {
      printf("%d ",res[j]);
    }
    printf("%d\n",res[res.size()-1]);
  }
  return 0;
}
