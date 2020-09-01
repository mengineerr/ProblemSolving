#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map <string, int> m;

int main(){
    m["a"] = 1;
    m["b"] = 1;
    m["c"] = 1;
    m["d"] = 1;
    m["e"] = 1;
    m["f"] = 1;


    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;
    m["a"]++;
    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;
    cout << m.find("z")->second;

    return 0;
}
