#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    struct Segment {
        char ch;
        int start;
        int end;
        int len;
    };

    struct OneSeg {
        int idx;
        int static_gain;
    };

    vector<vector<int>> st;
    vector<int> lg;

    void buildSparseTable(const vector<int>& data) {
        int n = data.size();
        if (n == 0) return;
        int max_log = log2(n) + 1;
        st.assign(n, vector<int>(max_log, -1e9));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st[i][0] = data[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int queryMax(int L, int R) {
        if (L > R) return -1e9;
        int j = lg[R - L + 1];
        return max(st[L][j], st[R - (1 << j) + 1][j]);
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();

        // 1. Total baseline number of '1's in the entire string
        int total_ones_in_s = 0;
        for (char c : s) {
            if (c == '1') total_ones_in_s++;
        }

        // 2. Compress the string into alternating character blocks
        vector<Segment> segments;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            segments.push_back({s[i], i, j - 1, j - i});
            i = j;
        }

        int m = segments.size();
        
        // 3. Collect all '1' blocks that can potentially be flipped
        vector<OneSeg> one_segs;
        vector<int> start_positions; 
        
        for (int idx = 1; idx < m - 1; idx++) {
            if (segments[idx].ch == '1') {
                // Total number of '0's contributed if neither side gets truncated
                int static_gain = segments[idx - 1].len + segments[idx + 1].len;
                one_segs.push_back({idx, static_gain});
                start_positions.push_back(segments[idx].start);
            }
        }

        // 4. Build the Sparse Table over static gains
        vector<int> static_gains_array;
        for (const auto& os : one_segs) {
            static_gains_array.push_back(os.static_gain);
        }
        buildSparseTable(static_gains_array);

        vector<int> answer;
        answer.reserve(queries.size());

        // 5. Process each query in O(1) time
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int max_gain = 0;

            // Find the first '1' segment candidate that starts strictly after l
            auto it_start = upper_bound(start_positions.begin(), start_positions.end(), l);
            
            if (it_start != start_positions.end()) {
                int first_pos = distance(start_positions.begin(), it_start);
                
                // Find the last '1' segment candidate that ends strictly before r
                int last_pos = -1;
                int low = first_pos, high = start_positions.size() - 1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (segments[one_segs[mid].idx].end < r) {
                        last_pos = mid;
                        low = mid + 1; // Look for a later valid segment
                    } else {
                        high = mid - 1;
                    }
                }

                if (last_pos != -1 && first_pos <= last_pos) {
                    // Evaluate boundary elements manually since their '0' neighbors might be clipped by l or r
                    for (int pos : {first_pos, last_pos}) {
                        if (pos < first_pos || pos > last_pos) continue;
                        int idx = one_segs[pos].idx;
                        
                        int len_l = segments[idx - 1].end - max(l, segments[idx - 1].start) + 1;
                        int len_r = min(r, segments[idx + 1].end) - segments[idx + 1].start + 1;
                        max_gain = max(max_gain, len_l + len_r);
                    }

                    // For internal segments strictly between first_pos and last_pos,
                    // their '0' neighbors are completely inside [l, r], so use the Sparse Table
                    if (last_pos - first_pos > 1) {
                        max_gain = max(max_gain, queryMax(first_pos + 1, last_pos - 1));
                    }
                }
            }

            answer.push_back(total_ones_in_s + max_gain);
        }

        return answer;
    }
};