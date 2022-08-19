#include<stdio.h>

struct distance
{
    int km;
    int m;
} d[2];

int main()
{
    int fkm=0,fm=0,i,t=0;
    for(i=0;i<2;i++)
    {
        printf("Enter %dth Length\n\n",i+1);
        printf("Length in Kilometers: ");
        scanf("%d",&d[i].km);
        printf("Length in Meters: ");
        scanf("%d",&d[i].m);
        printf("\n");
    }
    t=(d[0].m+d[1].m);
    fm=t%1000;
    fkm=d[0].km+d[1].km+(t/1000);
    printf("Sum of both length is: %d KM %d M\n",fkm,fm);
    return 0;
}