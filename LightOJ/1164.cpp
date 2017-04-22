#include<stdio.h>
#include<string.h>
#define sz 100005
struct T{
long long sum,lazy;
}tree[3*sz];
long long ar[sz],Id[3*sz];

void build_tree(long long p,long long l,long long r)
{
    if(l==r)
    {
        tree[p].sum=ar[l];
        Id[l]=p;
        return ;
    }

    long long m;
    m=(l+r)/2;
    build_tree(2*p,l,m);
    build_tree(2*p+1,m+1,r);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
}

void  update(long long p,long long l,long long r,long long x,long long y,long long v)
{
    if(l>y||r<x)
        return ;
    if(l>=x&&r<=y)
    {
        tree[p].sum+=(r-l+1)*v;
        tree[p].lazy+=v;
        return;
    }
    long long m=(l+r)/2;
    update(2*p,l,m,x,y,v);
    update(2*p+1,m+1,r,x,y,v);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum+(r-l+1)*tree[p].lazy;
}

long long query(long long p,long long l,long long r,long long x,long long y,long long cry=0)
{
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return tree[p].sum+cry*(r-l+1);
     long long m=(l+r)/2;
    return query(2*p,l,m,x,y,cry+tree[p].lazy)+query(2*p+1,m+1,r,x,y,cry+tree[p].lazy);
}
int main()
{
    long long a,b,n,m,r,t,q,i,v;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        memset(tree,0,sizeof(tree));
        scanf("%lld %lld",&n,&q);
        printf("Case %lld:\n",r);
        while(q--)
        {
            scanf("%lld",&m);
            if(m==0)
            {

                scanf("%lld %lld",&a,&b);
                    scanf("%lld",&v);
                update(1,1,n,a+1,b+1,v);
            }
            else if(m==1)
            {
                scanf("%lld %lld",&a,&b);
                printf("%lld\n",query(1,1,n,a+1,b+1));
            }
        }
    }
    return 0;
}

