struct cmp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first == b.first)
            return a.second < b.second; 
        return a.first > b.first; 
    }
};

class FoodRatings {
public:
    typedef pair<int, string> p;
    unordered_map<string, string> foodKaCuisine;
    unordered_map<string, int> foodKaRating;
    unordered_map<string, set<p, cmp>> highest;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            int rating = ratings[i];
            string cuisine = cuisines[i];
            string food = foods[i];
            highest[cuisine].insert({rating, food});
            foodKaCuisine[food] = cuisine;
            foodKaRating[food] = rating;
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodKaCuisine[food];
        int prevRating = foodKaRating[food];
        highest[cuisine].erase({prevRating, food});
        highest[cuisine].insert({newRating, food});
        foodKaRating[food] = newRating;
    }

    string highestRated(string cuisine) {
        auto& foods = highest[cuisine];
        return foods.begin()->second; 
    }
};
