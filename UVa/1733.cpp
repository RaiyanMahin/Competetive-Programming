//BISMILLAHIR RAHMANIR RAHIM
//SPOJ-POLYMUL
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

using namespace std;
const double PI= 2*acos(0);
typedef long long int ll;

const int mod = 7340033;
const ll root = 5;
const ll root_1 = 4404020;
const ll root_pw = 1<<20;

int rev_element[7340033];

ll getmod(ll a, ll tmod){
	return ((a%tmod)+tmod)%tmod;
}

void fft (vector<ll> & a, bool invert) {
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		ll wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = ll (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			ll w = 1;
			for (int j=0; j<len/2; ++j) {
				ll u = a[i+j],  v = ll (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = getmod(u+v,mod);
				a[i+j+len/2] = getmod(u-v,mod);
				w = ll (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		ll nrev = rev_element[n];
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

void precalc(){
    rev_element[1] = 1;
    for (int i=2; i<mod; i++)
        rev_element[i] = (mod - (mod/i) * rev_element[mod%i] % mod) % mod;
}


void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res) {
	vector <ll> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
	fft (fa, false),  fft (fb, false);
	for(int i=0;i<(int)n;i++)
		fa[i] *= fb[i];
	fft (fa, true);
	res.resize (n);
	for(int i=0;i<(int)n;i++)
		res[i] = fa[i] % mod;
}
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
ll fact[100005],ifact[100005];
vector<ll>ar1,ar,ar2,res;
int main() {
  ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,mod=7340033;
  fact[0]=1;
  ifact[0]=bigmod(fact[0],mod-2,mod);
  for(i=1;i<=100000;i++)
  {
      fact[i]=(fact[i-1]*i)%mod;
      ifact[i]=bigmod(fact[i],mod-2,mod);
     // pf("%lld %lld\n",fact[i],ifact[i]);
  }
  //a=36;b=15;
  //pf("%lld\n",(fact[a]*(ifact[a-b]*ifact[b]%mod)%mod));
  precalc();
  sn("%lld", &t);
  while(t--)
  {
      sn("%lld",&n);
      a=b=c=d=0;
      for(i=0;i<n;i++)
      {
          sn("%lld %lld",&u,&v);
          if(u<0&&v<0)
            d++;
          if(u<0&&v>0)
            b++;
          if(u>0&&v>0)
            a++;
          if(u>0&&v<0)
            c++;
      } ar.clear();ar1.clear();ar2.clear();
      for(i=1;i<=n;i++)
      {
          if(i>a||i>d)break;
          u=fact[a]*(ifact[a-i]*ifact[i]%mod);
          u=u%mod;
          v=fact[d]*(ifact[d-i]*ifact[i]%mod);
          v=v%mod;
          u=(u*v)%mod;
          ar.pb(u);
      }

      ar1.pb(1);
      ar1.pb(0);
      for(i=0;i<ar.size();i++)
      {
          ar1.pb(ar[i]);
          ar1.pb(0);
      }
      ar.clear();
      for(i=1;i<=n;i++)
      {
          if(i>b||i>c)break;
          u=fact[b]*(ifact[b-i]*ifact[i]%mod);
          u=u%mod;
          v=fact[c]*(ifact[c-i]*ifact[i]%mod);
          v=v%mod;
          u=(u*v)%mod;
          ar.pb(u);
      }

      ar2.pb(1);
      ar2.pb(0);
      for(i=0;i<ar.size();i++)
      {
          ar2.pb(ar[i]);
          ar2.pb(0);
      }
      m=max(ar1.size(),ar2.size());
      for(i=ar1.size();i<=m;i++)
      {
          ar1.pb(0);
      }
      for(i=ar2.size();i<=m;i++)
      {
          ar2.pb(0);
      }
      res.clear();
//      for(i=0;i<m;i++)
//      {
//          pf("%lld ",ar1[i]);
//      }
//      pf("\n");
//      for(i=0;i<m;i++)
//      {
//          pf("%lld ",ar2[i]);
//      }
//      pf("\n");
      multiply(ar1,ar2,res);
      for(i=res.size();i<=n+10;i++)
        res.pb(0);
      pf("Case %lld:\n",cs++);
      for(j=1;j<=n;j++)
      {
          if(j!=1)pf(" ");
          pf("%lld",res[j]%mod);
          a=res[j]%mod;
          if(a<0)
            while(1)
          {
              ;
          }
      }
      pf("\n");
  }
  return 0;
}
