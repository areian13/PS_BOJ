#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        int a;
        cin >> a;

        result += a;
    }
    result /= 2;

    cout << result << '\n';
}