#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = (n <= 100'000 && n % 2024 == 0 ? "Yes" : "No");
    cout << result << '\n';
}