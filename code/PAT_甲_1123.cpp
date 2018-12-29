#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct node
{
  int val;
  struct node *left,*right;
};
struct node* leftRotate(struct node *tree)
{
  struct node *temp = tree->right;
  tree->right = temp->left;
  temp->left = tree;
  return temp;
}
struct node* rightRotate(struct node *tree)
{
  struct node *temp = tree->left;
  tree->left = temp->right;
  temp->right = tree;
  return temp;
}
int getHeight(struct node *tree)
{
  if(tree == NULL)
    return 0;
  else
  {
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return l > r ? l + 1 : r + 1;
  }
}
struct node* leftRightRotate(struct node *tree)
{
  tree->left = leftRotate(tree->left);
  tree = rightRotate(tree);
  return tree;
}
struct node* rightLeftRotate(struct node *tree)
{
  tree->right = rightRotate(tree->right);
  tree = leftRotate(tree);
  return tree;
}
struct node* insert(struct node* tree,int val)
{
  if(tree == NULL)
  {
    tree = new struct node();
    tree->val = val;
    return tree;
  }
  if(tree->val > val)
  {
    tree->left = insert(tree->left,val);
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    if(l - r >= 2)
    {
      if(val < tree->left->val)
         tree = rightRotate(tree);
      else
        tree = leftRightRotate(tree);
    }
  }
  else
  {
    tree->right = insert(tree->right,val);
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    if(r - l >= 2)
    {
      if(val > tree->right->val)
        tree = leftRotate(tree);
      else
        tree = rightLeftRotate(tree);
    }
  }
  return tree;
}
int isComplete = 1, after = 0;
vector<int> levelOrder(struct node *tree)
{
  vector<int> v;
  queue<struct node*> q;
  q.push(tree);
  while(!q.empty())
  {
    struct node *temp = q.front();
    v.push_back(temp->val);
    if(temp->left)
    {
      if(after)
        isComplete = 0;
      q.push(temp->left);
    }
    else
      after = 1;
    if(temp->right)
    {
      if(after)
        isComplete = 0;
      q.push(temp->right);
    }
    else
       after = 1;
    q.pop();
  }
  return v;
}
void print(vector<int> v)
{
  for(int i = 0; i < v.size(); i++)
  {
    if(i == 0)
      printf("%d",v[i]);
    else
      printf(" %d",v[i]);
  }
  printf("\n");
}
int main()
{
  int n;
  scanf("%d",&n);
  struct node *tree = NULL;
  for(int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d",&temp);
    tree = insert(tree,temp);
  }
  vector<int> v = levelOrder(tree);
  print(v);
  if(isComplete)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
