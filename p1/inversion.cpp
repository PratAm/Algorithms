#include<iostream>
using namespace std;

int main(int argc, char**argv)
{

  int array[]={2,4,1,3,5};
  int inversion =0;

	 for(int i=0;i<5-1;i++){
		  for(int j=i+1;j<5;j++){
				  if(array[i]>array[j])
						   inversion++;

									}
						}
 cout<< "no of inversion: "<<inversion<<endl;

						return 0;
						}
