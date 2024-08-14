#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int result = 0;

    while (true)
    {
        string str;
        getline(cin, str);

        if (cin.eof())
            break;

        result++;
    }
    cout << result << '\n';
}