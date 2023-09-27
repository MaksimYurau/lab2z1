#ifndef QUEUEEXCEPTION_H
#define QUEUEEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class QueueException : public exception {

public:
    string GetStr() const {
        return "Поймана ошибка в очереди!";
    }
};

#endif