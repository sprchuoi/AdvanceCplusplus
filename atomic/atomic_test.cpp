#include <atomic>
#include<bits/stdc++.h>

using namespace std;


class A {
  public:
    void foo(int a){
      cout<<a<<endl;
      a++;
    }
  


};
class B{
  public:
    void fooB(int b){
      cout<<b<<endl;
    }


};

atomic<bool> flag{false};

int main(){
  B b; 
  A a;
  thread process1([&b]{
        while(true){
          if(!flag.load(std::memory_order_acq_rel))
          {
            b.fooB(10);
            flag.store(true, memory_order_acq_rel);
          }  
        }
  });
  thread process2([&a]{
        while(true){
          if(flag.load(std::memory_order_acq_rel))
          {
            a.foo(20);
            flag.store(false, memory_order_acq_rel);
          }  
        }
  });
  process2.join();  
  process1.join();

  return 0;
}

