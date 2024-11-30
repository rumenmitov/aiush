#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unistd.h>

/*
    @brief the function that compares the command with the error command
*/
float match(const std::string& str1, const std::string& str2);

/*
    @brief the function that compares the whole history list with the error 
    command using the "match" function
*/
std::unordered_map<std::string, float> match_commands(const std::string& err_com, std::vector<std::string> com_history_list);


