#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, l;
    cin >> n >> l;

    vector<int> lines(n);
    for (int i = 0; i < n; i++)
    {
        string horse;
        cin >> horse;

        for (int j = 0; j < l; j++)
            lines[i] += (horse[j] == '1' && (j == l - 1 || horse[j + 1] == '0'));
    }

    array<int, 2> result = { *max_element(lines.begin(), lines.end()),0 };
    for (int i = 0; i < n; i++)
        result[1] += (lines[i] == result[0]);
    cout << result[0] << ' ' << result[1] << '\n';
}