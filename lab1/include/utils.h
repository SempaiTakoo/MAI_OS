#pragma once
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <string>

enum PipeIO {
    READ,
    WRITE
};

pid_t CreateChild();
void CreatePipe(int pipeFd[2]);
void Exec(const char *pathToChild);
// std::stringstream WriteToPipe(int fd[2]);
void WriteToPipe(int fd[2]);
std::stringstream ReadFromPipe(int file_descriptor);