#include <iostream>
#include <string.h>

class MyString {
    char * string_content;
    int string_length;
    int memory_capacity;

    public:
        MyString(char c);
        MyString(const char * str);
        MyString(const MyString& str);
        ~MyString();

        int length() const;
        void print() const;
        void println() const;
        int capacity() const;
        void reserve(int size);
        char at(int i) const;
        int find(int find_from, MyString& str) const;
        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;
        int compare(const MyString& str) const;

        MyString& assign(const MyString& str);
        MyString& assign(const char* str);

        MyString& insert(int loc, const MyString& str);
        MyString& insert(int loc, const char* str);
        MyString& insert(int loc, const char c);

        MyString& erase(int loc, int num);

        char& operator[](const int index) { return string_content[index]; }
};

MyString::MyString(char c){
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}

MyString::MyString(const char* str){
    string_length = strlen(str);
    string_content = new char[string_length];

    for(int i= 0; i<string_length; i++){
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];

    for(int i= 0; i<string_length; i++){
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString(){
    delete[] string_content;
}

int MyString::length() const {return string_length;}

void MyString::print() const {
    for(int i= 0; i<string_length; i++){
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for(int i= 0; i<string_length; i++){
        std::cout << string_content[i];
    }

    std::cout << "\n";
}

MyString& MyString::assign(const MyString& str) {
    if(str.string_length > memory_capacity){
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }

    for(int i = 0; i!=str.string_length; i++){
        string_content[i] = str.string_content[i];
    }

    string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if(str_length > memory_capacity){
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }

    for(int i = 0; i!=str_length; i++){
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}

int MyString::capacity() const {
    return memory_capacity;
}

void MyString::reserve(int size){
    if(size > memory_capacity){
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for(int i = 0; i!=string_length; i++){
        string_content[i] = prev_string_content[i];
        }

        delete[] prev_string_content;
    }
}

char MyString::at(int i) const {
    if(i >= string_length || i < 0){
        return 0;
    }
    else return string_content[i];
}

int MyString::find(int find_num, MyString& str) const {
    int i, j;
    if(str.string_length == 0) return -1;

    for(i = find_num; i < string_length - str.string_length; i++){
        for(j = 0; j < str.string_length; j++){
            if(string_content[i+j] != str.string_content[j]) break;
        }
        if(j == str.string_length) return i;
    }

    return -1;
}

int MyString::find(int find_num, const char* str) const {
    MyString temp(str);
    return find(find_num, temp);
}

int MyString::find(int find_num, char c) const {
    MyString temp(c);
    return find(find_num, temp);
}

int MyString::compare(const MyString& str) const{
    for(int i = 0; i < std::min(string_length, str.string_length);i++){
        if(string_content[i] > str.string_content[i] ) return 1;
        else if ( string_content[i] < str.string_content[i]) return -1;
    }
}

MyString& MyString::insert(int loc, const MyString& str){
    if(loc < 0 || loc > string_length) return *this;

    if(string_length + str.string_length > memory_capacity){
        if(memory_capacity * 2 > string_length + str.string_length){
            memory_capacity *=2;
        }
        else memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i;
        for(i = 0 ; i<loc; i++){
            string_content[i]= prev_string_content[i];
        }

        for(int j = 0; j!=str.string_length; j++){
            string_content[i+j] = str.string_content[j];
        }

        for(; i<string_length; i++){
            string_content[str.string_length+i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;

        return *this;
    }

    for(int i = string_length -1 ; i>=loc; i--){
        string_content[i + str.string_length] = string_content[i];
    }

    for( int i = 0; i < str.string_length; i++){
        string_content[i+loc] = str.string_content[i];
    }

    string_length += str.string_length;

    return *this;
}

MyString& MyString::insert(int loc, const char* str){
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c){
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num){
    if(num < 0 || loc <0 || loc > string_length) return *this;

    for(int i = loc + num; i < string_length; i++){
        string_content[i-num] = string_content[i];
    }

    string_length -= num;
    return *this;
}



int main()
{
    MyString str("abcdefg");
    str[3] = 'c';

    str.println();
}