#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct data {

	int array [10000];

	unsigned long long  quicksort(int start,int end);
	void populateData();
	void printdata();
	int get_pivot(int start,int end);
	void swap(int& a, int& b);
	//					unsigned long long inline getConversion(){ return count;}

	data():noofData(10000){
		memset(array,0,10000);
	}
	private:
	int noofData ;

};


void data::printdata(){

	for(int i =0;i<noofData;i++){
		cout << "array["<<i<<"]: "
			<<array[i]
			<<endl;
	}
}

void data::populateData()
{
	ifstream in("QuickSort.txt");

	if(in){
		int i =0;
		while(!in.eof()){
			in >> array[i++];

		}
	}
}

int data::get_pivot(int low,int high){

	// return start;
	//  return end;
	int pivotindex = (high+low)/2;
		if (array[high] > array[pivotindex]) {
			if (array[low] > array[high])
			pivotindex = high;
		else if (array[low] > array[pivotindex])
			pivotindex = low;

	} else {
		if (array[low] < array[high])
			pivotindex = high;
		else if (array[low] < array[pivotindex])
			pivotindex = low;
	}
	return pivotindex;
	/* 
		 int first = 0;
		 int second = -1;
		 int high1 = array[start];
		 int high2= -1;


		 if (high1< array[middle_index]){
		 high1 = array[middle_index];
		 second = first;
		 first = middle_index;
		 high2 = high1;
		 }else if(high2<array[middle_index]){
		 high2 = array[middle_index];
		 second = middle_index;
		 }

		 if (high1 < array[end]){
		 high1 = array[end];
		 second = first;
		 first = end;
		 high2= high1;
		 }else if(high2<array[end]){
		 high2= array[end];
		 second = end;
		 }
		 return second;
	 */
}

void data::swap(int& a, int& b){
	int temp;
	temp = a;
	a= b;
	b= temp;
}


unsigned long long data::quicksort(int m,int n){

	int i,j,k,pivot,temp;
	unsigned long long count=0;

	i = m;j =n;
	if(m>=n)
		return 0;

	// find the pivot
	k = get_pivot(m, n); 

	// swap pivot to start of array
	data::swap(array[k],array[m]);

	count = n-m;
	pivot = array[m];
	i=m+1;

	for (j=m+1;j<=n;j++){
		if(array[j]<pivot){
			// swap the elements
			data::swap(array[i],array[j]);
			i++;
		}
	} 
	// swap the pivot with ith array element
	i--;
	data::swap(array[m],array[i]);

	//			count += data::quicksort(array,m,i-1);
	//			count += data::quicksort(array,i+1,n);
	count += quicksort(m,i-1);
	count += quicksort(i+1,n);
	return count;
}

//driver for quicksort

int main(int argc,char **argv)
{
	data mydata;

	mydata.populateData();
	mydata.printdata();
	unsigned long long count = mydata.quicksort(0,10000-1);

	cout<< "no of conversion:" << count <<endl;		

	printf("conversion : %llu\n" ,count);

	return 0;

}
