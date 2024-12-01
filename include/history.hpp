#pragma once

#include <ctime>
#include <unordered_map>
#include <string>
#include <deque>

namespace History {
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
	
    private:
	/**
	   @field Matches command name to all of its occurences.
	*/
	unordered_map<string, CmdEntry> entries;

    public:
	/* NOTE
	   Weights for frequency and recency should add up to 1.0.
	*/
	static constexpr  float RecencyBias = 0.30;
	static constexpr  float FrequencyBias = 0.25;
	static constexpr  float MatchBias = 0.45;

	
	CmdHistory(void) {};

	/**
	 * @brief Updates occurences of an entry. Creates a new entry if there was no match.
	 */
	void update(const string&);

	/**
	 * @brief Gets score of a given entry. Returns 0, if entry does not exist.
	 */
	double get_score(const string&);

	/**
	 * @brief Get scores of all enrties.
	 */
	unordered_map<string, double> get_all_scores(void);
    };
}
