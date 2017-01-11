#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int w[50010];
int mx[50010][17];int mi[50010][17];

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int min(int a,int b)
{
    if(a>b)return b;
    return a;
}

void init(int n)
{
    int i,j,m;
    m=int(trunc(log2(n)))+1;
    for(int i = 1; i < n+1; i++)
    {
        mx[i][1]=w[i-1];
        mi[i][1]=w[i-1];
    }
    for(i = 2;i < m+1; i++)
    {
        for(j = 1; j < n+1&&(j+(1<<(i-1))-1)<=n; j++)
        {
            mx[j][i]=mx[j][i-1];
            mi[j][i]=mi[j][i-1];
            if(j+(1<<(i-1)-1)<=n)
            {
                mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1)-1)][i-1]);
                mi[j][i]=min(mi[j][i],mi[j+(1<<(i-1)-1)][i-1]);
            }
        }
    }
    return;
}

int rmqmax(int l,int r)
{
    int m=int(trunc(log2(r-l+1)));
    //printf("%d**%d**%d\n",l,m+1,r-(1<<m)+1);
    return max(mx[l][m+1],mx[r-(1<<m)+1][m+1]);

}
int rmqmin(int l,int r)
{
    int m=int(trunc(log2(r-l+1)));
    return min(mi[l][m+1],mi[r-(1<<m)+1][m+1]);
}
int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        int i,j;
        for(i = 0; i < n; i++)
            scanf("%d",&w[i]);
        init(n);
        /*for(i = 1; i < 4;i++)
        {
            for(j = 1; j < n+1; j++)
                printf("%d ",mx[j][i]);
            printf("\n\n");
        }
        for(i = 1; i < 4;i++)
        {
            for(j = 1; j < n+1; j++)
                printf("%d ",mi[j][i]);
            printf("\n\n");
        }*/

        int l,r;
        for(i = 0; i < q; i++)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",rmqmax(l,r)-rmqmin(l,r));
        }
    }
    return 0;
}
