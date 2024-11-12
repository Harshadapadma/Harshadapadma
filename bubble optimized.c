#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    

}

void insertion(int arr[],int n){
    int i,j,temp;
    int flag=0;
    for ( i = 0; i < n; i++)
    {
        int flag=0;
        for ( j= 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;


            }
             print(arr,n);
        }
        if (n==1)
        {
            break;
        }
        
    }
    
    
}
int main() {
    int arr[] = {1,3,6,98,65,2,73};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion(arr,n);
    int i;
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d\n ", arr[i]);
    }
  
    return 0;
}