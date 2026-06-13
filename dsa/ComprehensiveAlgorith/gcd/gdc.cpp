#include <bits/stdc++.h>


int gdc(int a, int b){
  while(b){
    a%=b;
    std::swap(a, b);
  }
  return a;
}

int main(){
  int a=  10; 
  int b = 5; 
  std::cout<< gdc(a ,b );
  std::cout<<std::endl;
  return 0;
}
