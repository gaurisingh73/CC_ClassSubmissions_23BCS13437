class Solution {
public:
    void merge(vector<pair<int,int>>& v, int low, int mid, int high, vector<int>& count) {
        vector<pair<int,int>> temp;
        int i = low, j = mid + 1;
        int rightCount = 0;

        while (i <= mid && j <= high) {
            if (v[j].first < v[i].first) {
                rightCount++;
                temp.push_back(v[j++]);
            } else {
                count[v[i].second] += rightCount;
                temp.push_back(v[i++]);
            }
        }

        while (i <= mid) {
            count[v[i].second] += rightCount;
            temp.push_back(v[i++]);
        }

        while (j <= high) {
            temp.push_back(v[j++]);
        }

        for (int k = low; k <= high; k++) {
            v[k] = temp[k - low];
        }
    }

    void mergeSort(vector<pair<int,int>>& v, int low, int high, vector<int>& count) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        mergeSort(v, low, mid, count);
        mergeSort(v, mid + 1, high, count);
        merge(v, low, mid, high, count);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        mergeSort(v, 0, n - 1, count);
        return count;
    }
};
