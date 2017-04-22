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
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

ll dp[1003][1003],dpp[1001];

int main()
{
    ll i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    char st[1000],*cp;
    memset(dp,0,sizeof(dp));
    memset(dpp,0,sizeof(dpp));
    dpp[0]=1;dp[0][0]=1;
    for(i=1;i<=500;i++)
    {
        for(j=i;j<=500;j++)
        {
            if(dpp[j-i]!=0)
            {
                dpp[j]+=dpp[j-i];
                dp[j][i]+=dpp[j-i];
            }
        }
    }

    while(gets(st))
    {
        a=-1,b=-1,c=-1;
        cp=strtok(st," ");
        j=0;
        while(cp!=NULL)
        {
            if(j==0)
                a=atoll(cp);
            else if(j==1)
                b=atoll(cp);
            else if(j==2)
                c=atoll(cp);
            j++;
            cp=strtok(NULL," ");
        }

       if(a==0)
       {
           if((j==3&&b==0)||(j==2)||j==1)
            printf("1\n");
           else
            printf("0\n");
       }
      else if(j==1)
        {
            printf("%lld\n",dpp[a]);
        }
        else if(j==2)
        {
            d=0;
            for(i=1;i<=b;i++)
             d+=dp[a][i];
            printf("%lld\n",d);
        }
        else if(j==3)
        {
            d=0;
            for(i=b;i<=c;i++)
                d+=dp[a][i];
            printf("%lld\n",d);
        }

    }
    return 0;
}

