#include <iostream>

using namespace std;

int main()
{
    int n = 0;

    std::cin >> n;

    float arr[n] = {0,};

    for(int i =0;i<n;i++){
        cin >> arr[i];
    }

    cout.precision(2);
    cout<<fixed;

    float max = arr[0];

    for(int i =0;i<n;i++){
        if(arr[i]>max) max = arr[i];
    }

    float sum = 0;

    for(int i =0;i<n;i++){
        arr[i] = arr[i]*100/max;
        sum += arr[i];
    }

    cout << sum/n <<"\n";

    return 0;
}