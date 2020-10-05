#include <iostream>

int main() 
{
    std::cout << "<EX1>" << std::endl;

    int* p = new int;
    *p = 10;

    std::cout << *p << std::endl;

    // &p가 아님에 주의 (heap이 아닌 공간을 해제하려 하므로)
    // delete로 해제할 수 있는 메모리 공간은 new로 할당한 공간 뿐
    delete p; 

    //------------------------------------------------------------------

    std::cout << std::endl;
    std::cout << "<EX2>" << std::endl;

    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int* list = new int[arr_size];
    
    for( int i = 0; i < arr_size; i++){
        std::cin >> list[i];
    }

    for(int i = 0; i < arr_size; i++){
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }

    //배열의 경우 delete[] 주의!
    // new   와 delete
    // new[] 와 delete[]
    delete[] list;

    return 0;
}