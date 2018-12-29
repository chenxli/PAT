#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
  int v;
  struct node *left,*right;
};
struct node* L(struct node* root)
{
  struct node* temp = root->right;
  root->right = temp->left;
  temp->left = root;
  return temp;
}
struct node* R(struct node* root)
{
  struct node* temp = root->left;
  root->left = temp->right;
  temp->right = root;
  return temp;
}
struct node* LR(struct node* root)
{
  root->left = L(root->left);
  return R(root);
}
struct node* RL(struct node* root)
{
  root->right = R(root->right);
  return L(root);
}
int getHeight(struct node* root)
{
  if(root == NULL) return 0;
  else
  {
    int l = getHeight(root->left) + 1;
    int r = getHeight(root->right) + 1;
    return l > r ? l : r;
  }
}
struct node* insert(struct node* root,int val)
{
  if(root == NULL)
  {
    root = (struct node*)malloc(sizeof(struct node));
    root->v = val;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  else
  {
    if(root->v > val)
    {
      root->left = insert(root->left,val);
      int l = getHeight(root->left);
      int r = getHeight(root->right);
      if(l - r >= 2)
      {
        if(root->left->v > val)
          root = R(root);
        else
         root = LR(root);
      }
    }
    else
    {
      root->right = insert(root->right,val);
      int l = getHeight(root->left);
      int r = getHeight(root->right);
      if(r - l >= 2)
      {
        if(root->right->v <= val)
          root = L(root);
        else
          root = RL(root);
      }
    }
    return root;
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  struct node *root = NULL;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d",&val);
    root = insert(root,val);
  }
  printf("%d\n",root->v);
  return 0;
}
