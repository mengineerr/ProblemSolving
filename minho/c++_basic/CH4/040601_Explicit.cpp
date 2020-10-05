#include <iostream>

class MyString {
    char *string_content;
    int string_length;
    int memory_capacity;

    public:
        explicit MyString(int capacity);
        MyString(const char* str);
        MyString(const MyString& str);
        ~MyString();

        int length() const;
};

MyString::MyString(int capacity){
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
}

MyString::MyString(const char* str){
    string_length = 0;
    while(str[string_length++]){

    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for(int i = 0; i<string_length ; i++){
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];

    for(int i = 0; i < string_length ; i++){
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() {
    delete[] string_content;
}

int MyString::length() const {
    return string_length;
}

void DoSomethingWithString(MyString s){
    //Do anything
}

int main()
{
    MyString s(3);

    //DoSomethingWithString(3); explicit 때문에 암시적변환 불가능
    //MyString s = 5;           Same Case!
    
}