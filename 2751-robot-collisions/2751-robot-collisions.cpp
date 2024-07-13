class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        for (int index = 0; index < n; ++index) {
            indices[index] = index;
        }

        sort(indices.begin(), indices.end(),
             [&](int lhs, int rhs) { return positions[lhs] < positions[rhs]; });

        for (int currentIndex : indices) {
            // Add right-moving robots to the stack
            if (directions[currentIndex] == 'R') {
                stack.push(currentIndex);
            } else {
                while (!stack.empty() && healths[currentIndex] > 0) {
                    // Pop the top robot from the stack for collision check
                    int topIndex = stack.top();
                    stack.pop();

                    // Top robot survives, current robot is destroyed
                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        // Current robot survives, top robot is destroyed
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        // Both robots are destroyed
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        // Collect surviving robots
        for (int index = 0; index < n; ++index) {
            if (healths[index] > 0) {
                result.push_back(healths[index]);
            }
        }
        return result;
    }
};















/*class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int N = positions.size();
        
        // Edge case where all robots move in the same direction
        char c = directions[0];
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (directions[i] != c) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return healths;
        }

        // Create an array of indices
        vector<int> indices(N);
        for (int i = 0; i < N; ++i) {
            indices[i] = i;
        }

        // Sort indices based on positions
        sort(indices.begin(), indices.end(), [&positions](int a, int b) {
            return positions[a] < positions[b];
        });

        // Create sorted versions of positions, healths, and directions
        vector<int> sortedPositions(N), sortedHealths(N);
        string sortedDirections(N, ' ');
        for (int i = 0; i < N; ++i) {
            sortedPositions[i] = positions[indices[i]];
            sortedHealths[i] = healths[indices[i]];
            sortedDirections[i] = directions[indices[i]];
        }

        // Process collisions
        vector<int> survivedHealths;
        vector<int> stack;
        for (int i = 0; i < N; ++i) {
            while (!stack.empty() && sortedDirections[stack.back()] == 'R' && sortedDirections[i] == 'L') {
                int idx = stack.back();
                if (sortedHealths[idx] > sortedHealths[i]) {
                    sortedHealths[idx]--;
                    sortedHealths[i] = -1;
                    break;
                } else if (sortedHealths[idx] < sortedHealths[i]) {
                    sortedHealths[i]--;
                    sortedHealths[idx] = -1;
                    stack.pop_back();
                } else {
                    sortedHealths[idx] = -1;
                    sortedHealths[i] = -1;
                    stack.pop_back();
                    break;
                }
            }
            if (sortedHealths[i] != -1) {
                stack.push_back(i);
            }
        }

        // Collect the healths of the survived robots
        for (int i = 0; i < N; ++i) {
            if (sortedHealths[i] != -1) {
                survivedHealths.push_back(sortedHealths[i]);
            }
        }

        return survivedHealths;
    }
};
*/