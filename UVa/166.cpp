
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

int Min(int a,int b)
{
    return a>b?b:a;
}

int ar[]={5,10,20,50,100,200,-5,-10,-20,-50,-100,-200},dpp[50000],dp[50000];
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v,br[10000];
    double ff;
  //  freopen("output.txt","w",stdout);
    while(1)
    {
        s=0;m=0;
        for(i=0;i<6;i++)
        {
            scanf("%d",&a);
            for(k=1;k<=a&&k*ar[i]<=1500;k++)
            {
                br[m]=k*ar[i];
                dp[m]=k;m++;
            }
            s+=a;
        }

        if(s==0)
            break;
        scanf("%lf",&ff);

        n=(int)(ff*100.0);
        if(n%5!=0)
            n=((n+1)%5==0)?n+1:n-1;
        for(i=0;i<=10000-1;i++)
        {
            dpp[i]=10000;
        }
        dpp[0]=0;
        for(i=0;i<m;i++)
        {
            for(j=1500;j>=br[i];j--)
            {
                if(dpp[j-br[i]]!=10000)
                {
                    dpp[j]=Min(dpp[j],dpp[j-br[i]]+dp[i]);
                }
            }
        }
        for(i=6;i<12;i++)
        {
            for(j=(ar[i]>0)?ar[i]:-ar[i];j<=1500;j++)
            {
                if(dpp[j-ar[i]]!=10000)
                {
                    dpp[j]=Min(dpp[j-ar[i]]+1,dpp[j]);
                }
            }
        }

        printf("%3d\n",dpp[n]);
    }
  //  fclose(stdout);
    return 0;
}

