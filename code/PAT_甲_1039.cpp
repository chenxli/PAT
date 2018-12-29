#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>//必须使用scanf，改成char[],但是map麻烦,所以考虑将姓名转化为唯一的一个数字表示
using namespace std;//调用函数还比cin,cout快。。。。。。
int hsh(char* s)
{
  return (s[0]-'A')*26*26*10+(s[1]-'A')*26*10+(s[2]-'A')*10+s[3]-'0';
}
int main()
{
  int N,K;
  cin>>N>>K;
  map<int,vector<int> > student;
  while(K--)
  {
    int course_id,num;
    scanf("%d %d",&course_id,&num);
    while(num--)
    {
      char name[5];
      scanf("%s",name);
      student[hsh(name)].push_back(course_id);
    }
  }
  for(int i = 0; i < N; i++)
  {
    char Name[5];
    scanf("%s",Name);
    int temp = hsh(Name);
    printf("%s %d",Name,student[temp].size());
    if(student[temp].size() == 0)
    {
      printf("\n");
      continue;
    }
    sort(student[temp].begin(),student[temp].end());
    for(int j = 0; j < student[temp].size(); j++)
      printf(" %d",student[temp][j]);
    printf("\n");
  }
  return 0;
}
