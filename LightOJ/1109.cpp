#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define N 1005
using namespace std;
int ar[N]={0},pr[1000];
struct T{
 int a;
 int b;

}a[1001];
bool cmp(T x,T y)
{
    if(x.b==y.b)
        return x.a>y.a;
    return x.b<y.b;
}

int divisor(int n)
{
    int m=n,i,j,d=1;
    if(n==1)
        return 1;
    if(ar[n]==0&&n%2==1)
        return 2;
    for(i=0;i<=168;i++)
    {
        if(m==1)
            return d;
            j=1;
        while(m%pr[i]==0)
        {
            j++;m/=pr[i];
        }
        d=d*j;
    }
}
int main()
{
    int i,j,k,m,n,t,r;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }
    }
    k=1;pr[0]=2;
    for(i=3;i<=N;i+=2)
        if(ar[i]==0)
    {
        pr[k++]=i;
    }

    for(i=1;i<=1000;i++)
    {
        a[i-1].a=i;
        a[i-1].b=divisor(i);
    }
    sort(a,a+1000,cmp);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
         printf("Case %d: %d\n",r,a[n-1].a);

    }
 return 0;
}
