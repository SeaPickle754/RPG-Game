// This line allows map editing.
#define DOEDIT

/*
Player Constants
Have to use a macro here...
for some reason,
'const float PLAYER_SPEED = 130.f;'
seems to throw a compile error.
*/
#define PLAYER_SPEED 150.f
// Whether or not the player's sword is sheathed
#define PLAYER_DEFAULT_SWORD true
#define PLAYER_SWORD_DAMAGE 2.25
//sword damage cooldown in milliseconds
#define SWORD_COOLDOWN 300
#define HEALTH_BAR_HEIGHT 10
#define HEALTH_BAR_COLOR sf::Color(255, 0, 0)
#define HEALTH_BAR_MAX_LENGTH 40
