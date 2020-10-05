#include <iostream>
#include <string.h>

class Marine {
    static int total_marine_num;
    const static int i = 0;         //const static 의 경우 class 내부에서도 초기화 가능

    int hp;
    int coord_x, coord_y;  //location
    bool is_dead;

    const int default_damage;

    public:
        Marine();
        Marine(int x, int y);
        Marine(int x, int y, int default_damage);
        ~Marine() { total_marine_num--; }

        int attack();                        //return damage
        Marine& be_attacked(int damage_earn); 
        void move(int x , int y);
        static void show_total_marine(){
            std::cout << "Total Marine Numbers : " << total_marine_num << std::endl;
        }                                    // static 함수에서는 static 변수만 사용 가능
        void show_status();
};

int Marine::total_marine_num = 0; // static 변수의 초기화 방법, 클래스 내부 초기화 불가능

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
} 

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x), coord_y(y), hp(50), is_dead(false) , default_damage(default_damage) {
    total_marine_num++;
}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }

Marine& Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if(hp<=0) is_dead = true;

    return *this;
}

void Marine::show_status(){
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP       : " << hp << std::endl;
    std::cout << " Total Marine Numbers : " << total_marine_num <<std::endl;
}

void create_marine() {
    Marine marine3(10,10,4);
    marine3.show_total_marine();
}

int main()
{
    Marine marine1(2,3,10);
    marine1.show_total_marine();

    Marine marine2(3,5,10);  
    marine2.show_total_marine();

    create_marine();          //함수가 끝나고나면 함수 내부는 종결되므로 마린수는 다시 2명으로

    std::cout << std::endl << "Marine 1 attacks twice Marine 2! " <<std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();

    return 0;
}