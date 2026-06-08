#include<bits/stdc++.h>
#define ALPHALEN 26


// for in the trie , the charactor will mapping to the index of the array of children in the node


class TrieNode{ 
public:
  // node children
  bool endofWord;
  TrieNode* children[ALPHALEN];
  // contructor 
  TrieNode(){
    endofWord = false ;
    for(int i = 0 ; i < ALPHALEN ; i++){
      children[i]  = nullptr;
    }
  }
};

class Trie{
private :
  TrieNode * root; 
public: 
  Trie() { 
    root = new TrieNode() ;
  }

  // function using for insert
  bool search(std::string word) {
    TrieNode* node = root;
    for(char c  : word){ 
      int index = c - 'a';
      if(!node->children[index]) {
        return false;
      }
      // go to the next node-
      node = node->children[index];
    } 
    return node->endofWord;
  }
  // function insert
  void insert(std::string word){
    TrieNode * node = root;
    for(char c : word) {
      int index = c - 'a';
      if(!node->children[index]){
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    // after traversal all of the character in word we should mark that as end of word
    node->endofWord = true;
  }
  // delete function
  void deleteWord(std::string word) {
    TrieNode* node = root; 
    for(char c : word){
      int index = c- 'a';
      if(!node->children[index]){
        return; // word note found
      }
      node = node->children[index];
    }
    if(node->endofWord == true){
      node->endofWord = false; // mark as not end of Word
    } 
  }
  // void print Trie node 
  void printTrie(TrieNode* node , std::string prefix) const {
    if(node->endofWord){
      std::cout<<prefix<<std::endl;
    }
    for(int i = 0; i < ALPHALEN ; i++){
      if(node->children[i]){
        printTrie(node->children[i] , prefix + char('a' +i));
      }
    }
  }
  // function to print start from the root
  void printTrie() const { 
    printTrie(root , "");
  }
};
int main() { 
  // create Trie 
  Trie trie;
  trie.insert("greek");
  trie.insert("greeks");
  trie.insert("geeky");
  trie.insert("rookie");
  std::cout<<"Trie Content :" <<std::endl;
  trie.printTrie();
  // search for Word
  std::cout<< "greek : "  << trie.search("greek");
  std::cout<<std::endl;
  std::cout<< "hi : " << trie.search("hi"); 
   std::cout<<std::endl;
std::cout<< "roakie2 :" << trie.search("rookie2");
  std::cout<<std::endl;
 std::cout<< "rookie : "<< trie.search("rookie");
  std::cout<<std::endl; 
  return 0;

}
