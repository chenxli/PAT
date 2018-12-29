#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
  int data;
  struct node *left,*right;
};
// bool cmp(int a,int b)
// {
//   return abs(a) <= abs(b);
// }
// struct node* create(vector<int> v1,vector<int> v2,int a,int b,int c,int d)
// {
//   if(a > b) return NULL;
//   struct node* root = (struct node*)malloc(sizeof(struct node));
//   root->data = v1[a];
//   int pos = c;
//   while(v2[pos] != v1[a])
//   {
//     pos++;
//   }
//   root->left = create(v1,v2,a+1,a+pos-c,c,pos-1);
//   root->right = create(v1,v2,a+pos-c+1,b,pos+1,d);
//   return root;
// }
void build(struct node* &root,int val)
{
  if(root == NULL)
  {
    root = (struct node*)malloc(sizeof(struct node));
    root->data = val;
    root->left = NULL;
    root->right = NULL;
  }
  else
  {
    if(abs(val) < abs(root->data))
      build(root->left,val);
    else
      build(root->right,val);
  }
}
void dfs(struct node* root,int temp,int &black)
{
  if(root == NULL)
  {
    if(black == -1) black = temp;
    else if(black != temp)
      black = -2;
      return;
  }
  if(black == -2) return;
  if(root->data > 0) temp++;
  dfs(root->left,temp,black);
  dfs(root->right,temp,black);
}
bool isRedBlack(struct node* root)
{
  if(root->data < 0)
    return false;
  else
  {
    queue<struct node*> q;
    q.push(root);
    while(!q.empty())
    {
      struct node* temp = q.front();
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
      if(temp->data < 0)
      {
        if(temp->left)
        {
          if(temp->left->data < 0)
            return false;
        }
        if(temp->right)
        {
          if(temp->right->data < 0)
            return false;
        }
      }
      int black = -1;
      dfs(temp,0,black);
      if(black == -2)
        return false;
      q.pop();
    }
  }
  return true;
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    int m;
    scanf("%d",&m);
    // vector<int> v;
    struct node* root = NULL;
    for(int j = 0; j < m; j++)
    {
      int data;
      scanf("%d",&data);
      build(root,data);
      // v.push_back(data);
    }
    // vector<int> v1 = v;
    // sort(v1.begin(),v1.end(),cmp);
    // struct node* root = create(v,v1,0,v.size()-1,0,v1.size()-1);
    if(isRedBlack(root))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
