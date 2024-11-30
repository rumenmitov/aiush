#pragma once

#include <matching.hpp>
#include <unistd.h>
#include <string>
#include <vector>
#include <unordered_map>

float match(const std::string& str1, const std::string& str2);
std::unordered_map<std::string, float> match_commands(const std::string& err_com, const std::vector<std::string>& com_history_list);


namespace Tests {

    bool test_match()//test for the match function
    {
        std::cout<< "Running test_match...\n";

        std::string str1 = "echi";
        std::string str2 = "echo";
        float score = match(str1, str2);

        if(score >= 0 && score <= 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool test_match_commands()//test for the match_command function
    {
        std::cout<< "Runnign test_match_commands...\n";

        std::string err_comm = "echz";
        std::vector<std::string> com_history_list = {"ec", "echo", "exec"};
        auto results  = match_commands(err_comm, com_history_list);

        // Verify all commands in the history are either in the result or below threshold
        for (const auto& command : com_history_list)
        {
            if (results.find(command) != results.end())
            {
                // Ensure the match score is valid
                float score = results[command];
                if (score < 0.5 || score > 1.0)
                {
                    return false;
                }
            }
        }

        // Check no extra commands are in the results
        for (const auto& [cmd, score] : results)
        {
            if (std::find(com_history_list.begin(), com_history_list.end(), cmd) == com_history_list.end())
            {
                return false;
            }
        }

        return true;
    }

    bool test_edge_cases()//test for edge cases (empty strings, single commands, etc)
    {
        std::cout<< "Running test_edge_cases...\n";

        /*
            case 1: empty error command
        */
       std::string err_comm = "";
       std::vector<std::string> com_history_list = {"echo", "exec", "ec"};
       auto results = match_commands(err_comm, com_history_list);

       if(!results.empty())
       {
            return false;
       }
       else
       {
            return true;
       }

       /*
            case 2: empty history
       */
        err_comm = "echo";
        com_history_list = {};
        results = match_commands(err_comm, com_history_list);

        if(!results.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}





