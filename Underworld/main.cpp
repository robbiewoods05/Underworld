#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include "Player.h"

int main(void)
{
	const int WIDTH = 640, HEIGHT = 480, FPS = 60;
	bool keys[5] = { false, false, false, false, false }; 
	enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE }; 

    bool redraw = true, done = false; 

    Player player;

	ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL; 

    
    if (!al_init()) 
	{
        al_show_native_message_box(NULL, "Error", "Error", "Failed to initialise Allegro", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "Failed to initialise Allegro"; 
		return -1;
	}
    
	display = al_create_display(WIDTH, HEIGHT);

	if (!display) 
	{
		al_show_native_message_box(NULL, "Error", "Error", "Failed to create display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "Failed to create display";
		return -1; 
	}

	
	al_install_keyboard();
	al_init_primitives_addon();

	event_queue = al_create_event_queue(); 
	timer = al_create_timer(1.0 / FPS); 

	player.init(player);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
    
	al_start_timer(timer); 

	while (!done) 
	{ 
		ALLEGRO_EVENT ev; 
		al_wait_for_event(event_queue, &ev); 

		if (ev.type == ALLEGRO_EVENT_TIMER) 
		{
			if(keys[UP])
				player.moveUp(player);
			if(keys[DOWN])
				player.moveDown(player);
			if(keys[LEFT])
				player.moveLeft(player);
			if(keys[RIGHT])
				player.moveRight(player);
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) 
		{ 
			switch (ev.keyboard.keycode)
			{ 
				case ALLEGRO_KEY_ESCAPE: 				
					done = true;
					break; 
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break; 
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true; 
					break; 
				case ALLEGRO_KEY_UP: 
					keys[UP] = true;
					break;
				case ALLEGRO_KEY_DOWN: 
					keys[DOWN] = true;
					break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) 
			{ 
				switch (ev.keyboard.keycode) 
				{ 
					case ALLEGRO_KEY_ESCAPE: 				
						done = true;
						break; 
					case ALLEGRO_KEY_LEFT:
						keys[LEFT] = false;
						break; 
					case ALLEGRO_KEY_RIGHT:
						keys[RIGHT] = false; 
						break; 
					case ALLEGRO_KEY_UP: 
						keys[UP] = false;
						break;
					case ALLEGRO_KEY_DOWN: 
						keys[DOWN] = false;
						break; 
				}

		}
	}

	if(redraw && al_is_event_queue_empty(event_queue))
	{
		player.draw(player);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	
    
     
	al_destroy_display(display); 
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	return 0;
}

