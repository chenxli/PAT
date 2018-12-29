#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int m;
  int l;
  cin>>l;
  vector<int> s1(l+1);
  for(int i = 1; i<= l; i++)
  {
    cin>>s1[i];
  }
  cin>>m;
  vector<int> s2(m+1);
  for(int i = 1;i <= m; i++)
  {
    cin>>s2[i];
  }
  int arr[201][10001] = {0};
  int max = 0;
  for(int i = 1; i <= l; i++)
  {
    for(int j = 1; j <= m; j++)
    {
      max = arr[i-1][j-1];
      if(max < arr[i-1][j]) max = arr[i-1][j];
      if(max < arr[i][j-1]) max = arr[i][j-1];
      if(s1[i] == s2[j])
        arr[i][j] = max + 1;
      else arr[i][j] = max;
    }
  }
  cout<<arr[l][m]<<endl;
  return 0;
}
