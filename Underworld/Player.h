#pragma once
class Player
{
	public:

		int x, y, lives, speed, score;
		bool jumping;
		float gravity, jumpVelocity;

		Player();
		void draw();
		void update(); 
		void moveDown(); 
		void moveLeft();
		void moveRight();
};
