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

// void WriteToPipe(int fd[2], std::string message) {
//     ssize_t result = write(fd[WRITE], message.c_str(), message.length());
//     if (result == -1) {
//         std::cerr << "Failed to write to pipe" << std::endl;
//         exit(EXIT_FAILURE);
//     }
// }

// std::stringstream ReadFromPipe (int file_descriptor){   
//     std::stringstream stream;

//     while (1){
//         unsigned char buf[256] = "";
//         ssize_t state = read(file_descriptor, &buf, 256UL);
//         if (state > 0){
//             stream << buf;
//         }else if (state == 0){
//             return stream;
//         }else{
//             perror("Read fail");
//             exit(EXIT_FAILURE);
//         }
//     }
// }