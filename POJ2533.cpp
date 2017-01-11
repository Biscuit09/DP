#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int f[1010];
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a[1010];
        for(int i = 0; i <10;i++)
            f[i]=1;
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        int maxi=1;
        for(int i = 1; i < n; i++)
        {
            int maxx=0;
            for(int j = 0; j < i; j++)
                if(a[i]>a[j]&&f[j]>maxx)
                maxx=f[j];
            f[i]=maxx+1;
            if(f[i]>maxi)
                maxi=f[i];
        }

        printf("%d\n",maxi);
    }
    return 0;
}
