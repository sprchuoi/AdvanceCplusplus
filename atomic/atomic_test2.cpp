#include<atomic>
#include <exception>
#include<iostream>
#include <stdexcept>

using namespace std;

  int main() {
  int a = 5 ;
  int b = 5;
  try{
    
    if(a != b) cout<<"Not equal" <<endl;
    else throw runtime_error("Equal");
  }
  catch(const exception& e){
    cout<<e.what() << endl;
  }

  return 0;

}
