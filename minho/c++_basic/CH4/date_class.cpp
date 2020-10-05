#include <iostream>

class Date {
    int year_;
    int month_; //1~12
    int day_; //1~31

    public:
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);
        void ShowDate();

        //Constructor : 객체 생성시 자동으로 호출되는 함수, 초기화를 담당
        Date(int year, int month, int day){
            year_ = year;
            month_ = month;
            day_ = day;
        }

        /* 직접 default value 정의
        Date(){
            year_ = 2012;
            month_ = 7;
            day_ = 12;
        }

        이때 사용시
        Date day;   로 사용함에 유의 
        Date day(); 는 다른 의미
        */
        
        //Date() = default; 디폴트 생성자를 정의하라
};

void Date::SetDate(int year, int month, int date){
    year_ = year;
    month_ = month;
    day_ = date;
}

void Date::AddDay(int inc){
    day_ += inc;
            
    int end_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    while(day_>end_day[month_-1]){
        if(day_>end_day[month_-1]){
            day_ -= end_day[month_-1];
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc){
    month_ += inc;

    if(month_>12){
        int year_inc = (month_/12);
        month_ %= 12;
        year_ += year_inc;
    }
}

void Date::AddYear(int inc){
    year_ += inc;
}

void Date::ShowDate(){
    std::cout << year_ << " " <<month_ << " " << day_ << std::endl;
}


int main()
{
    Date date(2020,1,8); //       암시적방법
    //Date date = Date(2020,1,8); 명시적방법
    //date.SetDate(2020,1,8);     함수로 초기화
    //Date date;                  Default Constructor
    date.ShowDate();

    date.AddDay(85);
    date.ShowDate();

    date.AddMonth(30);
    date.ShowDate();

    date.AddYear(3);
    date.ShowDate();

    return 0;
}