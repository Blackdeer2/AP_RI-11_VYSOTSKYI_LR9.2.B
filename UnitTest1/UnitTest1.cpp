#include "pch.h"
#include "CppUnitTest.h"
#include "../PR9.2.B/PR9.2.B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* s = new Student;
			s->kurs = I;
			s->spec = IT;
			s->prizv = "A";
			int t = BinSearch(s, 1, "A", II, SA);
			Assert::AreEqual(t, -1);
		}
	};
}
