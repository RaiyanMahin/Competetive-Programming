
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
#include<iostream>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
struct T{
int x,y;
}temp;
vector<T>arr[200];
int p,n,m,R[]={0,0,0,1,-1,-1,1,-1,1},C[]={0,1,-1,0,0,-1,-1,1,1};
vector<string>ans;
char st[50][50],nam[30],ss[][5]={"*","R","L","D","U","UL","DL","UR","DR"};

void dfs(int x,int y,int l,int ln)
{
    int i,j,xx,yy;
    for(i=0;i<9;i++)
    {
        xx=x+R[i];yy=y+C[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&st[xx][yy]==nam[l])
        {
            ans.push_back(ss[i]);
            if(l+1==ln||p==1)
                p=1;
            else
             dfs(xx,yy,l+1,ln);
             if(p==0)
                ans.pop_back();
        }
    }
}
int main()
{
    int i,j,k,q,l,t,r,s,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
       scanf("%d %d",&n,&m);
       for(i=0;i<n;i++)
       {
           scanf("%s",&st[i]);
           for(j=0;j<m;j++)
           {
               temp.x=i;
               temp.y=j;
               arr[st[i][j]].push_back(temp);
           }
       }
       printf("Case %d:\n",r);
       scanf("%d",&q);
       while(q--)
       {
           scanf("%s",&nam);
           l=strlen(nam);h=0;p=0;
           for(i=0;i<l;i++)
            if(arr[nam[i]].size()==0)
           {
               p=0;h=1;break;
           }
           if(h==0)
           {
               j=arr[nam[0]].size();
               for(i=0;i<j;i++)
               {
                   p=0;ans.clear();
                   dfs(arr[nam[0]][i].x,arr[nam[0]][i].y,1,l);
                   if(p==1)
                   {
                      printf("%s found: (%d,%d)",nam,arr[nam[0]][i].x+1,arr[nam[0]][i].y+1);
                      for(k=0,b=ans.size();k<b;k++)
                        cout<<", "<<ans[k];
                      pf("\n");
                      break;
                   }
               }
           }
           if(p==0)
            printf("%s not found\n",nam);
          for(i='A';i<='Z';i++)
            arr[i].clear();
       }
    }
    return 0;
}
