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
typedef long long ll;
//fast fft;
const double PI= 2*acos(0);

struct complex{
	double r,v;
	complex(double a=0,double b=0):r(a),v(b){}
	inline complex operator+(const complex& b){return complex(r+b.r,v+b.v);}
	inline complex operator-(const complex& b){return complex(r-b.r,v-b.v);}
	inline complex operator*(const complex& b){return complex(r*b.r-v*b.v,v*b.r+r*b.v);}
};
typedef complex base;
inline void swap(complex& a,complex& b){complex t(a);a=b;b=t;}

void fft (vector<base> & a, bool invert) {
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
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w =w* wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i].r =a[i].r / n;
}
void multiply (const vector<int> & a, const vector<int> & b, vector<ll> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] = fa[i]*fb[i];
	fft (fa, true);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = ll (fa[i].r + 0.5);
}
char st[300005],ss[300005];
vector<int>ar1,rev;
     vector<int>ar2;
     vector<ll>res,ans;
int main() {
  int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  sn("%d", &t);
  while(t--)
  {
      sn("%s %s",&st,&ss);
     ar1.clear();
     ar2.clear();
     n=strlen(st);
     m=strlen(ss);
      for(i=0;i<n;i++)
      {
          ar1.push_back(st[i]-'0');
      }
      for(i=0;i<m;i++)
      {
          ar2.push_back(ss[i]-'0');
      }
      rev=ar1;
      for(i=n-1,a=0;i>=0;i--,a++)
      {
          ar1[a]=rev[i];
      }
      rev=ar2;
      for(i=m-1,a=0;i>=0;i--,a++)
      {
          ar2[a]=rev[i];
      }
      for(i=n;i<m;i++)
        ar1.pb(0);
      for(i=m;i<n;i++)
        ar2.pb(0);
     n=max(n,m);
     if(n<2)
     {
         sscanf(st,"%d",&a);
         sscanf(ss,"%d",&b);
         pf("%d\n",a*b);
         continue;
     }
     res.clear();ans.clear();
     multiply(ar1,ar2,res);
     ll cr=0;
      for(i=0;i<2*n-1;i++)
      {
          res[i]+=cr;
          ans.pb(res[i]%10);
          cr=res[i]/10;
      }
      ans.pb(cr);cr=0;
      for(i=ans.size()-1;i>=0;i--)
      {
          if(cr+ans[i]>0)
          {
              pf("%lld",ans[i]);cr=1;
          }
      }
      if(cr==0)pf("0");
      pf("\n");
  }
  return 0;
}

