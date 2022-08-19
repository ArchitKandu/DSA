#include<stdio.h>
#include<stdlib.h>
int add(int *x,int *y,int m,int n,int j)
{
    int *lsum=NULL;
    int i;
    lsum=(int*)malloc(j*sizeof(int));
    if(m>=n) for(i=0;i<=j;i++) lsum[i]=x[i];
    else for(i=0;i<=j;i++) lsum[i]=y[i];

    if(m>=n) for(i=0;i<=j;i++) lsum[i]=lsum[i]+y[i];
    else for(i=0;i<=j;i++) lsum[i]=lsum[i]+x[i];
    printf("\nSum of Polynomials is:\n");
    printf("(%d) + (%d)x + ",lsum[0],lsum[1]);
    for(i=2;i<j;i++) printf("(%d)x^%d + ",lsum[i],i);
    printf("(%d)x^%d\n",lsum[j],j);
}

int sub(int *x,int *y,int m,int n,int j)
{
    int *ldif=NULL;
    int i;
    ldif=(int*)malloc(j*sizeof(int));
    if(m>=n) for(i=0;i<=j;i++) ldif[i]=x[i];
    else for(i=0;i<=j;i++) ldif[i]=y[i];

    if(m>=n) for(i=0;i<=j;i++) ldif[i]=ldif[i]-y[i];
    else for(i=0;i<=j;i++) ldif[i]=ldif[i]-x[i];
    printf("\nDifference of Polynomials is:\n");
    printf("(%d) + (%d)x + ",ldif[0],ldif[1]);
    for(i=2;i<j;i++) printf("(%d)x^%d + ",ldif[i],i);
    printf("(%d)x^%d\n",ldif[j],j);
}

int pro(int *x,int *y,int m, int n,int j)
{
    int *pro=NULL;
    int i=0,k=0;
    pro=(int*)malloc((m+n)*sizeof(int));
    for(i=0;i<=j;i++) pro[i]=0;
    for(i=0;i<=j;i++)
    {
        for(k=0;k<=j;k++) pro[i+k]=pro[i+k]+(x[i])*(y[k]);
    }
    printf("\nProduct of Polynomials is:\n");
    printf("(%d) + (%d)x + ",pro[0],pro[1]);
    for(i=2;i<m+n;i++) printf("(%d)x^%d + ",pro[i],i);
    printf("(%d)x^%d\n\n",pro[m+n],m+n);
}

int main()
{
    int *a=NULL,*b=NULL;
    int i,j=0,m,n;
    printf("\nHighest Degree of 1st and 2nd polynomials: ");
    scanf("%d%d",&m,&n);
    if(m>=n) j=m;
    else j=n;
    a=(int*)malloc((j+1)*sizeof(int));
    b=(int*)malloc((j+1)*sizeof(int));
    printf("\nEnter Coefficients of 1st polynomial\n");
    for(i=0;i<=j;i++)
    {
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&a[i]);
    }
    printf("\nEnter Coefficients of 2nd polynomial\n");
    for(i=0;i<=j;i++)
    {
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&b[i]);
    }
    add(a,b,m,n,j);
    sub(a,b,m,n,j);
    pro(a,b,m,n,j);
    return 0;
}
