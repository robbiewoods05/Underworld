#include "Player.h"
#include <allegro5\allegro_primitives.h>

void Player::init(Player &player)
{
	player.lives = 3;
	player.speed = 5; 
	player.x = 0;
	player.y = 440;
	player.score = 0;
	player.jumping = false; 
	player.gravity = 0.2f;
	player.jumpVelocity = 2;
}
void Player::draw(Player &player)
{
	al_draw_filled_rectangle(player.x, player.y, player.x + 40, player.y + 40,  al_map_rgb(255, 0, 255));
}
void Player::jump(Player &player) 
{
	player.jumping = true; 

	if (jumping)
	{
		player.y -= player.jumpVelocity;
		player.jumpVelocity -= player.gravity; 
	}

	if(!jumping)
	{
		player.y = 440; 
		player.jumpVelocity = 2;
	}
}
void Player::moveDown(Player &player) 
{
	player.y += player.speed; 
	if (player.y > 480) 
		player.y = 480; 
}
void Player::moveLeft(Player &player)
{
	player.x -= player.speed; 
	if (player.x < 0)
		player.x = 0;
}
void Player::moveRight(Player &player)
{
	player.x += player.speed; 
	if (player.x > 640)
		player.x = 640; 

}