#include <iostream>
#include "vector"
#include "unordered_set"
#include "unordered_map"
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, deque<pair<int, int>>> tweets;
    int time = 0;

    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        if (tweets[userId].size() == 10) {
            tweets[userId].pop_back();
        }
        tweets[userId].push_front({tweetId, time});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<deque<pair<int, int>>> feeds;
        following[userId].insert(userId);
        for (auto u: following[userId]) {
            feeds.push_back(tweets[u]);
        }
        while (feeds.size() != 1) {
            vector<deque<pair<int, int>>> nf;
            for (int i = 0; i < feeds.size(); i += 2) {
                auto l1 = feeds[i];
                if (i == feeds.size() - 1) {
                    nf.push_back(l1);
                    continue;
                }
                auto l2 = feeds[i + 1];
                auto iter1 = l1.begin(), iter2 = l2.begin();
                deque<pair<int, int>> nl;
                while (iter1 != l1.end() && iter2 != l2.end()) {
                    if (nl.size() == 10) {
                        break;
                    }
                    if (iter1->second > iter2->second) {
                        nl.push_back(*iter1);
                        iter1++;
                    } else {
                        nl.push_back(*iter2);
                        iter2++;
                    }
                }
                while (iter1 != l1.end()) {
                    if (nl.size() == 10) {
                        break;
                    }
                    nl.push_back(*iter1);
                    iter1++;
                }
                while (iter2 != l2.end()) {
                    if (nl.size() == 10) {
                        break;
                    }
                    nl.push_back(*iter2);
                    iter2++;
                }
                nf.push_back(nl);
            }
            feeds = nf;
        }
        vector<int> r;
        for (auto x: feeds[0]) {
            r.push_back(x.first);
        }
        return r;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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
