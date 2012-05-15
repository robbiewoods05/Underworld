#pragma once
#define FLOOR_LEVEL 440

class Player
{
	public:
		int x, y, lives, speed, score;
		bool jumping;
		float gravityDefault, gravity, jumpVelocity;

		Player();
		void draw();
		void update(); 
		void moveDown(); 
		void moveLeft();
		void moveRight();
};
