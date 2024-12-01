#include "history.hpp"

#include <unistd.h>
#include <cassert>

    
int main(void) {
    History::CmdHistory hist;

    hist.update("echo");
    hist.update("cd");

    hist.update("echo");
    hist.update("echo");

    sleep(1);
    hist.update("cd");

    assert(hist.get_score("cd") > hist.get_score("echo"));
    return 0;
}

