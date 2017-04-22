//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
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
char x[10000],y[10000];
}ar[102];

char st[10000],ss[10000];

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  //   ;
   int vis[205];
     while(sn("%d",&n)==1)
     {
         t=0;
         if(n==0)
            break;
         int mx=0;
         memset(vis,0,sizeof(vis));
         for(i=0;i<n;i++)
         {
             sn("%s %s",&st,&ss);
             a=strlen(st);
             b=strlen(ss);
             st[a-1]='\0';
             ss[b-1]='\0';
             a=strlen(st);
             b=strlen(ss);
             for(j=0;j<a;j++)
               st[j]=st[j+1];
             for(j=0;j<b;j++)
                ss[j]=ss[j+1];
            a=strlen(st);
            b=strlen(ss);
             strcpy(ar[i].x,st);
             strcpy(ar[i].y,ss);

             for(j=0;j<b;j++)
             {
                 if(ss[j]>mx)mx=ss[j];
             }
             for(j=0;j<b;j++)
             {
                 if(st[j]!=ss[j])
                    break;
             }
             if(j!=b||b>a)
             {
                 t=-1;
             }
             else if(b<a)
             {
                 vis[st[b]]=1;
             }
         }
         if(t==0)
         for(i=0;i<n;i++)
         {
             a=strlen(ar[i].x);
             b=strlen(ar[i].y);
             for(j=0;j<a;j++)
             {
                 if(vis[ar[i].x[j]]==1)
                 {
                     ss[j]='\0';
                     break;
                 }
                 ss[j]=ar[i].x[j];
             }
             ss[j]='\0';
             if(strcmp(ar[i].y,ss)!=0)
             {
                 t=-1;
             }
         }
        pf("Case %d: ",cs++);
        if(t==0)
        {
            j=0;
            int mn=200;
            for(i='0';i<='9'&&i<=mx;i++)
            {
                if(vis[i]==0)
                {
                    ss[j++]=i;
                }
            }
            for(i='A';i<='Z'&&i<=mx;i++)
            {
                if(vis[i]==0)
                {
                    ss[j++]=i;
                }
            }
            for(i='a';i<='z'&&i<=mx;i++)
            {
                if(vis[i]==0)
                {
                    ss[j++]=i;
                }
            }
            ss[j]='\0';
            l=strlen(ss);
            if(l==0)
            {
                mn=200;
               for(i='0';i<='9';i++)
               {
                   if(vis[i]==0&&i<mn)
                    {
                        mn=i;break;
                    }
               }
               for(i='A';i<='Z';i++)
               {
                   if(vis[i]==0&&i<mn)
                    {
                        mn=i;break;
                    }
               }
               for(i='a';i<='z';i++)
               {
                   if(vis[i]==0&&i<mn)
                    {
                        mn=i;break;
                    }
               }
               if(mn==200)
                pf("I_AM_UNDONE\n");
               else
                pf("[%c]\n",mn);
            }
            else
            {
                pf("[%s]\n",ss);
            }
        }
        else
        {
            pf("I_AM_UNDONE\n");
        }
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

