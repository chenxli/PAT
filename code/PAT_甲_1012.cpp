/*#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
  int id,best;
  int score[4],rank[4];
}stu[2005];
int exist[1000000],flag=-1;
bool cmp1(node a,node b)
{
  return a.score[flag]>b.score[flag];
}

int main()
{
  int n,m,id;
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++)
  {
    scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
    stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[2])/3.0+0.5;//四舍五入
  }
  for(flag=0;flag<=3;flag++)
  {
    sort(stu,stu+n,cmp1);
    stu[0].rank[flag]=1;
    for(int i=1;i<n;i++)
    {
      stu[i].rank[flag]=i+1;
      if(stu[i].score[flag]==stu[i-1].score[flag])
       stu[i].rank[flag]=stu[i-1].rank[flag];
    }
  }
  for(int i=0;i<n;i++)
  {
    exist[stu[i].id]=i+1;
    stu[i].best=0;
    int min=stu[i].rank[0];
    for(int j=1;j<=3;j++)
    {
      if(stu[i].rank[j]<min)
      {
        min=stu[i].rank[j];
        stu[i].best=j;
      }
    }
  }
  char c[5]={'A','C','M','E'};
  for(int i=0;i<m;i++)
  {
    scanf("%d",&id);
    int temp=exist[id];
    if(temp)
    {
      int best=stu[temp-1].best;
      printf("%d %c\n",stu[temp-1].rank[best],c[best]);
    }
    else
    printf("N/A\n");
  }
  return 0;
}*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct stu
{
  int ID;
  int C;
  int M;
  int E;
  int A;
  int bestRank;
  char bestItem;
  stu(int id,int c,int m,int e):ID(id),C(c),M(m),E(e){
    A=(c+m+e)/3;
  }
};
bool cmpA(stu s1,stu s2)
{
  return s1.A>s2.A;
}
bool cmpC(stu s1, stu s2)
{
  return s1.C>s2.C;
}
bool cmpM(stu s1,stu s2)
{
  return s1.M>s2.M;
}
bool cmpE(stu s1,stu s2)
{
  return s1.E>s2.E;
}
int main()
{
  int N,M;
  cin>>N>>M;
  if(N==0)
  {
    int x;
    while(M--)
    {
      cin>>x;
      cout<<"N/A"<<endl;
    }
    return 0;
  }
  int id,c,m,e;
  vector<stu> students;
  for(int i=0;i<N;i++)
  {
    cin>>id>>c>>m>>e;
    students.push_back(stu(id,c,m,e));
  }
  sort(students.begin(),students.end(),cmpA);
  int rankA=1;
  students[0].bestRank=1;
  students[0].bestItem='A';
  for(int i=1;i<N;i++)
  {
    if(students[i].A<students[i-1].A)
       rankA=1+i;
    students[i].bestRank=rankA;
    students[i].bestItem='A';
  }
  sort(students.begin(),students.end(),cmpC);
  int rankC=1;
  if(students[0].bestRank!=1)
  {
    students[0].bestRank=1;
    students[0].bestItem='C';
  }
  for(int i=1;i<N;i++)
  {
    if(students[i].C<students[i-1].C)
     rankC=i+1;
    if(students[i].bestRank>rankC)
    {
      students[i].bestRank=rankC;
      students[i].bestItem='C';
    }
  }
  sort(students.begin(),students.end(),cmpM);
  int rankM=1;
  if(students[0].bestRank>rankM)
  {
    students[0].bestRank=1;
    students[0].bestItem='M';
  }
  for(int i=1;i<N;i++)
  {
    if(students[i].M<students[i-1].M)
    rankM=i+1;
    if(students[i].bestRank>rankM)
    {
      students[i].bestRank=rankM;
      students[i].bestItem='M';
    }
  }
  sort(students.begin(),students.end(),cmpE);
  int rankE=1;
  if(students[0].bestRank>rankE)
  {
    students[0].bestRank=1;
    students[0].bestItem='E';
  }
  for(int i=1;i<N;i++)
  {
    if(students[i].E<students[i-1].E)
    rankE=i+1;
    if(students[i].bestRank>rankE)
    {
      students[i].bestRank=rankE;
      students[i].bestItem='E';
    }
  }
  map<int,int> map;
  for(int i=0;i<N;i++)
  {
    map[students[i].ID]=i;
  }
  int x;
  while(M--)
  {
    cin>>x;
    if(map.find(x)==map.end())
     cout<<"N/A"<<endl;
    else
     cout<<students[map[x]].bestRank<<" "<<students[map[x]].bestItem<<endl;
  }
  return 0;
}
