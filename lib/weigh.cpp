#include "weigh.hpp"

namespace Weigh {

    float CmdHistory::get_score(const string& cmd) {
        // entry has not been seen before
        if (entries.count(cmd) == 0)
            return 0;

        CmdEntry entry = entries[cmd];

        // remove entries older than 60 seconds
        while (! entry.occurences.empty()) {
            // diff is measured in seconds
            int diff = difftime(time(nullptr), entry.occurences.front());

            if (diff > 60) entry.occurences.pop_front();
            else break;
        }

        // freq measures occurences in the last 60s
        float freq = (float) entry.occurences.size();

        // rec measures the most recent entry
        float rec  = (float)entry.occurences.back() / CLOCKS_PER_SEC;

        return (freq * FrequencyBias) + (rec * RecencyBias);
    }

    
    void CmdHistory::update(const string& cmd) {
        if (entries.count(cmd) == 0) {
            CmdEntry entry;

            entry.occurences.push_back(time(nullptr));
            entries.insert(pair(cmd, entry));
        } else {
            CmdEntry *entry = &entries[cmd];
            entry->occurences.push_back(time(nullptr));
        }
    }
}
