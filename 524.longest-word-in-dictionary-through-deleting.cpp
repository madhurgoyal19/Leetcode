/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
class Solution
{
    string lex(string a, string b)
    {
        if (a.size() == b.size())
        {
            int i = 0;
            while (i < a.size() && i < b.size())
            {
                if (a[i] > b[i])
                {
                    return b;
                }
                else if (a[i] < b[i])
                {
                    return a;
                }
                i++;
            }
        }
        return a.size() > b.size() ? a : b;
    }

public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]].push_back(i);

        string answer = "";
        for (auto &word : dictionary)
        {
            int ind = -1;
            bool found = true;
            for (auto &l : word)
            {
                if (mp[l].size() == 0)
                {
                    found = false;
                    break;
                }
                else
                {
                    int k = 0;
                    while (k < mp[l].size() && mp[l][k] <= ind)
                        k++;
                    if (k < mp[l].size())
                    {
                        ind = mp[l][k];
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }
            }
            if (found)
                answer = lex(answer, word);
        }
        return answer;
    }
};
// @lc code=end
