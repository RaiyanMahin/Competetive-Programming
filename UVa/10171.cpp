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
#define Inf 200000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

int ar[1000][1000];
vector<int>cost[1000];
queue<int>Q;
map<char,int>Si;
map<int,string>Is;
int Mdis[105][105],Ydis[105][105],Ma[105][105],Ya[105][105];


int main()
{
    int i,j,k,l,r=1,n,m,s,sc,d,dc,a,b,E;
    char ch,M,D,A,B;
    for(ch='A',i=1;ch<='Z';ch++,i++)
    {
        Si[ch]=i;
    }
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        memset(Ma,0,sizeof(Ma));
        memset(Ya,0,sizeof(Ya));
        for(i=1;i<=30;i++)
        {
            for(j=1;j<=30;j++)
            {
                Mdis[i][j]=Ydis[i][j]=Inf;
                if(i==j)
                    Mdis[i][j]=Ydis[i][j]=0;
            }
        }
        getchar();
        for(i=0;i<n;i++)
        {

            scanf("%c %c %c %c %d\n",&M,&D,&A,&B,&E);

            if(D=='U')
                {
                     if(M=='Y')
                         {
                              Ya[Si[A]][Si[B]]=1;
                              if(Ydis[Si[A]][Si[B]]>E)
                               Ydis[Si[A]][Si[B]]=E;
                         }
                      if(M=='M')
                        {

                      Ma[Si[A]][Si[B]]=1;
                      if(Mdis[Si[A]][Si[B]]>E)
                          Mdis[Si[A]][Si[B]]=E;
                        }

                }
            if(D=='B')
            {
                if(M=='Y'){
                Ya[Si[A]][Si[B]]=Ya[Si[B]][Si[A]]=1;
                if(Ydis[Si[A]][Si[B]]>E)
                               Ydis[Si[A]][Si[B]]=E;
                if(Ydis[Si[B]][Si[A]]>E)
                               Ydis[Si[B]][Si[A]]=E;
                //Ydis[Si[A]][Si[B]]=Ydis[Si[B]][Si[A]]=E;
                }
                      if(M=='M'){
                        Ma[Si[A]][Si[B]]=Ma[Si[B]][Si[A]]=1;
                        //Mdis[Si[A]][Si[B]]=Mdis[Si[B]][Si[A]]=E;
                         if(Mdis[Si[A]][Si[B]]>E)
                               Mdis[Si[A]][Si[B]]=E;
                        if(Mdis[Si[B]][Si[A]]>E)
                               Mdis[Si[B]][Si[A]]=E;}

            }


        }
        scanf("%c %c",&A,&B);


        for(k=1;k<=26;k++)
        {
            for(i=1;i<=26;i++)
            {
                for(j=1;j<=26;j++)
                {
                    if(Ydis[i][j]>Ydis[i][k]+Ydis[k][j])
                        Ydis[i][j]=Ydis[i][k]+Ydis[k][j];
                }
            }
        }
        for(k=1;k<=26;k++)
        {
            for(i=1;i<=26;i++)
            {
                for(j=1;j<=26;j++)
                {
                    if(Mdis[i][j]>Mdis[i][k]+Mdis[k][j])
                        Mdis[i][j]=Mdis[i][k]+Mdis[k][j];
                }
            }
        }

     l=Inf-10;
        for(i=1;i<=26;i++)
        {
            s=0;
              //  pf(" %d %d\n",dis[Si[A]][i],dis[Si[B]][i]);
                s=Ydis[Si[A]][i]+Mdis[Si[B]][i];
                if(s<l)
                    l=s;
        }
        if(l==Inf-10)
            printf("You will never meet.\n");
        else
         {
             pf("%d",l);
             for(i=1;i<=26;i++)
           {
                s=0;
                s=Ydis[Si[A]][i]+Mdis[Si[B]][i];
                if(s==l)
                    pf(" %c",i-1+'A');

          }
          pf("\n");
         }
    }
    return 0;
}



