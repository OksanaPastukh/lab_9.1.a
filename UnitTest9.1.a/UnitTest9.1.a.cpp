#include "pch.h"
#include "CppUnitTest.h"
#include "../Project9.1.A/project9.1.a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91a
{
	TEST_CLASS(UnitTest91a)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int N = 5;
			Student* p = new Student[N];
			p[0].prizv = "Pastukh";
			p[0].specialty = ComputerScience;
			p[0].grades_in_physics = 5;
			p[0].grades_in_mathematics = 4;
			p[1].prizv = "Petrov";
			p[1].specialty = Informatics;
			p[1].grades_in_physics = 3;
			p[1].grades_in_mathematics = 2;
			p[2].prizv = "Karginov";
			p[2].specialty = Informatics;
			p[2].grades_in_physics = 4;
			p[2].grades_in_mathematics = 5;
			p[3].prizv = "Ivanov";
			p[3].specialty = Mathematics;
			p[3].grades_in_physics = 2;
			p[3].grades_in_mathematics = 2;
			p[4].prizv = "Abramov";
			p[4].specialty = Mathematics;
			p[4].grades_in_physics = 3;
			p[4].grades_in_mathematics = 3;
			c = LineSearch_proc(p, N);
			Assert::AreEqual(c, 40);
		}
	};
}
