#include "history.hpp"

#include <unistd.h>


namespace Tests {
    
    bool test_history(void) {
	History::CmdHistory hist;

	hist.update("echo");
	hist.update("cd");

	hist.update("echo");
	hist.update("echo");

	sleep(1);
	hist.update("cd");

	return hist.get_score("cd") < hist.get_score("echo");
    }

}
