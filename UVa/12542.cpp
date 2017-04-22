#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 100000
int ar[N]={0};
int main()
{
    int i,j,k,n,l,m,a,b;
    ar[0]=1;ar[1]=1;
    char st[260];
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    while(scanf("%s",&st)!=EOF)
    {
        l=strlen(st);k=0;
        if(strcmp(st,"0")==0)
            break;
        for(i=0;i<l;i++)
        {
            m=0;
            for(j=i;j<l;j++)
            {
                m=m*10+(st[j]-'0');
                if(m<=100000)
                {
                   if((ar[m]==0&&m%2==1)||m==2)
                   {
                       if(m>k)
                        k=m;
                   }
                }
                else
                    break;
            }
        }
        if(k>0)
        printf("%d\n",k);
    }
    return 0;
}
