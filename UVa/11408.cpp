//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 5000000
int ar[N]={0};
int dep[N+9]={0},isdp[N],k;

int lower(int n)
{
    int l=0,h=k-1,m;
    m=(l+h)/2;
    while(l<=h)
    {
        if(isdp[m]>=n)
        {
            if(isdp[m]==n)
                break;
            if(m!=0&&isdp[m-1]>=n)
                h=m-1;
            else
                break;
        }
        else
            l=m+1;
    }

    if(l>h)
        return -1;
    else
        return m;
}

int upper(int n)
{
    int l=0,h=k-1,m;
    m=(l+h)/2;
    while(l<=h)
    {
        if(isdp[m]<=n)
        {
            if(isdp[m]==n)
                break;
            if(m!=k-1&&isdp[m+1]<=n)
                l=m+1;
            else
                break;
        }
        else
            h=m-1;
    }

    if(l>h)
        return -1;
    else
        return m;
}


int main()
{
    int i,j,n,a,b,c,d,l,h,m,t;ar[1]=1;ar[0]=1;
    for(i=2;i<=N;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i+i;j<=N;j+=i)
                if(j%i==0)
                {
                    ar[j]=1;
                    dep[j]+=i;
                }
        }
        if(i==2)
            i=1;
    }
    k=0;
   for(i=2;i<=5000000;i++)
     if(ar[i]==0)
   {
       isdp[k++]=i;
   }
   else if(ar[dep[i]]==0)
   {
       isdp[k++]=i;
   }
   while(scanf("%d %d",&a,&b)!=EOF)
   {
       c=lower(a);
       d=upper(b);
       if(c==-1||d==-1);
        else
        printf("%d\n",abs(d-c)+1);
   }
    return 0;

}
