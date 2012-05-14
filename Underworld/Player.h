#pragma once
class Player
{
	public:

		int x, y, lives, speed, score;
		bool jumping;
		float gravity, jumpVelocity;

		void init(Player &player); 
		void draw(Player &player);
		void jump(Player &player); 
		void moveDown(Player &player); 
		void moveLeft(Player &player);
		void moveRight(Player &player);
};

