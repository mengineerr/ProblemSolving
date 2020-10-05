#include <iostream>
#include <string.h>

class Marine {
    int hp;
    int coord_x, coord_y;  //location
    int damage;            //attack power
    bool is_dead;
    char* name;

    public:
        Marine();
        Marine(int x, int y, const char* marine_name);
        Marine(int x, int y);
        ~Marine();

        int attack();                        //return damage
        void be_attacked(int damage_earn); 
        void move(int x , int y);

        void show_status();
};

Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name){
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
    name = new char[strlen(marine_name)+1];
    strcpy(name,marine_name);
}

Marine::Marine(int x, int y){
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::~Marine(){
    std::cout << name << " 의 소멸자 호출! " << std::endl;
    if(name != NULL) {
        delete[] name;
    }
}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if(hp<=0) is_dead = true;
}

void Marine::show_status(){
    std::cout << " *** Marine : " << name << " *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP       : " << hp << std::endl;
}

int main()
{
    /* Basic code!
    Marine marine1(2,3);
    Marine marine2(3,5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "Marine 1 is attacking Marine 2" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    */

    Marine* marines[100];

    marines[0] = new Marine(2,3,"Marine 2");
    marines[1] = new Marine(3,5,"Marine 1");

    marines[0] -> show_status();
    marines[1] -> show_status();

    std::cout << std::endl << "Marine 1 attacks Marine 2" << std::endl;

    marines[0] -> be_attacked(marines[1]->attack());

    marines[0] -> show_status();
    marines[1] -> show_status();

    delete marines[0];
    delete marines[1];
}
