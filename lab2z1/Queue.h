#include <initializer_list>
#include <exception>
#include "Vect.h"
#include "QueueException.h"

template <typename T>
class Queue {

private:
    Vect<T> data;

public:
    Queue() = default;

    Queue(initializer_list<T> init_list) {
        for (const auto& item : init_list) {
            push_back(item);
        }
    }

    Queue(const Queue& other) : data(other.data) {}

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    Queue(Queue&& other) noexcept : data(move(other.data)) {}
    Queue& operator=(Queue&& other) noexcept {
        if (this != &other) {
            data = move(other.data);
        }
        return *this;
    }


    void push_back(const T& element) {
        data.push_back(element);
    }

    T GetFront() {
        if (data.empty()) {
            throw QueueException();
        }
        T front_elem = data.front();
        data.pop_front();
        return front_elem;
    }

    bool isEmpty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};
