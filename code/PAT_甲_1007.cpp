#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n;
  bool flag = false;
  cin>>n;
  vector<int> v;
  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    if(a>=0)
     flag=true;
    //v[i]=a;//为什么不可以
    v.push_back(a);//???
  }
  if(!flag)
  {
    cout<<0<<" "<<v[0]<<" "<<v[n-1]<<endl;
    return 0;
  }
//  vector<vector<int> > arr(n,vector<int>(n,0));内存不够
  int i,j,start,end,max=-100000;
  for(i=0;i<n;i++)
  {
    int sum =0;
    for(j=i;j<n;j++)
    {
      if(i==j)
        sum=v[i];
      else
       sum=sum+v[j];
      if(sum>max)
       {
         max=sum;
         start = i;
         end = j;
       }
    }
  }
  cout<<max<<" "<<v[start]<<" "<<v[end]<<endl;
  return 0;
}
