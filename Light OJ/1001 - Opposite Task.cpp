#include<stdio.h>

int main()
{
    int i, t, n;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        if(n<11)
            printf("%d %d\n",0, n);
        else
            printf("%d %d\n",n-10, 10);
    }

    return 0;
}

