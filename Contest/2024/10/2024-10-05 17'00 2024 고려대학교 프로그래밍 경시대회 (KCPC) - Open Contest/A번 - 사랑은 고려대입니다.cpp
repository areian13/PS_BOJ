#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    static const string result = "LoveisKoreaUniversity";

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cout << result << ' ';
}