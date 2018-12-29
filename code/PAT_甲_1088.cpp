#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
struct fen
{
  LL fenzi,fenmu;
  bool neg;
  int flag;
};
LL gcd(LL a,LL b)
{
  if(b == 0)
    return a;
  else
    return gcd(b,a%b);
}
struct fen addition(struct fen A,struct fen B)
{
  struct fen C;
  C.neg = false;
  LL a1 = A.fenzi,b1 = A.fenmu;
  LL a2 = B.fenzi,b2 = B.fenmu;
  if(A.neg)
    a1 = -a1;
  if(B.neg)
    a2 = -a2;
  LL fenzi = a1*b2 + a2*b1;
  LL fenmu = b1 * b2;
  if(fenzi < 0)
  {
    C.neg = true;
    fenzi = -fenzi;
  }
  LL k = gcd(fenzi,fenmu);
  fenzi /= k;
  fenmu /= k;
  C.fenzi = fenzi;
  C.fenmu = fenmu;
  return C;
}
struct fen subtract(struct fen A,struct fen B)
{
  struct fen C;
  C.neg = false;
  LL a1 = A.fenzi,b1 = A.fenmu;
  LL a2 = B.fenzi,b2 = B.fenmu;
  if(A.neg)
    a1 = -a1;
  if(B.neg)
    a2 = -a2;
  LL fenzi = a1*b2 - a2*b1;
  LL fenmu = b1 * b2;
  if(fenzi < 0)
  {
    C.neg = true;
    fenzi = -fenzi;
  }
  LL k =  gcd(fenzi,fenmu);
  fenzi /= k;
  fenmu /= k;
  C.fenzi = fenzi;
  C.fenmu = fenmu;
  return C;
}
struct fen multi(struct fen A,struct fen B)
{
  struct fen C;
  C.neg = false;
  LL a1 = A.fenzi,b1 = A.fenmu;
  LL a2 = B.fenzi,b2 = B.fenmu;
  if(A.neg)
    a1 = -a1;
  if(B.neg)
    a2 = -a2;
  LL fenzi = a1 * a2;
  LL fenmu = b1 * b2;
  if(fenzi < 0)
  {
    C.neg = true;
    fenzi = -fenzi;
  }
  LL k =  gcd(fenzi,fenmu);
  fenzi /= k;
  fenmu /= k;
  C.fenzi = fenzi;
  C.fenmu = fenmu;
  return C;
}
struct fen divide(struct fen A,struct fen B)
{
  struct fen C;
  C.neg = false;
  LL a1 = A.fenzi,b1 = A.fenmu;
  LL a2 = B.fenzi,b2 = B.fenmu;
  if(A.neg)
    a1 = -a1;
  if(B.neg)
    a2 = -a2;
  LL fenzi = a1 * b2;
  LL fenmu = b1 * a2;
  if(fenzi < 0)
  {
    fenzi = -fenzi;
    C.neg = true;
  }
  if(fenmu < 0)
  {
    fenmu = -fenmu;
    if(!C.neg)
      C.neg = true;
    else
      C.neg = false;
  }
  if(fenmu == 0)
  {
    C.flag = 1;
    return C;
  }
  long int k =  gcd(fenzi,fenmu);
  fenzi /= k;
  fenmu /= k;
  C.fenzi = fenzi;
  C.fenmu = fenmu;
  return C;
}

void print(struct fen A)
{
  LL c1 = A.fenzi / A.fenmu;
  if(A.fenmu == 1)
  {
    if(!A.neg)
      printf("%ld",A.fenzi);
    else
      printf("(-%ld)",A.fenzi);
   }
  else
  {
    if(c1 != 0)
    {
      if(!A.neg)
        printf("%ld %ld/%ld",c1,A.fenzi%A.fenmu,A.fenmu);
      else
        printf("(-%ld %ld/%ld)",c1,A.fenzi%A.fenmu,A.fenmu);
    }
    else
    {
      if(!A.neg)
        printf("%ld/%ld",A.fenzi,A.fenmu);
      else
        printf("(-%ld/%ld)",A.fenzi,A.fenmu);
    }
  }
}

int main()
{
  LL a1,b1,a2,b2;
  char s1[20],s2[20];
  scanf("%s %s",s1,s2);
  sscanf(s1,"%ld/%ld",&a1,&b1);
  sscanf(s2,"%ld/%ld",&a2,&b2);
  struct fen A,B;
  A.neg = B.neg = false;
  if(a1 < 0)
  {
    a1 = -a1;
    A.neg = true;
  }
  if(a2 < 0)
  {
    B.neg = true;
    a2 = -a2;
  }
  LL gcd1 = gcd(a1,b1);
  LL gcd2 = gcd(a2,b2);
  a1 /= gcd1;
  b1 /= gcd1;
  a2 /= gcd2;
  b2 /= gcd2;
  A.fenzi = a1;
  A.fenmu = b1;
  B.fenzi = a2;
  B.fenmu = b2;
  struct fen add = addition(A,B);
  struct fen sub = subtract(A,B);
  struct fen mul = multi(A,B);
  struct fen div = divide(A,B);
  char ch[4] = {'+','-','*','/'};
  struct fen res[4] = {add,sub,mul,div};
  for(int i = 0; i < 3; i++)
  {
    print(A);
    printf(" %c ",ch[i]);
    print(B);
    printf(" = ");
    struct fen C = res[i];
    print(C);
    printf("\n");
  }
  struct fen C = res[3];
  print(A);
  printf(" / ");
  print(B);
  printf(" = ");
  if(C.flag == 1)
    printf("Inf");
  else
    print(C);
  printf("\n");
  return 0;
}
