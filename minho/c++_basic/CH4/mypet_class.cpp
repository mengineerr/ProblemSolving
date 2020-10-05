#include <iostream>

class Animal {
    // private 내의 것들은 모두 객체 내에서 보호되고 있다
    // 자기 객체 안에서만 접근할 수 있고, 외부에서는 불가능
    // 명시하지 않으면 기본적으로 private로 배정
    private:
        int food;
        int weight;
    
    // public의 경우 외부에서도 이용 가능
    public:
        void set_animal(int _food, int _weight){
            food = _food;
            weight = _weight;
        }

        void increase_food(int inc){
            food += inc;
            weight += (inc/3);
        }

        void view_stat(){
            std::cout << "This animal's food   :" << food << std::endl;
            std::cout << "This animal's weight :" << weight << std::endl;
        }
}; // Don't forget semi-colon

int main()
{
    Animal animal;
    animal.set_animal(100,50);
    animal.increase_food(30);

    animal.view_stat();

    return 0;
}