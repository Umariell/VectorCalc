#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include <QString>


using namespace std;


class Vector
{
private:
    double arr[3] = {0.0, 0.0, 0.0};
    int length = 3;

public:
    Vector();
    Vector(double arr[3]);

    Vector sub(const Vector &other);
    Vector add(const Vector &other);
    Vector mul(const Vector &other);
    Vector mul(const double other);
    double abs() const;
    double mul_skalyar(const Vector &other);
    double angle(const Vector &other);
    double smesh(const Vector &other1, const Vector &other2);

    void print();
    QString as_string();

    Vector operator-(const Vector &other) { return sub(other); }
    Vector operator+(const Vector &other) { return add(other); }
    Vector operator*(const Vector &other) { return mul(other); }
    Vector operator*(const double other)  { return mul(other); }

    double get(int index) const;
    void set(int index, double value);
};

