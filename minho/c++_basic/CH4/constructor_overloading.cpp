#include <iostream>

class Date {
    int year;
    int month;
    int day;

    public:
        void ShowDate();

        //overloading을 사용한 생성자 설정
        Date() {
            std::cout << "Call Basic constructor!" << std::endl;
            year = 2020;
            month = 1;
            day = 9;
        }

        Date(int year_, int month_, int day_){
            std::cout << "Call by input value!" << std::endl;
            year = year_;
            month = month_;
            day = day_;
        }
};

void Date::ShowDate(){
    std::cout << "Today is " << year << " year " << month << " month " << day << " day " << std::endl;
}

int main()
{
    Date day1 = Date();     //Set Default Value
    Date day2;              //Set Default Value
    Date day3(1020, 11,19); //Use overloading

    day1.ShowDate();
    day2.ShowDate();
    day3.ShowDate();


    return 0;
}