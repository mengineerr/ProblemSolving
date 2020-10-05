#include <iostream>

namespace MyArray {
class Array; // 클래스 정의 순서 중요!!
class Int; // 미리 선언하지 않으면 friend Int; 인식 불가

class Array {
    friend Int;

    const int dim; // dim'th array
    int* size; //0~(dim-1)'s size array

    struct Address{
        int level;
        void* next;
    };

    Address* top;

    public:
        Array(int dim, int* array_size) : dim(dim) {
            size = new int[dim];
            for(int i = 0; i < dim;i++){
                size[i] = array_size[i];
            }

            top = new Address;
            top -> level = 0;
        }

        Array(const Array& arr) : dim(arr.dim) {
            size = new int[dim];
            for(int i = 0 ; i< dim; i++) size[i] = arr.size[i];

            top = new Address;
            top -> level = 0;

            inithialize_address(top);
        }

        ~Array() {
            delete_address(top);
            delete[] size; // Don't forget!!
        }

        void inithialize_address(Address* current){
            if(!current) return;
            if(current -> level == dim -1){
                current -> next = new int[size[current->level]];
                return;
            }

            current -> next = new Address[size[current->level]];
            for(int i = 0; i<size[current->level];i++){
                (static_cast<Address*>(current->next) + i)->level = current->level + 1;

                inithialize_address(static_cast<Address*>(current->next) + i);
            }
        }

        void delete_address(Address* current){
            if(!current) return;
            for(int i = 0; i < size[current->level] && current->level < dim-1 ; i++){
                delete_address(static_cast<Address *> (current->next)+i);
            }

            delete[] current->next; // 에러 발생
        }

        Int operator[](const int index);
};


class Int {
    void* data;
    int level;

    Array* array;

    public:
        Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL)
            : level(_level), data(_data), array(_array){
                if(_level < 1 || index >= array->size[_level - 1]){
                    data = NULL;
                    return;
                }
                if(level == array->dim){
                    data = static_cast<void* >((
                        static_cast<int*> (static_cast<Array::Address*>(data)->next)+index));
                }
                else{
                    data = static_cast<void* >(static_cast<Array::Address*>(
                        static_cast<Array::Address*>(data)->next) + index);
                }
        }

        Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

        operator int() {
            if(data) return *static_cast<int*>(data);
            return 0;
        }

        Int& operator=(const int& a){
            if(data) *static_cast<int* >(data) = a;
            return *this;
        }

        Int operator[](const int& index){
            if(!data) return 0;
            return Int(index, level+1, data, array);
        }
};

// Int를 실제로 이용하기 위해서 클래스 선언만으로 부족하므로 필요
// Int 클래스의 내부정보(생성자) 를 사용하는 경우에는 반드시 Int 클래스의 정의가 선행되어야 한다.
Int Array::operator[](const int index){
    return Int(index, 1, static_cast<void*>(top),this);
}

}

int main()
{
    int size[] = {2,3,4};
    MyArray::Array arr(3,size);

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            for(int k = 0 ;k<4;k++){
                arr[i][j][k] = (i+1)*(j+1)*(k+1);
            }
        }
    }
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            for(int k = 0 ;k<4;k++){
                std::cout << i << " " <<j << " " << k << " " << arr[i][j][k] << "\n";
            }
        }
    }
}