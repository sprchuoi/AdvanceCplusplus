#include<bits/stdc++.h>
#include<algorithm>
#include<string>

// class subcriber 

class Subcriber{
  private:
    int id; 
    std::string name; 
  public:
  Subcriber(int id , std::string name) : id(id) , name(name){}
  void notify(std::string title){
    std::cout<< "new video is uploaded with title: "<<title<<std::endl;
  }
  // customize compare operatore  
  bool operator==(const Subcriber& other) const{
    return id == other.id;
  }
};

// create the class that could notify for all observer in that class {
class VideoUploader{
  private:
    std::vector<Subcriber> subcribers;
  
  public:
    VideoUploader() {}
    ~VideoUploader() = default;

    void subcribe(const Subcriber& sub){
      subcribers.push_back(sub);
    }

    void unsubcribe(const Subcriber& sub){
      subcribers.erase(std::remove_if(subcribers.begin() , subcribers.end() , [&] (const Subcriber& s){
        return s == sub;
      })
      );
    }
    void uploadVideo(std::string title){
          std::cout<< title<<std::endl;
          this->notifier(title);
    }
    void notifier(std::string title){
      // notify for all sub 
      for(Subcriber &sub : subcribers){
          sub.notify(title);
      }
    }
    
  
};


int main(){
  Subcriber a(1, "test1");
  Subcriber b(2, "test2");
  auto uploader = std::make_unique<VideoUploader>();
  uploader->subcribe(a);
  uploader->subcribe(b);
  uploader->uploadVideo("this is a cat");

  return 0;
}
