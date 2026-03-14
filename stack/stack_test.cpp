#include<bits/stdc++.h>

using namespace std; 
using Task = fucntion<void()>; 
// the call stack class mean when we push the function to the callstack object that should exect and store as the call function 
class callStack{
  private:
    
    function<void()> func;
    stack<Task> m_callstack; // call stack to store the tasks
  
  public:
    callStack(){}
    

};

int main() {
  return 0;
}
