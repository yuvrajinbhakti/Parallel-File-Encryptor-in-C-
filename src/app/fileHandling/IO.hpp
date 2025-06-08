//header file for input output operations
//this file contains the declarations of the functions for input output operations

#ifndef IO_HPP
#define IO_HPP

#include <fstream>
#include <string>
#include <iostream>

class IO{
    public:
    IO(const std::string &filepath); //constructor
    ~IO(); //destructor 
    std::fstream getFileStream();

    private:
    std::fstream file_stream;

};


#endif 