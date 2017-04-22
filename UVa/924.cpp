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

int vis[30000];

int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,mm,md,d,e,f,g,h,dis[5000];
    char wd[50],st[3][20],ss[20],ds[20];

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&a);
                ar[i].push_back(a);
            }
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&d);
            memset(vis,0,sizeof(vis));
            Q.push(d);c=0;h=0;g=0;mm=b=0;vis[d]=1;d=1;
            while(!Q.empty())
            {

                a=Q.front();
                Q.pop();
                for(j=0,k=ar[a].size();j<k;j++)
                {
                    f=ar[a][j];
                    if(vis[f]==0)
                    {
                        vis[f]=1;h++;
                        Q.push(f);
                    }
                }
                if(c==g)
                {
                    if(h>b)
                    {
                        mm=h;b=h;md=d;
                    }
                    d++;g=h;c=0;h=0;
                }
                c++;
            }

            if(mm==0)
                printf("%d\n",mm);
            else
                printf("%d %d\n",mm,md);

        }
        for(i=0;i<n;i++)
                ar[i].clear();
    }

    return 0;
}



