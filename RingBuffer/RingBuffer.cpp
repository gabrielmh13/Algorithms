#include<cstddef>
#include<stdexcept>
#include<iostream>

template<typename T, size_t capacity>
class RingBuffer {
private:
    T buffer[capacity];
    size_t head = 0;
    size_t tail = 0;
    bool full = false;

public:
    void Push(const T& value){
        if(full){
            tail = (tail + 1) % capacity;
        }

        buffer[head] = value;
        head = (head + 1) % capacity;

        full = (head == tail);
    }

    T Pop(){
        if(Empty()) throw std::runtime_error("Buffer empty");

        T value = buffer[tail];
        full = false;
        tail = (tail + 1) % capacity;
        return value;
    }

    bool Empty() const {
        return (!full && head == tail);
    }
};

int main(){
    RingBuffer<int, 4> rb;

    std::cout << "Empty: " << rb.Empty() << std::endl;

    rb.Push(1);
    rb.Push(2);
    rb.Push(3);
    rb.Push(4);

    std::cout << "Empty: " << rb.Empty() << std::endl;

    std::cout << "Pop.... " << rb.Pop() << " | " << rb.Pop() << " | " << rb.Pop() << " | " << rb.Pop() << std::endl;

    std::cout << "Empty: " << rb.Empty() << std::endl;

    return 0;
}