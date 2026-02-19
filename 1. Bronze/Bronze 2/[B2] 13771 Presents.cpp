#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<double> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    nth_element(p.begin(), p.begin() + 1, p.end());
    printf("%.2lf\n", p[1]);
}