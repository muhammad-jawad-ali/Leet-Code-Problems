class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        
        unordered_map<int, int> countMap;
        for (int card : deck) {
            countMap[card]++;
        }
        
        int gcd = 0;
        for (auto& pair : countMap) {
            gcd = __gcd(gcd, pair.second);
        }
        
        return gcd >= 2;
    }
};