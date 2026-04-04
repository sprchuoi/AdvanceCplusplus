#include <bits/stdc++.h>
using namespace std;
// create the Linked List

class LinkedList{
  public:
   int val;
   LinkedList* next;
   //contructor 
  LinkedList(int val) : val(val) {
    this->next = nullptr;
  }
 };

// merge process
class MergeProcess{
  public:
   MergeProcess() {}
   LinkedList* mergePart(LinkedList* left , LinkedList* right){
   LinkedList dummy(-1);
   LinkedList* tail = &dummy;
   while(left && right ){
      if(left->val < right->val) {
       tail->next = left;
       left = left->next;
      }
      else {
       tail->next = right;
        right = right->next;
      }
      tail = tail->next;
    }
    // add the left one 
    tail->next = left ? left : right;
    return dummy.next;
  }
   LinkedList* sortLinkedList(LinkedList* head){
     if(!head || !head->next) return head;
     // node fast must go before slow 2 step  
     LinkedList* fast  = head->next;
     LinkedList* slow = head;
     while(fast && fast->next){
      slow = slow->next;
      fast = fast->next->next;
    }

    // slit by the slow-
    LinkedList* mid = slow->next;
    slow->next = nullptr;
    // recursive to separate path
     LinkedList* left = sortLinkedList(head);
     LinkedList* right = sortLinkedList(mid);
     // after get the part we will merge compare
     return mergePart(left , right );
   }
   void Display(LinkedList* head){
    LinkedList* curr = head;
    while(curr){
      cout<<curr->val<<" ";
      curr = curr->next; 
    }
  }

};


int main(){
  LinkedList a(1);
  LinkedList b(5);
  LinkedList c(29);
  LinkedList d(4);
  LinkedList e(6);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  MergeProcess p; 
  p.sortLinkedList(&a);
  p.Display(&a);
  return 0;
}
