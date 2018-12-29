#include<iostream>
#include<queue>
using namespace std;

int n;
int lchild[10]={-1};
int rchild[10]={-1};
queue<int> tree;
int cnt=0;

void Inorder(int a)
{
  if(lchild[a]!=-1)
  {
    Inorder(lchild[a]);
  }
  cout<<a;
  cnt++;
  if(cnt<n)
   cout<<" ";
  if(rchild[a]!=-1)
   Inorder(rchild[a]);
}

int main()
{
  for(int i=0;i<10;i++)
  {
    lchild[i]=-1;
    rchild[i]=-1;
  }
  int mark[10]={0};
  cin>>n;
  for(int i=0;i<n;i++)
  {
    char l,r;
    cin>>l>>r;
    if(l!='-')
    {
      rchild[i]=l-'0';
      mark[l-'0']++;
    }
    if(r!='-')
    {
      lchild[i]=r-'0';
      mark[r-'0']++;
    }
  }
  int root=0;
  for(int i=0;i<n;i++)
  {
    if(mark[i]==0)
    {
      root=i;
      break;
    }
  }
  tree.push(root);
  while(tree.size()>0)
  {
    if(lchild[tree.front()]!=-1)
    {
      tree.push(lchild[tree.front()]);
    }
    if(rchild[tree.front()]!=-1)
    {
      tree.push(rchild[tree.front()]);
    }
    cout<<tree.front();
    tree.pop();
    if(tree.size()!=0)
     cout<<" ";
  }
  cout<<endl;
  Inorder(root);
  return 0;
}
