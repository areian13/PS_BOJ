#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Calc(int a, char op, int b)
{
	switch (op)
	{
	case '+':
		return a + b;

	case '-':
		return a - b;

	case '*':
		return a * b;

	case '/':
		return a / b;
	}
}
int main()
{
	FastIO;

	int a, b, c;
	char op1, op2;
	cin>> a >> op1 >> b >> op2 >> c;

	int l = Calc(Calc(a, op1, b), op2, c);
	int r = Calc(a, op1, Calc(b, op2, c));

	array<int, 2> result = { min(l,r),max(l,r) };
	cout << result[0] << '\n' << result[1] << '\n';
}