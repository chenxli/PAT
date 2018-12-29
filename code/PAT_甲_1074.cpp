#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Node{
  int address;
  int data;
  int next;
};
Node arr[1000001];
Node v[1000001];
int main()
{
  int start_address,n,k;
  cin>>start_address>>n>>k;
  bool flag = false;
  for(int i = 0; i < n; i++)
  {
    int address,data,next;
    cin>>address>>data>>next;
    arr[address].address = address;
    arr[address].data = data;
    arr[address].next = next;
    if(address == start_address)
     flag = true;
  }
  if(flag)
  {
    int tmp = start_address;
    int t = 0;
    while(tmp != -1)
    {
      v[t++] = arr[tmp];
      tmp = arr[tmp].next;
    }
    for(int i = 0; i < t; i++)
    {
      for(int j = 1; j < k; j++,i++);
      if(i < t)
      {
        reverse(v+i-k+1,v+i+1);
      }
    }
    for(int i = 0; i < t; i++)
    {
      if(i < t - 1)
        printf("%05d %d %05d\n",v[i].address,v[i].data,v[i+1].address);
      else
        printf("%05d %d -1\n",v[i].address,v[i].data);
    }
  }
  else
  cout<<-1<<endl;
  return 0;
}
