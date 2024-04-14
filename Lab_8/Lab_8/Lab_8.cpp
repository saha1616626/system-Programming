#include <iostream>
#include "city.h"
#include <vector>
#include <fstream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr){}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// добавление города в заданную позицию
void LinkedList::addToPosition(int position, City newCity) {
    Node* newNode = new Node{ newCity, nullptr };

    if (position == 0 || head == nullptr) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// удаление города из заданной позиции
void LinkedList::removeByPosition(int position) {
    Node* current = head;

    if (position == 0) {
        head = head->next;
        delete current;
    }
    else {
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            string error = "Ошибка: выход за диапозон. Ведённый номер позиции: " + to_string(position) + " Метод: removeByPosition" + "\n";
            throw error;
        }
        else {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
}

// получение города по номеру позиции
City LinkedList::getByPosition(int position) {
    Node* current = head;
    for (int i = 0; i < position && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr) {
        string error = "Ошибка: выход за диапозон. Ведённый номер позиции: " + to_string(position) + " Метод: getByPosition" + "\n";
        throw error;
    }
    return current->City;
}

// получение позиции города / городов по заданной дате (иначе -1)
vector<int> LinkedList::checkFoundationDate(int date) {
    vector<int> position;
    Node* current = head;
    int index = 0;

    while (current != nullptr) {
        if (current->City.dateFoundation == date) {
            position.push_back(index);
        }
        current = current->next;
        index;
    }

    if (position.empty()) {
        position.push_back(-1);
    }

    return position;
}

// получение всех названий городов в массиве
vector<string> LinkedList::getAllCityNames() {
    vector<string> cityNames;
    Node* current = head;

    while (current != nullptr) {
        cityNames.push_back(current->City.cityName);
        current = current->next;
    }
    return cityNames;
}


int main()
{
    // путь к файлу
    string addresFile = "E:\\3comm\\Documents\\Предметы\\Курс 3.2\\Системное программирование\\Лаба 8\\Lab_8\\Log.txt";

    // стирать логи при каждом заходе
    ofstream file(addresFile, ios::out);


    setlocale(LC_ALL, "Ru"); // русская локализация

    LinkedList linkList;
    City cities;

    int position = 0; // позиция
    int date = 0; // дата
    int number = 0; // номер программы
    bool flag = true; // цикл работы программы

    while (flag != false) {

        cout << "\n1. Добавить город в заданную позицию" << endl;
        cout << "2. Удаление города по номеру позиции" << endl;
        cout << "3. Получение города по номеру позиции" << endl;
        cout << "4. Проверка наличия города с указанной датой" << endl;
        cout << "5. Получение названий всех городов в виде массива" << endl;

        cout << "6. Выход из программы" << endl;
        cout << "\nВведите номер: ";
        cin >> number;

        // добавление городов в список
        switch (number)
        {
        case 1:
            cout << "\nВведите номер позиции для добавления: ";
            cin >> position;
            cout << "Название города: ";
            cin >> cities.cityName;
            cout << "Дата основания города: ";
            cin >> cities.dateFoundation;
            cout << "Кол-во жителей: ";
            cin >> cities.numberInhabitants;
            cout << "Площадь города: ";
            cin >> cities.square;
            cout << endl;

            linkList.addToPosition(position, cities);
            break;

        case 2:
            cout << "\nВведите номер позиции города для удаления: ";
            cin >> position;
            try {
                linkList.removeByPosition(position);
            }
            catch (string error_message) {
                ofstream file;
                file.open(addresFile, ios::app | ios::ate); // дозапись + указатель в конец
                file << error_message;

                cin.clear(); // очистка ошибки ввода
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // пропуск некорректного ввода данных
            }
            break;

        case 3: {
            cout << "\nВведите номер позиции города для получения города: ";
            cin >> position;
            try {
                City city = linkList.getByPosition(position);
                cout << "\nНазвание города: " << city.cityName << endl;
                cout << "Дата основания: " << city.dateFoundation << endl;
                cout << "Кол-во жителей: " << city.numberInhabitants << endl;
                cout << "Площадь города: " << city.square << endl;
            }
            catch (string error_message) {
                ofstream file;
                file.open(addresFile, ios::app | ios::ate); // дозапись + указатель в конец
                file << error_message;

                cin.clear(); // очистка ошибки ввода
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // пропуск некорректного ввода данных
            }
            break;
        }

        case 4: {
            cout << "\nВведите дату основания города для получения позиции: ";
            cin >> date;
            vector<int> position;
            position = linkList.checkFoundationDate(date);
            for (size_t i = 0; position.size(); i++) {
                try {
                    City city = linkList.getByPosition(i);
                    cout << "Позиция: " << i << " Город: " << city.cityName << endl;
                }
                catch (string error_message) {
                    break;
                }
            }
            break;
        }

        case 5: {
            vector<string> cityNames = linkList.getAllCityNames();
            cout << "Все города: \n";
            for (const string& cityName : cityNames)
            {
                cout << cityName << endl;
            }
            //вывод всех городовы
            break;
        }

        case 6:
            flag = false;
            break;

        default:
            break;

            return 0;
        }
    }
}