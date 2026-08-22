class Twitter {
public:
    int count;

    unordered_map<int, vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});

        if (tweetMap[userId].size() > 10) {
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        followMap[userId].insert(userId);
        priority_queue<vector<int>> pq;

        for (int f: followMap[userId]) {
            if (tweetMap.find(f) == tweetMap.end())
                continue;

            int idx = tweetMap[f].size() - 1;
            auto& p = tweetMap[f][idx];

            pq.push({p.first, p.second, f, idx});
        }

        while (!pq.empty() && ans.size() < 10) {
            auto t = pq.top();
            pq.pop();

            int time = t[0];
            int tweetId = t[1];
            int user = t[2];
            int idx = t[3];

            ans.push_back({tweetId});

            if (idx > 0) {
                idx--;

                auto& p = tweetMap[user][idx];
                pq.push({p.first, p.second, user, idx});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */