

#ifndef MAIN_CPP_ATRIBUTE_H
#define MAIN_CPP_ATRIBUTE_H
#include <string>
#include <iostream>

template<typename T>
class atribute {
    T attacking{};
    T defending{};
    T passing{};
    T Strength{};
    T dribling{};
public:
    //atribute();
    explicit atribute(T a=10, T d=10, T p=10, T s=10, T drib=10);

    T getAttacking() const;

    T getDefending() const;

    T getPassing() const;

    T getStrength() const;

    T getDribling() const;

    //friend std::ostream& operator<<(std::ostream& os, const atribute<T>& atribute1);
    ~atribute();
};


#endif //MAIN_CPP_ATRIBUTE_H
