#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    stack<int> stack1;
    string str;

    for(int i = 0; i<N; i++){
        cin >> str;

        if(str == "push"){
            int num = 0;
            cin >> num;
            stack1.push(num);
        }
        else if(str == "pop"){
            if(!stack1.empty()){
                cout << stack1.top() << "\n";
                stack1.pop();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(str == "size"){
            cout << stack1.size() << "\n";
        }
        else if(str == "empty"){
            if(!stack1.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << 1 << "\n";
            }
        }
        else if(str == "top"){
            if(!stack1.empty()){
                cout << stack1.top() << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }
}