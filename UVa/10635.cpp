//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<map>
#define S 1000000

using namespace std;

int s[1000000],ss[1000000];
int vis[1000000],ar[1000000];
int lis[1000000];
int LIS(int n)
{
    int md,h,l,i,j,k;
    for(i=0,j=0;i<n;i++)
    {
        if(i==0)
        {
            lis[j]=i;
            j++;
        }
        else
        {
            l=0;h=j-1;
            md=(l+h)/2;
            while(l<=h)
            {
                if(ar[lis[md]]<ar[i])
                {
                    if(md!=j-1&&ar[lis[md+1]]<ar[i])
                        l=md+1;
                    else
                        break;
                }
                else
                {
                    h=md-1;
                }
                md=(l+h)/2;
            }
            if(l>h)
            {
                lis[0]=i;
            }
            else
            {
                lis[md+1]=i;
                if(md+1==j)
                    j++;
            }
        }
    }
    return j;
}


int main()
{
	int i,j,r,t,m,l,ll,n,p,q;
	scanf("%d",&t);
	for(r=1;r<=t;r++)
	{
		scanf("%d%d%d",&n,&p,&q);
		memset(vis,-1,sizeof(vis));
		l=p+1;ll=q+1;
		for(i=0;i<l;i++)
	      	{
	      	    scanf("%d",&s[i]);
	      	    vis[s[i]]=i;
	      	}
        for(i=0,j=0;i<ll;i++)
	      	{
	      	    scanf("%d",&ss[i]);
	      	    if(vis[ss[i]]>=0)
                    ar[j++]=vis[ss[i]];
	      	}
	      	m=0;
	      	m=LIS(j);
		printf("Case %d: %d\n",r,m);
	}
	return 0;
}
