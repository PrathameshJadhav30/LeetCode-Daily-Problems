//Problem Link: https://leetcode.com/problems/design-a-food-rating-system/description
//Date: 17/09/2025
#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    unordered_map<string, pair<string,int>> foodMap;
    struct cmp 
    {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const 
        {
            if(a.first != b.first) return a.first > b.first; // higher rating first
            return a.second < b.second; // lexicographically smaller first
        }
    };
    unordered_map<string, set<pair<int,string>, cmp>> cuisineSet;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++)
        {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            
            foodMap[food] = {cuisine, rating};
            cuisineSet[cuisine].insert({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodMap[food];
        cuisineSet[cuisine].erase({oldRating, food});
        cuisineSet[cuisine].insert({newRating, food});
        foodMap[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cuisineSet[cuisine].begin()).second;
    }
};

int main() {
    // Static input
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);

    cout << obj->highestRated("korean") << endl;   // kimchi
    cout << obj->highestRated("japanese") << endl; // ramen

    obj->changeRating("sushi", 16);
    cout << obj->highestRated("japanese") << endl; // sushi

    obj->changeRating("ramen", 16);
    cout << obj->highestRated("japanese") << endl; // ramen

    delete obj;
    return 0;
}
