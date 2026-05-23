#include<bits/stdc++.h>
#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include<queue>
#include <utility>
#include<vector>
using namespace std; 

struct Task {
  int priority; 
  std::function<void()> func;

  // constructor
  Task(int p , std::function<void()> f): priority(p), func(std::move(f)){}
};

// compare function 

class Comparable{
  public:
  bool operator() (const Task& a,const Task& b) { 
         return a.priority < b.priority; // this help to comprare class
  }
};

class ThreadPool {
public :
  // constuctor
  int core;
  // emplement the head min Taks
  std::priority_queue<Task , vector<Task> , Comparable > queue;
  std::mutex mtx; 
  std::condition_variable cv;
  std::vector<std::thread> workers;
  bool stop{false};
  // init the worker to the task 
  ThreadPool(int core){
     this->core = core;
    for(int i = 0  ; i < core ; i++){
       workers.emplace_back([this] () { 
          // run the Task
          while(true){
          // creat the default task
          Task task(0 , [](){});
          {
            std::unique_lock<std::mutex> lock(mtx);
            // wait for have Task 
            cv.wait(lock, [this](){
                return !queue.empty() || stop;
            });
            if(stop && queue.empty()) return;
            // get task and exec
            task = queue.top();
            queue.pop();
          }
          task.func();
        }
      });
    };
  }
  template<typename F, typename... Arg>
  auto enqueue(int priority, F&& f, Arg&&... args ) -> std::future<std::invoke_result_t<F, Arg...>>{
    using return_type = std::invoke_result_t<F, Arg...>;
    // creat the lock guard 
    // creat task ptr with share pointer
    auto task_ptr = std::make_shared<std::packaged_task<return_type()>>(
      std::bind(std::forward<F>(f) , std::forward<Arg>(args)...)
    );
    {
         std::lock_guard<std::mutex> lock(mtx);
         queue.emplace(priority , [task_ptr](){
             (*task_ptr)();
         });
    } 
    // notify all 
    cv.notify_one();
    return task_ptr->get_future();
  }

  // destructure
  ~ThreadPool() {
   {
      std::unique_lock<std::mutex> lock(mtx);
      stop = true; 
   }
    cv.notify_all();
    for(auto &t : workers){
      if (t.joinable()) t.join();
    }
  }
};

void Add(int a , int b){
  std::cout<<a + b <<std::endl;
}

class B {
   public:
   B(){}
   void funcB() {
    std::cout<<"Hello B " <<std::endl;
  };
};

int main() {
  int CoreSize = 2;
  auto b = std::make_unique<B>();
  auto a = b.get();
  // ThreadPool thread(CoreSize); // will declare on stack
  // thread.enqueue(0, Add , 2 ,3 );
  // thread.enqueue(1 , Add,  3 ,4 );
  thread t1([&a](){
       a->funcB();
  });
  t1.join();
  return 0;
}
