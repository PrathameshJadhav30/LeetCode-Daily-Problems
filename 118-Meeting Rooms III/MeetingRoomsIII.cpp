// Problem Link: https://leetcode.com/problems/meeting-rooms-iii/description
// Date: 27/12/2025
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> count(n, 0);           // Count of meetings per room
        vector<long long> timer(n, 0);     // End time of each room

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            long long duration = end - start;

            int freeRoom = -1;
            long long earliestTime = LLONG_MAX;
            int earliestRoom = -1;

            for (int r = 0; r < n; r++) {
                if (timer[r] < earliestTime) {
                    earliestTime = timer[r];
                    earliestRoom = r;
                }
                if (timer[r] <= start && freeRoom == -1) {
                    freeRoom = r;
                }
            }

            if (freeRoom != -1) {
                timer[freeRoom] = end;
                count[freeRoom]++;
            } else {
                timer[earliestRoom] += duration;
                count[earliestRoom]++;
            }
        }

        int maxMeetings = 0, roomIndex = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                roomIndex = i;
            }
        }

        return roomIndex;
    }
};

int main() {
    // 🔹 Static Input
    int n = 2;
    vector<vector<int>> meetings = {
        {0, 10},
        {1, 5},
        {2, 7},
        {3, 4}
    };

    Solution obj;
    int result = obj.mostBooked(n, meetings);

    cout << "Most booked room index: " << result << endl;

    return 0;
}
