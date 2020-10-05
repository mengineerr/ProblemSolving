#include <iostream>
#include <string.h>

class string{
    char *str;
    int len;

    public:
        string(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의 
        string(const char *s);
        string(const string &s);
        ~string();

        void add_string(const string &s);
        void copy_string(const string &s);
        int strlen_();
        void show_string();
};

string::string(char c, int n){
    len = n;
    str = new char[len];

    for(int i = 0; i<n; i++){
        *(str+i) = c;
    }

}

string::string(const char *s){
    str = new char[strlen(s)+1];
    strcpy(str,s);
    len = strlen(s);

}

string::string(const string &s){
    str = new char[s.len];

    strcpy(str,s.str);
    len = s.len;

}

string::~string(){
    if(str) delete[] str;
}

void string::add_string(const string &s){
    len += s.len;

    char *temp = new char[len];

    strcpy(temp,str);
    strcat(temp,s.str);

    delete[] str;
    str = temp;
}

void string::copy_string(const string &s){
    delete[] str;

    str = new char[s.len];
    len = s.len;

    strcpy(str,s.str);
}

int string::strlen_(){
    return len;
}

void string::show_string(){
    std::cout << str <<std::endl;
}

int main()
{
    string str1('c',5);
    string str2(str1);
    string str3("hi");
    str1.show_string();
    str2.show_string();
    str3.show_string();

    str1.add_string("add");
    str3.copy_string("hello");
    
    str1.show_string();
    str2.show_string();
    str3.show_string();
    std::cout << str1.strlen_() << std::endl;

    return 0;
}