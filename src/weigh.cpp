#include "weigh.hpp"

namespace Weigh {

    float CmdHistory::get_score(const string& cmd) {
        if (frequency.count(cmd) == 0 || recency.count(cmd) == 0)
            return 0;

        float freq = (float) frequency[cmd];
        float rec  = ( (float) recency[cmd]) / 1000;

        return (freq * 3 / 4) + (rec / 4);
    }

    void CmdHistory::update(const string& cmd) {
        if (frequency.count(cmd) == 0) {
            frequency.insert(pair(cmd, 0));
        }

        if (recency.count(cmd) == 0) {
            recency.insert(pair(cmd, 0));
        }

        frequency[cmd]++;
        recency[cmd] = time(nullptr);
    }
}
