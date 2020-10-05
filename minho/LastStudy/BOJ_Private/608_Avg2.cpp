#include <iostream>

int main()
{
    int test = 0;
    int num = 0;

    std::cin >>test;

    std::cout.precision(3);
    std::cout<<std::fixed;

    float result[test] = {0,};

    for(int i = 0; i < test ; i++){
        std::cin >> num;
        float arr[num];
        float sum = 0;
        for(int j=0;j<num;j++){
            std::cin >> arr[j];
            sum += arr[j];
        }
        float avg = sum/num;
        
        int cnt = 0;
        for(int j=0;j<num;j++){
            if(arr[j]>avg) cnt++;
        }
        
        result[i] = (cnt/(float)num)*100;
    }

     for(int i = 0; i<test ; i++){
        std::cout << result[i] << "%" << std::endl;
    }
}