#include "States.h"
// Over load the ! (not) operator to cycle through the game states
State operator!(const State& b){
    #ifdef NOMOTION
    if(b == State::PAUSED)
        return State::PLAYING;
    if(b == State::PLAYING)
        return State::NO_MOTION;
    if(b == State::NO_MOTION)
        return State::PAUSED;
    #else
    if(b == State::PAUSED)
        return State::PLAYING;
    if(b == State::PLAYING)
        return State::PAUSED;
    #endif
}

ostream& operator<<(ostream& os, const State& s){
    if(s == State::PAUSED)
        os << "paused";
    else if(s == State::PLAYING)
        os << "playing";
    else if(s == State::NO_MOTION)
        os << "no motion";
    else if(s == State::TITLESCREEN)
        os << "titlescreen";
}

