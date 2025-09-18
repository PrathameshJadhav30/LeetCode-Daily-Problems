//Problem Link: https://leetcode.com/problems/design-task-manager/description
//Date: 18/09/2025
#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    // taskId -> {userId, priority}
    unordered_map<int, pair<int, int>> taskMap;
    // max heap: {priority, taskId}
    priority_queue<pair<pair<int, int>, int>> pq; 
    // structure: {{priority, taskId}, userId}

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskMap[taskId] = {userId, priority};
            pq.push({{priority, taskId}, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({{priority, taskId}, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskMap[taskId];
        taskMap[taskId] = {userId, newPriority};
        pq.push({{newPriority, taskId}, userId});
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId); // lazy removal
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int priority = top.first.first;
            int taskId = top.first.second;
            int userId = top.second;
            
            if (taskMap.count(taskId) && taskMap[taskId].second == priority) {
                taskMap.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};

// Driver code for testing
int main() {
    vector<vector<int>> tasks = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager taskManager(tasks);

    taskManager.add(4, 104, 5);
    taskManager.edit(102, 8);
    cout << taskManager.execTop() << endl; // 3
    taskManager.rmv(101);
    taskManager.add(5, 105, 15);
    cout << taskManager.execTop() << endl; // 5
}
