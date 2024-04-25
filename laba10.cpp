// laba10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include <iostream>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(const std::string& message) = 0;
};

class MobTower : public Subject {
private:
    vector<Observer*> observers;

public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notify(const string& message) override {
        for (auto observer : observers) {
            observer->update(message);
        }
    }

    void transmitMessage(const string& message) {
        cout << "Вышка передает сообщение: " << message << endl;
        notify(message);
    }
};

class Smartphone : public Observer {
private:
    string model;

public:
    Smartphone(const string& num) : model(num) {}

    void update(const string& message) override {
        cout << "Смартфон " << model << " получил сообщение: " << message << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    cout << "Выполнил ст. гр. ИПсп-121: Аверкин С.М." << endl;

    cout << " " << endl;

    MobTower tower;

    // Создаем смартфоны с номерами
    Smartphone phone1("Iphone 12");
    Smartphone phone2("Xiaomi Redmi 7");
    Smartphone phone3("Samsung Galaxy SE");

    tower.attach(&phone1);
    tower.attach(&phone2);
    tower.attach(&phone3);
    cout << "" << endl;
    cout << endl;

    tower.transmitMessage("Привет, мир!");
    cout << "" << endl;
    cout << endl;
    tower.detach(&phone2);
    cout << "" << endl;
    cout << endl;
    tower.transmitMessage("Как дела?");

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
