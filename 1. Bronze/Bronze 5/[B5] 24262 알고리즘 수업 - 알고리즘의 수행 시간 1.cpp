#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin>> n;

    array<int, 2> result = { 1,0 };
    cout << result[0] << '\n';
    cout << result[1] << '\n';
}