
#ifndef MAIN_CPP_COMPETITION_H
#define MAIN_CPP_COMPETITION_H

#include "team.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "exceptions.h"
class competition {
        std::string com_name{};


private:
    std::string country{};
    std::vector <team> teams{};
    void  adauga_echipe();
    public:
        competition();//constr init fara param
        competition(const competition& other_competition); // contructor copiere explicit
        competition(const std::string &com_name, const std::string &country);// constr init cu param
        competition &operator=(const competition& other_competition);

    //const std::string &getComName() const;

    //void  adauga_echipe(std::vector<team> t);

    friend std::ostream& operator<<(std::ostream& os, const competition& cmp);
    std::vector<team> &getTeams();
};


#endif //MAIN_CPP_COMPETITION_H
