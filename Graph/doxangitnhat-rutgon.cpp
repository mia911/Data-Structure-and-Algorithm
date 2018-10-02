#include <bits/stdc++.h>

using namespace std;

int n, m, k, u, v, c, f;
//n city, m edges, k cities with gas, f gas amount can hold

int visited[1000][1000];
int minFill[1000][1000];

int leastFill(int gasStation[], vector<vector<pair<int, int> > > map) {
	int leastGasFill = INT_MAX;

	minFill[1][f] = 0;
	list<pair<int, int> >min_Fill;
	min_Fill.push_back(make_pair(1, f));
    //cout<<min_Fill.size()<<endl;
	while(1) {
        if(min_Fill.size() == 0)
			break;

		pair<int, int> minCity = min_Fill.front();
		//cout<<minCity.first<<" "<<minCity.second<<endl;
		min_Fill.pop_front();
        //cout<<min_Fill.size()<<endl;

		visited[minCity.first][minCity.second] = 1;

		for(int i = 0; i < map[minCity.first].size(); i++) {
			pair<int, int> temp = map[minCity.first][i];
			if(minCity.second >= temp.second) {
				if(!visited[temp.first][minCity.second - temp.second]) {
					minFill[temp.first][minCity.second - temp.second] = minFill[minCity.first][minCity.second] + 0;
					min_Fill.push_front(make_pair(temp.first, minCity.second - temp.second));
					visited[temp.first][minCity.second - temp.second] = 1;
				}

				if(gasStation[temp.first]) {
					if(!visited[temp.first][f]) {
						minFill[temp.first][f] = minFill[minCity.first][minCity.second] + 1;
						min_Fill.push_back(make_pair(temp.first, f));
						visited[temp.first][f] = 1;
					}
            	}
			}
		}
	}

	for(int i = 0; i <= f; i++) {
		if(leastGasFill > minFill[n][i])
			leastGasFill = minFill[n][i];
        cout<<minFill[n][i]<<endl;
	}
	return leastGasFill;
}

int main () {
    freopen("input.txt", "r", stdin);

	cin>>n; cin>>m;

	cin>>k;

	int gasStation[n + 1];
	for(int i = 0; i < n + 1; i++) {
		gasStation[i] = 0;
	}
	int z;

	for(int i = 0; i < k; i++) {
		cin>>z;
		gasStation[z] = 1;
	}

	pair<int, int>temp;
	vector<vector<pair<int, int> > >map(n + 1);
	for(int i = 0; i < m; i++) {
		cin>>u; cin>>v; cin>>c;
		map[u].push_back(make_pair(v, c));
		map[v].push_back(make_pair(u, c));
	}

	cin>>f;

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= f; j++) {
			minFill[i][j] = INT_MAX;
		}
	}

	int result = leastFill(gasStation, map);
    cout<<result<<endl;
	return 0;
}
