#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

typedef struct
{
  char res;
  float  pro;
}Bet;
bool cmp(Bet a,Bet b)
{
  return a.pro>b.pro;
}
int main()
{
  float max=1;
  vector<char> v;
  for(int i=0;i<3;i++)
  {
    Bet arr[3];
    arr[0].res='W';
    arr[1].res='T';
    arr[2].res='L';
    cin>>arr[0].pro>>arr[1].pro>>arr[2].pro;
    sort(arr,arr+3,cmp);
    max*=arr[0].pro;
    //cout<< arr[0].pro;
    v.push_back(arr[0].res);
  }
  for(int i=0;i<3;i++)
  cout<<v[i]<<" ";
  cout<<fixed<<setprecision(2)<<(max*0.65-1)*2<<endl;
  return 0;
}
