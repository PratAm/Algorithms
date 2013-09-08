/*
For the first two elements add smaller one to the maxHeap on the left, and bigger one to the minHeap on the right. Then process stream data one by one,

Step 1: Add next item to one of the heaps

   if next item is smaller than maxHeap root add it to maxHeap,
   else add it to minHeap

Step 2: Balance the heaps (after this step heaps will be either balanced or
   one of them will contain 1 more item)

   if number of elements in one of the heaps is greater than the other by
   more than 1, remove the root element from the one containing more elements and
   add to the other one

   If the heaps contain equal elements;
     median = (root of maxHeap + root of minHeap)/2
   Else
     median = root of the heap with more elements
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"heap.h"

const char INFILE[] = "Median.txt";
#define MAX	10000

	short RETURN_MEDIAN(short *A1,short *A2,short x)	{
		if (x<A2[1])
			MAX_HEAP_INSERT(A1,x);
		else
			MIN_HEAP_INSERT(A2,x);
		if (A1[0]-A2[0]>1)	
			MIN_HEAP_INSERT(A2,EXTRACT_MAX(A1));
		if (A2[0]>A1[0])	
			MAX_HEAP_INSERT(A1,EXTRACT_MIN(A2));
		return A1[1];
	}

	void print(short *A)	{
		short i;
		for (i=1; i<=A[0]; i++)
		printf("%d ",A[i]);
	}

	int main()	{

		short *A1,*A2,m=0;

		A1 = (short*)calloc(1+MAX,sizeof(short));   // min-heap
		A2 = (short*)calloc(1+MAX,sizeof(short));   // max-heap

		A1[0] = 1; A1[1] = 0;
		A2[0] = 1; A2[1] = 20000;

		char line[10];
		FILE *fp = fopen(INFILE,"r");

		while (fgets(line,10,fp)){	
		  m = (m + RETURN_MEDIAN(A1,A2,atoi(line))) % 10000;
		}

		printf("%d\n",m);

		return 0;
	}
