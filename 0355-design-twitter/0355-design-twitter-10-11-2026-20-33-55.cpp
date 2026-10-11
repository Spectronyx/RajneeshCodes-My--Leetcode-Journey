class Twitter {
public:
    int timer;

    // user id -> set of userids they follow
    unordered_map<int, unordered_set<int>> followee;

    // tweet -> {timestamp,tweetid}
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() { timer = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq;

        unordered_set<int> users = followee[userId];
        users.insert(userId);

        for (int uid : users) {
            if (!tweets[uid].empty()) {
                int idx = tweets[uid].size() - 1;
                pq.push({tweets[uid][idx].first, uid, idx});
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            auto [time, uid, idx] = pq.top();
            pq.pop();

            ans.push_back(tweets[uid][idx].second);

            // Add previous tweet from the same user
            if (idx > 0) {
                pq.push({tweets[uid][idx - 1].first, uid, idx - 1});
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followee[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followee[followerId].erase(followeeId);
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