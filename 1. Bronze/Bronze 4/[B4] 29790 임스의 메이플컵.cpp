#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, u, l;
    cin >> n >> u >> l;

    bool isBOJ = (n >= 1'000);
    bool isMaple = (u >= 8'000 || l >= 260);

    string result = (isBOJ && isMaple) ? "Very Good" : (isBOJ ? "Good" : "Bad");
    cout << result << '\n';
}