#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode = NULL;
    int dat;
    while (true)
    {
        cout << "데이터 입력: ";
        cin >> dat;
        if(dat < 1) break;

        newNode = new Node();
        newNode->data = dat;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
        }else tail->next = newNode;
        tail = newNode;
    }
    cout << endl;

    if(head == NULL){
        cout << "None";
    }else{
        cur = head;
        cout << cur->data << " ";
        while (cur->next != NULL)
        {
            cur = cur->next;
            cout << cur->data << " ";
        }
        
    }
    
    return 0;
}