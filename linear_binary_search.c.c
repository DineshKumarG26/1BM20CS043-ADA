#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int RecursiveLineareSearch(int arr[], int value, int index, int n)
{
    int pos = 0;
    if(index >= n)
    {
        return 0;
    }
    else if (arr[index] == value)
    {
        pos = index + 1;
        return pos;
    }
     else
    {
        return RecursiveLineareSearch(arr, value, index+1, n);
    }
    return pos;
}
 
 
int recursiveBinarySearch(int array[], int start_index, int end_index, int element)
{
   if (end_index >= start_index)
   {
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle] == element)
      {
         return middle;
      }
      if (array[middle] > element)
         return recursiveBinarySearch(array, start_index, middle-1, element);
      return recursiveBinarySearch(array, middle+1, end_index, element);
   }
   return -1;
}


int main()
{
    int n, choice, value, pos, m = 0, arr[100];
    
    float t,end,begin,clk_tck;
    printf("Enter the total elements in the array  ");
    scanf("%d", &n);
 
     for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%n;
    }
 
    printf("Enter the element to search  ");
    scanf("%d", &value);
 
    printf("\n Linerar Search or Binary Search or Exit( 0 or 1 or 2)");
    scanf("%d",&choice);
    switch(choice)
    {
        case 0: 
            begin = clock();
            pos =  RecursiveLineareSearch(arr, value, 0, n);
            end = clock();
            printf("\n Time taken is %l CPU Cycles",(end-begin)/clk_tck);
               break;
        case 1:
        begin = clock();
        pos =  recursiveBinarySearch(arr, value, 0, n);
            end = clock();
            printf("\n Time taken is %l CPU Cycles",(end-begin)/clk_tck);
              break;
        case 2: exit(0);
                break;
        default:printf("Wrong choice !!!");
    }
    if (pos != 0)
    {
        printf("\n Element found at pos %d ", pos);
    }
    else
    {
        printf("\n Element not found");
    }
    return 0;
}