#include "Game.h"


// Constructor
Game::Game()
    :x_coord(0), y_coord(0),first_entry(true), game_over(false)
{
    player.push_back(new Player);
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
    min_left_side = 0;
    max_right_side = map_storage[0].size();
    max_down = map_storage.size();
    min_up = 0;
}


// Handling pointer destuctions through destructor
Game::~Game()
{
    for (auto it : player)
    {
        delete it;
    }
    for (auto it : barriers)
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
}


// Moving terrain as player moves
void Game::MoveTerrain()
{    
    if (!first_entry)
    {
        min_up = (player[0]->Get_y_player() - 8 > 0) ? player[0]->Get_y_player() - 8 : 0;
        max_down = ((player[0]->Get_y_player() + 8) < (int)map_storage.size()) ? (player[0]->Get_y_player() + 8) : (int)map_storage.size();
        min_left_side = (player[0]->Get_x_player() - 25 > 0) ? player[0]->Get_x_player() - 25 : 0;
        max_right_side = ((player[0]->Get_x_player() + 25) < (int)map_storage[0].size()) ? (player[0]->Get_x_player() + 25) : (int)map_storage[0].size();
        if (min_up == 0)
        {
            max_down += 8 - player[0]->Get_y_player();
        }
        if (max_down == (map_storage.size()))
        {
            min_up += map_storage.size() - player[0]->Get_y_player() - 8;
        }
        if (min_left_side == 0)
        {
            max_right_side += 25 - player[0]->Get_x_player();
        }
        if (max_right_side == map_storage[0].size())
        {
            min_left_side += map_storage[0].size() - player[0]->Get_x_player() - 25;
        }
    }
    for (unsigned int y = 0; y < map_storage.size(); y++)
    {
        for (unsigned int x = 0; x < map_storage[0].size(); x++)
        {
            if (map_storage[y][x] == 'S')
            {
                stones.push_back(new Stone(x, y));
            }
            if (map_storage[y][x] == 'I')
            {
                stones.push_back(new Iron(x, y));
            }   
            else if (map_storage[y][x] == '1')
            {
                barriers.push_back(new InvisibleBarriers(x, y));
            }
            else if (map_storage[y][x] == '2')
            {
                barriers.push_back(new VisibleBarriers(x, y));
            }
            else if (map_storage[y][x] == '3')
            {
                barriers.push_back(new HalfVisibleBarriers(x, y));
            }
            else if (map_storage[y][x] == 'P')
            {
                if (first_entry)
                {
                    player[0] = (new Player(x, y));
                }
            }
            else if (map_storage[y][x] == 'Z')
            {
                if (first_entry)
                {
                    player.push_back(new Zombie(x, y));
                }
            }
            else if (map_storage[y][x] == 'T')
            {
                trees.push_back(new Trunk(x, y));
            }
            else if (map_storage[y][x] == 'L')
            {
                trees.push_back(new Leaves(x, y));
            }
        }
    }
    first_entry = false;
    if (min_left_side == 0 && min_up == 0 && max_right_side == map_storage[0].size() && max_down == map_storage.size())
    {
        MoveTerrain();
    }
}


