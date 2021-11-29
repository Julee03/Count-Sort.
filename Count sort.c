#include<stdio.h>
#define MAX 50
void input(int [],int);
int getmax(int [],int);
void count_sort(int [],int [],int,int);
void display(int [],int);
int main()
{
    int arr[MAX],n,k,arr2[MAX];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    input(arr,n);
    k=getmax(arr,n);
    count_sort(arr,arr2,n,k);
    display(arr2,n);
    return 0;
}
void input(int a[MAX],int num)
{
    int i;
    printf("Enter the array elements: ");
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);
}
int getmax(int a[MAX],int num)
{
    int i,max;
    max=a[0];
    for(i=1;i<num;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return(max);
}
void count_sort(int a[MAX],int b[MAX],int num,int key)
{
    int count[key+1],i;
    for(i=0;i<=key;i++)
        count[i]=0;
    for(i=0;i<num;i++)
        ++count[a[i]];
    for(i=1;i<=key;i++)
        count[i]=count[i]+count[i-1];
    for(i=num-1;i>=0;i--)
        b[--count[a[i]]]=a[i];
}
void display(int a[MAX],int num)
{
    int i;
    printf("Elements after sorting are: ");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);
}
