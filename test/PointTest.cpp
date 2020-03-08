#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Point.h"
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		TEST_METHOD(PointOperatorTestBasic)
		{
			Point p0 = Point(1.0, 2.0);
			Point p1 = Point(1.1, 1.9);
			Point p2 = Point(0.9, 2.1);
			Point p3 = Point(1.1, 1.9);
			std::set<Point> pointSet;
			pointSet.insert(p0);
			pointSet.insert(p1);
			pointSet.insert(p2);
			pointSet.insert(p3);
			Assert::AreEqual((int)pointSet.size(), 3);
		}
		TEST_METHOD(PointOperatorTestMoreDigits)
		{
			// basic case
			Point p0 = Point(1.000000001, 2.0);
			Point p1 = Point(1.000000002, 2.0);
			std::set<Point> pointSet;
			pointSet.insert(p0);
			pointSet.insert(p1);
			Assert::AreEqual((int)pointSet.size(), 1);
		}
		TEST_METHOD(PointGetTest)
		{
			// basic case
			Point p0 = Point(1.000000001, 2.0);
			Assert::AreEqual(p0.getX(), 1.000000001);
			Assert::AreEqual(p0.getY(), 2.0);
		}
	};
}
