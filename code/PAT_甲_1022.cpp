#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct book
{
  int id;//把id改成字符串相对没有那么麻烦，不用考虑前面的数字为0.。。。
  string title,author,key_words,publisher,year;
  book(int id,string title,string author,string key_words,string publisher,string year):id(id),title(title),author(author),key_words(key_words),publisher(publisher),year(year){}
  bool operator<(struct book b)
  {
    return id<b.id;
  }
};
int main()
{
  int n,m,i,j;
  cin>>n;
  vector<book> BOOK;
  for(i = 0; i < n; i++)
  {
    int id;
    string title,author,key_words,publisher,year;
    cin>>id;
    getchar();
    getline(cin,title,'\n');
    getline(cin,author,'\n');
    getline(cin,key_words,'\n');
    getline(cin,publisher,'\n');
    getline(cin,year,'\n');
    BOOK.push_back(book(id,title,author,key_words,publisher,year));
  }
  sort(BOOK.begin(),BOOK.end());
  cin>>m;
  for(i = 0; i < m; i++)
  {
    int num;
    string index;
    scanf("%d: ",&num);
    getline(cin,index,'\n');
    cout<<num<<": "<<index<<endl;
    bool flag = false;
    if(num == 1)
    {
      for(j = 0; j < BOOK.size(); j++)
      {
        if(BOOK[j].title == index)
        {
          flag = true;
          printf("%07d\n",BOOK[j].id);
        }
      }
    }
    else if(num == 2)
    {
      for(j = 0; j < BOOK.size(); j++)
      {
        if(BOOK[j].author == index)
        {
          flag = true;
          printf("%07d\n",BOOK[j].id);
        }
      }
    }
    else if(num == 3)
    {
      for(j = 0; j < BOOK.size(); j++)
      {
        if(BOOK[j].key_words.find(index) != string::npos)
        {
          flag = true;
          printf("%07d\n",BOOK[j].id);
        }
      }
    }
    else if(num == 4)
    {
      for(j = 0; j < BOOK.size(); j++)
      {
        if(BOOK[j].publisher == index)
        {
          flag = true;
          printf("%07d\n",BOOK[j].id);
        }
      }
    }
    else if(num == 5)
    {
      for(j = 0; j < BOOK.size(); j++)
      {
        if(BOOK[j].year == index)
        {
          flag = true;
          printf("%07d\n",BOOK[j].id);
        }
      }
    }
    if(!flag)
     cout<<"Not Found"<<endl;
  }
  return 0;
}
