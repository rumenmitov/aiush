#pragma once

#include <string>

#include "history.hpp"


namespace Recommend {
    using namespace std;

    /**
     * @brief Manages state of the auto-correction engine.
     */
    struct Recommender 
    {
    public:
	Recommender(void) {}
	~Recommender(void) {}
	
	
	/**
	 * @brief Provides a recommendation based on user's command history and the wrong command that they entered just now.
	 */
	string recommend(const string& wrong_command);

	/**
	 * @field Keeps track of successfully executed commands history.
	 */
	History::CmdHistory history;
    };
}
