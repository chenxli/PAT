#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct testee
{
  string registration_number;
  int location_number;
  int score;
  testee(string num,int l_num,int s):registration_number(num),location_number(l_num),score(s){}
  bool operator>(struct testee b)
  {
    return score > b.score;
  }
};
bool cmp(struct testee a,struct testee b)
{
  if(a.score != b.score)
    return a.score > b.score;
  else
    return a.registration_number < b.registration_number;
}
int main()
{
  int n;
  cin>>n;
  vector<testee> Testee;
  map<string,int> local_rank;
  map<string,int> final_rank;
  int sum = 0;
  int now_score = -1;
  int rank = 0;
  for(int i = 0; i < n; i++)
  {
    int K;
    cin>>K;
    vector<testee> tmp;
    for(int j = 0; j < K; j++)
    {
      string num;
      int l_num,s;
      cin>>num>>s;
      Testee.push_back(testee(num,i+1,s));
      tmp.push_back(testee(num,i+1,s));
    }
    sort(tmp.begin(),tmp.end(),cmp);
    now_score = -1;
    rank = 0;
    for(int t = 0; t < tmp.size(); t++)
    {
      if(tmp[t].score != now_score)
      {
        local_rank[tmp[t].registration_number] = t + 1;
        now_score = tmp[t].score;
        rank = t + 1;
      }
      else
        local_rank[tmp[t].registration_number] = rank;
    }
  }
  sort(Testee.begin(),Testee.end(),cmp);
  now_score = -1;
  rank = 0;
  for(int i = 0; i < Testee.size(); i++)
  {
    if(Testee[i].score != now_score)
    {
      final_rank[Testee[i].registration_number] = i + 1;
      now_score = Testee[i].score;
      rank = i + 1;
    }
    else
      final_rank[Testee[i].registration_number] = rank;
  }
  cout<<Testee.size()<<endl;
  for(int i = 0; i < Testee.size(); i++)
  {
    cout<<Testee[i].registration_number<<" "<<final_rank[Testee[i].registration_number]<<" "<<Testee[i].location_number<<" "
    <<local_rank[Testee[i].registration_number]<<endl;
  }
  return 0;
}
