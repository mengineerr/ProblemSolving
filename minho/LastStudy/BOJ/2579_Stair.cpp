#include <iostream>
#include <algorithm>

/*
void move(int point[], int check[], int loc, int& result, int max){
    result += point[loc];
    check[loc] = 1;
    
    if(loc==0){
        move(point, check, loc+1, result, max);
        move(point, check, loc+2, result, max);
    }
}
*/

int main()
{
    int stair = 0;
    std::cin >> stair;

    int *point = new int[stair+1];
    //int *check = new int[stair+1];
    int *dp = new int[stair+1];

    // Initialize check array
    // new's dynamic allocation cannot do initialization at the same time
    /*
    for(int i = 0; i<=stair; i++){
        check[i] = 0;
    }
    */

    for(int i = 0; i<=stair; i++){
        dp[i] = 0;
    }

    for(int i = 1; i <= stair; i++){
        std::cin >> point[i];
    }
    point[0] = 0;

    /*
    int loc = 0;
    int result = 0;
    */

   for(int i = 1; i <= stair; i++){
       if(i <= 2){
           dp[i] = dp[i-1] + point[i];
       }
       else if(i == 3){
           dp[i] = std::max(dp[i-2] + point[i], point[i-1] + point[i]);
       }
       else{
           dp[i] = std::max(dp[i-2] + point[i], dp[i-3] + point[i-1] + point[i]);
       }
   }

    std::cout << dp[stair] << "\n";

}