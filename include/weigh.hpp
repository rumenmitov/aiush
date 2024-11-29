#pragma once

#include <ctime>
#include <unordered_map>
#include <cstdint>
#include <string>

namespace Weigh {
    using namespace std;

    class CmdHistory {
        private:
            unordered_map<string, uint32_t> frequency; 
            unordered_map<string, time_t> recency;

            uint32_t get_score(const string&);

        public:
            CmdHistory(void) {};
            void update(const string&);
    };
}

