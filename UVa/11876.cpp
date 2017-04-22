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
#define N 100000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int pr[10000],K,ar[100000],k;
void prime()
{
    memset(ar,0,sizeof(ar));
    int i,j;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }k=1;
    pr[0]=2;
    for(i=3;i<=N;i+=2)
        if(ar[i]==0)
    {
        pr[k++]=i;
    }

}
int divisor(int n)
{
    int i,j,s=1,d=n;
    for(i=0;i<k;i++)
    {
        if(pr[i]>sqrt(d))
            break;
         j=0;
        while(d%pr[i]==0)
        {
            j++;
            d/=pr[i];
        }
        s*=(j+1);
    }
    if(d!=1)
        s*=2;
    return s;
}
void NOD()
{
    int i;
    ar[1]=1;
    for(i=2;;i++)
    {
        ar[i]=ar[i-1]+divisor(ar[i-1]);
        if(ar[i]>1000000)
            break;
    }
    K=i;
}
int binry(int a,int b)
{
    int l,h,md,e,f;
    l=1;h=K;
    while(l<=h)
    {
        md=(l+h)/2;
        if(ar[md]>=a)
        {
            if(md!=1&&ar[md-1]>=a)
                h=md-1;
            else
                break;
        }
        else
            l=md+1;
    }
    e=md;
    l=md;h=K;
     while(l<=h)
    {
        md=(l+h)/2;
        if(ar[md]>=a&&ar[md]<=b)
        {
            if(md!=K&&ar[md+1]<=b)
                l=md+1;
            else
                break;
        }
        else
            h=md-1;
    }
    f=md;
    if(l>h)
        return 0;
    else
        return f-e+1;

}
int main()
{
    int i,j,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
     prime();
     NOD();
//     freopen("Output.txt","r",stdin);
//     freopen("OOO.txt","w",stdout);
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d %d",&a,&b);
         d=binry(a,b);
         printf("Case %d: %d\n",r,d);
     }
    return 0;
}


