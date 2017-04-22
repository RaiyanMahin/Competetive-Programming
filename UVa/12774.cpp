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
#define sn scanf
#define pf printf
#define pb push_back
#define inf ((1<<30))
#define NN 100
#define MM 1009000

#define maxv(A,B) (A>B?A:B)

#define minv(A,B) (A>B?B:A)

using namespace std;
typedef long long int ll;

ll source,en,dest,par[NN*NN],d[NN*NN],Tflow,cnt;

struct gp{
	ll u,v,cap,cost;
};

vector<gp> edge;
vector<ll> graph[NN*NN];
pair<ll,ll>str[100000];
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
    return x.second<y.second;
}
void add(ll u,ll v,ll cap,ll cost)
{
	gp e1={u,v,cap,cost};
	gp e2={v,u,0,-cost};
	graph[u].push_back(en++);
	graph[v].push_back(en++);
	edge.push_back(e1);
	edge.push_back(e2);
}

struct gp1{

	ll u,cost;
	gp1(){};
	gp1( ll u,ll cost ):u(u),cost(cost){};
	bool operator <(const gp1 &tt)const
	{
		return cost>tt.cost;
	}
};


ll bfs()
{
	ll u,v,i,j,cc,e_cost,enn;
	for( i=0;i<=dest;i++ )
	{
		d[i]=inf;
		par[i]=-1;
	}
	d[source]=0;
	priority_queue<gp1> q;
	q.push( gp1(source,0) );
	while( !q.empty() )
	{
		u=q.top().u;
		cc=q.top().cost;
		q.pop();
		if( cc>d[u] ) continue;
		if(u==dest) break;
		for( i=0;i<graph[u].size();i++ )
		{
			enn=graph[u][i];
			v=edge[enn].v;
			e_cost=edge[enn].cost;
			if( edge[enn].cap>0 && cc+e_cost<d[v] )
			{
				d[v]=cc+e_cost;
				par[v]=enn;
				q.push(gp1(v,d[v]));
			}
		}

	}
	if( par[dest]==-1 ) return 0;
	int mx=inf;
	enn=par[dest];
	while(enn!=-1)
	{
		mx=minv(mx,edge[enn].cap);
		enn=par[ edge[enn].u ];
	}
	enn=par[dest];
	Tflow+=mx;
	while( enn!=-1 )
	{
		edge[enn].cap-=mx;
		edge[enn^1].cap+=mx;
		enn=par[ edge[enn].u ];
	}
	str[cnt++]=make_pair(mx,d[dest]);
	return d[dest];
}

ll mfmc()
{
	ll res=0;
	while( true )
	{
		ll tt=bfs();
		if( tt==0||tt>100) return res;
		res+=tt;
	}
}

int main()
{
	 ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,totalnd;
	scanf("%lld",&t);
	while( t--)
	{
	    Tflow=en=0;
	    totalnd=100;
		edge.clear();
		for(i=0;i<=totalnd;i++) graph[i].clear();
        cnt=0;
        sn("%lld %lld %lld",&n,&m,&k);
        source=1;dest=n;
        for(i=0;i<m;i++)
        {
            sn("%lld %lld %lld %lld",&u,&v,&c,&f);
            add(u,v,f,c);
        }
        sort(str,str+cnt,cmp);
        h=mfmc();
      ll day=0,arm=0;c=0;
      for(i=0;i<cnt;i++)
      {
          if(i==0)
          {
              day=day+str[i].second;
              arm=arm+str[i].first;
              c=arm;
          }
          else
          {
             d=(str[i].second-str[i-1].second);
              h=0;
              for(j=1;j<=d;j++)
              {
                  if(arm>=k)
                  {
                     h=1; break;
                  }
                  arm=c+arm;day++;
              }
              if(h==0)
              {
                  arm+=str[i].first;
                  c=c+str[i].first;
              }
          }
          if(arm>=k)
            break;
      }
       d=100;
       for(j=1;j<=d;j++)
        {
            if(arm>=k)
            {
                break;
            }
        arm=c+arm;day++;

        }
        if(day>100)
            day=-1;
        pf("Case %lld: %lld\n",cs++,day);
	}
	return 0;
}
