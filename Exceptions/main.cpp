#include<iostream>
#include<cstring>
using namespace std;

class Product
{
private:
    char name[10];
    int quantity;
    float price;

public:
    Product() {}
    void init(char *n, int q, float p);
    friend ostream &operator<<(ostream &os, Product p);
};

void Product::init(char *n, int q, float p)
{
    if (strlen(n) > 9)
        throw "error: name too long\n";
    strcpy(name, n);
    if (q < 0 || q > 100)
        throw q;
    quantity = q;
    if (p < 0)
        throw p;
    price = p;
}
ostream &operator<<(ostream &os, Product p)
{
    os << p.name << '\t';
    os << p.quantity << '\t';
    os << p.price << '\n';
    return os;
}
int main()
{
    char name[100];
    float price;
    int quantity, i;
    Product store[3];
    for (i = 0; i < 3; i++)
    {
        try
        {
            cout << "enter a product number " << i << " ";
            cin >> name >> quantity >> price;
            store[i].init(name, quantity, price);
        }
        catch (char *msg)
        {
            cout << msg;
            i--;
        }
        catch (float f)
        {
            cout << "error: price cann't be negative\n";
            i--;
        }
        catch (int num)
        {
            if (num < 0)
                cout << "error: quantity must be 0 or more\n";
            else
                cout << "error: quantity avalable up to 100\n";
            i--;
        }
        catch (...)
        {
            cout << "error: unknowen error\n";
            i--;
        }
    }
    for (int i = 0; i < 3; i++)
        cout << store[i] << 5;
        operator<<(cout,store[i]).operator<<(5);
    return 0;
}
