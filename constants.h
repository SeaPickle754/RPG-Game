// This line allows map editing.
#define DOEDIT

/*
Player Constants
Have to use a macro here...
for some reason,
'const float PLAYER_SPEED = 130.f;'
seems to throw a compile error.
*/
// Player's speed
#define PLAYER_SPEED 150.f
// Whether or not the player's sword is sheathed
#define PLAYER_DEFAULT_SWORD true
// The bare sword damage
#define PLAYER_SWORD_DAMAGE 2.25
//sword damage cooldown in milliseconds
#define SWORD_COOLDOWN 300
// the height of the health bar (10 default)
#define HEALTH_BAR_HEIGHT 10
// color of the health bar (red default)
#define HEALTH_BAR_COLOR sf::Color(255, 0, 0)
// the length of the health bar when it is
// full.
#define HEALTH_BAR_MAX_LENGTH 40
// Pi.
#define PI 3.14159265

#define PLAYER_HEIGHT 20
#define PLAYER_WIDTH 20
#define PLAYER_COLLISION_OFFSET 5
