#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_8_ap/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(QueueTest)
    {
    public:

        TEST_METHOD(TestEnqueue)
        {
            Elem* first = nullptr;
            Elem* last = nullptr;
            int value1 = 10;
            int value2 = 20;

            enqueue(first, last, value1);
            enqueue(first, last, value2);

            Assert::IsNotNull(first);
            Assert::AreEqual(value1, first->value);
            Assert::IsNotNull(first->next);
            Assert::AreEqual(value2, first->next->value);
        }
    };
}
