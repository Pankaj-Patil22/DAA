#include<stdio.h>
#include<stdlib.h>

int c=0;

struct m
{       
    float min;
    float max;
};

struct m mam(int f,int l,float a[])
{
    struct m mm,mml,mmr;

    int mid;

    if(f==l)
    {
        c++;
        mm.min=a[f];
        mm.max=a[l];
        return mm;
    }
    c++;

    if(l==f+1)
    {
        if(a[f]>a[l])
        {
            mm.min=a[l];
            mm.max=a[f];
        }
        else
        {
            mm.min=a[f];
            mm.max=a[l];
        }
        c=c+2;
        return mm;
    }
    c++;

    mid=(f+l)/2;
    mml=mam(f,mid,a);
    mmr=mam(mid+1,l,a);

    if(mml.min<mmr.min)
    mm.min=mml.min;
    else
    mm.min=mmr.min;

    if(mml.max>mmr.max)
    mm.max=mml.max;
    else
    mm.max=mmr.max;

    c=c+2;

    return mm;
}

void main()
{
    int n,i;
    printf("Give the number of elements\n ");
    scanf("%d",&n);
    float a[n];
    printf("Give the array elements \n");
    for(i=0;i<n;i++)
    scanf("%f",&a[i]);

    struct m minmax=mam(0,n-1,a);

    printf("The minimum and maximum numbers are %f %f\n",minmax.min,minmax.max);
    printf("The value of c is %d\n",c);

}