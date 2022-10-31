//
// Created by Marin Iulian on 10/26/2022.
//

#ifndef MAIN_CPP_COMPETITION_H
#define MAIN_CPP_COMPETITION_H

#include "team.h"
#include <string>
#include <vector>
#include <iostream>
class competition {
        std::string com_name;
        std::string country;
        team *teams=new team[20];
        int nr_teams;
    public:
        competition();//constr init fara param
        competition(const competition& other_competition); // contructor copiere explicit
        competition(const std::string com_name, const std::string country, int nr_teams);// constr init cu param
        competition &operator=(const competition& other_competition);
        //void set_nume(const std::string nume_);
        team* get_teams();
        void  adauga_echipe();
        friend std::ostream& operator<<(std::ostream& os, const competition& cmp);
        ~competition();//destructor
};


#endif //MAIN_CPP_COMPETITION_H
