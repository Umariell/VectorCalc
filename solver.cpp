#include "solver.h"
#include <cmath>
#include <QStringList>

Vector::Vector(double arr[3])
{
    length = 3;
    this->arr[0] = arr[0];
    this->arr[1] = arr[1];
    this->arr[2] = arr[2];
}

Vector::Vector()
{
    length = 3;
}

/**
 * Умножение с другим вектором
 */
Vector Vector::mul(const Vector &other)
{
    Vector res;
    res.set(0, get(1)*other.get(2) - get(2)*other.get(1));
    res.set(1, get(2)*other.get(0) - get(0)*other.get(2));
    res.set(2, get(0)*other.get(1) - get(1)*other.get(0));
    return res;
}

/**
 * Умножение на число
 */
Vector Vector::mul(const double other)
{
    Vector res;
    for (int i = 0; i < length; i++) {
        res.set(i, get(i) * other);
    }
    return res;
}


/**
 * Сложение с другим вектором
 */
Vector Vector::add(const Vector &other)
{
    Vector res;
    for (int i = 0; i < length; i++) {
        res.set(i, get(i) + other.get(i));
    }
    return res;
}

/**
 * Вычитание другого вектора
 */
Vector Vector::sub(const Vector &other)
{
    Vector res;
    for (int i = 0; i < length; i++) {
        res.set(i, get(i) - other.get(i));
    }
    return res;
}

/**
 * Нахождение модуля вектора
 */
double Vector::abs() const
{
    return sqrt(get(0)*get(0) + get(1)*get(1) + get(2)*get(2));
}

/**
 * Скалярное произведение
 */
double Vector::mul_skalyar(const Vector &other)
{
    return get(0)*other.get(0) + get(1)*other.get(1) + get(2)*other.get(2);
}

/**
 * Угол между векторами
 */
double Vector::angle(const Vector &other)
{
    return acos( mul_skalyar(other) / (abs() * other.abs()));
}

/**
 * Смешанное произведение векторов
 */
double Vector::smesh(const Vector &other1, const Vector &other2)
{
    double a11 = get(0), a12 = other1.get(0), a13 = other2.get(0);
    double a21 = get(1), a22 = other1.get(1), a23 = other2.get(1);
    double a31 = get(2), a32 = other1.get(2), a33 = other2.get(2);
    return a11 * a22 * a33 + a12 * a23 * a31 + a21 * a32 * a13 - a31 * a22 * a13 - a12 * a21 * a33 - a11 * a23 * a32;
}

/**
 * Вывод значения вектора как строки
 */
QString Vector::as_string()
{
    QStringList resultList;

    for (int i = 0; i < length; i++) {
        resultList.append(QString::number(get(i)));
    }

    return "(" + resultList.join("\t") + ")";
}

double Vector::get(int index) const
{
    return arr[index];
}

void Vector::set(int index, double value)
{
    arr[index] = value;
}
