#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string keys;
        cin >> keys;

        if (keys == "0")
            break;

        string text;
        cin >> text;

        int n = keys.size();
        int m = text.size();

        string result = "";
        for (int i = 0; i < m; i++)
        {
            char key = keys[i % n];
            result += ((text[i] + (key - 'A' + 1) - 'A') % 26) + 'A';
        }
        cout << result << '\n';
    }
}