#include "Practical03/Practical03Exercises.hpp"

namespace exercises {
    unsigned int length(const LinkedList03 & l) {
        const LinkedList03 * current = & l;
        unsigned int result = 0;

        while (current != nullptr) {
            result = result + 1;
            current = current -> getNext();
        }
        return result;
    }

    unsigned int lengthRecursive(const LinkedList03 & l) {
        if (l.hasNext() == false) {
            return 1;
        }
        return 1 + lengthRecursive(* l.getNext());
        }


    bool hasElement(const LinkedList03 & l, int i) {
        const LinkedList03* current = &l;

        while (current != nullptr) {
            if (current->getData() == i) {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }


    bool hasElementRecursive(const LinkedList03 & l, int i) {
        if (l.getData() == i) return true;
        if (l.hasNext() == true) {
            return hasElementRecursive(* l.getNext(), i);
        }
        return false;
    }

    int lastElement(const LinkedList03 & l) {
        const LinkedList03* current = &l;
        int last = current->getData();
        while(current->getData()) {
            current = current->getNext();
            last = current->getData();
        }
        return last;
    }

    int lastElementRecursive(const LinkedList03 & l) {
        if (l.hasNext() == false)
            return l.getData();
        return lastElementRecursive(* l.getNext());
    }

    int nextToLast(const LinkedList03 & l) {
        // assume at least two nodes for simplicity
        const LinkedList03* current = &l;
        while ( current-> getNext() -> hasNext()) {
            current = current->getNext();
        }
        return current->getData();
    }

    int nextToLastRecursive(const LinkedList03 & l) {
        if (!l.getNext() -> hasNext()) {
            return l.getData();
        }
        return nextToLastRecursive(* l.getNext());
    }

    LinkedList03 clone(const LinkedList03 & l) {
        LinkedList03 cloneHead(l.getData());
        const LinkedList03 * currentOriginal = &l;
        LinkedList03 * currentCloned = &cloneHead;

        while (currentOriginal -> hasNext()) {
            currentOriginal = currentOriginal -> getNext();
            currentCloned -> append(currentOriginal -> getData());
            currentCloned = currentCloned -> getNext();
        }
        return cloneHead;
    }

}














//
// Created by jcong on 11/1/24.
//
