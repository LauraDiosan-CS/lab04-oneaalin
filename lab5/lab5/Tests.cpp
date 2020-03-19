#include <assert.h>
#include <string.h>
#include "Tests.h"
#include "Family.h"

void testCheltuieli() {
    char* tip1 = new char[10];
    char* tip2 = new char[10];
    strcpy_s(tip1, sizeof "haine", "haine");
    strcpy_s(tip2, sizeof "gaz", "gaz");
    Family c1(tip1, 23, 100);
    Family c2(tip2, 12, 1560);
    assert(c1.getMoney() == 100);
    assert(c2.getMoney() == 1560);

}