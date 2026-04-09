#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ForbiddenZero(int n)
{
    while (to_string(n).find('0') != -1)
        n++;
    return n;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = ForbiddenZero(n + 1);
    cout << result << '\n';
}