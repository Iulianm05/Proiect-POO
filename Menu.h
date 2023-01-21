

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H
#include <iostream>
#include <string>
#include <algorithm>
#include "competition.h"
#include "match.h"
#include "offensive_coach.h"
#include "defensive_coach.h"
#include "coach.h"
#include "player.h"
#include "atribute.h"
class Menu {
private:
    Menu()=default;
    competition campionat{"Premier League","Anglia"};
    std::ifstream fin{"tastatura.txt"};
public:
    Menu(const Menu&)=delete;
    Menu& operator=(const Menu&)=delete;
    static Menu& get_Menu();
private:
    void optiuni();
    void optiune_1();
    void optiune_2();
    void abilitati_antrenori() ;
    void afisare_total_jucatori();
    void afisare_clasament();
    void afisare_meciuri(const std::vector<match> &meciuri,int contor);
    void afisare_jucatori();
    void continuare(int &tasta);
public:
    void rulare();


};


#endif //MAIN_CPP_MENU_H