// Show to screen
void Game::Show()
{
    system("cls");
    for (unsigned int y = min_up; y < max_down; y++)
    {
        for (unsigned int x = min_left_side; x < max_right_side; x++)
        {
            is_index_printed = false;
            // Checking for people
            for (unsigned int i = 0; i < player.size(); i++)
            {
                if (!is_index_printed && player[i]->Get_x_player() == x && player[i]->Get_y_player() == y)
                {
                    player[i]->ToConsole();
                    is_index_printed = true;
                    continue;
                }
            }
            // Checking for invisible barriers
            for (unsigned int i = 0; i < barriers.size(); i++)
            {
                if (!is_index_printed && barriers[i]->Get_x_inv_barrier() == x && barriers[i]->Get_y_inv_barrier() == y)
                {
                    barriers[i]->ToConsole();
                    is_index_printed = true;
                    break;
                }
            }
            // Checking for stones
            for (unsigned int i = 0; i < stones.size(); i++)
            {
                if (!is_index_printed && (stones[i]->Get_x_stone() == x && stones[i]->Get_y_stone() == y))
                {
                    stones[i]->ToConsole();
                    is_index_printed = true;
                    break;
                }
            }
            // Checking for trees
            for (unsigned int i = 0; i < trees.size(); i++)
            {
                if (!is_index_printed && (trees[i]->Get_x_tree() == x && trees[i]->Get_y_tree() == y))
                {
                    trees[i]->ToConsole();
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
    for (unsigned int j = 0; j < player.size(); j++)
    {
        if (dynamic_cast<Zombie*>(player[j]))
        {
            Zombie* helper = reinterpret_cast<Zombie*>(player[j]);
            helper->Modify_focus(false);
            helper->Modify_zombie_right(false);
            helper->Modify_zombie_left(false);
        }
        player[j]->Modify_left_move(true);
        player[j]->Modify_right_move(true);
        player[j]->Modify_gravity(true);
        player[j]->Modify_up(true);
        // Gravity
        for (unsigned int i = 0; i < stones.size(); i++)
        {
            if (stones[i]->Get_x_stone() == player[j]->Get_x_player() && stones[i]->Get_y_stone() - 1 == player[j]->Get_y_player())
            {
                player[j]->Modify_gravity(false);
            }
        }
        for (unsigned int i = 0; i < barriers.size(); i++)
        {
            if (barriers[i]->Get_x_inv_barrier() == player[j]->Get_x_player() && barriers[i]->Get_y_inv_barrier() - 1 == player[j]->Get_y_player())
            {
                player[j]->Modify_gravity(false);
            }
        }
        if (player[j]->Get_gravity() && !player[j]->Get_jump() && player[j]->Get_jump_counter() == 0)
        {
            player[j]->Increment_y_player();
        }
        // Stop movement (Invisible barriers)
        for (unsigned int i = 0; i < barriers.size(); i++)
        {
            if (barriers[i]->Get_x_inv_barrier() + 1 == player[j]->Get_x_player() && barriers[i]->Get_y_inv_barrier() == player[j]->Get_y_player())
            {
                player[j]->Modify_left_move(false);
            }
            if (barriers[i]->Get_x_inv_barrier() - 1 == player[j]->Get_x_player() && barriers[i]->Get_y_inv_barrier() == player[j]->Get_y_player())
            {
                player[j]->Modify_right_move(false);
            }
        }
        // Stop movement (Stones)
        for (unsigned int i = 0; i < stones.size(); i++)
        {
            if (stones[i]->Get_x_stone() + 1 == player[j]->Get_x_player() && stones[i]->Get_y_stone() == player[j]->Get_y_player())
            {
                player[j]->Modify_left_move(false);
            }
            if (stones[i]->Get_x_stone() - 1 == player[j]->Get_x_player() && stones[i]->Get_y_stone() == player[j]->Get_y_player())
            {
                player[j]->Modify_right_move(false);
            }
            if (stones[i]->Get_x_stone() == player[j]->Get_x_player() && stones[i]->Get_y_stone() + 1 == player[j]->Get_y_player())
            {
                player[j]->Modify_up(false);
            }
        }
        // Jump
        if (player[j]->Get_jump())
        {
            player[j]->Modify_jump_counter(2);
            player[j]->Modify_jump(false);
        }
        if (player[j]->Get_jump_counter() > 0)
        {
            player[j]->Modify_jump_counter(player[j]->Get_jump_counter() - 1);
            if (player[j]->Get_up())
            {
                player[j]->Decrement_y_player();
            }
        }
        // Zombie focus
        if (dynamic_cast<Zombie*>(player[j]))
        {
            Zombie* helper = reinterpret_cast<Zombie*>(player[j]);
            if ((player[0]->Get_x_player() + 10 > player[j]->Get_x_player() && player[0]->Get_x_player() - 10 < player[j]->Get_x_player())
                && (player[0]->Get_y_player() + 2 > player[j]->Get_y_player() && player[0]->Get_y_player() - 2 < player[j]->Get_y_player()))
            {
                helper->Modify_focus(true);
            }
            if (helper->Get_focus())
            {
                if (player[0]->Get_x_player() == player[j]->Get_x_player() && player[0]->Get_y_player() == player[j]->Get_y_player())
                {
                    game_over = true;
                }
                if (player[0]->Get_x_player() < player[j]->Get_y_player())
                {
                    helper->Modify_zombie_left(true);
                }
                if (player[0]->Get_x_player() > player[j]->Get_y_player())
                {
                    helper->Modify_zombie_right(true);
                }
            }
        }
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
        barriers.clear();
        trees.clear();
        for (int i = 0; i < player.size(); i++)
        {
            player[i]->Move();
        }
    }
}