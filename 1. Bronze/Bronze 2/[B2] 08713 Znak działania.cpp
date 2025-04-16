#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Bs(int n)
{
    if (n >= 0)
        return to_string(n);
    return '(' + to_string(n) + ')';
}

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    array<pair<int, char>, 3> val =
    {
        pair<int, char>
        {a + b,'+'},
        {a - b,'-'},
        {a * b,'*'}
    };
    sort(val.begin(), val.end(),
        [](auto& a, auto& b)
        {
            return a.first < b.first;
        }
    );

    if (val[1].first == val[2].first)
        printf("NIE\n");
    else
        printf("%s%c%s=%s\n", Bs(a).c_str(), val[2].second, Bs(b).c_str(), Bs(val[2].first).c_str());
}