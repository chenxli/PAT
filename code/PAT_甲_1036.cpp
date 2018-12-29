#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct student
{
  string name;
  string id;
  int grade;
  student(string n,string id, int g):name(n),id(id),grade(g){}
  bool operator<(struct student a)
  {
    return grade < a.grade;
  }
};
int main()
{
  int n;
  cin>>n;
  vector<student> male;
  vector<student> female;
  while(n--)
  {
    string name;
    string id;
    int grade;
    char sex;
    cin>>name>>sex>>id>>grade;
    if(sex == 'M')
      male.push_back(student(name,id,grade));
    else
    female.push_back(student(name,id,grade));
  }
  bool flag = false;
  sort(male.begin(),male.end());
  sort(female.begin(),female.end());
  if(female.size() == 0)
  {
    cout<<"Absent"<<endl;
    flag = true;
  }
  else
    cout<<female[female.size()-1].name<<" "<<female[female.size()-1].id<<endl;
  if(male.size() == 0)
  {
    cout<<"Absent"<<endl;
    flag = true;
  }
  else
    cout<<male[0].name<<" "<<male[0].id<<endl;
  if(flag)
    cout<<"NA"<<endl;
  else
    cout<<female[female.size()-1].grade-male[0].grade<<endl;
  return 0;
}
