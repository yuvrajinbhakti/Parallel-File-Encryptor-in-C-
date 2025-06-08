#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <iostream>
#include "../fileHandling/IO.hpp"
#include <sstream>

enum class Action {
    ENCRYPT,
    DECRYPT
};

//&& means that the variable is volatile i.e. kept in temporary buffer or memory , which means that it is stored temporarily in the RAM
// volatile is used for variables that are accessed by different threads
//it will be assigned further down the line  and it's copy will not be made

struct Task {
    std::string filePath;
    std::fstream f_stream;
    Action action;

//this is a move constructor i.e. it takes a rvalue reference to a std::fstream object
//it moves the object to the new Task object and then destroys the original object
    Task(std::fstream  &&stream, Action act, std::string filePath) : f_stream(std::move(stream)), action(act), filePath(filePath) {} //this constructor takes multiple objects and assigns it to local variables

    //method 2 
    // Task(std::fstream  &&stream, Action act, std::string filePath) {
    //     f_stream = std::move(stream);
    //     action = act;
    //     filePath = filePath;
    // }

    std::string toString(){
        std::ostringstream oss;
        oss<<filePath<<","<<(action==Action.ENCRYPT?"ENCRYPT":"DECRYPT");
        return oss.str();
    }

    static Task fromString(const std::string &taskData){
        std::istringstream iss(taskData);
        std::string filePath;
        std::string actionStr;

        if(std::getline(iss,filePath,',') && std::getline(iss,actionStr)){
            Action action = (actionStr == "ENCRYPT") ? Action::ENCRYPT : Action::DECRYPT;
            IO io(filePath);
            std::fstream f_stream = std::move(io.getFileStream());
            if(f_stream.is_open()){
                return Task(std::move(f_stream),action,filePath);
            }
            else{
                throw std::runtime_error("Failed to open file: "+filePath);
            }
        }
        else{
            throw std::runtime_error("Invalid task data: "+taskData);
        }
    }
};


#endif
