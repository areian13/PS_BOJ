#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    int s, f;
    cin >> s >> f;

    cout << (s <= f ? "high speed rail" : "flight") << '\n';
}