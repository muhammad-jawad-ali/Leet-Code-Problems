class Solution {
public:
    bool canPlaceBalls(std::vector<int>& position, int m, int min_force) {
        int count = 1; 
        int last_position = position[0];
        
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - last_position >= min_force) {
                count++;
                last_position = position[i];
                if (count == m) return true;
            }
        }
        return false;
    }
    
    int maxDistance(std::vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        
        int left = 1;
        int right = position.back() - position.front();
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceBalls(position, m, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};