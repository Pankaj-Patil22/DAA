#include<stdio.h>

float merge(int l,int m,int r,float a[])
{
    int i,j,k;
    int n1=m-l+1,n2=r-m;
    float L[n1],R[n2];
    for(i=l;i<m;i++)
    L[i]=a[i];
    for(i=m+1;i<r;i++)
    R[i]=a[i];

    while(i<n1 && j<n2)
    {
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
        k++; 
    }

    while(i<n1) 
    { 
        a[k]=L[i]; 
        i++; 
        k++; 
    } 

    while(j<n2) 
    { 
        a[k]=R[j]; 
        j++; 
        k++; 
    }


}

float mergesort(int l, int r,float a[])
{
    if(l<r)
    {   
        int m=(l+r)/2;
        //l-left,r-right
        mergesort(l,m,a);
        mergesort(m+1,r,a);

        merge(l,m,r,a);
    }
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

    return 0; 
} 