#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool Is666(int n)
{
	while (n > 0)
	{
		if (n % 1000 == 666)
			return true;

		n /= 10;
	}
	return false;
}

int main()
{
	FastIO;

	int n;
	cin >> n;

	int result = 665;
	for (int i = 0; i < n; i++)
	{
		while (!Is666(result + 1))
			result++;

		result++;
	}
	cout << result << '\n';
}