#include "ProcessManagment.hpp"
#include <iostream>
#include <cstring>
#include <sys/wait.h>
// #include "../encryptDecrypt/Cryption.hpp"

ProcessManagment::ProcessManagment(){}

bool ProcessManagment::submitToQueue(std::unique_ptr<Task> task){
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagment::executeTasks(){
     while(!taskQueue.empty()){
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        taskQueue.pop();
        std::cout<<"Execute task: "<<taskToExecute->toString()<<std::endl;
        executeCyption(taskToExecute->toString());
     }
}