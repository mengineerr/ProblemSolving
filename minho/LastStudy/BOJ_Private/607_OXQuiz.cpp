#include <iostream>
#include <string>

int main()
{
    int n;
    std::string name;

    std::cin >> n;

    int result[n] ={0,};
    int len = 0;
    int temp;
    int idx;
    int sum = 0;

    for(int i=0;i<n+1;i++){
        getline(std::cin,name,'\n');
        len = name.length();
        for(int k = 0; k<len ;k++){
            temp = 0;
            idx = k;
            while(name[idx]!='X' && idx>=0){
                temp++;
                idx--;
            }
            sum += temp;
        }
        result[i] = sum;
        sum = 0;   
    }

    for(int i=1;i<n+1;i++){
        std::cout << result[i] <<"\n";
    }

}