//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
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
/**
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

typedef long long int ll;
using namespace std;
struct T{
int a;
};
int dp[101][101],ar[105];
int rec(int p,int a,int b,int n)
{
    if(p>=n)
        return 0;
    int &ret=dp[a][b];
    if(ret!=-1)
        return ret;
    ret=rec(p+1,a,b,n);
    if(ar[a]<=ar[p]&&ar[b]>=ar[p])
    {
        ret=max(ret,1+rec(p+1,p,b,n));
        ret=max(ret,1+rec(p+1,a,p,n));
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
           sn("%d",&ar[i+1]);
        }
        ar[0]=0;ar[i+1]=1000000;
        memset(dp,-1,sizeof(dp));
        pf("Case %d: %d\n",cs++,rec(1,0,n+1,n+1));
    }
    return 0;

}

#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
**/
int dp[101][103][103],ar[105];

int rec(int ps,int a,int b,int n)
{
    if(ps>=n)
        return 0;
    int &ret=dp[ps][a][b];
    if(ret!=-1)
        return ret;
    ret=0;
    ret=max(ret,rec(ps+1,a,b,n));
    if(ar[ps]<=ar[b]&&ar[ps]>=ar[a]){
    ret=max(ret,rec(ps+1,a,ps,n)+1);
    ret=max(ret,rec(ps+1,ps,b,n)+1);
    }
    return ret;
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
        }
        memset(dp,-1,sizeof(dp));
        ar[101]=0;ar[102]=1000000;
        pf("Case %d: %d\n",cs++,rec(0,101,102,n));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

