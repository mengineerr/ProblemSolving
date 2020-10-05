#include <iostream>
#include <string>
#include <string.h>

void reverseString(std::string &s) {
  size_t size = s.length();
  char temp;

  for (size_t i = 0; i < size / 2; i++) {
    temp = s[i];
    s[i] = s[(size - 1) - i];
    s[(size - 1) - i] = temp;
  }
}

int main()
{
    std::string str1;
    std::string str2;

    std::cin >> str1;
    std::cin >> str2;

    reverseString(str1);
    reverseString(str2);

    //std::cout << str1 << " " << str2 <<"\n";

    int check = str1.compare(str2);

    if(check > 0){
        std::cout << str1 << "\n";
    }
    else if(check < 0){
        std::cout << str2 << "\n";
    }
    else{
        std::cout << str1 << "\n";
    }
}