#include<bits/stdc++.h> 
#include<assert.h>
using namespace std;
class DSU {
  private:
  vector<int> parent;
  vector<int> ranks; // ranks using rank that could help to optimize the time complexity of merging function tree
  public:
    // With the union the first step that init the parent value as it self
    DSU(int size) {
      // resize ranks
      ranks.resize(size);
      for(int i = 0; i < size ; i++){
        parent.push_back(i); // we will get the parent[i] as i
      }
    }
    // @function find the parent of the node
    // @param input is the value of the node that we want to fidn the parent
    // @return the parent value of the node , to update the time complexity for this algorith , we using the path compressing to optimize the root . example after we find to root , we will update that parent node to direct root we found
    int find(int value){
      if(parent[value] == value)
        parent[value] = find(parent[value]); // path compressing
      return parent[value] = find(parent[value]); // path compressing
    }
    // @function this is the function that we want to merge from the value 2 with the value 1
    void unit(int value1 , int value2){
      // with this algorith that we will get the parent of value 1 and merge with the parent of the value 2 that mean merge the represent
      int value1_rep = find(value1);
      // represent of value 2 
      int value2_rep = find(value2);
      // if value 1 equal value 2 skip that
      if( value1_rep == value2_rep) return;
      // mark the represent of value 1 as value 2 that mean 2 is the parent of value 1
      if(ranks[value1_rep] < ranks[value2_rep]){ 
        // mark as the value2 is the parent of value 1
        parent[value1_rep] = value2_rep;
      }
      else if (ranks[value1_rep] > ranks[value2_rep]){
        parent[value2_rep] = value1_rep; 
      }
      else {
          // if two ranks is equal
          parent[value2_rep] = value1_rep; 
          ranks[value1_rep]++; // increase the ranks of value 1 because we have merged the value 2 to value 1
      } 
    }

};


// implementation of DSU
int main(void){
  DSU a(5); // create the object DSU
  a.unit(0, 1);
  a.unit(2 , 3);
  a.unit(3 , 1);
  // cout<<a.find(1) <<endl;
  // cout<<a.find(2) <<endl;
  // cout<<a.find(3) <<endl;
  // parent of 1 is 1 , parent of 2 is 1, because parent of 3 is 3 
  assert(a.find(2) == 1);
  cout<<endl;
  return 0;
}
