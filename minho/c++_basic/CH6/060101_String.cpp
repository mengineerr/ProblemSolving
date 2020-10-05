#include <iostream>
#include <string>


int main()
{
    std::string s = "abc";
    std::string t = "def";
    std::string s2 = s;

    std::cout << s << " 's length : " << s.length() << "\n";
    std::cout << s << " add with " << t << " is " << s+t << "\n";

    if(s == s2){
        std::cout << s << " is similar with " << t << "\n";
    }
    else {
        std::cout << s << " is not similar with " << t << "\n";
    }

    return 0;
}
