#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_MATRIX 21
#define MAX_CUSTOMER 401

using namespace std;

int rowDir[4] = { -1, 0, 1, 0 };
int colDir[4] = { 0, 1, 0, -1 };

struct INFO {
	int row, col, dis;
};

struct CUSTOMER {
	int startRow, startCol, arriveRow, arriveCol, dis;
	bool status; // false : not finished, true : finished
};

CUSTOMER customer[MAX_CUSTOMER];
int N, M, Oil;
int map[MAX_MATRIX][MAX_MATRIX];
int backLoacation[2] = { 0, 0 };

void binding(int& row, int& col, int num) { // num 0 : up, num 1 : right, num 2 : down, num 3 : left
	row = row + rowDir[num];
	col = col + colDir[num];
}

int findMinDis(int sRow, int sCol, int aRow, int aCol) {
	if(sRow == aRow && sCol == aCol){
		return 0;
	}
	else{
		queue <INFO> infoQ;
		bool trace[MAX_MATRIX][MAX_MATRIX];
		for (int i = 1; i <= N; i++) {
			fill_n(trace[i], N + 1, false);
		}
		infoQ.push({ sRow, sCol, 0 });
		int leastDis = __INT_MAX__;
		while (!infoQ.empty()) {
			int newRow = infoQ.front().row;
			int newCol = infoQ.front().col;
			int newDis = infoQ.front().dis;
			infoQ.pop();
			for (int i = 0; i < 4; i++) {
				int tempRow = newRow, tempCol = newCol;
				binding(tempRow, tempCol, i);
				if (tempRow == aRow && tempCol == aCol) {
					leastDis = min(leastDis, newDis + 1);
				}
				else if (tempRow <= N && tempRow >= 1 && tempCol <= N && tempCol >= 1 && map[tempRow][tempCol] == 0 && !trace[tempRow][tempCol]) {
					infoQ.push({ tempRow, tempCol, newDis + 1 });
					trace[tempRow][tempCol] = true;
				}
			}
		}
		return leastDis;
	}
}

int findCustomer() {
	int minDistance = __INT_MAX__;
	int checkDis = 0;
	queue<int> customerNum;
	for (int i = 1; i <= M; i++) {
		if(!customer[i].status){
			customer[i].dis = findMinDis(backLoacation[0], backLoacation[1], customer[i].startRow, customer[i].startCol);
			minDistance = min(minDistance, customer[i].dis);
		}
	}
	for (int i = 1; i <= M; i++) {
		if (!customer[i].status && customer[i].dis == minDistance) {
			checkDis++;
			customerNum.push(i);
		}
	}
	if (checkDis == 1) {
		return customerNum.front();
	}
	else {
		queue<int> tempCustomerInfo;
		int minRow = __INT_MAX__;
		while (!customerNum.empty()) {
			int tempRow = customer[customerNum.front()].startRow;
			minRow = min(tempRow, minRow);
			tempCustomerInfo.push({ customerNum.front() });
			customerNum.pop();
		}
		int checkRow = 0;
		while (!tempCustomerInfo.empty()) {
			int tempRow = customer[tempCustomerInfo.front()].startRow;
			if (tempRow == minRow) {
				customerNum.push({ tempCustomerInfo.front() });
				checkRow++;
			}
			tempCustomerInfo.pop();
		}
		if (checkRow == 1) {
			return customerNum.front();
		}
		else {
			int minCol = __INT_MAX__;
			while (!customerNum.empty()) {
				int tempCol = customer[customerNum.front()].startCol;
				minCol = min(tempCol, minCol);
				tempCustomerInfo.push({ customerNum.front() });
				customerNum.pop();
			}
			while (!tempCustomerInfo.empty()) {
				int tempCol = customer[tempCustomerInfo.front()].startCol;
				if (tempCol == minCol) {
					return tempCustomerInfo.front();
				}
				tempCustomerInfo.pop();
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> Oil;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	cin >> backLoacation[0] >> backLoacation[1];

	for (int i = 1; i <= M; i++) {
		cin >> customer[i].startRow >> customer[i].startCol >> customer[i].arriveRow >> customer[i].arriveCol;
		customer[i].status = false;
	}

	int leftCustomer = M;

	while (leftCustomer > 0 && Oil > 0) {
		int num = findCustomer();
		Oil = Oil - customer[num].dis;
		if (Oil < 0) Oil = 0;
		else {
			int dis = findMinDis(customer[num].startRow, customer[num].startCol, customer[num].arriveRow, customer[num].arriveCol);
			Oil = Oil - dis;
			if (Oil < 0) Oil = 0;
			else {
				Oil = Oil + dis * 2;
				backLoacation[0] = customer[num].arriveRow;
				backLoacation[1] = customer[num].arriveCol;
				customer[num].status = true;
				leftCustomer--;
			}
		}
	}

	if (leftCustomer == 0) cout << Oil;
	else cout << "-1";

	return 0;
}
