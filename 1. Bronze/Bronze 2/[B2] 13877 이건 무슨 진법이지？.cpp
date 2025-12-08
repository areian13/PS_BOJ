#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int k;
        string n;
        cin >> k >> n;

        int oct = (n.find('8') != -1 || n.find('9') != -1 ? 0 : stoi(n, nullptr, 8));
        int dec = stoi(n);
        int hex = stoi(n, nullptr, 16);
        cout << k << ' ' << oct << ' ' << dec << ' ' << hex << '\n';
    }
}