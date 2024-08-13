#include "vectorfunctions.h"
#include <bits/stdc++.h>

using namespace std;

void backwards(std::vector<int> &vec)
{
    reverse(vec.begin(), vec.end());
}

std::vector<int> everyOther(const std::vector<int> &vec)
{
    std::vector<int> ans;
    for (int i = 0; i < vec.size(); i += 2)
    {
        ans.push_back(vec[i]);
    }
    return ans;
}

int smallest(const std::vector<int> &vec)
{
    int small = 2e9;
    for (int a : vec)
    {
        small = min(small, a);
    }

    return small;
}

int sum(const std::vector<int> &vec)
{
    int ttl = 0;
    for (int a : vec)
        ttl += a;
    return ttl;
}

int veryOdd(const std::vector<int> &suchVector)
{
    int ttl = 0;
    for (int i = 1; i < suchVector.size(); i += 2)
    {
        if (suchVector[i] & 1)
        {
            ttl++;
        }
    }

    return ttl;
}