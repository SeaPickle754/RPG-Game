
//#define NOMOTION
#include <iostream>
using namespace std;
enum class State{PAUSED,PLAYING,NO_MOTION,TITLESCREEN};

State operator!(const State&);

ostream& operator<<(ostream&, const State&);
