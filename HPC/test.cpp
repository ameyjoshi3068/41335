#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

void ops(vector<int> &arr)
{
    int minV = INT_MAX;
    int maxV = INT_MIN;
    long long sum = 0;
    int avg;

    for (int i = 0; i < arr.size(); i++)
    {
        minV = min(arr[i], minV);
        maxV = max(arr[i], maxV);
        sum += arr[i];
    }
    cout << minV << endl;
    cout << maxV << endl;
    cout << sum << endl;
    cout << avg << endl;
}

void pops(vector<int> &arr)
{
    int minV = INT_MAX;
    int maxV = INT_MIN;
    long long sum = 0;
    int avg;

#pragma omp parallel for reduction(min : minV)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < minV)
        {
            minV = arr[i];
        }
    }

#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    cout << minV << endl;
    cout << maxV << endl;
    cout << sum << endl;
    cout << avg << endl;
}

int main()
{
    int n = 10000000;
    vector<int> random(n);
    for (int i = 0; i < n; i++)
    {
        random[i] = rand() % n;
    }

    double start = omp_get_wtime();
    ops(random);
    double end = omp_get_wtime();

    cout << "Time taken: " << end - start << endl;

    start = omp_get_wtime();
    pops(random);
    end = omp_get_wtime();

    cout << "Time taken: " << end - start << endl;

    return 0;
}