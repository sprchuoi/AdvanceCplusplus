#include<iostream>

enum class Sex {Male , Female };

struct Animal{
  std::string name ;
  int quantity;
  std::string sound;
  Sex sex; 
};
class AnimalBuilder {
   private:
     Animal m_animal;
   public: 
    explicit AnimalBuilder(std::string animal_name) {
      this->m_animal.name = animal_name;
    }
    AnimalBuilder& setSex(Sex sex){
      m_animal.sex = sex;
      return *this; 
    };
    AnimalBuilder& quantity(int quantity){
       m_animal.quantity = quantity;
       return *this;
    }; 
    AnimalBuilder& setSound(std::string sound){
     m_animal.sound = sound;
    return *this;
  };
    Animal build(){
    if(m_animal.sex == Sex::Male){
       // do abc
       std::cout<< "This animal is Male"<<std::endl;
    }
    else{ std::cout << "This animal is Female" <<std::endl;}

    // const auto animal = m_animal;
    // m_animal = Animal{};
    // return animal;
    return m_animal;
  };

  std::string getName(){ return m_animal.name;}
  Sex getSex() { return m_animal.sex;}
  int getQuatity(){ return m_animal.quantity;}
  std::string getSound(){return m_animal.sound;}

     

};


int main() {

  AnimalBuilder a("dog");
  a.quantity(2).setSex(Sex::Male).setSound("Gau Gau").build();
  std::cout<< "this animal have name as : " << a.getName() <<std::endl; 
  return 0;
}
