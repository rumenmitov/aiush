#include "weigh.hpp"

#include <unistd.h>
#include <cassert>


int main(int argc, char* argv[]) {
    Weigh::CmdHistory hist;

    hist.update("echo");
    hist.update("cd");

    hist.update("echo");
    hist.update("echo");

    sleep(1);
    hist.update("cd");

    assert(hist.get_score("cd") < hist.get_score("echo"));

    return 0;
}

