/* 
 * File:   main.cpp
 * Author: theskidster
 *
 * Created on March 8, 2023, 7:05 PM
 */

#include <string>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    std::string data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {

private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void insert(const std::string& str) {
        Node* node = new Node;
        node->data = str;
        node->prev = tail;
        node->next = nullptr;
        
        if(tail != nullptr) {
            tail->next = node;
        } else {
            head = node;
        }
        
        tail = node;
        
        printf("Added new element: "<<str);
    }
    
    Node* find(const std::string& str) {
        Node* curr = head;
        
        while(curr != nullptr) {
            if(curr->data == str) {
                printf("Found element: "<<str);
                return curr;
            }
            
            curr = curr->next;
        }
        
        return nullptr;
    }
    
    void remove(const std::string& str) {
        Node* node = find(str);
        
        if(node == nullptr) {
            return;
        }
        
        if(node == head) {
            head = node->next;
        } else {
            node->prev->next = node->next;
        }
        
        if(node == tail) {
            tail = node->prev;
        } else {
            node->next->prev = node->prev;
        }
        
        printf("Removed element: "<<str);
        delete node;
    }
    
};

int main(int argc, char** argv) {

    const char* el1 = "element1";
    const char* el2 = "element2";
    const char* el3 = "element3";
    
    DoublyLinkedList* dll = new DoublyLinkedList;
    
    dll->insert(el1);
    dll->insert(el2);
    dll->insert(el3);
    
    //...I don't know C++... :(
    
    return 0;
}