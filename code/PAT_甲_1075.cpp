#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct tester
{
  int id;
  int total_score;
  int perfectly_solve;
  tester(int id = 0, int total_score = 0, int perfectly_solve = 0):id(id),total_score(total_score),perfectly_solve(perfectly_solve){}
};
bool cmp(tester a,tester b)
{
  if(a.total_score != b.total_score)
     return a.total_score > b.total_score;
  else if(a.perfectly_solve != b.perfectly_solve)
     return a.perfectly_solve >b.perfectly_solve;
  else
     return a.id < b.id;
}
int main()
{
  int N,K,M;
  cin>>N>>K>>M;
  vector<vector<int> >  v(N+1,vector<int>(K,-2));
  vector<int> score(K,0);
  vector<int> tot(N+1,0);
  for(int i = 0; i < K; i++)
  {
    int scr;
    scanf("%d",&scr);
    score[i] = scr;
  }
  while(M--)
  {
    int id,pro_id,scr;
    scanf("%d %d %d",&id,&pro_id,&scr);
    if(v[id][pro_id - 1] == -2)
       v[id][pro_id - 1] = scr;
    else if(scr > v[id][pro_id - 1])
       v[id][pro_id - 1] = scr;
  }
  vector<tester> board;
  for(int i = 1; i <= N; i++)
  {
    int tot_score = 0;
    int perfect = 0;
    bool submit = false;
    for(int j = 0; j < K; j++)
    {
      if(v[i][j] >= 0)
         tot_score += v[i][j];
      if(v[i][j] == score[j])
         perfect++;
      if(v[i][j] >= 0)
         submit = true;
    }
    if(submit)
        board.push_back(tester(i,tot_score,perfect));
  }
  sort(board.begin(),board.end(),cmp);
  printf("1 %05d %d",board[0].id,board[0].total_score);
  int user_id = board[0].id;
  for(int i = 0; i < K; i++)
  {
    if(v[user_id][i] == -2)
       printf(" -");
    else if(v[user_id][i] == -1 || v[user_id][i] == 0)
       printf(" 0");
    else if(v[user_id][i] > 0)
       printf(" %d",v[user_id][i]);
  }
  printf("\n");
  int rank = 1;
  for(int i = 1; i < board.size(); i++)
  {
    if(board[i].total_score == board[i-1].total_score)
    {
      printf("%d %05d %d",rank,board[i].id,board[i].total_score);
      for(int j = 0; j < K; j++)
      {
        if(v[board[i].id][j] == -2)
           printf(" -");
        else if(v[board[i].id][j] == -1 || v[board[i].id][j] == 0)
           printf(" 0");
        else if(v[board[i].id][j] > 0)
           printf(" %d",v[board[i].id][j]);
      }
      printf("\n");
    }
    else
    {
      rank = i + 1;
      printf("%d %05d %d",rank,board[i].id,board[i].total_score);
      for(int j = 0; j < K; j++)
      {
        if(v[board[i].id][j] == -2)
           printf(" -");
        else if(v[board[i].id][j] == -1 || v[board[i].id][j] == 0)
           printf(" 0");
        else if(v[board[i].id][j] > 0)
           printf(" %d",v[board[i].id][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
