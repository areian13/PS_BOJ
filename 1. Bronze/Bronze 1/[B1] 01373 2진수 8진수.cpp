#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string bin;
    cin >> bin;

    string result = "";
    for (int i = bin.size() - 1; i >= 0; i -= 3)
    {
        int value = 0;
        for (int j = 0; j < 3 && i - j >= 0; j++)
            value += (bin[i - j] - '0') * pow(2, j);
        result += (value + '0');
    }
    reverse(result.begin(), result.end());
    cout << result << '\n';
}