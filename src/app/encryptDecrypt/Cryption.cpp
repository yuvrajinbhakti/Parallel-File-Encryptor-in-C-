#include "Cryption.hpp"
#include "../process/Task.hpp"
#include "../fileHandling/ReadEnv.cpp"

int executeCryption(){
 Task task = Task::fromString(taskData);
 ReadEnv env;
 std::string envKey = env.getenv();
 int key = std::stoi(envKey);
 if(task.action == Action::ENCRYPT){    //encrypting
    char ch;
    while(task.f_stream.get(ch)){
        ch=(ch+key)%256;
        task.f_stream.seekp(-1,std::io::cur);
        task.f_stream.put(ch);
    }
task.f_stream.close();
 }else{      //decrypting
char ch;
while(task.f_stream.get(ch)){
    ch=(ch-key+256)%256;
    task.f_stream.seekp(-1,std::ios::cur);
    task.f_stream.put(ch);
}
task.f_stream.close();
 }
 return 0;
}