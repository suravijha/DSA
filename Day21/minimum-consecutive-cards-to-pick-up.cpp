// LeetCode 2260
// You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
// Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> hash;
        int n = cards.size();
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int card = cards[i];
            if (hash.find(card) != hash.end())
            {
                int num = i - hash[card] + 1;
                if (ans == -1)
                    ans = num;
                else
                    ans = min(ans, num);
            }
            hash[card] = i;
        }
        return ans;
    }
};