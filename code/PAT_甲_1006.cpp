#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Sign
{
  string id;
  string start;
  string finish;
};
bool cmp1(struct Sign a,struct Sign b)
{
  return a.start<b.start;
}
bool cmp2(struct Sign a,struct Sign b)
{
  return a.finish>b.finish;
}
int main()
{
  int n;
  cin>>n;
  vector<struct Sign> v;
  while(n--)
  {
    struct Sign s;
  //  string id,start,finish;
    cin>>s.id>>s.start>>s.finish;
  //  s.id=id;
    //s.start=start;
    //s.finish=finish;
    v.push_back(s);
 }
 cout<<v.size()<<endl;
 sort(v.begin(),v.end(),cmp1);
 cout<<v[0].id<<" ";
 sort(v.begin(),v.end(),cmp2);
 cout<<v[0].id<<endl;
 return 0;
}
