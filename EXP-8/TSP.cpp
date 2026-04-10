#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>& dist, int n) {
    vector<int> cities;
    for (int i= 1;i< n; i++)
        cities.push_back(i);
    int min_path = INT_MAX;
    do {
        int current_path = 0;
        int k = 0;
        for (int i = 0; i < cities.size(); i++) {
            current_path += dist[k][cities[i]];
            k = cities[i];
        }
        current_path += dist[k][0];
        min_path = min(min_path, current_path);
    } while (next_permutation(cities.begin(), cities.end()));
    return min_path;
}
// NP-HARD
//No deterministic time complexity
