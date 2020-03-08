#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Point.h"
#include "../src/Line.h"
#include "../src/Circle.h"
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		TEST_METHOD(CircleConstructAndGetTest)
		{
			Circle a = Circle(1, 2, 3);
			Assert::AreEqual(a.getX(), 1.0);
			Assert::AreEqual(a.getY(), 2.0);
			Assert::AreEqual(a.getR(), 3.0);
		}
		TEST_METHOD(CircleCircleIntersect0Out)
		{
			// ��Բ����
			std::set<Point> pointSet;
			Circle a = Circle(1, 1, 1);
			Circle b = Circle(5, 1, 1);
			Circle::getCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 0);
		}
		TEST_METHOD(CircleCircleIntersect0In)
		{
			// ��Բ�ں�
			std::set<Point> pointSet;
			Circle a = Circle(2, 2, 2);
			Circle b = Circle(2, 2, 1);
			Circle::getCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 0);
		}
		TEST_METHOD(CircleCircleIntersect1Out)
		{
			// ��Բ����
			std::set<Point> pointSet;
			Circle a = Circle(1, 1, 1);
			Circle b = Circle(3, 1, 1);
			Circle::getCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 1);
		}
		TEST_METHOD(CircleCircleIntersect1In)
		{
			// ��Բ����
			std::set<Point> pointSet;
			Circle a = Circle(2, 2, 2);
			Circle b = Circle(3, 2, 1);
			Circle::getCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 1);
		}
		TEST_METHOD(CircleCircleIntersect2)
		{
			// ��Բ�ཻ
			std::set<Point> pointSet;
			Circle a = Circle(0, 0, 1);
			Circle b = Circle(1, 1, 1);
			Circle::getCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 2);
			a = Circle(2, 2, 2);
			b = Circle(3, 2, 2);
			Circle::getCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 4);
		}
		TEST_METHOD(LineCircleIntersect0)
		{
			// ֱ����Բ����
			std::set<Point> pointSet;
			Line a = Line(0, -2, 2, 0);
			Circle b = Circle(1, 1, 1);
			Circle::getLineCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 0);
		}
		TEST_METHOD(LineCircleIntersect1)
		{
			// ֱ����Բ����
			std::set<Point> pointSet;
			Line a = Line(2, 0, 2, 1);
			Circle b = Circle(1, 1, 1);
			Circle::getLineCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 1);
		}
		TEST_METHOD(LineCircleIntersect2)
		{
			// ֱ����Բ��
			std::set<Point> pointSet;
			Line a = Line(0, 0, 1, 1);
			Circle b = Circle(1, 1, 1);
			Circle::getLineCircleIntersect(pointSet, a, b);
			Assert::AreEqual((int)pointSet.size(), 2);
		}
	};
}
