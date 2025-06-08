#include <iostream>
#include <string>
#include <fstream>
#include "IO.hpp"
#include "ReadEnv.hpp"
#include <sstream>

std::string ReadEnv::getEnv(){
    std::string env_path=".env";
    IO io(env_path);
    std::fstream f_stream = io.getFileStream();
    std::stringstream buffer;
    buffer<< f_stream.rdbuf(); //read the file stream and store it in the buffer 
    std::string content = buffer.str(); //convert the buffer to a string 
    return content;
}



