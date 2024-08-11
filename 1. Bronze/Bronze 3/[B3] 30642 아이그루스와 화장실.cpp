#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    string mascot;
    cin >> n >> mascot >> k;

    int result = ((mascot == "annyong" && k % 2 == 1) ||
        (mascot == "induck" && k % 2 == 0)) ?
        k : (k == 1 ? k + 1 : k - 1);
    cout << result << '\n';
}