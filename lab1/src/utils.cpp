#include "utils.h"

pid_t CreateChild() {
    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "Failed to create child" << std::endl;
        exit(EXIT_FAILURE);
    }
    return pid;
}

void CreatePipe(int pipeFd[2]) {
    int result = pipe(pipeFd);
    if (result == -1) {
        std::cerr << "Failed to create pipe" << std::endl;
        exit(EXIT_FAILURE);
    }
    return;
}

void Exec(const char *pathToChild) {
    int result = execl(pathToChild, "child", nullptr);
    if (result == -1) {
        std::cerr << "Failed to execute child" << std::endl;
        exit(EXIT_FAILURE);
    }
    return;
}

void WriteToPipe(int fd[2], std::string message) {
    ssize_t result = write(fd[WRITE], message.c_str(), message.length());
    if (result == -1) {
        std::cerr << "Failed to write to pipe" << std::endl;
        exit(EXIT_FAILURE);
    }
}