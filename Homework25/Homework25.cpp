#include <iostream>
#include <string>
#include <locale>
using namespace std;

// Создание структуры.
struct date {
    int day;
    int month;
    int year;
};
struct movies {
    string title;
    date premiere;
    string ganre;
    unsigned int duration;
    unsigned int price;
};

// Задача 1. Вывод информации о фильме.
void showMovie(movies& M) {
    cout << "Название фильма: " << M.title << 
        ".\nДата премьеры: "  << M.premiere.day << "." << M.premiere.month << "." << M.premiere.year << 
        ".\nЖанр: "  << M.ganre << ".\nПродолжиьельность фильма: " << M.duration << " мин.\nЦена за диск: " << M.price << ".\n\n";
}

// Задача 2. Cамый дорогой фильм.
movies expensive(movies& M1, movies& M2, movies& M3) {
    if (M1.price > M2.price && M1.price > M3.price)
        return M1;
    if (M1.price < M2.price && M2.price > M3.price)
        return M2;
    return M3;
}

// Задача 3. Изменение информации о фильме.
void updateInfo(movies& M) {
    setlocale(LC_ALL, "ru");
    int n;
    cin >> n;
    cin.ignore();
    switch (n) {
    case 1: cout << "Введите новое название: "; getline(cin, M.title); break;
    case 2: cout << "Введите новую дату (через пробел): "; cin >> M.premiere.day >> M.premiere.month >> M.premiere.year; break;
    case 3: cout << "Введите новый жанр: "; cin.ignore(); getline(cin, M.ganre); break;
    case 4: cout << "Введите новую продолжительность: "; cin >> M.duration;  break;
    case 5: cout << "Введите новую цену: "; cin >> M.price; break;
    default: cout << "В меню нет такого пункта! Информация не изменилась!\n"; break;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;


    // Заполнение структуры.
    movies film1 = { "Зелёный слоник", {12, 10, 1999}, "ужасы, триллер", 86, 400 };
    movies film2 = { "Нападение помидоров-убийц", {30, 5, 1972}, "ужасы", 83, 389 };
    movies film3 = { "Комната", {21, 02, 2003},"драма, мелодрама", 99, 1000001 };

    //Задача 1.
    cout << "\tЗадача 1.\nФИЛМЫ В НАЛИЧИИ!!!:\n";
    showMovie(film1);
    showMovie(film2);
    showMovie(film3);

    //Задача 2.
    cout << "\tЗадача 2.\nСамый дорогой фильм:\n";
    movies exF = expensive(film1, film2, film3);
    showMovie(exF);

    // Задача 3.
    cout << "\tЗадача 3.\nИныормацию о каком фильме нужно обновить:\n1. Зелёный слоник.\n2. Нападение помидоров-убийц.\n3. Комната.\n";
    cout << endl << "Ввод -> ";
    cin >> n;
    cin.ignore();
    switch (n) {
    case 1: cout << "Какую информацию о фильме следует изменить:\n1. Название фильма.\n2. Дата премьеры.\n3. Жанр.\n4. Продолжительность фильма.\n5. Цена за диск.\n";
        cout << endl << "Ввод -> ";
        updateInfo(film1);
        cout << endl << "Обновлённая информация:\n";
        showMovie(film1); break;
    case 2: cout << "Какую информацию о фильме следует изменить:\n1. Название фильма.\n2. Дата премьеры.\n3. Жанр.\n4. Продолжительность фильма.\n5. Цена за диск.\n";
        cout << endl << "Ввод -> ";
        updateInfo(film2);
        cout << endl << "Обновлённая информация:\n";
        showMovie(film2); break;
    case 3: cout << "Какую информацию о фильме следует изменить:\n1. Название фильма.\n2. Дата премьеры.\n3. Жанр.\n4. Продолжительность фильма.\n5. Цена за диск.\n";
        cout << endl << "Ввод -> ";
        updateInfo(film3);
        cout << endl << "Обновлённая информация:\n";
        showMovie(film3); break;
    default: cout << "Такого фильма нет в списке!\n"; break;
    }
    return 0;
}