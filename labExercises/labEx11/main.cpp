#include <iostream>
#include <memory>
#include <exception>

using namespace std;


struct noAccess : public exception
{
    const char* what() const throw () {
        return " does NOT have access";
    }
};

class MyClass {
public:
    void display() { cout << "Displaying MyClass!" << endl; }
};

class AnotherClass {
public:
    void display() { cout << "Displaying AnotherClass!" << endl; }
};


void showPointers(const shared_ptr<MyClass>& sharedPtr, const weak_ptr<MyClass>& weakPtr) {
    cout << endl;
    if (sharedPtr) { cout << "shared_ptr1 has access" << endl; }
    else { cout << "sharedPtr"; throw noAccess(); }

    if (auto sharedPtr2 = weakPtr.lock()) { cout << "weak_ptr has access" << endl; }
    else { cout << "weak_ptr"; throw noAccess(); }
    cout << endl;

}

int main() {
    //string hello_world = format("Hello {2:.2f} {1:d} {0} {3:x}","world",0b0101,3.141516,12648430);
    //cout << hello_world;

    //try{ throw MyException(); }
    //catch (exception& e) { cout << e.what() << endl; }

    {  // unique_ptr
        unique_ptr<MyClass> uniquePtr(new MyClass);
        uniquePtr->display();
        // uniquePtr will automatically delete the memory when it goes out of scope
    }

    {  // shared_ptr
        shared_ptr<MyClass> sharedPtr1 = make_shared<MyClass>();
        shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
        sharedPtr1->display();
        sharedPtr2->display();

        cout << endl << "sharedPtr1: | sharedPtr2:";
        showPointers(sharedPtr1, sharedPtr2);
        // Memory will be automatically deleted when the last sharedPtr goes out of scope
    }

    {  // weak_ptr
        shared_ptr<MyClass> sharedPtr1 = make_shared<MyClass>();
        weak_ptr<MyClass> weakPtr = sharedPtr1;
        sharedPtr1->display();

        // Using weak_ptr to access shared object
        /* Locking
         If lock() succeeds, it means the object is still valid,
         * and you can safely use sharedPtr2 to access the object.
         If lock() fails (returns an empty shared_ptr),
         * the object no longer exists, and you need to handle that case.
        */
        if (auto sharedPtr2 = weakPtr.lock()) {
            sharedPtr2->display();
        } else { cout << "Object no longer exists." << endl; }

        cout << endl << "sharedPtr1: | weakPtr:";
        showPointers(sharedPtr1, weakPtr);
    }

    {  // Using shared_ptr with custom deleter
        shared_ptr<AnotherClass> sharedPtr3(new AnotherClass, [](AnotherClass* ptr) {
            cout << "Custom deleter called." << endl;
            delete ptr;
        });
        sharedPtr3->display();
        // sharedPtr3 will be automatically deleted with custom deleter when it goes out of scope
    }

    return 0;
}
