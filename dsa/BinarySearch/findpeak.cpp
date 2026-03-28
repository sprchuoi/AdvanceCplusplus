#include<bits/stdc++.h>
#include<assert.h> 
using namespace std;

class Processing{
	
  public:
	int findpeak(vector<int>& vec){
		int n = vec.size() ;
		// in this case we will using binary search to find the peak
		int left =0; 
		int right = n -1; 
		int mid; 
		int max =0;  
    if(vec.size() ==1 ) return vec[0];
		while(left < right){
			mid = left + ( right - left) /2 ; 
			if(vec[mid] < vec[mid+1]){
				left = mid +1;
			} 
			else{
				right = mid ;
			}
		}
		return max= vec[left];	
	}
};

int main(){
	vector<int> vec = {1, 3 ,4 ,5 , 5 ,6 ,3 ,2, 1};
	Processing a;
	cout<<a.findpeak(vec)<<endl;
  // display
  vector<int> veca = {1};
  assert(a.findpeak(veca) == 1);
  vector<int> b = {1,  2 , 4 ,5 ,6 ,7 ,6 ,5 ,3 , 1}; 
  assert(a.findpeak(b) == 6);
	return 0; 
}


