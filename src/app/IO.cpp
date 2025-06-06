//implementation file for IO.hpp
#include <iostream>
#include "IO.hpp"
#include <fstream>

IO::IO(const std::string &filepath):file_stream(filepath){ //constructor implementation 
file_stream.open(filepath, std::ios::in | std::ios::out | std::ios::binary);  //open the file in read,write and binary mode 

    if(!file_stream.is_open()){
        std::cout<<"Unable to open the file: "<<file_path<<std::endl;
    }
}

std::fstream IO::getFileStream(){
    return std::move(file_stream); //give the opened file stream //move is used to transfer the ownership of the file stream to the called function
}

IO::~IO(){
    if(file_stream.is_open()){
        file_stream.close();
    }
}
