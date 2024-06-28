#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    bool isS = true;
    for (int i = 0; i < 8; i++)
    {
        int n;
        cin >> n;

        isS &= (n != 9);
    }
    char result = (isS ? 'S' : 'F');
    cout << result << '\n';
}