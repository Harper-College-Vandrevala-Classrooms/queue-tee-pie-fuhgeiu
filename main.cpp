#include <string>
#include <cassert>


struct Cutie {
    virtual const std::string description() = 0;     // All cuties need to have a description of what makes them cute.
    virtual const int cuteness_rating() = 0; // All cuties get a cuteness rating out of ten.
};

struct puppy : public Cutie {

    const std::string description () {return "very  ";}

    const int cuteness_rating () {return 80;}
};

struct kitty : public Cutie {

    const std::string description () {return "comically soft fur, like a bird or bunny \n";}

    const int cuteness_rating () {return 700;}
};

struct penguin : public Cutie {

    const std::string description () {return "its a penguin what can i say \n";}

    const int cuteness_rating () {return 999999;}
};


class Queue {
private:
    Cutie** arr;
    int capacity;
    int size;
    Cutie** front;
    Cutie** rear;

public:
    Queue(int size) : capacity(size), size(0) {
        arr = new Cutie*[capacity];
        front = arr;
        rear = arr;
    }

    ~Queue() {delete[] arr;}

    void enqueue(Cutie* cutie) {
        if (size == capacity) {
            throw std::runtime_error("queue is full cannot add");
        }

        *rear = cutie;
        rear = arr + ((rear - arr + 1) % capacity);
        ++size;
    }

    Cutie* dequeue() {
        if (size == 0) {throw std::runtime_error("container empty");}

        Cutie* obj = *front;
        front = arr + ((front - arr + 1) % capacity);
        size--;
        return obj;
    }

    int Size() const {return size;}

};


int main () {


    auto *Puppy = new puppy;
    auto *Kitty = new kitty;
    auto *Penguin = new penguin;

    assert(Puppy->cuteness_rating() == 80);
    assert(Kitty->cuteness_rating() == 700);
    assert(Penguin->cuteness_rating() == 999999);


    Queue myque(5);

    myque.enqueue(Puppy);
    myque.enqueue(Kitty);
    myque.enqueue(Penguin);

    assert(myque.Size() == 3);

    assert(myque.dequeue()->cuteness_rating() == 80);
    assert(myque.dequeue()->cuteness_rating() == 700);
    assert(myque.dequeue()->cuteness_rating() == 999999);

    assert(myque.Size() == 0);

}