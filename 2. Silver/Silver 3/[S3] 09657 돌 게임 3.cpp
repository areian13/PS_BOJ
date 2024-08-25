#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = (n % 7 == 0 || n % 7 == 2 ? "CY" : "SK");
    cout << result << '\n';
}