//BISMILLAHIR  RAHMINIR RAHIM

 #include<stdio.h>
#include<string.h>
int ar[1000000];
int main()
{
    int i,j,k,ans,l,m,n,h,t,r,mid;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);m=0;l=0;h=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            ar[i]=k-m;
            h+=ar[i];
            m=k;
            l=(ar[i]>l)?ar[i]:l;
        }
        mid=(h+l)/2;
        while(l<=h)
        {
            ans=mid;
            for(i=0;i<n;i++)
            {
                if(ans<ar[i])
                    {
                        ans=-1;break;
                    }
                if(ar[i]==ans)
                    ans--;
                if(ans<0)
                    break;

            }
            if(ans>=0)
            {
                ans=mid-1;
                for(i=0;i<n;i++)
               {
                   if(ans<ar[i])
                        {
                            ans=-1;break;
                        }
                    if(ar[i]==ans)
                        ans--;
                    if(ans<0)
                        break;


                }
                if(ans>=0)
                    h=mid-1;
                else
                    break;
            }
            else
                l=mid+1;
            mid=(l+h)/2;
        }
        printf("Case %d: %d\n",r,mid);
    }
    return 0;
}
