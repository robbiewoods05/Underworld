#include "Player.h"
#include <allegro5/allegro_primitives.h>

Player::Player()
{
	lives = 3;
	speed = 5; 
	x = 0;
	y = 440;
	score = 0;
	jumping = false;
	gravityDefault = 5.0f; /* Raise this for higher jumps */
	gravity = gravityDefault;
	jumpVelocity = 0.2f;
}
void Player::draw()
{
	al_draw_filled_rectangle(x, y, x + 40, y + 40,  al_map_rgb(255, 0, 255));
}
void Player::update() 
{

	if (jumping) {
		gravity -= jumpVelocity;
		y -= gravity;

		if(y > FLOOR_LEVEL) {
			y = FLOOR_LEVEL;
			gravity = gravityDefault;
			jumping = false;
		}
	}
}
void Player::moveDown() 
{
	y += speed; 
	if (y > 480) 
		y = 480; 
}
void Player::moveLeft()
{
	x -= speed; 
	if (x < 0)
		x = 0;
}
void Player::moveRight()
{
	x += speed; 
	if (x > 640)
		x = 640; 

}
