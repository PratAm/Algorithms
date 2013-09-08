/*
	 header text
*/

#include<iostream>
#include<vector>

class Heap{
	public:
		void insert(int value);
		void heapSort();
		std::vector<int> data;
		void printSortedArray();

	private:
		int extractMin();
		std::vector<int> sortedData;
};

void Heap::printSortedArray(){

	std::vector<int>::iterator it;
	std::cout<<"Sorted Array: "<<std::endl;
	for(it = sortedData.begin();it != sortedData.end();it++)
		std::cout<< *it << " ";
	std::cout<<std::endl;
}

void Heap::insert(int value){
	
	data.push_back(value);
	int index = data.size() -1;

	while(index>0){

		int parent = (index-1)>>1;
		if(data[parent] > data[index]){
			std::swap(data[parent],data[index]);
			index = parent;
		}else{
			return;
		}
	}
}

int Heap::extractMin(){

	std::swap(data[0],data[data.size()-1]);
	int min = data[data.size()-1];
	data.pop_back();
	return min;
}

void Heap::heapSort(){

	int loop = 1;
	int index = 0;
	int child=0;
	int leftchild =0;
	int rightchild =0;

	while(loop <= 100){

		sortedData.push_back(extractMin());
		leftchild = (index<<1)+1;
		rightchild =(index<<1)+2;
		child = (data[leftchild] > data[rightchild]) ? rightchild : leftchild ;


		while (child < data.size() && data[index] > data[child]){
			std::swap(data[index] , data[child]);
			index = child;
			leftchild = (index<<1)+1;
			rightchild =(index<<1)+2;
			child = (data[leftchild] > data[rightchild]) ? rightchild : leftchild ;
		}
		index = 0;
		loop++;
	}
}



// overridden ostream operator

std::ostream& operator<<(std::ostream &os,const Heap& heap){

	std::vector<int>::const_iterator it;
  os<<"Heap Data :"<<std::endl;
	for(it=heap.data.begin();it!=heap.data.end();it++){
		os<<*it<<" ";
	}
  os<<std::endl;
	return os;
}

// driver program to test Heap class

int main(){

	Heap heap;
	int data =-1;
	int loop =1;
	for(loop=1;loop<=100;loop++){
		std::cin >> data;
		heap.insert(data);
	}
	
	std::cout<<heap;
	heap.heapSort();
  heap.printSortedArray();

	return 0;

}
