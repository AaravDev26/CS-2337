// Aarav Dev
// axd220001

#include "Player.h" // includes player class
#include <string> // used for toString method
#include <cmath> // used to round numbers

// default constructor, sets all integer variables to zero
Player::Player()
{
    hits = 0;
    outs = 0;
    strikeouts = 0;
    walks = 0;
    hitsByPitch = 0;
    sacrifices = 0;
    errors = 0;
}

double Player::getBattingAverage() // finds the batting average of a player
{
    // if denominator is zero, return zero to avoid dividing by zero error
    if (getAtBats() == 0)
    {
        return 0.0;
    }
    else // return hits divided by at-bats
    {
        return (double)(hits) / (double)(hits + outs + strikeouts + errors);
    }
}

double Player::getOnBasePercentage() // finds the on-base percentage of a player
{
    // if denominator is zero, return zero to avoid dividing by zero error
    if (hits + outs + strikeouts + walks + hitsByPitch + sacrifices + errors == 0)
    {
        return 0.0;
    }
    else // return appropriate result
    {
        return (double)(hits + walks + hitsByPitch) / (double)(hits + outs + strikeouts + walks + hitsByPitch + sacrifices + errors);
    }
}

// converts player to string representation
std::string Player::toString()
{
    std::string a = name + "\t";
    std::string b = std::to_string(getAtBats()) + "\t"; // number of at-bats and a tab
    std::string c = std::to_string(hits) + "\t"; // number of hits and a a tab
    std::string d = std::to_string(walks) + "\t"; // number of walks and a tab
    std::string e = std::to_string(strikeouts) + "\t"; // number of strikeouts and a tab
    std::string f = std::to_string(hitsByPitch) + "\t"; // number of hits by pitch and a tab
    std::string g = std::to_string(sacrifices) + "\t"; // number of sacrifices and a tab
    std::string h = std::to_string((round(getBattingAverage()*1000))/1000).substr(0, 5) + "\t"; // batting average and a tab
    std::string i = std::to_string((round(getOnBasePercentage()*1000))/1000).substr(0,5) + "\n"; // on-base percentage
    return a + b + c + d + e + f + g + h + i; // add all strings and return it
}
