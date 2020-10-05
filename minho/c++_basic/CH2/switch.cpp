#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int user_input;
    cout << "Show my information" << endl;
    cout << "1. Name   " << endl;
    cout << "2. Age    " << endl;
    cout << "3. Gender " << endl;
    cin >> user_input;

    switch(user_input){
        case 1:
            cout << "Siru!" <<endl;
            break;
        case 2:
            cout << "3 years" <<endl;
            break;
        case 3:
            cout << "Man" <<endl;
            break;
        default:
            cout << "no information" <<endl;
            break;

    }

    return 0;
}
