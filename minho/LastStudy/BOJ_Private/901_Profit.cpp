#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long A, B, C;
	cin >> A >> B >> C;

	// 예외 처리
	if (B >= C)
	{
		cout << -1 << "\n";

		return 0;
	}

	long long result = A / (C - B) + 1;

	cout << result << "\n";

	return 0;
}