#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// template <T>
class Heap {
	vector<int>vec; // CBT

public :
	// ---- push -----
	void push(int val){
		// step 1
		vec.push_back(val);
	
		// heapify
		int x = vec.size()-1;    /*new node at the end || child */
		int parent = (x-1)/2; // parent index

	while(parent >= 0 && vec[x] > vec[parent]){

		swap(vec[x] ,vec[parent]);

		x = vec[parent];
		
		parent = (x -1)/2;
	}


}

	void heapify(int i){
		if(i >= vec.size()){ // if only one Node;
			return;
		}

		int l = 2 * i + 1;
		int r = 2 * i + 2;
			
		int maxI = i;
		if(l < vec.size() && vec[l] > vec[maxI]){ // if greater left child
			maxI = l;
		}

		if(r < vec.size() && vec[r] > vec[maxI]){  // if greater right child
			maxI = r;
		}

		swap(i,maxI); // parent swaped  with greater  child
	
			
		if(maxI != i){  // if swapping with child nodes

			heapify(maxI);
		}	
	}

	
	// ----- pop -----
	void pop(){
		// step 1
		swap(vec[0] , vec[vec.size() -1]);
		
		// step 2
		vec.pop_back();

		//step 3 heapify
		heapify(0);
	
}
	
	// ----- top ----
	int top(){
	return vec[0];
}
	
	// ---empty- ---
	bool  empty(){
	return vec.size() == 0;
}
	


};

// objec-PQ 

	
class Student {
	public:
	string name;
	int marks;

	Student(string n , int m){
	this->name = n;
	this->marks = m;	
	}

	
	/*
	  Operator Overlaoding use now ; " < " overlaod 
	*/
	bool  operator < (const Student &obj) const {
		return this->marks  > obj.marks;    // acesending order checking
	}
		 
};


struct ComparePair
{
	bool operator () (pair<string,int> &p1,pair<string,int> &p2){
		return p1.second < p2.second;
	}
};


int main(){
	priority_queue<pair<string ,int>,vector<pair<string,int>>, ComparePair>pq;   // default pair ke first basis  { int , string } => int  or string ,int => string
	pq.push(make_pair("aman" ,2));
	pq.push(make_pair("bhumika" ,50));
	pq.push(make_pair("osman" ,5));
	pq.push(make_pair("noor" ,15));

	// pq.push(make_pair(1 , "noor"));
	// pq.push(make_pair(15,"osman"));

	while (!pq.empty())
	{
		cout << "top =" << pq.top().first << ", " << pq.top().second << endl;
		pq.pop();
	}
	
	// pq.push(Student("osman",50));
	// pq.push(Student("noor",100));
	// pq.push(Student("bhumii",101));
		
	// while(!pq.empty()){
	// 	cout << "top :" << pq.top().name << "marks :" << pq.top().marks <<  endl;
	// 	pq.pop();
	// }

	return 0;

}
 