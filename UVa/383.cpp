//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define N 1000004
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
vector<int>ar[N];
queue<int>Q;

int aa[200],dis[N];
int main()
{
    aa['A'-1]=0;aa['A'-2]=0;
    for(int i='A';i<='Z';i++)
    {
        aa[i]=1+aa[i-1]+aa[i-2];
      // printf("%d\n",aa[i]);
    }
    int i,j,k,l,t,r,s,m,n,a,b,c,p,d,e,f,g,h,BB[1000];
    char W[35][5],ch[5],st[5];
    scanf("%d",&t);
   pf("SHIPPING ROUTES OUTPUT\n\n");
    for(r=1;r<=t;r++)
    {
        scanf("%d%d%d",&m,&n,&p);
        for(i=0;i<m;i++)
        {
            sn("%s",W[i]);
        }
        memset(dis,0,sizeof(dis));d=0;
        for(i=0;i<n;i++)
        {
           scanf("%s %s",&st,&ch);
           if(st[0]==st[1])
            st[1]='A'-1;
           if(ch[0]==ch[1])
            ch[1]='A'-1;
           ar[aa[st[0]]+aa[st[1]]].push_back(aa[ch[0]]+aa[ch[1]]);
           ar[aa[ch[0]]+aa[ch[1]]].push_back(aa[st[0]]+aa[st[1]]);

           if(dis[aa[st[0]]+aa[st[1]]]==0)
           {
               BB[d]=aa[st[0]]+aa[st[1]];
                d++;dis[aa[st[0]]+aa[st[1]]]=1;

           }
           if(dis[aa[ch[0]]+aa[ch[1]]]==0)
           {
               BB[d]=aa[ch[0]]+aa[ch[1]];
               d++;dis[aa[ch[0]]+aa[ch[1]]]=1;
           }
        }
        pf("DATA SET %2d\n\n",r);
        for(i=0;i<p;i++)
        {
            scanf("%d %s %s",&b,&st,&ch);
             if(st[0]==st[1])
            st[1]='A'-1;
           if(ch[0]==ch[1])
            ch[1]='A'-1;
         for(k=0;k<N;k++)
            dis[k]=N;
        //  printf("%d %d\n",N,dis[20]);
           dis[aa[st[0]]+aa[st[1]]]=0;
           Q.push(aa[st[0]]+aa[st[1]]);
           while(!Q.empty())
           {
               f=Q.front();
               Q.pop();
               for(j=0,k=ar[f].size();j<k;j++)
               {

                   h=ar[f][j];
                   if(dis[h]>dis[f]+1)
                   {
                       dis[h]=dis[f]+1;
                       Q.push(h);
                   }
               }
           }

           if(dis[ aa[ch[0]]+aa[ch[1]]]==N)
            printf("NO SHIPMENT POSSIBLE\n");
           else
            printf("$%d\n",100*dis[aa[ch[0]]+aa[ch[1]]]*b);
        }
        pf("\n");
        for(i=0;i<d;i++)
            ar[BB[i]].clear();

    }
    pf("END OF OUTPUT\n");
    return 0;
}

