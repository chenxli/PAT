#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;
struct node
{
  int data;
  struct node * left;
  struct node * right;
};
vector<int> v1, v2;
int n;
struct node* create(int a, int b,int c, int d)
{
  if(a > b)
    return NULL;
  struct node*  root = (struct node*)malloc(sizeof(struct node));
  root->data = v1[a];
  int i;
  for(i = c; i <= d; i++)
  {
    if(v2[i] == v1[a])
    {
      break;
    }
  }
  root->left = create(a+1,a+i-c,c,i-1);
  root->right = create(a+i-c+1,b,i+1,d);
  return root;
}

vector<int> post;
void postorder(node* root)
{
  if(root)
  {
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->data);
  }
}

int main()
{
  cin>>n;
  stack<int> ss;
  int m = n;
  while(m)
  {
    string s;
    cin>>s;
    if(s == "Push")
    {
      int val;
      cin>>val;
      ss.push(val);
      v1.push_back(val);
    }
    else if(s == "Pop")
    {
      v2.push_back(ss.top());
      ss.pop();
      m--;
    }
  }
  struct node* r = create(0,n-1,0,n-1);
  postorder(r);
  int cnt = 0;
  for(int i = 0; i < post.size(); i++)
  {
    if(cnt == 0)
    {
      printf("%d",post[i]);
      cnt++;
    }
    else
      printf(" %d",post[i]);
  }
  cout<<endl;
  return 0;
}
