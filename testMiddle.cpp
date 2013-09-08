#include<iostream>

using namespace std;
int main(){

 int array[]={9,7,5};
 int start = 0;
 int end =2;

 int middle_index = (end-start+1)/2;
 cout<<"middle"<<middle_index<<endl; 
 int first = 0;
 int second = -1;
int high = array[start];
int high2= -1;


 if (high< array[middle_index]){
    high = array[middle_index];
    second = first;
    first = middle_index;
   high2 = high;
   }else if(high2<array[middle_index]){
      high2 = array[middle_index];
      second = middle_index;
     }

 if (high < array[end]){
    high = array[end];
    second = first;
    first = end;
    high2= high;
   }else if(high2<array[end]){
        high2= array[end];
         second = end;
     }
 cout<< "value is "<< array[second]<<endl;
return 1;
}
