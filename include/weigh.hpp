#pragma once

#include <ctime>
#include <unordered_map>
#include <string>
#include <deque>

namespace Weigh {
    using namespace std;

    struct CmdEntry {
        string val;
        deque<time_t> occurences;
    };

    class CmdHistory {
        private:
           unordered_map<string, CmdEntry> entries;

        public:
            CmdHistory(void) {};
            void update(const string&);
            float get_score(const string&);
    };
}

