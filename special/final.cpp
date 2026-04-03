#include<bits/stdc++.h>
#include <memory>
#include <thread>


class serviceA{
  private:
    int a;
    int c;
  public:
  serviceA(){
    std::cout<<"Vinfast"<<std::endl;
  }
  void function(int c){
    std::cout<<"this is the function hide"<<std::endl;
  }
  void func(int a) 
  {
     std::cout<<"base"<<a<<std::endl;
  }
};

class serviceB : virtual private serviceA{
  public:
  void func(int c){
    std::cout<<"derived"<<c<<std::endl;
  }  
  using serviceA::function;
};

class serviceC : virtual public serviceA{

};



int main(){
  auto a = std::make_unique<serviceC>();
  auto b = std::make_unique<serviceB>();
  std::thread task1([&] () {
    while(true)
      a->func(4);
  });
  std::thread task2([&] (){
    while(true){
      b->func(5);
      b->function(6);
    }
  });
  if(task1.joinable()){
    task1.join();
  }
  if(task2.joinable()){
    task2.join();
  }
  return 0;
}

