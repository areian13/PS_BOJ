#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
	FastIO;

	int n;
	cin>> n;

	string result = (n % 2 == 1 ? "Either" : ((n / 2) % 2 == 1 ? "Odd" : "Even"));
	cout << result << '\n';
}