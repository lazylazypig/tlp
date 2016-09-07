#include <tlp/test/Test.hpp>
#include <tlp/list/algo/Comb.h>
#include <Point.h>
#include <Line.h>
#include <Points.h>
#include <Lines.h>
#include <Triple.h>
#include <CountTriangles.h>

FIXTURE(TestTriangle)
{
    using Lines = __lines( __line(__p(1), __p(2), __p(8))
                         , __line(__p(1), __p(3), __p(7), __p(9))
                         , __line(__p(1), __p(4), __p(6), __p(10))
                         , __line(__p(1), __p(5), __p(11))
                         , __line(__p(2), __p(3), __p(4), __p(5))
                         , __line(__p(8), __p(7), __p(6), __p(5))
                         , __line(__p(8), __p(9), __p(10), __p(11)));

    TEST("test triangle")
    {
        ASSERT_TRUE(__is_triangle(__triple(__p(1), __p(2), __p(3)), Lines));
        ASSERT_FALSE(__is_triangle(__triple(__p(1), __p(2), __p(8)), Lines));
    };

    TEST("count triangles")
    {
        using Points = __points( __p(1), __p(2), __p(3), __p(4), __p(5), __p(6)
                               , __p(7), __p(8), __p(9), __p(10), __p(11));

        using TriplePoints = __comb(Points, __int(3));

        ASSERT_EQ(__count_triangles(TriplePoints, Lines), __int(24));
    };
}

int main()
{
    TLP_REPORT_ALL_TESTS();
    return 0;
}
