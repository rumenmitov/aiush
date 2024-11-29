#pragma once

#include <ctime>
#include <unordered_map>
#include <string>
#include <deque>

namespace Weigh {
    using namespace std;

    /**
     * @brief Keeps track of how many times the command was called and when it was called.
     */
    struct CmdEntry {
        deque<time_t> occurences;
    };

    /**
     * @brief Manages shell history.
     */
    class CmdHistory {

	/* NOTE
	   Weights for frequency and recency should add up to 1.0.
	*/
	static constexpr float RecencyBias = 0.75;
	static constexpr  float FrequencyBias = 0.25;
	
    private:
	/**
	   @field Matches command name to all of its occurences.
	*/
	unordered_map<string, CmdEntry> entries;

    public:
	CmdHistory(void) {};

	/**
	 * @brief Updates occurences of an entry. Creates a new entry if there was no match.
	 */
	void update(const string&);

	/**
	 * @brief Gets score of a given entry. Returns 0, if entry does not exist.
	 */
	float get_score(const string&);
    };
}
