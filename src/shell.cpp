#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

void executeCommand(std::vector<std::string>& args, int inputFd = 0, int outputFd = 1) {
    if (args.empty()) return;
    for (auto it = args.begin(); it != args.end();) {
        if (*it == ">") {
            outputFd = open((++it)->c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (outputFd == -1) perror("Failed to open output file");
            it = args.erase(it - 2, it + 1);
        } else if (*it == "<") {
            inputFd = open((++it)->c_str(), O_RDONLY);
            if (inputFd == -1) perror("Failed to open input file");
            it = args.erase(it - 2, it + 1);
        } else {
            ++it;
        }
    }
    std::vector<char*> argv;
    for (auto& arg : args) argv.push_back(&arg[0]);
    argv.push_back(nullptr);

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (inputFd != 0) { dup2(inputFd, 0); close(inputFd); }
        if (outputFd != 1) { dup2(outputFd, 1); close(outputFd); }
        execvp(argv[0], argv.data());
        perror("execvp failed");
        exit(1);
         // If execvp fails, exit with error
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for the child 
        
        // Check if child process terminated normally
        if (WIFEXITED(status)) {
            int exitCode = WEXITSTATUS(status);
            if (exitCode == 0) {
                std::cout << "Command executed successfully.\n";
            } else {
                std::cout << "Command execution failed with exit code " << exitCode << ".\n";
            }
        }
        // Check if child process was terminated by a signal
       // else if (WIFSIGNALED(status)) {
        //    int signal = WTERMSIG(status);
       //     std::cout << "Command terminated by signal " << signal << ".\n";
       // }
        // Handle other possible statuses
        else {
            std::cout << "Command terminated abnormally.\n";
        }

        if (inputFd != 0) close(inputFd);
        if (outputFd != 1) close(outputFd);
    } else {
        // Fork failed
        perror("fork failed");
    }
}

bool handleBuiltInCommands(const std::vector<std::string>& args) {
    if (args.empty()) return false;
    if (args[0] == "cd") {
        if (args.size() < 2) std::cerr << "cd: missing argument\n";
        else if (chdir(args[1].c_str()) != 0) perror("cd failed");
        return true;
    }
    if (args[0] == "exit") exit(0);
    return false;
}

void parseAndExecute(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> args;
    std::string token;
    while (iss >> token) args.push_back(token);
    if (args.empty()) return;
    if (handleBuiltInCommands(args)) return;
    if (std::find(args.begin(), args.end(), "|") != args.end()) {
        std::vector<std::string> cmd;
        int pipeFd[2], inputFd = 0;
        for (const auto& arg : args) {
            if (arg == "|") {
                pipe(pipeFd);
                executeCommand(cmd, inputFd, pipeFd[1]);
                close(pipeFd[1]);
                inputFd = pipeFd[0];
                cmd.clear();
            } else {
                cmd.push_back(arg);
            }
        }
        executeCommand(cmd, inputFd, 1);
        if (inputFd != 0) close(inputFd);
    } else {
        executeCommand(args, 0, 1);
    }
}

int main() {
    std::string input;
    while (true) {
        std::cout << "aiush> ";
        std::getline(std::cin, input);
        
        parseAndExecute(input);
    }
    return 0;
}