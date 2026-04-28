#include "DoubleLinkedList.cpp"
#include "SinglyLinkedList.cpp"
#include <iostream>
#include <string>

int main()
{
    try {
        SinglyLinkedList<int> a;
        a.addFront(2);
        a.addFront(7);
        a.addFront(9);
        a.addBack(3);
        a.deleteFront();
        a.deleteBack();
        a.deleteByIndex(1);
        a.addByIndex(100, 0);
        a.getSize();
        a.isEmpty();
        a.findElement(7);
        a.printList();
        std::cout << a[4] << std::endl;
    }
    catch (const MyException& error) {
        std::cout << "Error: " << error.what() << std::endl;
    };

    std::cout<<std::endl;

    try {
        DoubleLinkedList<std::string> b;
        b.addFront("all");
        b.addFront("beat");
        b.addFront("castle");
        b.addFront("power");
        b.addBack("spring");
        b.deleteFront();
        b.deleteBack();
        b.deleteByIndex(1);
        b.addByIndex("word", 2);
        b.getSize();
        b.isEmpty();
        b.findElement("word");
        b.printList();
        std::cout << b[1] << std::endl;
    }
    catch (const MyException& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }
}
