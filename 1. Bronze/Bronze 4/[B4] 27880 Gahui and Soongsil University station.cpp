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
        string way;
        int cnt;
        cin >> way >> cnt;

        if (cin.eof())
            break;

        result += cnt * ((way == "Es") ? 21 : 17);
    }
    cout << result << '\n';
}