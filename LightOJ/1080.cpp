#include<stdio.h>
#include<string.h>
#define sz 100015
struct T{
int sum,lazy;
}tree[4*sz];
int ar[sz];

void build_tree(int p,int l,int r)
{
    if(l==r)
    {
        tree[p].lazy=ar[l];
        return ;
    }

    int m;
    m=(l+r)/2;
    build_tree(2*p,l,m);
    build_tree(2*p+1,m+1,r);
   // tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
}

void  update(int p,int l,int r,int x,int y,int v)
{
    if(l>y||r<x)
        return ;
    if(l>=x&&r<=y)
    {
        //tree[p].sum+=(r-l+1)*v;
        tree[p].lazy=(tree[p].lazy+v)%2;
        return;
    }
    int m=(l+r)/2;
    update(2*p,l,m,x,y,v);
    update(2*p+1,m+1,r,x,y,v);
   // tree[p].sum=tree[2*p].sum+tree[2*p+1].sum+(r-l+1)*tree[p].lazy;
}

int query(int p,int l,int r,int x,int y)
{

    if(l>=x&&r<=y)
        return tree[p].lazy;
    if(l>y||r<x)
        return 0;
     int m=(l+r)/2;
    return  query(2*p,l,m,x,y)+query(2*p+1,m+1,r,x,y)+tree[p].lazy;
}
  char st[100005],ss[5];
int main()
{
    int m,n,a,b,q,i,x,t,r;

    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%s",st);
        n=strlen(st);
        for(i=1;i<=n;i++)
          ar[i]=st[i-1]-'0';
        memset(tree,0,sizeof(tree));
        build_tree(1,1,n);
        scanf("%d",&q);
        printf("Case %d:\n",r);
        while(q--)
        {
            scanf("%s",&ss);
            if(ss[0]=='I')
            {
                scanf("%d %d",&a,&b);
                update(1,1,n,a,b,1);
            }
            else if(ss[0]=='Q')
            {
                scanf("%d",&a);
                printf("%d\n",query(1,1,n,a,a)%2);
            }
        }
    }
    return 0;
}
