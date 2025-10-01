struct my_task {
    int uid;
    int tid;
    int pri;
    my_task() = default;
    my_task(int u, int t, int p) : uid(u), tid(t), pri(p) {}
    bool operator<(const my_task& other) const {
        return ((pri == other.pri) ? tid > other.tid
                                        : pri > other.pri);
  }
};

class TaskManager {
 public:
  unordered_map<int, my_task> um;
  set<my_task> stsk;

    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++ i)
            add(tasks[i][0], tasks[i][1], tasks[i][2]);
    }

    void add(int userId, int taskId, int priority) {
        my_task task(userId, taskId, priority);
        um[taskId] = task;
        stsk.insert(task);
    }

    void edit(int taskId, int newPriority) {
        my_task task = um[taskId];
        stsk.erase(task);
        my_task tsk = my_task(task.uid, task.tid, newPriority);
        stsk.insert(tsk);
        um[taskId] = tsk;
    }

    void rmv(int taskId) {
        my_task task = um[taskId];
        stsk.erase(task);
        um.erase(taskId);
    }

    int execTop() {
        if (stsk.empty())
            return -1;
        my_task task = *stsk.begin();
        stsk.erase(task);
        um.erase(task.tid);
        return task.uid;
    }
};
