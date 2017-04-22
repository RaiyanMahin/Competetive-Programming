#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

vector <int> v[1005];
int deg[1005],c,num[1005],set[1005];

void dfs(int x){
    set[x] = c;
    for(int i=0;i<v[x].size();i++)
        if(set[v[x][i]]==-1)
            dfs(v[x][i]);
}

int main()
{
   // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    for(int N,M,cas=1,T;scanf(" %d %d %d",&N,&M,&T)==3 && (N+M+T);cas++){
        for(int n=1;n<=N;n++)
            v[n].clear(),deg[n] = num[n] = 0, set[n] = -1;
        int ans = M;
        for(int x,y;M--;){
            scanf(" %d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
            deg[x]++;
            deg[y]++;
        }
        c = 0;
        for(int n=1;n<=N;n++)
            if(set[n]==-1 && deg[n]>0)
                c++,dfs(n);
        if(c>0)    ans += c-1;
        for(int n=1;n<=N;n++)
            if(deg[n]&1)
                num[set[n]]++;
        for(int i=1;i<=c;i++)
            if(num[i]>=4)
                ans += (num[i]/2) - 1;
        printf("Case %d: %d\n",cas,ans*T);
    }

    return 0;
}
