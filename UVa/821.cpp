
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
#define N 100000000
#define Inf 1<<27
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

vector<int>ar[1000];
vector<int>cost[1000];
queue<int>Q;
map<string,int>Si;
map<int,string>Is;
int P[1000],dis[105][105];


int main()
{
    int i,j,k,l,r=1,n,m,s,sc,d,dc,a,b;
    while(1)
    {
        for(i=0;i<=100;i++)
        {
            for(j=0;j<=100;j++)
            {
                dis[i][j]=Inf;
                if(i==j)
                    dis[i][j]=0;
            }
        }
        memset(P,0,sizeof(P));
        sn("%d %d",&n,&m);
        if(n==0&&m==0)
            break;
         d=(n>m)?n:m;
         P[n]=P[m]=1;
         dis[n][m]=1;
        while(1)
        {
            sn("%d%d",&n,&m);
            if(n>d)
                d=n;
            if(m>d)
                d=m;
            if(n==0&&m==0)
                break;
               P[n]=P[m]=1;
            dis[n][m]=1;
        }
        for(k=1;k<=d;k++)
        {
            for(i=1;i<=d;i++)
            {
                for(j=1;j<=d;j++)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
        l=0;s=0;
        for(i=1;i<=d;i++)
        {
            if(P[i]==1)
            {
                for(j=1;j<=d;j++)
            {
                if(P[j]==1)
                {
                   s+=dis[i][j]; l++;
                }
            }
                l--;
            }
        }
        pf("Case %d: average length between pages = %.3lf clicks\n",r++,double(s)/double(l));
    }
    return 0;
}








