#include "main.h"
#include "Player.h"

Player::Player()
{
	lives = 3;
	speed = 5; 
	x = 0;
	y = (HEIGHT - 40);
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

		if(y > (HEIGHT- 40)) {
			y = (HEIGHT - 40);
			gravity = gravityDefault;
			jumping = false;
		}
	}
}
void Player::moveDown()
{
	y = (HEIGHT - 40);

}
void Player::moveLeft()
{
	if (x > 0)
		x -= speed;
	else
		x = 0;
}
void Player::moveRight()
{
	if (x < (WIDTH - 40))
		x += speed;
	else
		x = (WIDTH - 40);
}
