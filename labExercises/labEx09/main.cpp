#include <iostream>
#include <string>

using namespace std;

// 1
template <typename T>
class TempClass {
    T value;
public:
    // Constructor with member initializer list
    TempClass(T item) : value(item) {}

    T getValue() const { // Added const to indicate this function doesn't modify the object
        return value;
    }

    // Destructor to clean up any resources (not necessary in this case)
    ~TempClass() = default;
};

// 2
template <typename T>
class stream {
public:
    void f() { cout << "stream<T>::f()" << endl; }

    ~stream() = default;
};

template <>
class stream<char> {
public:
    void f() { cout << "stream<char>::f()" << endl; }

    ~stream() = default;
};

// 3
template<class T, class Enable = void>
class A { ~A() = default; };

template<class T>
class A<T, typename enable_if<is_floating_point_v<T>>::type> {
public:
    void f() { cout << "type enabled." << endl ; }

    ~A() = default;
};


int main() {

    /* 1. Typical class template
    // Initialise the template with an explicit integer ptr
    class TempClass<int>* integer2 = new TempClass<int>(9);

    // Alternatively use auto to simplify type declarations
    auto* String = new TempClass<string>("Template example");
    auto* integer = new TempClass<int>(12);


    cout << "Output: " << String->getValue() << "\n";
    cout << "Output: " << integer->getValue() << "\n";
    cout << "Output: " << integer2->getValue() << "\n";

    // Free memory
    delete String;
    delete integer;
    delete integer2;
    */

    /* 2. Generic and Specialised + calling templates
    Generic Template Class (stream<T>):
    This is a generic class template that can handle any type T.
    It has a member function f() which tries to print the result of calling stream<T>::f().

    Specialized Class for char (stream<char>):
    This is a specialization of the generic template for the specific type char.
    It provides its own implementation of the member function f().

    The classes must have the same name (`stream`) because they are related in terms of the template specialization.
    When you specialize a class template, you're essentially providing a specific version of that template for a particular type.
    The name remains the same to indicate that it's a specialization of the original template.

    In the context of template specialization, it's the template parameter (`<char>`) that distinguishes the specialized version from the generic one.
    This allows you to have a different implementation for a specific type while still maintaining a relationship with the original generic template.

    stream<int> intStream;
    stream<char> charStream;

    // creates a pointer to the stream<int>*
    auto* openType1 =  new stream<int>;
    // auto infers the type to be stream<int>*, so openType2 is also a pointer.
    auto openType2 = new stream<int>;

    intStream.f();
    charStream.f();
    openType1->f();
    openType2->f();

    delete openType1;
    delete openType2;
    */

    /* 3. Type enabling
    //A<int>{};       // error: class A<int> is incomplete.
    //A<double>{};    // OK: matches the partial specialization
    auto* result =  new A<double>;
    result->f();
    delete result;
    */


    return 0;
}
