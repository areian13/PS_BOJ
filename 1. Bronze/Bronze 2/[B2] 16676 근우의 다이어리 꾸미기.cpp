#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 1, eleven = 11;
    while (eleven <= n)
    {
        result++;
        eleven = (eleven * 10 + 1);
    }
    cout << result << '\n';
}