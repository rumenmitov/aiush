#ifdef TESTS
#include <cassert>
#include "tests/test-weigh.hpp"
#endif // TESTS


int main(int argc, char* argv[]) {

#ifdef TESTS
    assert(Tests::test_weights());
#endif // TESTS


    return 0;
}
