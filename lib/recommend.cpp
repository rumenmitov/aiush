#include "recommend.hpp"
#include "matching.hpp"

namespace Recommend {
    string Recommender::recommend(const string &wrong_command) 
    {
	// calculate match score for wrong command
	vector<string> commands_in_history; // TODO optimize later
	unordered_map<string, float> scores = history.get_all_scores();

	if (scores.empty()) return "";

	
	for (auto entry : scores) {
	    commands_in_history.push_back(entry.first);
	}

	if (commands_in_history.empty()) return "";
    
	
	unordered_map<string, float> possibilities = match_commands(
	    wrong_command,
	    commands_in_history
	    );

	if (commands_in_history.empty()) return "";
	

	float max_score = 0;
	string recommendation = "";
	
	
	// for each match entry, add biased match score to get_score(entry)
	for (auto entry : possibilities) {
	    float score = entry.second * History::CmdHistory::MatchBias + scores[entry.first];

	    if (score > max_score) {
		max_score = score;
		recommendation = entry.first;
	    }
	}

	return recommendation;
    }
}
