#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int a[10][10];
int n,ans=0;;

void ok()
{
    for(int i=0;i<n;i++)
    {for(int j=0;j<n;j++)
    printf("%d ",a[i][j]);
    printf("\n");}

    ans++;
    printf("---------------\n");
}

int isSafe(int r,int c)
{
    int i=r,j=c;

    for(int i=0;i<c;i++)
    if(a[r][i])
    return 0;

    for (i=r, j=c; i>=0 && j>=0; i--, j--)
        if (a[i][j])
            return 0;

    for (i=r, j=c; j>=0 && i<n; i++, j--)
        if (a[i][j])
            return 0;

    return 1;
}

int nqueen(int col)
{
    if(n==col)
    {
        ok();
        return 1;
    }

    int res=0;

    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col))
        {
            a[i][col]=1;
            res=nqueen(col+1) || res;
            a[i][col]=0;  //backtracking
        }

    }

    return res;
}

int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));

    nqueen(0);
    printf("\n\n%d\n",ans);

}