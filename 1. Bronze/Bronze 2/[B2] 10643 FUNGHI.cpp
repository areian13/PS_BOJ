#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 8> s;
    for (int i = 0; i < 8; i++)
        cin >> s[i];

    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
            sum += s[(i + j) % 8];
        result = max(result, sum);
    }
    cout << result << '\n';
}