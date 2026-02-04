#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    for (int i = 0; i < 3; i++)
    {
        string s;
        getline(cin, s);
    }

    for (int i = 0; i < 10'000; i++)
        cout << -1 << '\n';
}