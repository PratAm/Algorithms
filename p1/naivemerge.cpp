#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct data {

 						int array [100000];

								void noofInversion();
								void populateData();
								void printdata();
								unsigned long long inline getinversion(){ return inversion;}

								data():inversion(0LL),noofData(100000){
								 
									memset(array,0,100000);
								}


								private:
								unsigned long long inversion;
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
		ifstream in("IntegerArray.txt");

		if(in){
				int i =0;
				while(!in.eof()){
					in >> array[i++];

					//  while (getline(in,temp))
					// cout << temp <<endl;
							}
			}
}

void data::noofInversion(){
 
	 for(int i=0;i<noofData-1;i++){
		  for(int j=i+1;j<noofData;j++){
				  if(array[i]>array[j])
						   inversion++;

									}
						}
		}

  //driver for inversions

	int main(int argc,char **argv)
	{
	 data mydata;

	 mydata.populateData();
  mydata.printdata();
		mydata.noofInversion();

		cout<< "no of inversions:" << mydata.getinversion() <<endl;		

		printf("no : %llu\n" ,mydata.getinversion());

	 return 0;

	 }
