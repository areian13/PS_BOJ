#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsRight(int t1, int t2)
{
    return (t1 - t1 / 30 * 30) * 12 == t2;
}

int main()
{
    FastIO;

    int t1, t2;
    cin >> t1 >> t2;

    bool result = IsRight(t1, t2);
    cout << (result ? 'O' : 'X') << '\n';
}