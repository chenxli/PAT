#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct node
{
  int data;
  struct node *lchild,*rchild;
};
struct node* create(vector<int> v1,vector<int> v2,int low1,int high1,int low2,int high2)
{
  if(low1 > high1) return NULL;
  struct node* root = (struct node*)malloc(sizeof(struct node));
  root->data = v2[high2];
  int pos = low1;
  while(v1[pos] != v2[high2])
  {
    pos++;
  }
  root->lchild = create(v1,v2,low1,pos-1,low2,low2+pos-low1-1);
  root->rchild = create(v1,v2,pos+1,high1,low2+pos-low1,high2-1);
  return root;
}
vector<vector<int>> v(31);
unordered_map<struct node*,int> mymap;
unordered_map<struct node*,int> mmap;
int height = 0;
void l2r(struct node* root)
{
  queue<struct node*> q;
  q.push(root);
  mymap[root] = 1;
  while(!q.empty())
  {
    struct node * temp = q.front();
    if(mymap[temp] % 2 == 0)
    {
      v[mymap[temp]].push_back(temp->data);
    }
    if(mymap[temp] > height)
      height = mymap[temp];
    if(temp->lchild)
    {
      q.push(temp->lchild);
      mymap[temp->lchild] = mymap[temp] + 1;
    }
    if(temp->rchild)
    {
      q.push(temp->rchild);
      mymap[temp->rchild] = mymap[temp] + 1;
    }
    q.pop();
  }
}
void r2l(struct node* root)
{
  queue<struct node*> q;
  q.push(root);
  mmap[root] = 1;
  while(!q.empty())
  {
    struct node* temp = q.front();
    if(mmap[temp] % 2 == 1)
    {
      v[mmap[temp]].push_back(temp->data);
    }
    if(temp->rchild)
    {
      q.push(temp->rchild);
      mmap[temp->rchild] = mmap[temp] + 1;
    }
    if(temp->lchild)
    {
      q.push(temp->lchild);
      mmap[temp->lchild] = mmap[temp] + 1;
    }
    q.pop();
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  vector<int> in,post;
  for(int i = 0; i < n; i++)
  {
    int data;
    scanf("%d",&data);
    in.push_back(data);
  }
  for(int i = 0; i < n; i++)
  {
    int data;
    scanf("%d",&data);
    post.push_back(data);
  }
  struct node* root = create(in,post,0,n-1,0,n-1);
  l2r(root);
  r2l(root);
  int cnt = 0;
  for(int i = 1; i <= height; i++)
  {
    for(int j = 0; j < v[i].size(); j++)
    {
      if(cnt == 0)
      {
        printf("%d",v[i][j]);
        cnt++;
      }
      else
        printf(" %d",v[i][j]);
    }
  }
  return 0;
}
