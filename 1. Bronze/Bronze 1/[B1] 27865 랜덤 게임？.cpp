#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    while (true)
    {
        cout << "? " << n << endl;
        char c;
        cin >> c;

        if (c == 'Y')
        {
            cout << "! " << n << endl;
            break;
        }
    }
}