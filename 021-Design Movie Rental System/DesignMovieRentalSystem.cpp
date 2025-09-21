//Problem Link: https://leetcode.com/problems/design-movie-rental-system/description
//Date: 21/09/2025
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int shop, movie, price;
};

// Comparator for availableByMovie (price, shop)
struct CmpAvailable {
    bool operator()(const Node& a, const Node& b) const {
        if (a.price != b.price) return a.price < b.price;
        return a.shop < b.shop;
    }
};

// Comparator for rentedSet (price, shop, movie)
struct CmpRented {
    bool operator()(const Node& a, const Node& b) const {
        if (a.price != b.price) return a.price < b.price;
        if (a.shop != b.shop) return a.shop < b.shop;
        return a.movie < b.movie;
    }
};

class MovieRentingSystem {
    unordered_map<long long, Node> byPair;
    unordered_map<int, set<Node, CmpAvailable>> availableByMovie;
    set<Node, CmpRented> rentedSet;

    long long key(int shop, int movie) {
        return ((long long)shop << 32) ^ movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            Node node{shop, movie, price};
            byPair[key(shop, movie)] = node;
            availableByMovie[movie].insert(node);
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (availableByMovie.count(movie) == 0) return res;
        auto& s = availableByMovie[movie];
        int count = 0;
        for (auto it = s.begin(); it != s.end() && count < 5; ++it, ++count) {
            res.push_back(it->shop);
        }
        return res;
    }

    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        Node node = byPair[k];
        availableByMovie[movie].erase(node);
        rentedSet.insert(node);
    }

    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        Node node = byPair[k];
        rentedSet.erase(node);
        availableByMovie[movie].insert(node);
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto it = rentedSet.begin(); it != rentedSet.end() && count < 5; ++it, ++count) {
            res.push_back({it->shop, it->movie});
        }
        return res;
    }
};

int main() {
    vector<vector<int>> entries = {
        {0, 1, 5}, {0, 2, 6}, {0, 3, 7},
        {1, 1, 4}, {1, 2, 7}, {2, 1, 5}
    };

    MovieRentingSystem movieRentingSystem(3, entries);

    // search(1)
    auto s1 = movieRentingSystem.search(1);
    cout << "search(1): ";
    for (int x : s1) cout << x << " ";
    cout << "\n";

    // rent(0,1)
    movieRentingSystem.rent(0, 1);

    // rent(1,2)
    movieRentingSystem.rent(1, 2);

    // report()
    auto r1 = movieRentingSystem.report();
    cout << "report(): ";
    for (auto &v : r1) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << "\n";

    // drop(1,2)
    movieRentingSystem.drop(1, 2);

    // search(2)
    auto s2 = movieRentingSystem.search(2);
    cout << "search(2): ";
    for (int x : s2) cout << x << " ";
    cout << "\n";

    return 0;
}
