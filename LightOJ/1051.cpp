//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
char st[55];

int l,g,b,dp[51][10][10];
int rec(int p,int v,int c)
{


       if(v>=3||c>=5)
        {
            return 2;
        }
     if(p>=l)
       {
           return 1;
       }
    int &ret=dp[p][v][c];
    if(ret!=-1)
        return ret;

    if(st[p]=='C')
        ret=rec(p+1,0,c+1);
    else if(st[p]=='V')
       ret=rec(p+1,v+1,0);
    else if(st[p]=='?')
    {
          int a=rec(p+1,v+1,0);
          int b=rec(p+1,0,c+1);
          if(a!=b)
            ret=5;
          else ret=a;
    }
   return ret;
}
int main()
{
    int i,j,k,t,r,s,m,n,a,c,d,e,f,h,u,v,w;
      scanf("%d",&t);
      for(r=1;r<=t;r++)
      {
          scanf("%s",&st);
          l=strlen(st);
          for(i=0;i<l;i++)
          {
              if(st[i]!='A'&&st[i]!='E'&&st[i]!='I'&&st[i]!='O'&&st[i]!='U'&&st[i]!='?')
                st[i]='C';
              else if(st[i]=='?');
              else
                st[i]='V';
          }
           memset(dp,-1,sizeof(dp));
           a=rec(0,0,0);

          pf("Case %d: ",r);
          if(a==1)
            pf("GOOD\n");
          else if(a==2)
             pf("BAD\n");
          else
            pf("MIXED\n");
      }
    return 0;
}



