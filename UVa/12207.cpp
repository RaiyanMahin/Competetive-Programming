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
int a;
};
char st[100];
int ar[5005],vis[5005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    while(sn("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)break;
        s=1;c=0;e=0;
        c=min(1000,n);
        for(i=1;i<=c;i++)
        {
            ar[i]=i;
        }
        ar[0]=0;

        map<int,int>vss;
        for(i=0;i<m;i++)
        {
            sn("%s",&st);
            if(st[0]=='N')
            {
                vis[i]=-1;
            }
            else
            {
                sn("%d",&b);
                vis[i]=b;
                if(vss[b]==0&&b>1000)
                {
                    vss[b]=1;
                    ar[++c]=b;
                }
            }
        }
        sort(ar,ar+c+1);
        pf("Case %d:\n",cs++);
        for(i=0;i<m;i++)
        {
            if(vis[i]==-1)
            {
                pf("%d\n",ar[1]);
                a=ar[1];
                for(j=1;j<c;j++)
                {
                    ar[j]=ar[j+1];
                }
                ar[c]=a;
            }
            else
            {
                d=0;
                for(j=c;j>1;j--)
                {
                    if(ar[j]==vis[i])
                        d=vis[i];
                    if(d>0)
                    {
                        ar[j]=ar[j-1];
                    }
                }
                ar[1]=d;
            }
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

