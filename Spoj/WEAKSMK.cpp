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
int a,b,p,ans;
}ar[100005];
vector<int>ary[10005],cst[10005];
char text[20006];
const int maxlen = 20005;
const int alphabet = 256;
struct TT{
int p,indx;
}arr[maxlen];
bool cmp(TT x,TT y)
{
    if(x.p==y.p)
        return x.indx>y.indx;
        return x.p<y.p;
}
int Rank[15][maxlen],LCP[maxlen],step;
int pn[maxlen], cn[maxlen],p[maxlen], cnt[maxlen];
void build_suffix_array()
{
    int n;
    n=strlen(text)+1;
    memset (cnt, 0, alphabet * sizeof(int));
    for (int i=0; i<n; ++i)
        ++cnt[text[i]];
    for (int i=1; i<alphabet; ++i)
        cnt[i] += cnt[i-1];
    for (int i=0; i<n; ++i)
        p[--cnt[text[i]]] = i;
    Rank[0][p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (text[p[i]] != text[p[i-1]])  ++classes;
        Rank[0][p[i]] = classes-1;
    }
    for(int i=0;i<n;i++)
    {
        arr[i].p=Rank[0][i],arr[i].indx=i;
    }
    step=1;

    for (int h=0; (1<<h)<n; ++h) {
        for (int i=0; i<n; ++i) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        memset (cnt, 0, classes * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[Rank[h][pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[Rank[h][pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i) {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (Rank[h][p[i]] != Rank[h][p[i-1]] || Rank[h][mid1] != Rank[h][mid2])
                ++classes;
            cn[p[i]] = classes-1;
        }
       for(int i=0;i<n;i++)
        Rank[h+1][i]=cn[i],arr[i].p=cn[i],arr[i].indx=i;
        step=h+2;
    }
    sort(arr,arr+n,cmp);
    for(int i=1;i<n;i++) arr[i-1]=arr[i];
}
void build_LCP_array(void)
{
    LCP[0] = 0;
    int n = strlen(text), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i-1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2]!=-1)
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
       // cout << arr[i-1] << ' ' << arr[i] << ' ' << LCP[i] << endl;
    }
}
int find_indx(int ocur,int val){

  int lw=0,hi=ary[ocur].size()-1,mid;
  int l=hi;
  while(lw<=hi){
    mid=(lw+hi)/2;
    if(ary[ocur][mid]<=val){
        if(mid+1<=l&&ary[ocur][mid+1]<=val){
            lw=mid+1;
        }
        else break;
    }
    else {
        hi=mid-1;
    }
  }
 // pf("--%d\n",mid);
  return mid;
}
int minx[10005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--){
        memset(Rank,-1,sizeof(Rank));
        sn("%d %d",&n,&m);
        sn("%s",&text);
        for(i=0;i<m;i++){
            sn("%d %d",&ar[i].a,&ar[i].b);
            ar[i].p=i;
            ar[i].ans=-1;
            if(ar[i].a<=n&&ar[i].b<=n){
                ary[ar[i].b].pb(ar[i].a);
            }
            else{
                ar[i].ans=0;
            }
        }
        for(i=0;i<=n;i++){
            ary[i].pb(0);
            sort(ary[i].begin(),ary[i].end());
            for(j=k=0;j<ary[i].size();j++){
                if(ary[i][k]!=ary[i][j]){
                    ary[i][++k]=ary[i][j];
                }
            }
            while(ary[i].size()>k+1){
                ary[i].pop_back();
            }
            for(j=0;j<k+1;j++){
                cst[i].pb(0);
            }
        }
        build_suffix_array();
        build_LCP_array();
        for(i=0;i<n;i++){
            minx[i]=n-arr[i].indx;
            for(j=i+1;j<n;j++){
                minx[j]=min(minx[j-1],LCP[j]);
                if(minx[j]==0){
                    j++;
                    break;
                }
            }
             u=LCP[i];
            for(j=j-1;j>=i;j--){
                if(minx[j]>u){
                    v=u;
                    u=minx[j];
                   // pf("%d\n",cst[i].size());
                    cst[j-i+1][find_indx(j-i+1,u)]++;
                    cst[j-i+1][find_indx(j-i+1,v)]--;
                }
            }
        }
        for(i=0;i<=n;i++){
            for(j=ary[i].size()-2;j>=0;j--){
                cst[i][j]+=cst[i][j+1];
            }
        }
        for(i=0;i<m;i++){
            if(ar[i].ans==-1){
                u=find_indx(ar[i].b,ar[i].a);
                pf("%d\n",cst[ar[i].b][u]);
            }
            else{
                pf("0\n");
            }
        }
        for(i=0;i<=n;i++){
            ary[i].clear();
            cst[i].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

