#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int f[12888];
int v[3410];
int w[3410];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(f,0,sizeof(f));
        for(int i = 1; i < n+1; i++)
            scanf("%d%d",&w[i],&v[i]);
        for(int i = 1; i < n+1; i++)
        {
            for(int j = m; j >w[i]-1; j--)
            {

                if(f[j-w[i]]+v[i]>f[j])
                    f[j]=f[j-w[i]]+v[i];

            }
        }
       /* for(int i = 1; i < n+1; i++)
        {
            for(int j = 0; j < m+1; j++)
            printf("%d ",f[i][j]);
            printf("\n");
        }*/
        printf("%d\n",f[m]);
    }
    return 0;
}
