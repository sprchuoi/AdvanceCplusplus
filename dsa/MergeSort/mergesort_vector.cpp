#include<bits/stdc++.h>

using namespace std;

class sortProcess{
 public:
  sortProcess() {}
  void mergPart(vector<int> &data , int l , int mid,int r){
  
    vector<int> temp; 
    int  i = l ; 
    int j = mid + 1 ;
    while(i <= mid  && j <= r){
      if (data[i] < data[j]) temp.push_back(data[i++]);
      else temp.push_back(data[j++]);
    }
    // sort the left one
    while( i <= mid) temp.push_back(data[i++]);
    // sort the right one 
    while( j <= r) temp.push_back(data[j++]);
    for(int i = 0 ; i < temp.size() ; i++){
      data[l+i] = temp[i];
    }
    // copy the array sorted to current data
  }

  void mergeSort(vector<int>& data , int l , int r){
    if(l >= r ) return;
    
    int mid = (r+l)/2 ;
    // seperate left
    mergeSort(data, l , mid);
    // seperate right
    mergeSort(data, mid +1, r);

    // merge every mergPart
    mergPart(data , l , mid, r);

  }
};


int main(){
  sortProcess a;
  vector<int> dataA = {1 ,8 ,4 ,6 ,7 };
  a.mergeSort(dataA, 0, dataA.size() -1 );
  for(int i = 0 ;i < dataA.size() ; i++){
    cout<< dataA[i] << " "; 
  }
  cout<<endl; 
  return 0;
}
