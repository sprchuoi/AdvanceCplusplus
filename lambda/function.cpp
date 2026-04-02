#include<bits/stdc++.h>

using namespace std; 
int main() {

  int a , b;
  cin >> a >> b;
  function<int(int & , int &)> multiply = [&] (const int &a , const int &b){
      return a +b ;
  };
  cout<<"a+b "<<multiply(a , b);
  cout<<endl;
  return 0;
}
