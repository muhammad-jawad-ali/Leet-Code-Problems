class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int pLen = p.length();
        int sLen = s.length();

        if (pLen > sLen) return ans;

        int pCount[26] = {0};
        int sCount[26] = {0};

        for (int i = 0; i < pLen; i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        if (equal(begin(pCount), end(pCount), begin(sCount))) {
            ans.push_back(0);
        }

        for (int i = pLen; i < sLen; i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - pLen] - 'a']--;

            if (equal(begin(pCount), end(pCount), begin(sCount))) {
                ans.push_back(i - pLen + 1);
            }
        }

        return ans;
    }
};