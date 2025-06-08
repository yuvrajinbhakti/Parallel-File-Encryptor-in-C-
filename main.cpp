#include <iostream>
#include <filesystem>
#include "./src/app/processes/ProcessManagment.hpp"
#include "./src/app/processes/Task.hpp"

namespace fs = std::filesystem;

int main(){
 std::string directory;
 std::string action;
 std::cout<<"Enter the directory path: "<<std::endl;   
 std::getline(std::cin,directory);

 std::cout<<"Enter the action (encrypt/decrypt): "<<std::endl;
 std::getline(std::cin,action);

 try{
if(fs::exists(directory) && fs::is_directory(directory)){
    ProcessManagment processManagment;
    for(const auto &entry : fs::recursive_directory_iterator(directory)){
        if(entry.is_regular_file()){
            std::string filePath = entry.path().string();
            IO io(filePath);
            std::fstream f_stream = io.getFileStream();
            if(f_stream.is_open()){
                Action taskAction = (action == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
                auto task = std::make_unique<Task>(std::move(f_stream),taskAction,filePath);
                processManagment.submitToQueue(std::move(task));
            }
            else{
                std::cout<<"Unable to open the file: "<<filePath<<std::endl;
            }
        }
    }
    processManagment.executeTasks();
}
else{
    std::cout<<"Invalid directory path: "<<std::endl; 
}
 }catch(const fs::filesystem_error &ex){
std::cout<<"Filesystem error: "<<ex.what()<<std::endl;
 }
}