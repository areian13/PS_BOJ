#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = (char)((n + 8) % 12 + 'A') + to_string((n + 6) % 10);
    cout << result << '\n';
}