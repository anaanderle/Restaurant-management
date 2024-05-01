#include <iostream>
#include <vector>
#include "Date.hpp"

using namespace std;

Date::Date(int day, int month, int year){
    if(validDate(day, month, year)){
        this->day = day;
        this->month = month;
        this->year = year;
        return;
    }
    else {
        cout << "ERRO : Data inválida" << endl;
    }
}

Date::Date(){
    this->day = 1;
    this->month = 1;
    this->year = 2000;
}

int Date::getDay(){
    return this->day;
}

int Date::getMonth(){
    return this->month;
}

int Date::getYear(){
    return this->year;
}

bool Date::setDate(int day, int month, int year) {
    if(this->validDate(day, month, year)){
        this->day = day;
        this->month = month;
        this->year = year;
        return true;
    }

    cout << "Data inválida" << endl;

    return false;
}

void Date::print() {
    cout << this->day << "/" << this->month << "/" << this->year << endl;
}

bool Date::validDate(int day, int month, int year) {
    vector<int> monthsWithThirtyDays = {4, 6, 9, 11};
    vector<int> monthsWithThirtyOneDays = {1, 3, 5, 7, 8, 10, 12};

    if(month == 2){
        if(year % 4 == 0){
            return day <= 29;
        }

        return day <= 28;
    }

    for (int currentMonth : monthsWithThirtyDays) {
        if (currentMonth == month) {
            return day <= 30;
        }
    }

    for (int currentMonth : monthsWithThirtyOneDays) {
        if (currentMonth == month) {
            return day <= 31;
        }
    }

    return false;
}

bool Date::operator!=(Date* other) const {
    return day != other->day || month != other->month || year != other->year;
}
