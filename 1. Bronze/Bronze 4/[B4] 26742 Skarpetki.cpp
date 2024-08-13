#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string str;
    cin >> str;

    int b = 0;
    int c = 0;
    for (char ch : str)
    {
        b += (ch == 'B');
        c += (ch == 'C');
    }

    int result = b / 2 + c / 2;
    cout << result << '\n';
}