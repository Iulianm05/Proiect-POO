#include <iostream>
#include <string>

class competition{
    std::string com_name;
    std::string country;
    int nr_teams;
};

class coach{
    std::string coach_name;
    std::string style;

};

class team{
    std::string name_team;
    int nr_goluri;
    int nr_players;
    coach c;

};

class atribute{
    int attacking;
    int defending;
    int passing;
    int strenght, dribling;
    atribute(int a, int d, int p, int s, int drib){
        attacking=a;
        defending=d;
        passing=p;
        strenght=s;
        dribling=drib;
        std::cout<<"constructor atribute\n";
    }
};

class player: public atribute{
    std::string nume_player;
    int Overall;
    std::string position;
public:
    player(std::string nume, int ovv, std::string position){
        this->nume_player=nume;
        this->Overall=ovv;
        this->position=position;
        std::cout<<"contructor cu parametrii player\n";
    }
};

int main() {
    player p1("Lionel Messi",92, "Left Winger");

    return 0;
}
