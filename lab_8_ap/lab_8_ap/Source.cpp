#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

struct Elem {
    int value;
    Elem* next;
    Elem* prev;
};

void enqueue(Elem*& first, Elem*& last, int value) {
    Elem* newNode = new Elem;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = last;
    if (last != nullptr)
        last->next = newNode;
    last = newNode;
    if (first == nullptr)
        first = newNode;
}

int dequeue(Elem*& first, Elem*& last) {
    if (first == nullptr)
        return 0;
    Elem* temp = first;
    int value = temp->value;
    first = first->next;
    if (first != nullptr)
        first->prev = nullptr;
    else
        last = nullptr;
    delete temp;
    return value;
}

int calculateExpressionOrSum(Elem*& first, Elem*& last, int n) {
    int result = 0;

    if (n % 2 == 0 && n > 0) {
        for (int i = 0; i < n / 2; i++) {
            int firstValue = dequeue(first, last);
            int secondValue = dequeue(first, last);
            result += (firstValue - secondValue);
        }
    }
    else {
        while (first != nullptr) {
            result += dequeue(first, last);
        }
    }

    return result;
}

int main() {
    ifstream inputFile("123.txt");
    if (!inputFile) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    Elem* first = nullptr;
    Elem* last = nullptr;

    int n = 0;  // ≤н≥ц≥ал≥зуЇмо к≥льк≥сть елемент≥в €к 0

    string line;
    getline(inputFile, line);
    istringstream iss(line);
    iss >> n;  // «читуЇмо к≥льк≥сть елемент≥в

    while (getline(inputFile, line)) {
        istringstream iss(line);
        int num;
        while (iss >> num) {
            enqueue(first, last, num);
        }
    }

    inputFile.close();

    cout << "Number of elements in the deque: " << n << endl;
    cout << "Elements in the deque: ";
    Elem* current = first;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;

    int result = calculateExpressionOrSum(first, last, n);

    if (n % 2 == 0 && n > 0) {
        cout << "Value of expression (x1 - xn) + (x2 - (n-1)) + ... + (xn/2 - xn/2+1): " << result << endl;
    }
    else {
        cout << "Sum of elements in the deque: " << result << endl;
    }

    return 0;
}
