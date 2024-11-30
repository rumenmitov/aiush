#include <cassert>

#include "test-history.hpp"
#include "test-recommend.hpp"


int main(int argc, char *argv[])
{
    assert(Tests::test_history());
    assert(Tests::test_recommend_mistype());
    assert(Tests::test_recommend_mistype_long());
    assert(Tests::test_recommend_mistype_short());
    
    return 0;
}
