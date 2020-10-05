#include <iostream>
#include <string>
#include <string.h>

int main()
{
    std::string str;
    getline(std::cin,str);
    int str_len = str.length();
    int voca_num = 1;

    for(int i=0; i<str_len;i++){
        if(str.at(i)==' ' && i>0 && i < (str_len-1)){
            voca_num++;
        }
        else if(str.at(i)==' ' && str_len==1){
            voca_num = 0;
        }
    }

    std::cout <<voca_num <<"\n";


    /*여기부터 뻘짓

    int idx_voca_last[voca_num] ={0,};
    int temp = 0;

    for(int i=0; i<str_len;i++){
        if(str.at(i)==' ' && i>0 && i < str_len-1){
            idx_voca_last[temp] = i-1;
            temp++;
        }
        else if(i==str_len-1){
            idx_voca_last[temp] = i;
        }
    }


    int idx_start = 0;
    temp = 0;
    char *voca[voca_num];
    int cnt = 0;
    int cnt2 = 0;

    for(int i=0; i<str_len;i++){
        voca[cnt] = (char *)malloc(sizeof(char)*(idx_voca_last[temp]-idx_start));
        if(idx_start<=i && idx_voca_last[temp]>=i){
            voca[cnt][cnt2] = str.at(i);
        }

        if(i==(idx_voca_last[temp]+1)){
            cnt++;
            cnt2 = 0;
            idx_start = idx_voca_last[temp]+2;
            temp++;
        }
    }
    */
}