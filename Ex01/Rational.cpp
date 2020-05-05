#include "Rational.h"

Rational::Rational(Rational const &num) : mone(num.getMone()), mechane(num.getMechane()) {}
//Rational::Rational(Rational &&num) : mone(num.getMone()), mechane(num.getMechane()) {}

//modify functions
void Rational::setMone(int Mone) { mone = Mone; }
void Rational::setMechane(int Mechane) {
    mechane = Mechane;
}
//view functions
int Rational::getMone() const { return mone; }
int Rational::getMechane() const { return mechane; }
//operations
Rational Rational::operator+(Rational num){
    Rational tmp;
    tmp.setMone(mone * num.getMechane() + num.getMone() * mechane);
    tmp.setMechane(mechane * num.getMechane());
    return tmp;
}
Rational Rational::operator-(Rational num){
    Rational tmp;
    tmp.setMone(mone * num.getMechane() - num.getMone() * mechane);

    tmp.setMechane(mechane * num.getMechane());
    return tmp;
}
Rational Rational::operator*(Rational num){
    Rational tmp;
    tmp.setMone(mone * num.getMone());
    tmp.setMechane(mechane * num.getMechane());
    return tmp;
}
Rational Rational::operator/(Rational num){
    Rational tmp;
    tmp.setMone(mone * num.getMechane());
    tmp.setMechane(mechane * num.getMone());
    return tmp;
}
Rational &Rational::operator=(const Rational &num){
    mone = num.getMone();
    mechane = num.getMechane();
    return *this;
}
bool Rational::operator==(Rational num){
    return mone == num.getMone() &&
           mechane == num.getMechane();
}
Rational Rational::operator*(int num){
    Rational tmp;
    tmp.setMone(mone * num);
    tmp.setMechane(mechane * num);
    return tmp;
}
Rational operator*(int num, Rational rat){
    Rational tmp = rat.operator*(num);
    return tmp;
}
ostream &operator<<(ostream &os, Rational num){
    os << num.mone;
    os << '/';
    os << num.mechane;
    os << endl;
    return os;
}
istream &operator>>(istream &is, Rational &num){
    is >> num.mone;
    char slash;
    is >> slash;
    is >> num.mechane;
    return is;
}