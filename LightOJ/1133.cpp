#include<stdio.h>
#include<string.h>
int main()
{
    long long int i,t,r,a,b,m,n,k,l,j,ar[105],pr[5],tem[105];
    char s[10];
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        for(l=0;l<m;l++)
        {
            scanf("%s",&s);
            if(strcmp(s,"P")==0)
            {
                scanf("%lld %lld",&a,&b);
                k=ar[a];
                ar[a]=ar[b];ar[b]=k;
            }
            else if(strcmp(s,"S")==0)
            {
                scanf("%lld",&a);
                for(i=0;i<n;i++)
                    ar[i]+=a;
            }
            else if(strcmp(s,"D")==0)
            {
                scanf("%lld",&a);
                for(i=0;i<n;i++)
                    ar[i]/=a;
            }
             else if(strcmp(s,"M")==0)
            {
                scanf("%lld",&a);
                for(i=0;i<n;i++)
                    ar[i]*=a;
            }
             else if(strcmp(s,"R")==0)
            {
                for(i=0;i<n;i++)
                    tem[i]=ar[i];
                for(i=n-1,j=0;i>=0;i--,j++)
                    ar[j]=tem[i];
            }
        }
        printf("Case %lld:\n",r);
        for(i=0;i<n;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%lld",ar[i]);
        }
        printf("\n");
    }
    return 0;
}
