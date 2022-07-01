    #define INF -1
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <int> price(n, INF);
        vector <int> temp(n);
        price[src] = 0;
        for (int i=0; i<k+1; i++) {
            temp = price;
            for (int j=0; j<flights.size(); j++) {
                int from = flights[j][0];
                int to = flights[j][1];
                int p = flights[j][2];
                if (price[from]==INF) continue;
                if (temp[to]==INF || temp[to]>price[from]+p) temp[to] = price[from]+p;
            }
            price = temp;
        }
        return price[dst];
    }