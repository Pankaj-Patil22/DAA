#include<stdio.h>
#include<stdlib.h>

float e,a[50];
int n,c,j;

int ls()
{
    int i;
    for(i=0;i<n;i++)
    {
        c++;
        if(e==a[i])
        {
            c++;
            return i;
        }
        c++;
    }
    c++;
    return -1;
}

int bs(int f,int l)
{   
    int m;
    m=(f+l)/2;
    if(e==a[m])
    {
        c++;
        return m;
    }
    else if(f==l)
    {
        c=c+2;
        return -1;
    }
    c=c+2;

    if(e<a[m])
    {
        c++;
        l=m-1;
    }
    else if(e>a[m])
    {
        c=c+2;
        f=m+1;
    }
    bs(f,l);
}


int main()
{
    int op;
    printf("1.Linear Search 2.Binary Search \n");
    scanf("%d",&op);

    switch(op)
    {
    case 1:
        printf("Give the array size\n");
        scanf("%d",&n);
        printf("Give the array elements\n");
        for(int i=0;i<n;i++)
        {
            scanf("%f",&a[i]);
        }
        printf("Give the element that has to be searched\n");
        scanf("%f",&e);
        if(ls()!=-1)
        {
            printf("The value of c is %d\n",c);
            printf("The first instance of the element was found at %d position\n",ls()+1);
        }
        else
        printf("Element not found\n");
        break;
    
    case 2:
        printf("Give the array size\n");
        scanf("%d",&n);
        printf("Give the sorted array elements\n");
        for(int i=0;i<n;i++)
        {
            scanf("%f",&a[i]);
        }
        printf("Give the element that has to be searched\n");
        scanf("%f",&e);
        if(bs(0,n-1)!=-1)
        {
            printf("The value of c is %d\n",c);
            printf("The first instance of the element was found at %d position\n",bs(0,n-1)+1);
        }
        else if(bs(0,n-1)==-1)
        printf("Element not found\n");
        break;

    default:
        printf("Invalid input\n");
        break;
    }
    return 0;
}
