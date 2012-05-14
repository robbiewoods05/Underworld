#pragma once
class Player
{
	public:

		int x, y, lives, speed, score; 

		void init(Player &player); 
		void draw(Player &player);
		void moveUp(Player &player); 
		void moveDown(Player &player); 
		void moveLeft(Player &player);
		void moveRight(Player &player);
};

