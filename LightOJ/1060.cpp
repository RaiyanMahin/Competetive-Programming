//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<set>
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
ll ar[21],vis[200];
char st[21];
vector<int>unq;
void permut()
{
   ll i;
   ar[0]=1;
   for(i=1;i<=20;i++)
   {
       ar[i]=ar[i-1]*i;
   }
}

ll cal(int i,int j,int l)
{
    ll a,b,s=1;
    for(a=0;a<unq.size();a++)
    {
        int c=unq[a];
         b=vis[c];
        if(a==j&&b>0)
            b--;
        s=s*ar[b];
    }
    if(s==0)
        s=1;
    return ar[l-i-1]/s;
}
int main()
{
    int i,j,k,l,t,r;
    ll s,m,n,a,b,c,d,e,f,g,h,u,v;
    permut();
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%s %lld",st,&n);
        l=strlen(st);
        memset(vis,0,sizeof(vis));
        for(i=0;i<l;i++)
        {
            vis[st[i]]++;
        }
        for(i='a';i<='z';i++)
        {
            if(vis[i]>0)
            unq.push_back(i);
        }
        v=cal(-1,23,l);
        if(v<n)
            printf("Case %d: Impossible\n",r);
        else
        {
            printf("Case %d: ",r);
            u=0;
        for(i=0;i<l;i++)
        {
            for(j=0;j<unq.size();j++)
            {
                if(vis[unq[j]]>0)
                {
                    v=cal(i,j,l);
                    u+=v;
                    if(n<=u)
                    {
                       pf("%c",unq[j]);
                       vis[unq[j]]--;
                       u=u-v;
                       break;
                    }
                }
            }
        }
        pf("\n");
        }
        unq.clear();
    }
    return 0;
}

