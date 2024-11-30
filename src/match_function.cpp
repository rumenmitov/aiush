#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

//made another helping function to check if the 2 comannds match with a matching rate
//of over 50%

float match(const std::string& str1, const std::string& str2)
{
    //i initialize the frequency counters for each letter of each word and count 
    //the frequencies afterwards

    std::unordered_map<char, int> freq1, freq2;//rising the frequency of each character
    for(char c : str1) freq1[c]++;
    for(char c : str2) freq2[c]++;

    int matching_chars = 0;
    for(const auto& [char1, count1] : freq1)//for each letter in both words
    {
        if(freq2.count(char1))//i compare their frequencies 
        {
            matching_chars += std::min(count1, freq2[char1]);
        }
    }

    //now to check if their letters match over 50%
    float matching_percentage = matching_chars / std::max(str1.size(), str2.size());

    return matching_percentage;//rreturning the matching percentage
}

//the arguments of the function will take in the error command (misspelled) and compare it to what I have in my command list

//i am still contemplating on what it should return

std::unordered_map<std::string, float> match_command(std::string err_com, std::vector<std::string> com_history_list)
{
    std::unordered_map<std::string, float> matching_commands;

    for(std::string& each_comm : com_history_list)//iterate through each command in the history
    {
        float comm_match = match(err_com, each_comm);//saving the match as a variable
        if(comm_match > 0.5)
        {
            matching_commands[each_comm] = comm_match;
        }
    }

    return matching_commands;
}

//we are pretty confident with our progress and we are looking forward to the 
// to see the finished product by tomorrow