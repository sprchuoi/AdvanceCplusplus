#include<bits/stdc++.h>
#include <memory>
#include <mutex>

using namespace std;


template<class T> 
class Node{
  private:
    T value;
  public:
    Node<T>* next;
    Node(T value) : value(value){}
    int getValue(){
      return this->value;  
    }
};

template<class T>
class ThreadSafeQueue{
private:
    mutex m_mtx;
    Node<T>* head;
    Node<T>* tail;

public:

    ThreadSafeQueue(){
        head = nullptr;
        tail = nullptr;
    }

    void enqueueData(T data){
        auto newNode = new Node<T>(data);

        unique_lock<mutex> lock(m_mtx);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeueData(){
        unique_lock<mutex> lock(m_mtx);

        if(head == nullptr)
            return;

        Node<T>* temp = head;
        head = head->next;

        if(head == nullptr)
            tail = nullptr;

        delete temp;
    }

    Node<T>* getHead(){
        unique_lock<mutex> lock(m_mtx);
        return head;
    }
    
    Node<T>* getTail(){
      unique_lock<mutex>lock(m_mtx);
      return tail;
   }
};
int main(){
  auto queue_safe = make_unique<ThreadSafeQueue<int>>();
  int a = 0;
  queue_safe->enqueueData(a);
  a++;
  queue_safe->enqueueData(a);
  auto node = queue_safe->getHead();
  auto node_tail = queue_safe->getTail();
  cout<<node->getValue()<<endl;
  cout<<node_tail->getValue()<<endl;
  
  return 0;
}
