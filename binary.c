# include <stdio.h>
int bin(int arr[],int n,int x){
    int left=0,right=n-1;
    while (left<=right){
    int mid= left+((right-left)/2);
    if (arr[mid]==x)
    {
        return mid;
    }
    
    if (arr[mid]>x)
    {
        right=mid-1;
    }
    else
    {
        left=mid+1;
    }
}
return -1;

}
int main () {
    printf("enter the size of the array");
    int size;
    scanf("%d",&size);
    printf("enter the array of elements");
    int i,arr[100],n;
    for (i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    for ( i = 0; i < size; i++)
    {
        printf("%d\n",arr[i]);
    }
    int y;
    printf("enter the element to search");
    scanf("%d",&y);

    n= bin(arr,size,y);
    if (n==-1)
    {
        printf("element is not there");
    }
    else
    {
        printf("%d is the index",n);
    }
    return 0;
    

    
} 