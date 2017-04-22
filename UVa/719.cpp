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
const int MAX =30004;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
    bool operator<(const info &a)const
    {
        return tup[0] != a.tup[0]? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
}arr[MAX];
int Rank[18][MAX], LCP[MAX], step;
string text;

void build_suffix_array(void)
{
    int n = text.size(), jump,m;
    for(int j = 0; j < n; j++)
    {
        Rank[0][j] = text[j]; ///rank suffixes according to 1st char
        memset(arr[j].tup, 0,sizeof(arr[j].tup));
    }
    for(step = 1, jump = 1; jump <=n/2; step++, jump <<= 1)
    {
        for(int j = 0; j <=n; j++)
        {
            arr[j].indx = j;
            arr[j].tup[0] = Rank[step - 1][j]; /// what i was in prev step
           arr[j].tup[1] = j + jump < n? Rank[step - 1][j + jump] :-1;
        }
        sort(arr, arr + n);
        Rank[step][arr[0].indx] = 0;
        for(int j = 1; j < n; j++)
            Rank[step][arr[j].indx] = arr[j].tup[0] == arr[j - 1].tup[0] &&
            arr[j].tup[1] == arr[j - 1].tup[1] ? Rank[step][arr[j - 1].indx] : j;
    }

}

void build_LCP_array(void)
{
    LCP[0] = 0;
    int n = text.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2]!=-1)
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
         }

}
int Count_LCP(int id1,int id2,int n,int m)
{
    int  i, j,lc=0;
     // n=n-id1;
     // m=m-id2;
        for(j = step - 1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2]!=-1)
            {
                lc += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
        lc=min(n,lc);
        lc=min(m,lc);
      return lc;
}
vector<int>ar;
int main()
{
    int i,j,k,a,b,c,d,n,m,cs=1,t,u,v;
    sn("%d",&t);
    while(t--)
    {
        for(i=0;i<19;i++)
        {
            for(j=0;j<=20005;j++)
                Rank[i][j]=-1;
        }
        cin >> text;
        text=text+text;
        build_suffix_array();
        //build_LCP_array();
        n=text.size();a=0;
        for(i=0;i<n;i++)
        {
            if(arr[i].indx<(n/2))
                ar.pb(arr[i].indx);
        }
        n=ar.size();
           a=ar[0];
            for(j=1;j<n;j++)
            {
                int h=Count_LCP(a,ar[j],n,n);
                if(h==n&&a>ar[j])
                {
                    a=ar[j];
                }
            }
        pf("%d\n",a+1);
        ar.clear();
    }
    return 0;
}

