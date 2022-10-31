//
// Created by Marin Iulian on 10/26/2022.
//

#ifndef MAIN_CPP_ATRIBUTE_H
#define MAIN_CPP_ATRIBUTE_H
#include <string>
#include <iostream>


class atribute {
    int attacking;
    int defending;
    int passing;
    int strenght, dribling;
public:
    atribute();
    atribute(int a, int d, int p, int s, int drib);
    //trebuie getters pentru ostream la player
    friend std::ostream& operator<<(std::ostream& os, const atribute& atribute1);
    ~atribute();
};


#endif //MAIN_CPP_ATRIBUTE_H
