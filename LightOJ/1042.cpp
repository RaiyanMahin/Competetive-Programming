#include<stdio.h>
long long int dec(long long int ar[],int j)
{
    long long int i,l=0,tw=1;
    for(i=j-1;i>=0;i--)
    {
        l=l+ar[i]*tw;
        tw*=2;
    }
    return l;
}
int main()
{
    long long int i,j,k,a,b,l,t,r,tw,m,q,w,ma,n,ar[1000],tem[1000],cs,ans;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld",&n);
        i=0;m=n;
        while(m!=0)
        {
            tem[i++]=m%2;
            m/=2;
        }
        for(j=i-1,k=0;j>=0;j--)
        ar[k++]=tem[j];
        ans=0;
        for(i=k-1;i>=0;i--)
        {

            if(ar[i]==1)
            {
                for(j=i-1;j>=0;j--)
                {
                    if(ar[j]==0)
                    {
                        m=ar[i];
                        ar[i]=ar[j];
                        ar[j]=m;
                        ans=dec(ar,k);
                    }

                    if(ans>n)
                    {
                        for(a=k-1;a>j;a--)
                        {
                            if(ar[a]==0)
                            {
                                for(b=a-1;b>j;b--)
                                {
                                    if(ar[b]==1)
                                    {
                                        ar[b]=0;
                                        ar[a]=1;q=dec(ar,k);
                                        if(q>n&&q<ans)
                                            ans=q;

                                            break;
                                    }

                                }
                            }
                        }
                    }
                    if(ans>n)
                        break;
                }

            }
            if(ans>0)
               break;
        }
         if(ans==0)
         {
            ar[k]=0;
            k++;
            ans=dec(ar,k);
                for(a=k-1;a>1;a--)
                        {
                            if(ar[a]==0)
                            {
                                for(b=a-1;b>0;b--)
                                {
                                    if(ar[b]==1)
                                    {
                                        ar[b]=0;
                                        ar[a]=1;q=dec(ar,k);
                                        if(q>n&&q<ans)
                                            ans=q;

                                            break;
                                    }

                                }
                            }
                        }
                    }

            printf("Case %lld: %lld\n",r,ans);
    }
    return 0;
}

