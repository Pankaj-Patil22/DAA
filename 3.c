#include<stdio.h>

//pi- partition index

int n,c=0;

int partition(int a[],int f,int l)
{
    int i,j;
    int pivot=a[l];
    int pi=f;
    for(i=f;i<l;i++)
    {
        c++;
        if(a[i]<=pivot)
        {
            int temp=a[i];
            a[i]=a[pi];
            a[pi]=temp;
            pi++;
        }
        c=c+1;
    }
    c++;
    int t=a[pi];
    a[pi]=a[l];
    a[l]=t;

    return pi;
}

void qs(int a[],int f,int l)
{
    if(f>=l)
    {
        c++;
        return ;
    }
    c++;
    int pi=partition(a,f,l);
    qs(a,f,pi-1);
    qs(a,pi+1,l);
}

int main()
{
    int i,j;
    printf("Give the no of elements\n");
    scanf("%d",&n);
    int a[n]; 
    printf("Enter the elements of the array:\n");
    for (i=0;i<n;i++)	
    {
        scanf("%d",&a[i]);
	}
    qs(a,0,n-1);
    printf("The sorted array is:\n");
    for (j=0;j<n;j++)	
    {
        printf("%d ",a[j]);	
    }

    printf("\nThe no of comparisons made are %d\n",c);
}