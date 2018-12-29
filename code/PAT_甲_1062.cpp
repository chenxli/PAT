#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct info
{
  int id;
  int virtue_grade;
  int talent_grade;
  int total_grade;
  info(int id,int v,int t,int tot):id(id),virtue_grade(v),talent_grade(t),total_grade(tot){}
};
bool cmp(info a,info b)
{
  if(a.total_grade != b.total_grade)
    return a.total_grade > b.total_grade;
  else if(a.virtue_grade != b.virtue_grade)
    return a.virtue_grade > b.virtue_grade;
  else
    return a.id < b.id;
}
int main()
{
  int n,l,h;
  cin>>n>>l>>h;
  vector<info> v1;
  vector<info> v2;
  vector<info> v3;
  vector<info> v4;
  while(n--)
  {
    int id,v,t;
    scanf("%d%d%d",&id,&v,&t);
    if(v >= h && t >= h)
      v1.push_back(info(id,v,t,v+t));
    else if(t >= l && t < h && v >= h)
      v2.push_back(info(id,v,t,v+t));
    else if(t < h && t >= l && v < h && v >= l && v >= t)
      v3.push_back(info(id,v,t,v+t));
    else if(t >= l && v >= l)
      v4.push_back(info(id,v,t,v+t));
  }
  sort(v1.begin(),v1.end(),cmp);
  sort(v2.begin(),v2.end(),cmp);
  sort(v3.begin(),v3.end(),cmp);
  sort(v4.begin(),v4.end(),cmp);
  cout<<v1.size()+v2.size()+v3.size()+v4.size()<<endl;
  for(int i = 0; i < v1.size(); i++)
    printf("%d %d %d\n",v1[i].id,v1[i].virtue_grade,v1[i].talent_grade);
  for(int i = 0; i < v2.size(); i++)
    printf("%d %d %d\n",v2[i].id,v2[i].virtue_grade,v2[i].talent_grade);
  for(int i = 0; i < v3.size(); i++)
    printf("%d %d %d\n",v3[i].id,v3[i].virtue_grade,v3[i].talent_grade);
  for(int i = 0; i < v4.size(); i++)
    printf("%d %d %d\n",v4[i].id,v4[i].virtue_grade,v4[i].talent_grade); 
  return 0;
}
