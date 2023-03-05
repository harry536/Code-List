class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> nums;
        for (int i = 0; i < n; i++) {
            nums[arr[i]].push_back(i);
        }

        vector<bool> visited(n);
        queue<int> que;
        que.push(0);
        visited[0] = true;
        int step = 0;

        while (!que.empty()) {
            int length = que.size();
            for (int i = 0; i < length; i++) {
                auto index = que.front();
                que.pop();

                if (index == n - 1) {
                    return step;
                }

                if (0 < index and !visited[index - 1]) {
                    que.push(index - 1);
                    visited[index - 1] = true;
                }

                if (index < n - 1 and !visited[index + 1]) {
                    que.push(index + 1);
                    visited[index + 1] = true;
                }

                if (nums.find(arr[index]) != nums.end()) {
                    for (auto& next: nums[arr[index]]) {
                        if (!visited[next]) {
                            que.push(next);
                            visited[next] = true;
                        }
                    }
                    nums.erase(arr[index]);                    
                }
            }
            step++;
        }
        return 0;
    }
};