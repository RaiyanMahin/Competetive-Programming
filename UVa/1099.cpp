
//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
//#include<pair>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define Inf  1<<30
#define mp make_pair
typedef long long int ll;
using namespace std;
struct T{
int a;
};
vector<int>ar[5005];
vector<int>ct[5005];
priority_queue< pair<int,int> >Q;
pair<int,int>temp,dis[5005];
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    while(t--)
    {
        double cl=clock();
        scanf("%d %d",&n,&m);
        while(m--)
        {
            scanf("%d %d %d",&u,&v,&c);
            ar[u].pb(v);
            ct[u].pb(c);
            ct[v].pb(c);
            ar[v].pb(u);
        }
        for(i=0;i<=n;i++)
            dis[i]=mp(Inf,Inf);
        dis[1]=mp(0,Inf);
        Q.push(mp(1,0));
        while(!Q.empty())
        {
            temp=Q.top();Q.pop();
            u=temp.first;
            c=temp.second;
            e=dis[u].second;
            for(i=0,j=ar[u].size();i<j;i++)
            {
                v=ar[u][i];
                d=ct[u][i];
                a=dis[v].first;
                b=dis[v].second;
                if(b>c+d&&a!=c+d)
                {
                    if(a<c+d)
                    {
                        b=c+d;
                    }
                    else
                    {
                        b=a;
                        a=c+d;
                    }
                    dis[v]=mp(a,b);
                    Q.push(mp(v,a));
                }
                a=dis[v].first;
                b=dis[v].second;
                if(b>e+d&&a!=e+d)
                {
                    if(a<e+d)
                    {
                        b=e+d;
                    }
                    else
                    {
                        b=a;
                        a=e+d;
                    }
                    dis[v]=mp(a,b);
                    Q.push(mp(v,a));
                }
            }
        }
       printf("Case %d: %d\n",r++,dis[n].second);
       cl=clock()-cl;
     //  pf("Execution Time : %lf\n",cl/CLOCKS_PER_SEC);
       for(i=0;i<=n;i++)
       {
           ar[i].clear();
           ct[i].clear();
       }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);

  using namespace std;

  int main() { _

    return 0;
  }
*/
