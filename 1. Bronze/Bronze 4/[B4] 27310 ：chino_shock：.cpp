#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string emoji;
    cin >> emoji;

    int result = emoji.size();
    for (char c : emoji)
    {
        if (c == ':')
            result++;
        else if (c == '_')
            result += 5;
    }
    cout << result << '\n';
}