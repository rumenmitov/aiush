#include <cassert>

#include "test-history.hpp"
#include "test-recommend.hpp"
#include "test-match.hpp"


int main(int argc, char *argv[])
{
    assert(Tests::test_match());
    assert(Tests::test_match_commands());
    assert(Tests::test_edge_cases());
    assert(Tests::test_history());
    assert(Tests::test_recommend_mistype());
    assert(Tests::test_recommend_mistype_long());
    assert(Tests::test_recommend_mistype_short());
    
    return 0;
}
