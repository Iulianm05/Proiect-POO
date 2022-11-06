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
        std::vector <team> teams;
        int nr_teams;
    public:
        competition();//constr init fara param
        competition(const competition& other_competition); // contructor copiere explicit
        competition(const std::string &com_name, const std::string &country, int nr_teams);// constr init cu param
        competition &operator=(const competition& other_competition);


    void  adauga_echipe(std::vector<team> t);
        friend std::ostream& operator<<(std::ostream& os, const competition& cmp);
};


#endif //MAIN_CPP_COMPETITION_H
