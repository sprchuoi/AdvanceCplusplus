#include<bits/stdc++.h>
#include<future>
#include<thread>
#include<string>
#include<iostream>

int doCallculate(int data , std::string& message){
  data += 1 ; 
  // after go in to this function we will change the message
  message += std::to_string(data);
  std::this_thread::sleep_for(std::chrono::seconds(10)); // sleep 10ms 
  return data; 
}

int main() {
  int data =1;
  std::string originalMessage = "Hello program";
  // TODO: Implement a async fution to doCallculate
  std::future<int> res = std::async(std::launch::async , doCallculate, data ,std::ref(originalMessage));
  std::cout<<originalMessage<<std::endl;
  std::cout<<res.get()<<std::endl;
  return 0;
}
