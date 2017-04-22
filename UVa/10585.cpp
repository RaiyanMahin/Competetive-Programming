
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

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
struct T{
int a,b;
}ar[10005];

bool cmp(T x,T y)
{
    if(x.a==y.a)
        return x.b<y.b;
        return x.a<y.a;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        int mnx=100000000,mny=100000000,mxx=-100000000,mxy=-100000000;
        for(i=0;i<n;i++)
        {
            sn("%d %d",&ar[i].a,&ar[i].b);
            mnx=min(mnx,ar[i].a);
            mxx=max(mxx,ar[i].a);
            mny=min(mny,ar[i].b);
            mxy=max(mxy,ar[i].b);
        }
        int anx=mnx+mxx,any=mny+mxy;
        sort(ar,ar+n,cmp);
        s=1;
        for(i=0;i<n;i++)
        {
            int lw=0,hi=n-1,mid;
            while(lw<=hi)
            {
                mid=(lw+hi)/2;
                if(ar[mid].a==anx-ar[i].a)
                {
                    if(mid-1>=0&&ar[mid-1].a==anx-ar[i].a)
                        hi=mid-1;
                    else
                        break;
                }
                else if(ar[mid].a<anx-ar[i].a)
                  lw=mid+1;
                else if(ar[mid].a>anx-ar[i].a)
                  hi=mid-1;
            }
            if(lw<=hi)
            {
                a=mid;
            }
            else{
                s=0;
                break;
            }
            lw=a,hi=n-1;
            while(lw<=hi)
            {
                mid=(lw+hi)/2;
                if(ar[mid].a==anx-ar[i].a)
                {
                    if(mid+1<=n-1&&ar[mid+1].a==anx-ar[i].a)
                        lw=mid+1;
                    else
                        break;
                }
                else if(ar[mid].a<anx-ar[i].a)
                  lw=mid+1;
                else if(ar[mid].a>anx-ar[i].a)
                  hi=mid-1;
            }
            if(lw<=hi)
            {
                b=mid;
            }
            else {
                s=0;break;
            }
             lw=a,hi=b;
            while(lw<=hi)
            {
                mid=(lw+hi)/2;
                if(ar[mid].b==any-ar[i].b)
                {
                   break;
                }
                else if(ar[mid].b<any-ar[i].b)
                  lw=mid+1;
                else if(ar[mid].b>any-ar[i].b)
                  hi=mid-1;
            }
            if(lw<=hi)
            {
                b=mid;
            }
            else {
                s=0;break;
            }
        }
        if(s)
            pf("yes\n");
        else
            pf("no\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

