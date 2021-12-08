#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money
{
    long all_cents;//monetary value stored as pennies

public:

    //initializes the object to dollars *100 cents
    Money(long dollars, int cents = 0) :
        all_cents(dollars * 100 + cents) {}

    //Initializes the object to $0.00
    Money(void) : all_cents(0) {}

    //overloaded operators
    Money operator+(const Money& amount) const
    {
        Money temp(*this);
        temp.all_cents += amount.all_cents;
        return temp;
    }

    Money operator-(const Money& amount) const
    {
        Money temp(*this);
        temp.all_cents -= temp.all_cents;
        return temp;
    }

    Money operator-(void) const
    {
        Money temp(*this);
        temp.all_cents = -temp.all_cents;
        return temp;
    }

    Money operator-=(const Money& amount)
    {
        this->all_cents -= amount.all_cents;
        return *this;
    }

    Money& operator+=(const Money& amount)
    {
        this->all_cents += amount.all_cents;
        return *this;
    }

    //bool operators
    bool operator==(const Money& amount) const
    {
        return all_cents == amount.all_cents;
    }
    bool operator>=(const Money& amount) const
    {
        return all_cents >= amount.all_cents;
    }
    bool operator>(const Money& amount) const
    {
        return all_cents > amount.all_cents;
    }
    bool operator<(const Money& amount) const
    {
        return all_cents < amount.all_cents;
    }
    bool operator<=(const Money& amount) const
    {
        return all_cents <= amount.all_cents;
    }
    bool operator==(const Money& amount)
    {
        return all_cents == amount.all_cents;
    }
    bool operator!=(const Money& amount)
    {
        return all_cents != amount.all_cents;
    }

    //input and output function
    void input(std::istream& ins = std::cin);
    void output(std::ostream& outs = std::cout) const;

    friend std::istream& operator >>(std::istream& ins, Money& amount)
    {
        amount.input(ins);
        return ins;
    }
    friend std::ostream& operator<<(std::ostream& outs, const Money& amount)
    {
        amount.output(outs);
        return outs;
    }

    //getter
    double get_value(void) const
    {
        return all_cents/100.00;
    }

};

#endif
