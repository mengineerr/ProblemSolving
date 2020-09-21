#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for(int i = 0 ; i < phone_book.size() - 1 ; i++){
		if(phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) return false;
	}
    return answer;
}

int main(){

	vector<string> phone_books;

	phone_books.push_back("12");
	phone_books.push_back("123");
	phone_books.push_back("1235");
	phone_books.push_back("567");
	phone_books.push_back("88");

	cout << solution(phone_books);

	return 0;
}
