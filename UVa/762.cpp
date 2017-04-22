//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

vector<int> ar[50000];
queue<int>Q;
map<string,int>Si;
map<int,string>Is;

int vis[300][300];
int P[50000];

void path(int ds,char ss[])
{
    if(P[ds]==-1)
        return;
    path(P[ds],ss);
    if(ds!=Si[ss])
    cout<<Is[P[ds]]<<" "<<Is[ds]<<endl;
}
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,dis[5000];
    char wd[50],st[3][20],ss[20],ds[20];
      //scanf("%d",&t);

      while(scanf("%d",&n)==1)
      {

         for(i=0,j=1;i<n;i++)
         {
             scanf("%s %s",&st[0],&st[1]);
             if(Si[st[0]]==0)
               {
                    Si[st[0]]=j;
                  //  pf("%d\n",r);
                  Is[j]=st[0];j++;
               }
             if(Si[st[1]]==0)
                {
                    Si[st[1]]=j;
                   Is[j]=st[1];j++;
               }
             ar[Si[st[0]]].push_back(Si[st[1]]);
             ar[Si[st[1]]].push_back(Si[st[0]]);
         }

         scanf("%s %s",&ss,&ds);
         if(Si[ss]==0)
               {
                    Si[ss]=j;
                  //  pf("%d\n",r);
                  Is[j]=ss;j++;
               }
             if(Si[ds]==0)
                {
                    Si[ds]=j;
                   Is[j]=ds;j++;
               }

         h=j;
         for(i=0;i<=j;i++)
            {
                dis[i]=N;
            }
         Q.push(Si[ss]);dis[Si[ss]]=0;P[Si[ss]]=-1;
          while(!Q.empty())
          {
              a=Q.front();
              Q.pop();
              for(k=0,j=ar[a].size();k<j;k++)
              {
                  b=ar[a][k];
                  if(dis[b]>dis[a]+1)
                  {
                      dis[b]=dis[a]+1;
                      P[b]=a;
                      Q.push(b);
                  }
              }
          }
          if(r!=1)
          pf("\n");
         if(dis[Si[ds]]==N)
         pf("No route\n");
         else
            path(Si[ds],ss);
            r++;
         Is.clear();Si.clear();
          for(i=0;i<=h;i++)
            {
                ar[i].clear();
            }

      }
    return 0;
}


