#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char LShift(char c, int n)
{
    return (c - 'A' + 26 - n) % 26 + 'A';;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    for (int i = 0; i < 26; i++)
    {
        for (char c : s)
        {
            char result = LShift(c, i);
            cout << result;
        }
        cout << '\n';
    }
}