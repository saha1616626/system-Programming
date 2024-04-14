#include <string>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include "city.h"
using namespace std;
#pragma once

class LinkedList
{
private:
    struct Node {
        City City;
        Node* next;
    };

    Node* head;

public:
    //LinkedList() : head(nullptr) {}
    //~LinkedList() {
    //    clear();
    //}
    LinkedList();
    ~LinkedList();

    void addToPosition(int position, City newCity); // добавление города в заданную позицию
    void removeByPosition(int position); // удаление города из заданной позиции
    City getByPosition(int position); // получение города по номеру позиции
    vector<int> checkFoundationDate(int date); // получение позиции города / городов по заданной дате (иначе -1)
    vector<string> getAllCityNames(); // получение всех названий городов в массиве


    //void clear() {
    //    Node* curr = head;
    //    while (curr != nullptr) {
    //        Node* next = curr->next;
    //        delete curr;
    //        curr = next;
    //    }
    //    head = nullptr;
    //}
};

