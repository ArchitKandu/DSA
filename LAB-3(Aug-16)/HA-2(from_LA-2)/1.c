#include<stdio.h>

struct employee
{
    char name[50];
    char gender[10];
    char desg[50];
    char dept[50];
    float bp;
} emp[50];

int main()
{
    float hr=0,da=0;
    int n,i;
    printf("Enter number of Employees: ");
    scanf("%d",&n);
    printf("\n-----Enter data-----\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter info of employee %d\n\n",i+1);
        printf("Enter name: ");
        scanf("%s",emp[i].name);
        printf("Enter gender: ");
        scanf("%s",emp[i].gender);
        printf("Enter Designation: ");
        scanf("%s",emp[i].desg);
        printf("Enter Department: ");
        scanf("%s",emp[i].dept);
        printf("Enter Basic Pay: ");
        scanf("%f",&emp[i].bp);
    }
    printf("\n\n----Displaying information----\n");
    for(i=0;i<n;i++)
    {
        hr=0.25*emp[i].bp;
        da=0.75*emp[i].bp;
        printf("Employer %d\n\n",i+1);
        printf("Name: %s\n",emp[i].name);
        printf("Gender: %s\n",emp[i].gender);
        printf("Designation: %s\n",emp[i].desg);
        printf("Department: %s\n",emp[i].dept);
        printf("Gross Pay: %.2f\n",hr+da);
        printf("\n");
    }
    return 0;
}