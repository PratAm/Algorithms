#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
const char INFILE[] = "HashInt.txt";
#define MAX	10000000

void fetch_hash(long *hash)	{
  FILE *fp = fopen(INFILE,"r");
  char line[10];
  long i;
  for (i=0; i<MAX; i++)
	hash[i] = 0;
  while (fgets(line,10,fp))
	hash[atoi(line)] ++;
}
short two_sum(long *hash, long t)	{
  long x;
  for (x = 1; x < (t-1)/2; x++)	
	if ((hash[x])&&(hash[t-x]))
	  return 1;
  return 0;
}
 
int main()
{
  long *hash = (long*)calloc(MAX,sizeof(long));
  fetch_hash(hash);
  short i,count = 0;
  for (i = 2500; i <= 4000; i++)
	if (two_sum(hash,i))
	  count++;
  printf("count = %d\n",count);

	return 0;
}

