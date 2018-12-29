#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef struct Student{
  string name;
  string id;
  int grade;
  Student(string name = "",string id = "",int grade = 0):name(name),id(id),grade(grade){}
}Student;
bool cmp(Student a,Student b)
{
  return a.grade > b.grade;
}
int main()
{
  int n;
  cin>>n;
  vector<Student> v(n);
  for(int i = 0; i < n; i++)
  {
    cin>>v[i].name>>v[i].id>>v[i].grade;
  }
  sort(v.begin(),v.end(),cmp);
  int grade1,grade2;
  cin>>grade1>>grade2;
  bool flag = false;
  for(int i = 0; i < n; i++)
  {
    if(v[i].grade >= grade1 && v[i].grade <= grade2)
    {
      flag = true;
      cout<<v[i].name<<" "<<v[i].id<<endl;
    }
  }
  if(!flag)
    cout<<"NONE"<<endl;
  return 0;
}
