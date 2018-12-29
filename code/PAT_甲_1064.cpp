#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001];
int n;
int pos = 0;
vector<int> v;
void buildBST(int m)
{
  if(m > n) return;
  buildBST(2*m);
  a[m] = v[pos++];
  buildBST(2*m+1);
}
int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    int a;
    cin>>a;
    v.push_back(a);
  }
  sort(v.begin(),v.end());
  buildBST(1);
  for(int i = 1; i <= n; i++)
  {
    if(i == 1)
      cout<<a[i];
    else
      cout<<" "<<a[i];
  }
  cout<<endl;
  return 0;
}
