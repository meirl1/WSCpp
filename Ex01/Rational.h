#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream> //iostream includes ostream and istream,
                    //in order to use operator<< or >> we have to include iostream here (h file)
using namespace std;
class Rational
{
private:
    int mone;
    int mechane;

public:
    //constructor
    Rational(int Mone = 1, int Mechane = 1) : mone(Mone), mechane(Mechane) {}
    Rational(Rational const &num);
    //Rational(Rational &&num);
    //modify functions
    void setMone(int Mone);
    void setMechane(int Mechane);
    //view functions
    int getMone() const;
    int getMechane() const;
    //operations
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
    Rational &operator=(const Rational &);
    bool operator==(Rational);
    //הפונקציות להלן הינן פונקציות חברות
    //לא שייכות למחלקה
    Rational operator*(int);
    friend Rational operator*(int, Rational);
    friend int multi(Rational,Rational);
    //input/output
    friend ostream &operator<<(ostream &os, Rational num);
    friend istream &operator>>(istream &is, Rational &num);
};
#endif