#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = "";
    for (int i = 0; i < n / 5; i++)
        result += 'V';
    for (int i = 0; i < n % 5; i++)
        result += 'I';
    cout << result << '\n';
}