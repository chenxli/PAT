#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct Student
{
  char id[10];
  char name[10];
  int grade;
};
bool cmp1(struct Student a,struct Student b)
{
  return strcmp(a.id,b.id) < 0;
}
bool cmp2(struct Student a,struct Student b)
{
  if(strcmp(a.name,b.name) == 0)
   return strcmp(a.id,b.id) < 0;
  else
   return strcmp(a.name,b.name) < 0;
}
bool cmp3(struct Student a,struct Student b)
{
  if(a.grade == b.grade)
   return strcmp(a.id,b.id) < 0;
  else
   return a.grade < b.grade;
}
int main()
{
  int n,c;
  scanf("%d%d",&n,&c);
  vector<Student> v;
  for(int i = 0; i < n; i++)
  {
    char ID[10],Name[10];
    int Grade;
    scanf("%s%s%d",ID,Name,&Grade);
    Student a;
    strcpy(a.id,ID);
    strcpy(a.name,Name);
    a.grade = Grade;
    v.push_back(a);
  }
  if(c == 1)
   sort(v.begin(),v.end(),cmp1);
  else if(c == 2)
   sort(v.begin(),v.end(),cmp2);
  else
   sort(v.begin(),v.end(),cmp3);
  for(int i = 0; i < n; i++)
  {
    printf("%s %s %d\n",v[i].id,v[i].name,v[i].grade);
  }
  return 0;
}
