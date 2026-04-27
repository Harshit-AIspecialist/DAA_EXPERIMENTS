int tsp(vector<vector<int>& cost,int n){
    vector<int>cities;
    for(int i = 0;i<n;i++){
        cities.push_back(i);
    }
    int ans = INT_MAX;
    do{
        int curcost = 0;
        int prev = 0;
        for(int city: cities){
            curcost+= cost[prev][city];
            prev = city;
        }
        curcost+= cost[prev][0];
        ans = min(ans,curcost);
    }while(next_permuatation(cities.begin(),cities.end()));
    return ans;
}
