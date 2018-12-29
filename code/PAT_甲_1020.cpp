#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* l_child;
    TreeNode* r_child;
    TreeNode(int v = 0,TreeNode* l = NULL,TreeNode* r = NULL):val(v),l_child(l),r_child(r){}
};
typedef struct TreeNode* node;

node createTree(string post,string in)
{
    node root = NULL;
    if(post.size() == 0 || post.size() != in.size()) return root;
    int index = in.find(post[post.size()-1]);
    root = new struct TreeNode(post[post.size()-1] - '0',NULL,NULL);
    int l_len = index;
    int r_len = in.size() - 1 - index;
    string l_post = post.substr(0,l_len);
    string l_in = in.substr(0,l_len);
    string r_post = post.substr(l_len,r_len);
    string r_in = in.substr(index + 1,r_len);
    root->l_child = createTree(l_post,l_in);
    root->r_child = createTree(r_post,r_in);
    return root;
}

void levelTraversal(node root)
{
    queue<node> q;
    if(root == NULL) return;
    q.push(root);
    bool tag = true;
    node p = NULL;
    while(!q.empty())
    {
        p = q.front();
        int value = p->val; 
        if(tag)
          tag = false;
        else
          printf(" ");
        printf("%d",value);
        if(p->l_child)
         q.push(p->l_child);
        if(p->r_child)
         q.push(p->r_child);
        q.pop();
    }
    printf("\n");
}

int main()
{
    int n;
    cin>>n;
    string post;
    string in;
    for(int i = 0; i < n; i++)
    {
        int v;
        cin>>v;
        post += v + '0';
    }
    for(int i = 0; i < n; i++)
    {
        int v;
        cin>>v;
        in += v + '0';
    }
    node root = NULL;
    root = createTree(post,in);
    levelTraversal(root);
    return 0;
}
/*
#include <iostream>  
#include <memory.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <queue>  
  
using namespace std;  
  
#define MAX 40  
  
int postOrder[MAX];  
int inOrder[MAX];  
int N;  
int cur;  
  
typedef struct TreeNode *Tree;  
struct TreeNode{  
  
    Tree left;  
    Tree right;  
    int  num;  
  
};  
  
  
  
int findRootIndex(int rootNum){  
  
    for(int i = 0;i < N; i++){  
        if(inOrder[i] == rootNum){  
            return i;  
        }  
    }  
    return -1;  
  
}  
  
Tree CreateTree(int left, int right){  
    if(left > right ) return NULL;  
    int root = postOrder[cur];  
    cur --;  
    int rootIndex = findRootIndex(root);  
    Tree T = (Tree)malloc(sizeof(struct TreeNode));  
    T->num = root;  
    if(left == right){  
        T->left = NULL;  
        T->right = NULL;  
    }else{  
        T->right = CreateTree(rootIndex+1,right);  
        T->left = CreateTree(left,rootIndex-1);  
    }  
    return T;  
  
}  
  
void BFS(Tree T){  
  
    bool firstout = true;  
    queue<Tree> q;  
    q.push(T);  
  
    while(!q.empty()){  
  
        Tree t = q.front();  
        q.pop();  
        if(firstout){  
            firstout = false;  
            cout << t->num;  
        }else{  
            cout << " " << t->num;  
        }  
        if(t->left != NULL){  
            q.push(t->left);  
        }  
        if(t->right!= NULL){  
            q.push(t->right);  
        }  
  
    }  
  
  
  
}  
  
  
int main()  
{  
    cin >> N;  
    cur = N-1;  
    for(int i = 0; i < N; i++){  
        cin >> postOrder[i];  
    }  
    for(int i = 0; i < N; i++){  
        cin >> inOrder[i];  
    }  
  
    Tree T = CreateTree(0,cur);  
  
    BFS(T);  
  
    cout << endl;  
  
    return 0;  
}  */