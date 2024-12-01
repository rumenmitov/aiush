#include "history.hpp"


namespace History {

    double CmdHistory::get_score(const string& cmd) {
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
        double freq = (float) entry.occurences.size();

        // rec measures the most recent entry (more recent is better)
	/* NOTE
	 * rec is a negative value. Hence the further away the entry is from the current
	 * time, the more it subtracts from the overall score.
	 */
        double rec  = difftime(entry.occurences.back(), time(nullptr));

        return (freq * FrequencyBias) + (rec * RecencyBias);
    }


    unordered_map<string, double> CmdHistory::get_all_scores(void) 
    {
	unordered_map<string, double> scores;

	for (auto entry : entries) {
	    scores[entry.first] = get_score(entry.first);
	}

	return scores;
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
