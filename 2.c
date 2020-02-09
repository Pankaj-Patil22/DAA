#include<stdio.h>

int c=0;

float merge(int l,int m,int r,float a[])
{
    int i,j,k;
    int n1=m-l+1,n2=r-m;
    float L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        c++;
        L[i]=a[l+i];
    }
    c++;

    for(i=0;i<n2;i++)
    {
        c++;
        R[i]=a[m+1+i];
    }
    c++;

    i=0,j=0;

    while(i<n1 && j<n2)
    {
        c++;
        c++;
        if(L[i]<=R[j]) 
        { 
            a[k]=L[i]; 
            i++; 
        } 
        else
        { 
            a[k]=R[j]; 
            j++; 
        } 
        c++;
        k++; 
    }
    c=c+2;

    while(i<n1) 
    { 
        c++;
        a[k]=L[i]; 
        i++; 
        k++; 
    } 
    c++;

    while(j<n2) 
    { 
        c++;
        a[k]=R[j]; 
        j++; 
        k++; 
    }
    c++;


}

float mergesort(int l, int r,float a[])
{
    int m=(l+r)/2;
    if(l<r)
    {   
        c++;
        //l-left,r-right
        mergesort(l,m,a);
        mergesort(m+1,r,a);

        merge(l,m,r,a);
    }
    c++;
}

int main() 
{ 
    int n,i;

    printf("Give the no of elements\n");
    scanf("%d",&n);

    float a[n]; 
  
    printf("Give the array\n"); 
    for(i=0;i<n;i++)
    scanf("%f",&a[i]); 

    mergesort(0,n-1,a);

    printf("The sorted array is\n");
    for(i=0;i<n;i++)
    printf("%f ",a[i]);

    printf("\nThe no of comparisions made are %d",c);

    return 0; 
} 