#include <iostream>
using namespace std;
int main()
{
    int num1;
    int num2;
    char op;
    cout << "Enter 2 numbers: ";
    cin >> num1 >> num2;
    cout << "Choose the operation you want to perform(+, -, /, *): ";
    cin >> op;

    switch (op) {
    case '+':
        cout << "Result: " << num1 + num2;
        break;

    case '-':
        cout << "Result: " << num1 - num2;
        break;

    case '*':
        cout << "Result: " << num1 * num2;
        break;

    case '/':
        if (num2 != 0)
            cout << "Result: " << double(num1) / num2;
        else
            cout << "Error: Division by zero is not allowed.";
        break;

    default:
        cout << "Invalid operation. Please choose +, -, *, or /";
        break;
    }
    return 0;
}
