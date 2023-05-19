#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_9_ap/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(BinarySearchTreeTest)
    {
    public:

        TEST_METHOD(TestCountNodes)
        {
            // ��������� ��������� �������� ������
            std::shared_ptr<Node> bst = nullptr;
            std::vector<int> elements = { 5, 3, 7, 2, 4, 6, 8 };
            bst = createBinarySearchTree(elements);

            // ��������� ������� ��������
            int expectedCount = elements.size();

            // ��������� �������� ������� ��������
            int actualCount = countNodes(bst);

            // �������� �� ���������
            Assert::AreEqual(expectedCount, actualCount);
        }
    };
}
