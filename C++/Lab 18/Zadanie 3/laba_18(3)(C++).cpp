#include "Header.h"
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Russian");
    Stack<int> stack1(5);
    char ch;
    for (int i=0;i<5;i++)
    {
        cin >> ch;
        stack1.push(ch); 
    }
    cout << endl;
    stack1.print();
    cout << endl << endl;
    cout << "Удалим элемент из стэка! " << endl;
    stack1.pop();
    stack1.print();
    //Stack<char> stack2(stack1);
    cout << endl << endl;
    cout << "Сработал конструктор копирования!" << endl;
    cout << stack1;
    cin >> stack1;
    //!stack2;
    //++stack2;
    //stack2.print();
    //cout << "Второй в очереди элемент:" << stack2.peek(2) << endl;
    return 0;
}
