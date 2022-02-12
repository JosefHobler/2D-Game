#include "Game.h"


// Constructor
Game::Game()
    :x_coord(0), y_coord(0),first_entry(true), game_over(false), jump_counter(0)
{
	// Loading map from file
	ifstream map("Map.txt");
	if (map.is_open())
	{
		while (map.get(read_from_file))
		{
            if (read_from_file == '\n')
            {
                map_storage.push_back(map_storage_helper);
                map_storage_helper.clear();
                continue;
            }
            map_storage_helper.push_back(read_from_file);
        }
        map.close();
        map_storage.push_back(map_storage_helper);
	}
    screen_height = map_storage.size();
    screen_width = map_storage[0].size();
    min_left_side = 0;
    max_right_side = 25;
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
    for (auto it : trees)
    {
        delete it;
    }
    for (auto it : leaves)
    {
        delete it;
    }
}


// Moving terrain as player moves
void Game::MoveTerrain()
{    
    if (!first_entry)
    {
        min_left_side = (player->Get_x_player() - 25 > 0) ? player->Get_x_player() - 25 : 0;
        max_right_side = (player->Get_x_player() + 25 < map_storage[0].size()) ? player->Get_x_player() + 25 : map_storage[0].size() - 1;
    }
    for (unsigned int y = 0; y < screen_height; y++)
    {
        for (int x = min_left_side; x < max_right_side; x++)
        {
            if (map_storage[y][x] == 'W')
            {
                stones.push_back(new Stone(x, y));
            }
            else if (map_storage[y][x] == 'Y')
            {
                invisible_barriers.push_back(new InvisibleBarriers(x, y, 0));
            }
            else if (map_storage[y][x] == 'X')
            {
                invisible_barriers.push_back(new InvisibleBarriers(x, y, 1));
            }
            else if (map_storage[y][x] == 'Z')
            {
                invisible_barriers.push_back(new InvisibleBarriers(x, y, 2));
            }
            else if (map_storage[y][x] == 'P')
            {
                if (first_entry)
                {
                    player = new Player(x, y);
                }
            }
            else if (map_storage[y][x] == 'I')
            {
                trees.push_back(new Tree(x, y));
            }
            else if (map_storage[y][x] == 'L')
            {
                leaves.push_back(new Leaves(x, y));
            }
        }
    }
    first_entry = false;
}


// Show to screen
void Game::Show()
{
    system("cls");
    for (unsigned int y = 0; y < screen_height; y++)
    {
        for (unsigned int x = min_left_side; x < max_right_side; x++)
        {
            is_index_printed = false;
            // Checking for player
            if (player->Get_x_player() == x && player->Get_y_player() == y)
            {
                cout << "\x4F";
                is_index_printed = true;
                continue;
            }
            // Checking for invisible barriers
            for (unsigned int i = 0; i < invisible_barriers.size(); i++)
            {
                if (!is_index_printed && invisible_barriers[i]->Get_x_inv_barrier() == x && invisible_barriers[i]->Get_y_inv_barrier() == y)
                {
                    if (invisible_barriers[i]->Get_type() == 1)
                    {
                        cout << "\xDB";
                    }
                    else if (invisible_barriers[i]->Get_type() == 0)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << "\xDF";
                    }
                    is_index_printed = true;
                    break;
                }
            }
            // Checking for stones
            for (unsigned int i = 0; i < stones.size(); i++)
            {
                if (!is_index_printed && (stones[i]->Get_x_stone() == x && stones[i]->Get_y_stone() == y))
                {
                    cout << "\xDB";
                    is_index_printed = true;
                    break;
                }
            }
            // Checking for trunks
            for (unsigned int i = 0; i < trees.size(); i++)
            {
                if (!is_index_printed && (trees[i]->Get_x_tree() == x && trees[i]->Get_y_tree() == y))
                {
                    cout << "\xBA";
                    is_index_printed = true;
                    break;
                }
            }
            // Checking for leaves
            for (unsigned int i = 0; i < leaves.size(); i++)
            {
                if (!is_index_printed && (leaves[i]->Get_x_tree() == x && leaves[i]->Get_y_tree() == y))
                {
                    cout << "\xB0";
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
    for (unsigned int i = 0; i < invisible_barriers.size(); i++)
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
    for (unsigned int i = 0; i < stones.size(); i++)
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
    for (unsigned int i = 0; i < stones.size(); i++)
    {  
        if (stones[i]->Get_x_stone() == player->Get_x_player() && stones[i]->Get_y_stone() - 1 == player->Get_y_player())
        {
            gravity = false;
        }
    }
    for (unsigned int i = 0; i < invisible_barriers.size(); i++)
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
        MoveTerrain();
        Logic();
        Show();
        stones.clear();
        invisible_barriers.clear();
        trees.clear();
        leaves.clear();
        player->Move(right_move, left_move, gravity);
    }
}