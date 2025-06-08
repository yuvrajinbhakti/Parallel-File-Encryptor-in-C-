#ifndef PROCESSMANAGMENT_HPP
#define PROCESSMANAGMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>


class ProcessManagment{
    public:
        ProcessManagment();
        bool submitToQueue(std::unique_ptr<Task> task);
        void executeTasks();
    private:
        std::queue<std::unique_ptr<Task>> taskQueue;
}; 

#endif