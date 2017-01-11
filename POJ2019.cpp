#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int w[260][260];
int mx[260][260][10 ];int mi[260][260][9];

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

void init(int n,int b)
{
    int i,j,k,m;
    m=int(trunc(log2(b)));
    //printf("*****%d\n",m);
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            mx[i][j][0]=w[i][j];
            mi[i][j][0]=w[i][j];
        }
    }
    for(i = 1;i < m+1; i++)
    {
        for(j = 1; j + (1<<i)-1 < n+1; j++)
        {
            for(k = 1; k + (1<<i)-1 < n+1; k++)
            {
                //printf("%d**\n",i);
                mx[j][k][i]=mx[j][k][i-1];
                mi[j][k][i]=mi[j][k][i-1];
                    mx[j][k][i]=max(mx[j][k][i],mx[j+(1<<(i-1))][k][i-1]);
                    mx[j][k][i]=max(mx[j][k][i],mx[j][k+(1<<(i-1))][i-1]);
                    mx[j][k][i]=max(mx[j][k][i],mx[j+(1<<(i-1))][k+(1<<(i-1))][i-1]);
                    mi[j][k][i]=min(mi[j][k][i],mi[j+(1<<(i-1))][k][i-1]);
                    mi[j][k][i]=min(mi[j][k][i],mi[j][k+(1<<(i-1))][i-1]);
                    mi[j][k][i]=min(mi[j][k][i],mi[j+(1<<(i-1))][k+(1<<(i-1))][i-1]);

            }
        }
    }
    return;
}

int rmqmax(int r, int c, int b)
{
    int m=int(trunc(log2(b)));
    //printf("%d**%d**%d\n",l,m+1,r-(1<<m)+1);
    int maxn;
    maxn=max(mx[r][c][m],mx[r+b-(1<<m)][c][m]);
    maxn=max(maxn,mx[r+b-(1<<m)][c+b-(1<<m)][m]);
    maxn=max(maxn,mx[r][c+b-(1<<m)][m]);
    return maxn;
}
int rmqmin(int r, int c, int b)
{
    int m=int(trunc(log2(b)));
    int minn;
    minn=min(mi[r][c][m],mi[r+b-(1<<m)][c][m]);
    minn=min(minn,mi[r+b-(1<<m)][c+b-(1<<m)][m]);
    minn=min(minn,mi[r][c+b-(1<<m)][m]);
    return minn;
}
int main()
{
    int n,b,q;
    while(~scanf("%d%d%d",&n,&b,&q))
    {
        int i,j,k;
        for(i = 1; i < n+1; i++)
            for(j = 1; j < n+1; j++)
            scanf("%d",&w[i][j]);
        init(n,b);
        /*printf("mx*********\n");
        for(i = 0; i < 4;i++)
        {
            for(j = 1; j < n+1; j++)
            {
                for(k = 1; k < n+1; k++)
                    printf("%d ",mx[j][k][i]);
                printf("\n");
            }
            printf("%d***\n",i);

        }
        printf("mi*********\n");
        for(i = 1; i < 4;i++)
        {
            for(j = 1; j < n+1; j++)
            {
                for(k = 1; k < n+1; k++)
                    printf("%d ",mi[j][k][i]);
                printf("\n");
            }
            printf("%d***\n",i);
        }*/
        int r,c;
        for(i = 0; i < q; i++)
        {
            scanf("%d%d",&r,&c);
            printf("%d\n",rmqmax(r,c,b)-rmqmin(r,c,b));
        }
    }
    return 0;
}
/*
5 3 1
5 1 2 6 3
1 3 5 2 7
7 2 4 6 1
9 9 8 6 5
0 6 9 3 9
1 2
*/

