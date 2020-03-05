#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Line.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {
	TEST_CLASS(test) {
public:

	TEST_METHOD(LineIntersectTest) {
		Line a = Line(0, 0, 1, 1);
		Line b = Line(0, 2, 2, 0);
		Point *ab = Line::getIntersectPoint(a, b);
		Assert::AreEqual(ab->getX(), 1.0);
		Assert::AreEqual(ab->getY(), 1.0);
	}
	};
}
