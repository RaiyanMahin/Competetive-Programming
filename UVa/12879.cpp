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

//fast fft;


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
void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
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
		res[i] = (int) (fa[i].r + 0.5);
}
int ar[300000],arr[300000];
int main() {
  int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  //sn("%d", &t);
  while(sn("%d",&a)!=EOF)
  {

     vector<int>ar1;
     vector<int>ar2;
     n=0;
     memset(ar,0,sizeof(ar));
     memset(arr,0,sizeof(arr));
      ar[0]=1;
      for(i=0;i<a;i++)
      {
          sn("%d",&u);
          ar[u]=1;
          n=max(n,u);
      }
      n++;
      for(i=0;i<n;i++)
        ar1.pb(ar[i]);
      ar2=ar1;
     vector<int> res;
     multiply(ar1,ar2,res);
      for(i=1;i<2*n-1;i++)
      {
          if(res[i]>0)
          arr[i]=1;
      }
      int ans=0;
      sn("%d",&m);
      while(m--)
      {
          sn("%d",&u);
          ans=ans+arr[u];
      }
      pf("%d\n",ans);
  }
  return 0;
}

