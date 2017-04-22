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
typedef long long int ll;
using namespace std;

vector<ll>ar[100000];
vector<ll>cost[100000];
ll mx,node,vis[100000];
void treedia(int n,int c)
{
    vis[n]=1;
    if(c>mx)
    {
        mx=c;node=n;
    }
    int i,j,k=ar[n].size();
    for(i=0;i<k;i++)
    {
        j=ar[n][i];
        if(vis[j]==0)
        treedia(j,cost[n][i]+c);
    }
}

int main()
{
    ll i=0,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h;
      char st[100],*cp;

      while(gets(st))
      {
          i=0;j=0;d=0;
           if(strlen(st)>4)
           {
                cp=strtok(st," ");
          while(cp!=NULL)
          {
              if(j==0)
               a=atoi(cp);
              if(j==1)
              b=atoi(cp);
              if(j==2)
              c=atoi(cp);
              d=a;
              j++;
              cp=strtok(NULL," ");
          }
          ar[a].push_back(b);
          ar[b].push_back(a);
          cost[a].push_back(c);
          cost[b].push_back(c);
          i++;
          while(gets(st)&&st[0])
          {
               i=0;j=0;
              cp=strtok(st," ");
              while(cp!=NULL)
              {
                  if(j==0)
                   a=atoi(cp);
                  if(j==1)
                  b=atoi(cp);
                  if(j==2)
                  c=atoi(cp);
                  j++;
                  cp=strtok(NULL," ");
              }
              ar[a].push_back(b);
             ar[b].push_back(a);
             cost[a].push_back(c);
            cost[b].push_back(c);
              i++;
          }

           }
          n=i;
          memset(vis,0,sizeof(vis));
          mx=0;
         treedia(d,0);
         memset(vis,0,sizeof(vis));
         treedia(node,0);
         pf("%lld\n",mx);
         for(i=1;i<=10000;i++)
           {
                ar[i].clear();
                cost[i].clear();
           }
      }
    return 0;
}



