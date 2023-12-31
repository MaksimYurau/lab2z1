﻿/*
Требуется создать шаблон некоторого целевого класса А. 
В каждом варианте уточняются требования к реализации – указанием на применение некоторого серверного класса В. 
Это означает, что объект класса В используется как элемент класса А. 
В качестве серверного класса может быть указан либо класс, созданный программистом в рамках того же задания, 
либо класс стандартной библиотеки. 
Если не указан серверный класс или класс стандартной библиотеки, 
используется структура (класс) Node с типизированной переменной value, 
и указателями на предыдущий/следующий элемент. Целевой класс должен содержать: 
конструктор по умолчанию, создающий экземпляр класса нулевого размера; 
Конструктор от std::initializer_list<T>. Конструктор копирования и копирующий оператор присваивания. 
Конструктор перемещения и перемещающий оператор присваивания. 
Добавить в целевой класс другие методы, необходимые для реализации задания. 
При выборе методов ориентироваться на методы, которые есть у шаблонных классов библиотеки STL. 
Во всех вариантах необходимо предусмотреть генерацию и обработкуисключений для возможных ошибочных ситуаций. 
Во всех вариантах в целевом классе для указателей необходимо предусмотреть использование созданного ранее шаблонного класса, 
реализующего умный указатель. 
Проект должен состоять из нескольких файлов, в каждом файле реализация своего шаблонного класса 
(целевой класс, (серверный класс), класс обработчик исключений, класс умных указателей).
Во всех вариантах показать в клиенте main использование созданного целевого класса, включая ситуации, 
приводящие к генерации исключений. 
Показать инстанцирование шаблона для типов int, doublе, std::string. 
Для этого написать программу, демонстрирующую работу с этим шаблоном для различных типов параметров шаблона. 
Программа должна содержать меню, позволяющее осуществить проверку всех методов шаблона. 
9. Целевой шаблонный класс: Queue. 
   Реализация с применением Vect.
*/

#include <iostream>
#include <string>

#include "Vect.h"
#include "VectError.h"
#include "Queue.h"
#include "QueueException.h"


using namespace std;

//template <class T>
//void SomeFunction(Vect<T> v) {
//    std::cout << "Reversive output for " << v.mark() << ":" << endl;
//    size_t n = v.size();
//    for (int i = n - 1; i >= 0; --i) std::cout << v[i] << " ";
//    std::cout << endl;
//}


int main() {
    setlocale(0, "Ru");

    Queue<int> iQ;
    Queue<double> dQ;
    Queue<string> sQ;
    Queue<int> eQ;

    //iQ.push_back(1);
    //iQ.push_back(2);

    //dQ.push_back(1.1);
    //dQ.push_back(2.4);

    //sQ.push_back("Hello");
    //sQ.push_back("World");

    //cout << "Первый элемент очереди int: " << iQ.GetFront() << endl;
    //cout << endl;
    //cout << "Первый элемент очереди double: " << dQ.GetFront() << endl;
    //cout << endl;
    //cout << "Первый элемент очереди string: " << sQ.GetFront() << endl;
    //cout << endl;
    //try {
    //    Queue<int> eQ;
    //    cout << eQ.GetFront() << endl;
    //}
    //catch (const QueueException& e) {
    //    cerr << "Исключение: " << e.GetStr() << endl;
    //}

    int a = 0;

    while (a != 5)
    {
        cout << "-------------------" << endl;
        cout << "Меню:" << endl;

        cout << "1. Работа с int\n2. Работа с double\n3. Работа с string\n4. Обработка исключения\n5. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> a;
        cout << "-------------------" << endl;

        switch (a)
        {
        case 1: {
            int var1, var2;
            cout << "Добавление числа в начало очереди:" << endl;
            cout << "Введите первое число: ";
            cin >> var1;
            cout << "Введите второе число: ";
            cin >> var2;
            iQ.push_back(var1);
            iQ.push_back(var2);
            cout << "Первый элемент очереди: " << iQ.GetFront() << endl;
            break;
        }
        case 2: {
            double var1, var2;
            cout << "Добавление числа в начало очереди:" << endl;
            cout << "Введите первое число: ";
            cin >> var1;
            cout << "Введите второе число: ";
            cin >> var2;
            dQ.push_back(var1);
            dQ.push_back(var2);
            cout << "Первый элемент очереди: " << dQ.GetFront() << endl;
            break;}

        case 3: {
            string var1, var2;
            cout << "Добавление строку в начало очереди:" << endl;
            cout << "Введите первую строку: ";
            cin >> var1;
            cout << "Введите вторую строку: ";
            cin >> var2;
            sQ.push_back(var1);
            sQ.push_back(var2);
            cout << "Первый элемент очереди: " << sQ.GetFront() << endl;
            break;}

          case 4:
              try {
                  cout << eQ.GetFront() << endl;
              }
              catch (const QueueException& e) {
                  cerr << "Исключение: " << e.GetStr() << endl;
              }
              break;
        case 5:
            cout << "Завершение работы..." << endl;
            break;

        default:
            cout << "Ошибка - неизвестное значение!" << endl;
            break;
        }
    }

    /* 
    try
    {
        string initStr[5] = { "first", "second", "third", "fourth", "fifth" };
        Vect<int> v1(10);
        v1.mark(string("v1"));
        size_t n = v1.size();
        for (int i = 0; i < n; ++i) v1[i] = i + 1;
        v1.show();
        SomeFunction(v1);
        try {
            Vect<string> v2(5);
            v2.mark(string("v2"));
            size_t n = v2.size();
            for (int i = 0; i < n; ++i) v2[i] = initStr[i];
            v2.show();
            v2.insert(v2.begin() + 3, "After_third");
            v2.show();
            cout << v2[6] << endl;
            v2.push_back("Add_1");
            v2.push_back("Add_2");
            v2.push_back("Add_3");
            v2.show();
            v2.pop_back();
            v2.pop_back();
            v2.show();
        }
        catch (VectError& vre)
        {
            vre.ErrMsg();
        }

        try
        {
            Vect<int> v3;
            v3.mark(string("v3"));
            v3.push_back(41);
            v3.push_back(42);
            v3.push_back(43);
            v3.show();
            Vect<int> v4;
            v4.mark(string("v4"));
            v4 = v3;
            v4.show();
            v3.pop_back();
            v3.pop_back();
            v3.pop_back();
            v3.pop_back();
            v3.show();
        }
        catch (VectError& vre)
        {
            vre.ErrMsg();
        }
    }
    catch (...) { cerr << "Epilogue: error of Main().\n"; }
    */

    cout << endl;
    system("pause");

    return 0;
}
