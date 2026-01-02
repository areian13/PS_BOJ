#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Slice(vector<int>& a)
{
    int n = a.size();
    vector<int> b;
    for (int i = 1; i < n; i += 2)
        b.push_back(a[i]);
    a = b;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    while (a.size() > 1)
        Slice(a);
    cout << a[0] << '\n';
}