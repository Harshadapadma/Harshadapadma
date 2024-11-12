#include <stdio.h>


void selectionSort(int arr[], int n) {
    int i, j, minindex, temp;


    for (i = 0; i < n - 1; i++) {
      
        minindex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        


        temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    printf("enter the array of 5 elements");
    int i,arr[5],n;
    for (i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    

    nselectionsort(arr,5,y);
    for ( i = 0; i < 5; i++)
    {
        printf("%d\n",arr[i]);
    }
   

    
}