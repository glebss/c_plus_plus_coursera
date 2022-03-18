#include <string>
#include <tuple>
#include <map>
#include <vector>
#include <iostream>
using namespace std;



// Перечислимый тип для статуса задачи
// enum class TaskStatus {
//   NEW,          // новая
//   IN_PROGRESS,  // в разработке
//   TESTING,      // на тестировании
//   DONE          // завершена
// };

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
// using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return persons_to_tasks.at(person);
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++persons_to_tasks[person][TaskStatus::NEW];
    }

    void DeleteZeros(TasksInfo& tasks) {
        vector<TaskStatus> task_names;
        for (const auto& item : tasks) {
            if (tasks.at(item.first) == 0) {
                task_names.push_back(item.first);
            }
        }
        for (const auto& n : task_names) {
            tasks.erase(n);
        }
    }

  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        if (persons_to_tasks.count(person) == 0) {
            return make_tuple(TasksInfo(), TasksInfo());
        }
        TasksInfo& person_tasks = persons_to_tasks[person];
        int n_not_done = 0;
        for (const auto& item : person_tasks) {
            if (item.first != TaskStatus::DONE) {
                n_not_done += item.second;
            }
        }
        task_count = min(n_not_done, task_count);
        TasksInfo updated;
        TasksInfo not_updated = person_tasks;
        for (auto& item : person_tasks) {
            if (task_count != 0) {
                int to_decrease = min(task_count, item.second);
                updated[static_cast<TaskStatus>(static_cast<int>(item.first) + 1)] += to_decrease;
                not_updated[item.first] -= to_decrease;
                task_count -= to_decrease;
                
            } else {
                if (item.first != TaskStatus::DONE) {
                    not_updated[item.first] = item.second;
                }
            }
        }
        not_updated.erase(TaskStatus::DONE);
        for (const auto& item : updated) {
            int diff = item.second;
            person_tasks[item.first] += diff;
            person_tasks[static_cast<TaskStatus>(static_cast<int>(item.first) - 1)] -= diff;
        }
        DeleteZeros(updated);
        DeleteZeros(not_updated);
        DeleteZeros(person_tasks);
        return make_tuple(updated, not_updated);
    }

private:
    map<string, TasksInfo> persons_to_tasks;
};


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
// void PrintTasksInfo(TasksInfo tasks_info) {
//   cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
//       ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
//       ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
//       ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
// }

// int main() {
//   TeamTasks tasks;
//   tasks.AddNewTask("Ilia");
//   for (int i = 0; i < 3; ++i) {
//     tasks.AddNewTask("Ivan");
//   }
//   cout << "Ilia's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//   cout << "Ivan's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
//   TasksInfo updated_tasks, untouched_tasks;
  
//   tie(updated_tasks, untouched_tasks) =
//       tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
  
//   tie(updated_tasks, untouched_tasks) =
//       tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);

//   return 0;
// }
