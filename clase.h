//
// Created by Marin Iulian on 10/23/2022.
//

#ifndef OOP_CLASE_H
#define OOP_CLASE_H
#include <string>
#include <vector>

class team;

class competition{
    std::string com_name;
    std::string country;
    std::vector<team> *teams;
    int nr_teams;
public:
    competition();//constr init fara param
    competition(const competition& other_competition); // contructor copiere explicit
    competition(const std::string com_name, const std::string country, int nr_teams);// constr init cu param
    competition &operator=(const competition& other_competition);
    friend std::ostream& operator<<(std::ostream& os, const competition& cmp);
    ~competition();//destructor
};


class coach{
    std::string coach_name;
    std::string style;
    int age;
public:
    coach();
    coach(const std::string coachName, const std::string style, int age);
    //getters pentru ostream team
    friend std::ostream& operator<<(std::ostream& os, const coach& coach1);
};


class team{
    std::string name_team;
    int nr_goluri;
    int nr_players;
    //competition campionat;
    coach c;
public:
    team();
    ~team();
    team(const std::string name, int nr_goluri, int nr_players);
    std::string get_name();
    void set_name(const std::string& nume);
    friend std::ostream& operator<<(std::ostream& os, const team& team1);


};

class atribute{
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

class player{
    std::string nume_player;
    int Overall;
    std::string position;
    atribute atributes;
public:
    player();
    player(std::string nume, int ovv, std::string position, atribute atributes);
    friend std::ostream& operator<<(std::ostream& os, const player& player1);
    ~player();
};

#endif //OOP_CLASE_H
