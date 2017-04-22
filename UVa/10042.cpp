#include<stdio.h>
#include<math.h>
#define N 1000000
int ar[N]={0},pr[100000];

int sum(int n)
{
    int m=n,s=0;
    while(m!=0)
    {
        s+=m%10;
        m/=10;
    }
    return s;
}

int main()
{
    int i,j,k,kk,l,m,t,r,n;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    pr[0]=2;k=1;
    for(i=3;i<=N;i+=2)
        if(ar[i]==0)
    {
       pr[k]=i;k++;

    }
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        n+=1;
        for(;n>0;n++)
        {
            kk=sum(n);
            l=0;  m=n;
            for(i=0;i<k;i++)
            {

                while(m%pr[i]==0)
                {
                    l+=sum(pr[i]);
                    m/=pr[i];
                    j=pr[i];
                }
                if(m==1||pr[i]>=n)
                    break;
            }
            if(m!=1)
                l+=sum(m);
            if(kk==l&&n!=j&&n!=m)
            {
                printf("%d\n",n);break;
            }


        } if(n==0)
            printf("4\n");
    }
    return 0;
}


