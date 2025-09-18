class TaskManager {
public:
    typedef pair<int, int> p;
    unordered_map<int, p> taskMap;
    set<vector<int>> priorityMap;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto temp : tasks) {
            int userId = temp[0];
            int taskId = temp[1];
            int priority = temp[2];
            taskMap[taskId] = {priority, userId};
            priorityMap.insert({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {priority, userId};
        priorityMap.insert({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        int prevPriority = taskMap[taskId].first;
        int userId = taskMap[taskId].second;
        priorityMap.erase({prevPriority, taskId, userId});
        taskMap[taskId].first = newPriority;
        priorityMap.insert({newPriority, taskId, userId});
    }

    void rmv(int taskId) {
        int priority=taskMap[taskId].first;
        int userId=taskMap[taskId].second;
        priorityMap.erase({priority,taskId,userId});
        taskMap.erase(taskId);
    }

    int execTop() {
        if(priorityMap.empty()) return -1;
        auto it= priorityMap.rbegin();
        int userId= (*it)[2];
        int priority= (*it)[0];
        int taskId= (*it)[1];
        priorityMap.erase({priority,taskId,userId});
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
