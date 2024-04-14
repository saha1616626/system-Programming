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

    void addToPosition(int position, City newCity); // ���������� ������ � �������� �������
    void removeByPosition(int position); // �������� ������ �� �������� �������
    City getByPosition(int position); // ��������� ������ �� ������ �������
    vector<int> checkFoundationDate(int date); // ��������� ������� ������ / ������� �� �������� ���� (����� -1)
    vector<string> getAllCityNames(); // ��������� ���� �������� ������� � �������


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

