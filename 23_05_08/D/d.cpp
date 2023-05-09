#include <iostream>
#include <vector>

using namespace std;
const long long maxIslands = 2e5 + 5;
bool visited[maxIslands];
long long subtrees[maxIslands];
vector<long long> g[maxIslands];
long long islands, friends;
const long long mod = 1e9 + 7;

// To compute x^y under modulo m
long long power(long long x, long long y, long long M)
{
    if (y == 0)
        return 1;

    long long p = power(x, y / 2, M) % M;
    p = (p * p) % M;

    return (y % 2 == 0) ? p : (x * p) % M;
}
long long modInverse(long long A, long long M)
{
    // if (islands == 200000 && friends == 2)
    // {
    //    // cout << "inv of " << A << " wrt " << M << "\n";
    //     power(A, M - 2, M);
    // }
    return power(A % mod, M - 2, M);
}

void contribution(long long v, long long &totalLength)
{
    visited[v] = true;
    for (long long u : g[v])
    {
        if (visited[u] == false)
        {
            totalLength += (subtrees[u]) * (islands - subtrees[u]);
            totalLength = totalLength;
            contribution(u, totalLength);
        }
    }
}
void calculateTotalLength(long long &totalLength)
{
    for (long long i = 0; i < maxIslands; i++)
    {
        visited[i] = 0;
    }
    contribution(1, totalLength);
}
void clearInput(long long islands)
{
    for (long long i = 0; i < islands; i++)
    {
        g[i].clear();
        subtrees[i] = 0;
        visited[i] = false;
    }
    subtrees[islands] = 0;
    visited[islands] = 0;
}
void dfs(long long v)
{
    visited[v] = true;
    subtrees[v] = 1;
    for (long long u : g[v])
    {
        if (visited[u] == false)
        {
            dfs(u);
            subtrees[v] += subtrees[u];
        }
    }
    // cout << "subtrees[" << v << "] = " << subtrees[v] << "\n";
}
long long findGCD(long long a, long long b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}
void lowestFraction(long long num1, long long num2)
{
    long long denom;
    denom = findGCD(num1, num2);
    num1 /= denom;
    num2 /= denom;

    cout << ((num1 % mod) * modInverse(num2, mod)) % mod << endl;
}

int main()
{

    cin >> islands >> friends;
    clearInput(islands);
    for (long long j = 0; j < islands - 1; j++)
    {
        long long a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (friends == 1 || friends == 3)
    {
        cout << "1\n";
        return 0;
    }
    dfs(1);
    long long totalLength = 0;
    calculateTotalLength(totalLength);
    long long pairs = islands * (islands - 1) / 2;
    totalLength += pairs;
    // if (islands == 200000 && friends == 2)
    //     cout << totalLength << " " << pairs << "\n";
    lowestFraction(totalLength, pairs);
    // cout << (totalLength * modInverse(pairs, mod)) % mod;

    return 0;
}