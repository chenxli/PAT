#include <cstdio>
using namespace std;
struct node
{
  int address,data,next;
};
struct node arr[100001];
int main()
{
  int firstAdd,n,k;
  scanf("%d%d%d",&firstAdd,&n,&k);
  for(int i = 0; i < n; i++)
  {
    int address,data,next;
    scanf("%d%d%d",&address,&data,&next);
    arr[address].address = address;
    arr[address].data = data;
    arr[address].next = next;
  }
  int nextAdd = firstAdd;
  int pre = -1;
  while(nextAdd != -1)
  {
    if(arr[nextAdd].data < 0)
    {
      if(pre == -1)
        printf("%05d %d",nextAdd,arr[nextAdd].data);
      else
        printf(" %05d\n%05d %d",nextAdd,nextAdd,arr[nextAdd].data);
      pre = nextAdd;
    }
    nextAdd = arr[nextAdd].next;
  }
  nextAdd = firstAdd;
  while(nextAdd != -1)
  {
    if(arr[nextAdd].data <= k && arr[nextAdd].data >= 0)
    {
      if(pre != -1)
        printf(" %05d\n%05d %d",nextAdd,nextAdd,arr[nextAdd].data);
      else
        printf("%05d %d",nextAdd,arr[nextAdd].data);
      pre = nextAdd;
    }
    nextAdd = arr[nextAdd].next;
  }
  nextAdd = firstAdd;
  while(nextAdd != -1)
  {
    if(arr[nextAdd].data > k)
    {
      if(pre == -1)
        printf("%05d %d",nextAdd,arr[nextAdd].data);
      else
        printf(" %05d\n%05d %d",nextAdd,nextAdd,arr[nextAdd].data);
      pre = nextAdd;
    }
    nextAdd = arr[nextAdd].next;
  }
  printf(" -1\n");
  return 0;
}
