#include<bits/stdc++.h> 

using namespace std;
// class DSU
class findUnion {
  private:
  vector<int> parent; 
  vector<int> ranks;
  public :  

    findUnion(int size){
      ranks.resize(size);
      for(int i = 0 ; i < size ; i++){
        parent.push_back(i);
      }
    }

    // find funciton 
    int find(int value){
        if(parent[value] != value)
          return parent[value] = find(parent[value]);
        return parent[value];
    }

    // union function 
    bool unite(int value1 , int value2){
        // get the prepresent of value
        int value1_pre = find(value1);
        int value2_pre = find(value2); 
        if ( value1_pre == value2_pre) return false;
        if( ranks[value1_pre] < ranks[value2_pre] ){
          parent[value1_pre] = value2_pre;
        }
        else if (ranks[value2_pre]  < ranks[value1_pre]){
          parent[value2_pre] = value1_pre;
        }
        else {
          parent[value2_pre] = value1_pre;
          ranks[value1_pre]++;
        }
        return true;
    }

};

// the cyclic data


int main(){
  vector<pair<int , int>> data = {
    {1 ,2},
    {1 ,4},
    {2 ,3},
  };
  findUnion f(data.size()+1);
  for(auto d : data){
    if(!f.unite(d.first,d.second)){
      cout<<"cycle detected!!!"<<endl;
      return 0;
    }
  }
  cout<<"No cycle"<<endl;
  return 0;
}
