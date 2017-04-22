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
ll MD;
 ll mode(ll a)
 {
     return a%MD;
 }
 ll A[7][7],B[7][7],aa[7][7];
 void Matrix_expo(ll n,ll m)
{
    ll i,j,k,s;
    if(n<=1) return;
    if(n%2)
    {
        Matrix_expo(n-1,m);
    }
    else
    {
        Matrix_expo(n/2,m);
    }
    if(n%2)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                s=0;
                for(k=0;k<m;k++)
                {

                    s=mode(s+mode(mode(A[i][k])*mode(B[k][j])));
                }
                aa[i][j]=s;
            }
        }
    }
    else
    {
         for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                s=0;
                for(k=0;k<m;k++)
                {
                    s=mode(s+mode(mode(A[i][k])*mode(A[k][j])));
                }
                aa[i][j]=s;
            }
        }
    }
     for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                A[i][j]=aa[i][j];
            }
        }
}


int main()
{
    ll i,j,k,l,t,r,s,m,n,a1,b1,c1,a2,b2,c2,d,e,f,g,h,u,v,bb[7];
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {


        scanf("%lld %lld %lld",&a1,&b1,&c1);
        scanf("%lld %lld %lld",&a2,&b2,&c2);
        ll bbb[10];
        j=0;
        for(i=2;i>=0;i--)
            scanf("%lld",&bb[i]),bbb[j++]=bb[i];
            for(i=5;i>=3;i--)
            scanf("%lld",&bb[i]),bbb[j++]=bb[i];
            scanf("%lld",&MD);
            ll q;
           scanf("%lld",&q);
           printf("Case %lld:\n",r);
           for(m=0;m<q;m++)
           {
            memset(A,0,sizeof(A));
            scanf("%lld",&n);
            A[0][0]=a1,A[0][1]=b1,A[0][5]=c1;
            A[1][0]=1,A[2][1]=1;
            A[3][2]=c2,A[3][3]=a2,A[3][4]=b2;
            A[4][3]=1,A[5][4]=1;
        for(i=0;i<6;i++)
        {
            for(j=0;j<6;j++)
            {
                B[i][j]=A[i][j];
            }
        }
          if(n>2)
            Matrix_expo(n-2,6);
            ll s1=0,s2=0;
        for(k=0;k<6;k++)
        {
            s1=mode(s1+mode((A[0][k]*bb[k])));
            s2=mode(s2+mode((A[3][k]*bb[k])));
        }

        if(n<3)
        {
            s1=bb[2-n];s2=bb[5-n];
        }


        printf("%lld %lld\n",s1%MD,s2%MD);

     }

    }
    return 0;
}

