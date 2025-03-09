#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = 0;
    char l = '\0';
    for (char c : s)
    {
        result += (c == l ? 5 : 10);
        l = c;
    }
    cout << result << '\n';
}