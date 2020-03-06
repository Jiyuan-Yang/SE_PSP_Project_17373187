#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Circle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {
	TEST_CLASS(test) {
public:

	TEST_METHOD(PointConstructorTest) {
		Point* a = new Point(1.1, 2.2);
		Assert::AreEqual(a->getX(), 1.1);
		Assert::AreEqual(a->getY(), 2.2);

		Point b = Point(1.2, 3.4);
		Assert::AreEqual(b.getX(), 1.2);
		Assert::AreEqual(b.getY(), 3.4);
	}
	};
}
