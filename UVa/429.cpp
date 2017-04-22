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

vector<int> ar[500];
queue<int>Q;
map<string,int>Si;

int vis[300][300];

int cheak(char a[],char b[])
{
    int k;
    for(int i=k=0;i<strlen(a);i++)
    {
        if(a[i]!=b[i])
            k++;
    }
    return k;
}


int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,dis[500];
    char wd[50],st[300][20],ss[3][20],*CP;
      scanf("%d",&t);
      while(t--)
      {
          i=0;
           while(1)
           {
              // cin>>st[i];
              scanf("%s",&st[i]);
               if(st[i][0]=='*')
                break;
                Si[st[i]]=i+1;
                ar[i].clear();
              i++;
           }
           n=i;memset(vis,0,sizeof(vis));
           for(i=0;i<n;i++)
           {
               for(j=0;j<n;j++)
               {
                  if(strlen(st[i])==strlen(st[j])&&cheak(st[i],st[j])==1&&vis[i][j]==0)
                  {
                     vis[i][j]=vis[j][i]=1;
                     ar[Si[st[i]]].push_back(Si[st[j]]);
                     ar[Si[st[j]]].push_back(Si[st[i]]);
                  }
               }
           }
           getchar();

         while(gets(wd)&&wd[0])
           {
               i=0;
              CP=strtok(wd," ");
              while(CP!=NULL)
              {
                  strcpy(ss[i],CP);
                  CP=strtok(NULL," ");
                  i++;
              }
              for(i=0;i<=n;i++)
                dis[i]=N;
              Q.push(Si[ss[0]]);dis[Si[ss[0]]]=0;
              while(!Q.empty())
              {
                  a=Q.front();
                  Q.pop();
                  for(k=0,j=ar[a].size();k<j;k++)
                  {
                     if(dis[ar[a][k]]>dis[a]+1)
                     {
                         b=ar[a][k];
                         dis[b]=dis[a]+1;
                         Q.push(b);
                     }
                  }
              }

              printf("%s %s %d\n",ss[0],ss[1],dis[Si[ss[1]]]);
           }
           if(t!=0)
            pf("\n");
      }
    return 0;
}

