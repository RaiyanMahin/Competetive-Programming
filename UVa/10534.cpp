//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<map>
#define S 1000000

using namespace std;

int dlis[100000],dlds[100000],ar[100000],arr[100000];
int lis[100000];
void LIS(int n)
{
    int md,h,l,i,j,k;
    for(i=0,j=0;i<n;i++)
    {
        if(i==0)
        {
            lis[j]=i;
            dlis[i]=1;
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
                dlis[i]=1;
            }
            else
            {
                lis[md+1]=i;
                dlis[i]=md+1+1;
                if(md+1==j)
                    j++;
            }
        }
    }
}

void LDS(int n)
{
    int md,h,l,i,j,k;
    for(i=0,j=0;i<n;i++)
    {
        if(i==0)
        {
            lis[j]=i;
            dlds[n-1-i]=1;
            j++;
        }
        else
        {
            l=0;h=j-1;
            md=(l+h)/2;
            while(l<=h)
            {
                if(arr[lis[md]]<arr[i])
                {
                    if(md!=j-1&&arr[lis[md+1]]<arr[i])
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
                dlds[n-1-i]=1;
            }
            else
            {
                lis[md+1]=i;
                dlds[n-1-i]=md+1+1;
                if(md+1==j)
                    j++;
            }
        }
    }

}



int main()
{
	int i,j,r,t,m,l,ll,n,p,q;
               //  freopen("Output.txt","w",stdout);
		while(scanf("%d",&n)==1){
		memset(dlis,0,sizeof(dlis));
		memset(dlds,0,sizeof(dlds));

		for(i=0;i<n;i++)
	      	{
	      	    scanf("%d",&ar[i]);
	      	    arr[n-1-i]=ar[i];
	      	}
        m=1;
        LIS(n);LDS(n);
        for(i=0;i<n;i++)
        {
            if((dlis[i]+dlds[i]-abs(dlis[i]-dlds[i])-1)>m)
                m=(dlis[i]+dlds[i]-abs(dlis[i]-dlds[i])-1);
        }
		printf("%d\n",m);
	}
	//fclose(stdout);
	return 0;
}


