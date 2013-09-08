#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct data {

								int array [100000];

								void mergesort();
								void populateData();
								void printdata();

								private:
								void merge(int first,int middle,int end);
};

void data::merge(int first,int middle,int end){

 while ()

void data::mergesort(uint32_t start,uint32_t end){
 
if(start<end){
 uint32_t middle = (start+end)/2;
 data::mergesort(start,middle);
 data::mergesort(middle+1,end);

	merge(start,middle+1,);

	return 0;

	}




void data::printdata(){
								for(int i =0;i<100000;i++){
																cout << "array["<<i<<"]: "
																     <<array[i]
																					<<endl;
								}
}

void data::populateData()
{
								ifstream in("IntegerArray.txt");
				//				string temp;

								if(in){
																int i =0;
																while(!in.eof()){
																								in >> array[i++];

																								//  while (getline(in,temp))
																								// cout << temp <<endl;


																}
								}
}
 

  //driver for mergeshort

	int main(int argc,char **argv)
	{
	 data mydata;

	 mydata.populateData();
  mydata.printdata();
		mydata.mergesort(0,100000-1);
				

	 return 0;

	 }
