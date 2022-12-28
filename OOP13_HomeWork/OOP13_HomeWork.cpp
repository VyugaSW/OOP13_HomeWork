

#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;


string HooksCheck(string str) {
    string buffStr; // строка необходимая для вывода в случае неудачи
    Stacks st; // объекст класса stack

    for (auto i = str.begin(); i < str.end(); i++) {
        buffStr.push_back(*i); // добавляем в буфер по элементу из основной строка
        switch (*i) { // проверям со switch()
            // если есть открывающася скобка, заносим в стек обратную
            case '(': 
                st.PushStack(')');
                break;
            case '[':
                st.PushStack(']');
                break;
            case '{':
                st.PushStack('}');
                break;

            // если символ равен закрывающейся, то сравниваем с последним элементом стека,
            // при несоответствии возращаем строку, где обнаружен недочёт,
            // иначе удаляем последний элемент из стека, как нашедшийся
            case ')':
            case ']':
            case '}':
                if (st.IsEmptyStack() || st.GetTopStack() != *i) {
                    return buffStr;
                }
                st.PopStack();
            default:
                break;
        }           
    }
    return "OK";
}






int main()
{
    string str;
    cout << "Enter a string: \n";
    getline(cin, str, ';');

    cout << HooksCheck(str);
}


