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


int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,x,y,C[]={0,0,1,-1,1},R[]={1,-1,1,-1,0};
    char wd[50],st[200][200];
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%s",&st[i]);
        while(scanf("%s",&wd))
        {
            if(wd[0]=='0')
            break;
            c=0;
            for(i=0;i<n;i++)
            {
                for(j=0,k=strlen(st[i]);j<k;j++)
                {
                    if(st[i][j]==wd[0])
                    for(a=0;a<5;a++)
                    {
                        x=i;y=j;
                        for(b=1;b<strlen(wd);b++)
                        {
                           x+=C[a];y+=R[a];
                           if(x>=0&&y>=0&&x<n&&y<strlen(st[x])&&st[x][y]==wd[b]);
                           else
                            break;
                        }

                         if(b==strlen(wd))
                        {
                            printf("%d,%d %d,%d\n",i+1,j+1,x+1,y+1);
                            a=5;j=k;i=n;c=23;
                        }
                    }

                }
            }
            if(c==0)
                printf("Not found\n");
        }
    }
    return 0;
}



