#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string n;
        cin >> n;

        int sum = 0;
        for (char c : n)
            sum += c - '0';

        string result = (sum % 9 == 0 ? "YES" : "NO");
        cout << result << '\n';
    }
}