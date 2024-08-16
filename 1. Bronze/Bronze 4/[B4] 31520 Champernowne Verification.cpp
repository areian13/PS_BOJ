#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int KthChamperwowne(string& n)
{
    int k = n.size();

    if (n[0] != '1')
        return -1;

    for (int i = 0; i < k - 1; i++)
    {
        if (n[i] + 1 != n[i + 1])
            return -1;
    }
    return k;
}

int main()
{
    FastIO;

    string n;
    cin >> n;

    int result = KthChamperwowne(n);
    cout << result << '\n';
}