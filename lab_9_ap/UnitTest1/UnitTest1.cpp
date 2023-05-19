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
            // Створення тестового бінарного дерева
            std::shared_ptr<Node> bst = nullptr;
            std::vector<int> elements = { 5, 3, 7, 2, 4, 6, 8 };
            bst = createBinarySearchTree(elements);

            // Очікувана кількість елементів
            int expectedCount = elements.size();

            // Отримання фактичної кількості елементів
            int actualCount = countNodes(bst);

            // Перевірка на співпадіння
            Assert::AreEqual(expectedCount, actualCount);
        }
    };
}
