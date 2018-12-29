#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;
struct node
{
  int data;
  node* r;
  node* l;
  node():l(NULL),r(NULL){}
};
void insert(node* &root,int x)
{
  if(!root)
  {
    root = (node*)malloc(sizeof(node));
    root->data = x;
    root->r = NULL;
    root->l = NULL;
    return;
  }
  else
  {
    if(x >= root->data) insert(root->r,x);
    else if(x < root->data) insert(root->l,x);
  }
}
int i = 0;
vector<int> v,vpre,vpost;
void preorder(node* root)
{
  if(root)
  {
    vpre.push_back(root->data);
    preorder(root->l);
    preorder(root->r);
  }
}
void Imagepreorder(node* root)
{
  if(root)
  {
    vpre.push_back(root->data);
    Imagepreorder(root->r);
    Imagepreorder(root->l);
  }
}
bool image = false;
void postorder(node* root)
{
  if(root)
  {
    if(!image)
    {
      postorder(root->l);
      postorder(root->r);
      vpost.push_back(root->data);
    }
    else
    {
      postorder(root->r);
      postorder(root->l);
      vpost.push_back(root->data);
    }
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  node* root = NULL;
  int x;
  for(int i = 0; i < n; i++)
  {
    scanf("%d",&x);
    v.push_back(x);
    insert(root,x);
  }
  preorder(root);
  for(int i = 0; i < n;i++)
  {
    if(vpre[i] != v[i])
    {
      image = true;
      break;
    }
  }
  vpre.clear();
  Imagepreorder(root);
  if(image)
  {
    for(int i = 0; i < n; i++)
    {
      if(vpre[i] != v[i])
      {
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }
  postorder(root);
  cout<<"YES"<<endl;
  for(int i = 0; i < n; i++)
  {
    if(i == 0)
    {
      cout<<vpost[i];
    }
    else
    {
      cout<<" "<<vpost[i];
    }
  }
  cout<<endl;
  return 0;
}
