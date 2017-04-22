//BISMILLAHIR RAHMANIR RAHIM
//#include <bits/stdc++.h>
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
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll left[30005],right[30005],ar[30005];
int main()
{
    ll i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            left[i]=right[i]=i;
        }
        for(i=1;i<n;i++)
        {
            j=i-1;
            while(ar[j]>=ar[i])
            {
                left[i]=left[j];
                if(j==0)
                    break;
                if(j==left[j])
                   j--;
                else
                  j=left[j];
            }
        }
         for(i=n-2;i>=0;i--)
        {
            j=i+1;
            while(ar[j]>=ar[i])
            {
                right[i]=right[j];
                if(j==n-1)
                    break;
                if(j==right[j])
                   j++;
                else
                   j=right[j];
            }
        }
        ll ans=0;
        for(i=0;i<n;i++)
        {
            ans=max(ans,ar[i]*(right[i]-left[i]+1));
        }
        printf("Case %lld: %lld\n",r++,ans);
    }
    return 0;
}

