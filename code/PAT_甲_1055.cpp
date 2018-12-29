#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct people
{
  char name[10];
  int age;
  int worth;
  people(char na[],int age,int worth)
  {
    strcpy(name,na);
    this->age = age;
    this->worth = worth;
  }
};
bool cmp(struct people a,struct people b)
{
  if(a.worth != b.worth)
    return a.worth > b.worth;
  else if(a.age != b.age)
    return a.age < b.age;
  else
   return strcmp(a.name,b.name) < 0;
}
int main()
{
  int m,n;
  scanf("%d %d",&m,&n);
  vector<people> v;
  for(int i = 0; i < m; i++)
  {
    char name[10];
    int age,worth;
    scanf("%s %d %d",name,&age,&worth);
    v.push_back(people(name,age,worth));
  }
  sort(v.begin(),v.end(),cmp);
  for(int i = 1; i <= n; i++)
  {
    int num,minAge,maxAge;
    scanf("%d%d%d",&num,&minAge,&maxAge);
    int count = 0;
    printf("Case #%d:\n",i);
    for(int j = 0; j < v.size(); j++)
    {
      if(v[j].age >= minAge && v[j].age <= maxAge && count < num)
      {
        printf("%s %d %d\n",v[j].name,v[j].age,v[j].worth);
        count++;
      }
    }
    if(count == 0)
      printf("None\n");
  }
  return 0;
}
