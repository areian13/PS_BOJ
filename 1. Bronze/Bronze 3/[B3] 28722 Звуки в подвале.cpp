#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string belt;
    cin >> belt;

    string result = (belt.front() != belt.back() ? "Win" : "Lose");
    cout << result << '\n';
}