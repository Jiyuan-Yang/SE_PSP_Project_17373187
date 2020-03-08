#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Point.h"
#include "../src/Line.h"
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		TEST_METHOD(LineConstructAndGetTestNormal)
		{
			Line l0 = Line(0, 1, 1, 2);
			Assert::AreEqual(l0.getX0(), 0);
			Assert::AreEqual(l0.getY0(), 1);
			Assert::AreEqual(l0.getX1(), 1);
			Assert::AreEqual(l0.getY1(), 2);
			Assert::AreEqual(l0.getA(), 1.0);
			Assert::AreEqual(l0.getB(), -1.0);
			Assert::AreEqual(l0.getC(), 1.0);
		}
		TEST_METHOD(LineConstructAndGetTestBEql0)
		{
			Line l0 = Line(0, 1, 0, 2);
			Assert::AreEqual(l0.getX0(), 0);
			Assert::AreEqual(l0.getY0(), 1);
			Assert::AreEqual(l0.getX1(), 0);
			Assert::AreEqual(l0.getY1(), 2);
			Assert::AreEqual(l0.getA(), 1.0);
			Assert::AreEqual(l0.getB(), 0.0);
			Assert::AreEqual(l0.getC(), 0.0);
		}
		TEST_METHOD(LineConstructAndGetTestAEql0)
		{
			Line l0 = Line(1, 1, 60, 1);
			Assert::AreEqual(l0.getX0(), 1);
			Assert::AreEqual(l0.getY0(), 1);
			Assert::AreEqual(l0.getX1(), 60);
			Assert::AreEqual(l0.getY1(), 1);
			Assert::AreEqual(l0.getA(), 0.0);
			Assert::AreEqual(l0.getB() / l0.getC(), -1.0);
		}
		TEST_METHOD(LineIntersectTestParallels)
		{
			std::set<Point> pointSet;
			// x
			Line a = Line(1, 1, 60, 1);
			Line b = Line(-100, 100, 12345, 100);
			Line::getLineIntersectPoint(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 0);
			// y
			a = Line(100, 1, 100, 12345);
			b = Line(-100, 100, -100, -12345);
			Line::getLineIntersectPoint(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 0);
			// normal
			a = Line(0, 0, 1, 2);
			b = Line(0, -100, 1, -98);
			Line::getLineIntersectPoint(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 0);
		}
		TEST_METHOD(LineIntersect)
		{
			std::set<Point> pointSet;
			Line a = Line(1, 1, 3, -1);
			Line b = Line(1, 0, 2, 1);
			Line::getLineIntersectPoint(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 1);
			for (Point p : pointSet) {
				Assert::AreEqual(p.getX(), 1.5);
				Assert::AreEqual(p.getY(), 0.5);
			}
			Line c = Line(1, 2, 2, -1);
			Line::getLineIntersectPoint(pointSet, a, c);
			Line::getLineIntersectPoint(pointSet, b, c);
			Assert::AreEqual((int)pointSet.size(), 1);
		}
	};
}
