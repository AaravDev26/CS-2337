// Aarav Dev
// axd220001

#ifndef PLAYER_H // if player is not defined
#define PLAYER_H // define player if it is not defined
#include <string> // includes string library

class Player
{
private:
    std::string name; // variable to hold name of player
    std::string stats; // variable to hold letters representing stats of the player
    int hits; // variable to hold the number of hits for the player
    int outs; // variable to hold the number of outs for the player
    int strikeouts; // variable to hold the number of strikeouts for the player
    int walks; // variable to hold the number of walks for the player
    int hitsByPitch; // variable to hold the number of hits by pitch for the player
    int sacrifices; // variable to hold the number of sacrifices for the player
public:
    // default constructor
    Player();
    
    // accessor methods, each method returns the specified variable of the player, needed because the variables are private
    std::string getName() {return name;}
    std::string getStats() {return stats;}
    int getHits() {return hits;}
    int getOuts() {return outs;}
    int getStrikeouts() {return strikeouts;}
    int getWalks() {return walks;}
    int getHitsByPitch() {return hitsByPitch;}
    int getSacrifices() {return sacrifices;}
    
    // mutator methods, changes the specified variable of the player to the specified value, needed because the variables are private
    void setName(std::string n) {name = n;}
    void setStats(std::string s) {stats = s;}
    void setHits(int a) {hits = a;}
    void setOuts(int a) {outs = a;}
    void setStrikeouts(int a) {strikeouts = a;}
    void setWalks(int a) {walks = a;}
    void setHitsByPitch(int a) {hitsByPitch = a;}
    void setSacrifices(int a) {sacrifices = a;}
    
    // class methods
    int getAtBats() {return hits + outs + strikeouts;} // finds the number of at-bats a player has
    double getBattingAverage() {return (double)(hits) / (double)(hits + outs + strikeouts);} // finds the batting average of a player
    double getOnBasePercentage() {return (double)(hits + walks + hitsByPitch) / (double)(hits + outs + strikeouts + walks + hitsByPitch + sacrifices);} // finds the on-base percentage of a player
};
#endif // ends if statement
