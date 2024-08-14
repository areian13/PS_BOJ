#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string news = "NESW";
    int idx = 0;
    for (int i = 0; i < 10; i++)
    {
        int t;
        cin >> t;

        idx = (idx + t) % 4;
    }

    char result = news[idx];
    cout << result << '\n';
}