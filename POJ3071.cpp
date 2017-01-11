#include<stdio.h>
#include<string.h>
int num[8]={1,2,4,8,16,32,64,128};
double dp[8][200];
double p[200][200];
void cal(int n)
{
    int i,j,k;
    for(i = 0; i < num[n]+1; i++)dp[0][i]=1;
    for(i = 1; i < n+1;i++)
        for(j = 0; j < num[n];j++)
    {
        int t=j/(1<<(i-1));
                t^=1;
                dp[i][j]=0;
                for(int k=t*(1<<(i-1));k<t*(1<<(i-1))+(1<<(i-1));k++)
                  dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n == -1)break;
        memset(dp,0,sizeof(dp));
        int i,j;
        for(i = 0; i < num[n];i++)
            for(j = 0; j < num[n];j++)
                scanf("%lf",&p[i][j]);
        cal(n);
        float maxp=0;
        int maxi=0;
        for(i = 0; i < num[n];i++)
            if(maxp<dp[n][i])
            {
                maxp=dp[n][i];
                maxi=i;
            }
        printf("%d\n",maxi+1);
    }
    return 0;
}
