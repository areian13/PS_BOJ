#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Fraction
{
    int p, q;

    Fraction(int p, int q) : p(p), q(q) {}
    friend bool operator != (const Fraction& a, const Fraction& b)
    {
        return a.p != b.p || a.q != b.q;
    }
};

void Inorder(const Fraction& a, const Fraction& b, vector<Fraction>& fs, int& n)
{
    if (fs.empty() || fs.back() != a)
        fs.push_back(a);

    Fraction c(a.p + b.p, a.q + b.q);
    if (c.q <= n)
    {
        Inorder(a, c, fs, n);
        Inorder(c, b, fs, n);
    }

    if (fs.back() != b)
        fs.push_back(b);
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;
    k--;

    vector<Fraction> fs;
    Inorder({ 0,1 }, { 1,1 }, fs, n);

    cout << fs[k].p << ' ' << fs[k].q << '\n';
}