#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct info
{
  string name;
  int height;
};
bool cmp(info a,info b)
{
  if(a.height != b.height)
    return a.height > b.height;
  else
    return a.name < b.name;
}
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  vector<info> v;
  for(int i = 0; i < n; i++)
  {
    info temp;
    cin>>temp.name>>temp.height;
    v.push_back(temp);
  }
  sort(v.begin(),v.end(),cmp);
  vector<vector<info> > res;
  int j,end;
  for(int i = 0; i < k; i++)
  {
    if(i == 0)
    {
      int m = n / k + n % k;
      end = m;
      vector<info> vv(m+1);
      int mid = m / 2 + 1;
      vv[mid] = v[0];
      int tag = 0;
      int t = -1;
      for(j = 1; j < end; j++)
      {
        vv[mid+t] = v[j];
        if(!tag)
        {
          t = -t;
          tag = 1;
        }
        else
        {
          t = -t - 1;
          tag = 0;
        }
      }
      res.push_back(vv);
      // for(int l = 1; l < m + 1; l++)
      // {
      //   cout<<vv[l].name<<" ";
      // }
      // cout<<endl;
    }
    else
    {
      int m = n / k;
      int tag = 0;
      int t = -1;
      end = end + m;
      vector<info> vv(m+1);
      int mid = m / 2 + 1;
      vv[mid] = v[j++];
      for(; j < end; j++)
      {
        vv[mid+t] = v[j];
        if(!tag)
        {
          t = -t;
          tag = 1;
        }
        else
        {
          t = -t - 1;
          tag = 0;
        }
      }
      res.push_back(vv);
      // for(int l = 1; l < m + 1; l++)
      // {
      //   cout<<vv[l].name<<" ";
      // }
      // cout<<endl;
    }
  }
  for(int i = 0; i < res.size(); i++)
  {
    cout<<res[i][1].name;
    for(int x = 2; x < res[i].size(); x++)
    {
      cout<<" "<<res[i][x].name;
    }
    cout<<endl;
  }
  return 0;
}
