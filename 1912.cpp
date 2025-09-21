class MovieRentingSystem {
public:
    unordered_map <int, set<vector<int>>> movieMap;
    set<vector<int>>rented;
    unordered_map<string,int>onRent;
    unordered_map<string,int>priceMap;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &temp:entries)
        {
            int shop=temp[0];
            int movie=temp[1];
            int price=temp[2];
            movieMap[movie].insert({price,shop});
            string ss=to_string(movie)+"_"+to_string(shop);
            priceMap[ss]=price;
        }
    }

    vector<int> search(int movie) {
        int n=movieMap[movie].size();
        vector<int>ans;
        int count=0;
        auto it=movieMap[movie].begin();
        auto end=movieMap[movie].end();
        while(count<5 && it!=end)
        {
            int shop=(*it)[1];
            string ss=to_string(movie)+"_"+to_string(shop);
            if(!onRent.count(ss))
            {
                ans.emplace_back(shop);
                count++;
            }
            it++;
        }
        return ans;
    }

    void rent(int shop, int movie) {
        string ss=to_string(movie)+"_"+to_string(shop);
        onRent[ss]=1;
        int price=priceMap[ss];
        rented.insert({price,shop,movie});
    }

    void drop(int shop, int movie) {
        string ss=to_string(movie)+"_"+to_string(shop);
        onRent.erase(ss);
        int price=priceMap[ss];
        rented.erase({price,shop,movie});
    }

   vector<vector<int>> report() {
    vector<vector<int>> ans;
    int count = 0;
    for (auto it = rented.begin(); it != rented.end() && count < 5; ++it) {
        int shop = (*it)[1];
        int movie = (*it)[2];
        ans.push_back({shop, movie});
        count++;
    }
    return ans;
}

};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */


//better approach with less space
class MovieRentingSystem {
public:
    unordered_map<int, set<vector<int>>> movieMap;
    set<vector<int>> rented;                       
    unordered_map<string, int> priceMap;           

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &temp : entries) {
            int shop = temp[0];
            int movie = temp[1];
            int price = temp[2];
            movieMap[movie].insert({price, shop});
            string ss = to_string(movie) + "_" + to_string(shop);
            priceMap[ss] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        int count = 0;
        for (auto it = movieMap[movie].begin(); it != movieMap[movie].end() && count < 5; ++it) {
            int price = (*it)[0];
            int shop = (*it)[1];
                ans.push_back(shop);
                count++;
        }
        return ans;
    }

    void rent(int shop, int movie) {
        string ss = to_string(movie) + "_" + to_string(shop);
        int price = priceMap[ss];
        rented.insert({price, shop, movie});
        movieMap[movie].erase({price,shop});
    }

    void drop(int shop, int movie) {
        string ss = to_string(movie) + "_" + to_string(shop);
        int price = priceMap[ss];
        rented.erase({price, shop, movie});
        movieMap[movie].insert({price,shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = 0;
        for (auto it = rented.begin(); it != rented.end() && count < 5; ++it) {
            int shop = (*it)[1];
            int movie = (*it)[2];
            ans.push_back({shop, movie});
            count++;
        }
        return ans;
    }
};

