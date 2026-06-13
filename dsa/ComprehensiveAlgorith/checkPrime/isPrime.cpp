#include<bits/stdc++.h>
#include<assert.h>

bool isPrime(int x)
{
  for(int p =2 ; p*p <=x ; p++) if(x %p ==0 ) return false;
  return true; 

}


int main(){

  assert(isPrime(7) == true);
  return 0;
}
