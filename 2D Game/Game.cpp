#include "Game.h"


// Constructor
Game::Game()
    :x_coord(0), y_coord(0), screen_height(0), screen_width(0), game_over(false), jump_counter(0)
{
	// Loading map from file
	ifstream map("Map.txt");
	if (map.is_open())
	{
		while (map.get(read_from_file))
		{
            if (read_from_file == 'X')
            {
                invisible_barriers.push_back(new InvisibleBarriers(x_coord, y_coord, 1));
            }
            if (read_from_file == 'Y')
            {
                invisible_barriers.push_back(new InvisibleBarriers(x_coord, y_coord, 0));
            }
            if (read_from_file == 'W')
            {
                stones.push_back(new Stone(x_coord, y_coord));
            }
            if (read_from_file == 'P')
            {
                player = new Player(x_coord, y_coord);
            }
            if (read_from_file == '\n')
            {
                y_coord++;
                x_coord = 0;
            }
            else
            {
                x_coord++;
            }
            screen_width = max(screen_width, x_coord);
            screen_height = max(screen_height, y_coord + 1);
        }
        map.close();
	}
}


// Handling pointer destuctions through destructor
Game::~Game()
{
    delete player;
    for (auto it : invisible_barriers)
    {
        delete it;
    }
    for (auto it : stones)
    {
        delete it;
    }
}


// Show to screen
void Game::Show()
{
    system("cls");
    for (unsigned int y = 0; y < screen_height; y++)
    {
        for (unsigned int x = 0; x < screen_width; x++)
        {
            is_index_printed = false;
            // Checking for player
            if (player->Get_x_player() == x && player->Get_y_player() == y)
            {
                cout << "P";
                is_index_printed = true;
                continue;
            }
            // Checking for invisible barriers
            for (int i = 0; i < invisible_barriers.size(); i++)
            {
                if (!is_index_printed && invisible_barriers[i]->Get_x_inv_barrier() == x && invisible_barriers[i]->Get_y_inv_barrier() == y)
                {
                    if (invisible_barriers[i]->Get_type())
                    {
                        cout << "O";
                    }
                    else
                    {
                        cout << " ";
                    }
                    is_index_printed = true;
                    break;
                }
            }
            // Checking for stones
            for (int i = 0; i < stones.size(); i++)
            {
                if (!is_index_printed && (stones[i]->Get_x_stone() == x && stones[i]->Get_y_stone() == y))
                {
                    cout << "O";
                    is_index_printed = true;
                    break;
                }
            }
            // Printing ' ' if nothing else was printed before
            if (!is_index_printed)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}


// Game logic
void Game::Logic()
{
    left_move = true, right_move = true, gravity = true, up = true;
    // Stop movement (Invisible barriers)
    for (int i = 0; i < invisible_barriers.size(); i++)
    {
        if (invisible_barriers[i]->Get_x_inv_barrier() + 1 == player->Get_x_player() && invisible_barriers[i]->Get_y_inv_barrier() == player->Get_y_player())
        {
            left_move = false;
        }
        if (invisible_barriers[i]->Get_x_inv_barrier() - 1 == player->Get_x_player() && invisible_barriers[i]->Get_y_inv_barrier() == player->Get_y_player())
        {
            right_move = false;
        }
    }
    // Stop movement (Stones)
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i]->Get_x_stone() + 1 == player->Get_x_player() && stones[i]->Get_y_stone() == player->Get_y_player())
        {
            left_move = false;
        }
        if (stones[i]->Get_x_stone() - 1 == player->Get_x_player() && stones[i]->Get_y_stone() == player->Get_y_player())
        {
            right_move = false;
        }
        if (stones[i]->Get_x_stone() == player->Get_x_player() && stones[i]->Get_y_stone() + 1 == player->Get_y_player())
        {
            up = false;
        }
    }
    // Gravity
    for (int i = 0; i < stones.size(); i++)
    {  
        if (stones[i]->Get_x_stone() == player->Get_x_player() && stones[i]->Get_y_stone() - 1 == player->Get_y_player())
        {
            gravity = false;
        }
    }
    for (int i = 0; i < invisible_barriers.size(); i++)
    {
        if (invisible_barriers[i]->Get_x_inv_barrier() == player->Get_x_player() && invisible_barriers[i]->Get_y_inv_barrier() - 1 == player->Get_y_player())
        {
            gravity = false;
        }
    }
    if (gravity && !player->Get_jump())
    {
        player->Increment_y_player();
    }
    // Jump
    if (player->Get_jump())
    {
        jump_counter = 3;
        player->Modify_jump(false);
    }
    if (jump_counter > 0 && up)
    {
        jump_counter--;
        player->Decrement_y_player();
    }
}


// Infinite loop 
void Game::Run()
{
    while (!game_over)
    {
        Sleep(1000/60);
        Logic();
        Show();
        player->Move(right_move, left_move, gravity);
    }
}