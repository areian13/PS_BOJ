#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k;
    string word;
    cin >> k >> word;

    string result = word;
    for (int i = 0; result[i] != '\0'; i++)
        result[i] = (result[i] - 'A' + 26 - 3 * (i + 1) - k) % 26 + 'A';
    cout << result << '\n';
}