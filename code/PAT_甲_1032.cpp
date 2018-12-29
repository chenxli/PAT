#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct node{
  char ch;
  int next;
};
int main() {
  int first,second;
  int n;
  cin>>first>>second>>n;
  string s1,s2;
  map<int,node> lst;
  map<int,int> existed;
  for(int i = 0; i < n; i++)
  {
    int a;
    node m;
    char ch;
    int next;
    scanf("%d %c %d",&a,&ch,&next);
    m.ch = ch;
    m.next = next;
    lst[a] = m;
  }
  while(first != -1)
  {
    existed[first] = 1;
    first = lst[first].next;
  }
  while(second != -1)
  {
    if(existed[second] == 1)
    {
      printf("%05d\n",second);
      return 0;
    }
    second = lst[second].next;
  }
  cout<<"-1"<<endl;
  return 0;
}
