
#include<iostream>
#include<stdio.h>

using namespace std;
 
void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
 
int choose_pivot(int i,int j )
{
   return i;
}
 
int quicksort(int array[],int m,int n)
{
   int i,j,pivot,temp;
   int count=0;

   i = m;j =n;
   if(m>=n)
     return 0;
 
   count = n-m;
			pivot = array[m];
			i=m+1;
			
			for (j=m+1;j<=n;j++){
			 if(array[j]<pivot){
						// swap the elements
			 	 temp = array[i];
						array[i]=array[j];
						array[j]=temp;
						i++;
					}
    } 
   // swap the pivot with ith array element
			temp = array[m];
			array[m]= array[i-1];
			array[i-1]= temp;
   i--;

			count += quicksort(array,m,i-1);
			count += quicksort(array,i+1,n);
  return count;
}

void printlist(int list[],int n)
{
   int i;
   for(i=0; i < n;i++)
      printf("%d\t",list[i]);
}
 
int main()
{
   int MAX_ELEMENTS;
   int list[100];
 
   int i = 0;
   printf("Enter the number of elements to be sorted:");
   scanf("%d",&MAX_ELEMENTS);
   printf("Enter the elements to be sorted:\n");
   for(i = 0; i < MAX_ELEMENTS; i++ ){
       scanf("%d",&list[i]);
   }
   printf("\nThe list before sorting is:\n");
   printlist(list,MAX_ELEMENTS);
    
   // sort the list using quicksort
  int count = quicksort(list,0,MAX_ELEMENTS-1);
 
   // print the result
   printf("\nThe list after sorting using quicksort algorithm:\n");
   printlist(list,MAX_ELEMENTS);
   printf("\n");

 cout <<"comparsion" <<count <<endl;

   return 1;

}
