#include <iostream>
#include <time.h>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#pragma warning(disable:4551)
#pragma warning(disable:6262)
#pragma warning(disable:4244)
#include <Windows.h>

using namespace std;
using namespace sf;

//global variable for special candies
int  temporary_stripe;

//function to set the position of candies
void setpos(RectangleShape& shape, float& x, float& y)
{
    shape.setPosition(Vector2f(x, y));
    if (x >= 721)
    {
        x = 254 - 27.5;
        y += 61;
    }
    else
    {
        x += 62;
    }
}

//function to set textures(candies) to tiles
void setTex(RectangleShape& tile_variable, int& tile_number, int pos[9][9], int i, int j, float& x, float& y,
    Texture& ct1, Texture& ct2, Texture& ct3, Texture& ct4, Texture& ct5, Texture& ct6, Texture& ct7, Texture& ct8, Texture& ct9, Texture& ct10,
    Texture& ct11, Texture& ct12, Texture& ct13, Texture& ct14, Texture& ct15, Texture& ct16, Texture& ct17, Texture& ct18, Texture& ct19, Texture& ct20, Texture& ct21)
{
    //these checks will define that which texture(candy) should be allocated to the tile(tile_variable)
    if (pos[i][j] == 1)
    {
        tile_variable.setTexture(&ct1);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 2)
    {
        tile_variable.setTexture(&ct2);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 3)
    {
        tile_variable.setTexture(&ct3);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 4)
    {
        tile_variable.setTexture(&ct4);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 5)
    {
        tile_variable.setTexture(&ct5);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 6)
    {
        tile_variable.setTexture(&ct6);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 7)
    {
        tile_variable.setTexture(&ct7);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 8)
    {
        tile_variable.setTexture(&ct8);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 9)
    {
        tile_variable.setTexture(&ct9);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 10)
    {
        tile_variable.setTexture(&ct10);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 11)
    {
        tile_variable.setTexture(&ct11);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 12)
    {
        tile_variable.setTexture(&ct12);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 13)
    {
        tile_variable.setTexture(&ct13);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 14)
    {
        tile_variable.setTexture(&ct14);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 15)
    {
        tile_variable.setTexture(&ct15);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 16)
    {
        tile_variable.setTexture(&ct16);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 17)
    {
        tile_variable.setTexture(&ct17);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 18)
    {
        tile_variable.setTexture(&ct18);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 19)
    {
        tile_variable.setTexture(&ct19);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 20)
    {
        tile_variable.setTexture(&ct20);
        setpos(tile_variable, x, y);
    }
    else if (pos[i][j] == 21)
    {
        tile_variable.setTexture(&ct21);
        setpos(tile_variable, x, y);
    }
}

//function to check whether the mouse is over a candy
template <typename type1, typename type2>
bool isMouseOver(type1& window, type2& entity)
{
    float mouseX = static_cast<float>(Mouse::getPosition(window).x);
    float mouseY = static_cast<float>(Mouse::getPosition(window).y);

    float entityX = entity.getPosition().x;
    float entityY = entity.getPosition().y;

    float entityWidth = entity.getPosition().x + entity.getLocalBounds().width;
    float entityHeight = entity.getPosition().y + entity.getLocalBounds().height;


    if (mouseX < entityWidth && mouseX>entityX && mouseY<entityHeight && mouseY > entityY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to display red boundry(cursor) over a candy when it is clicked
template <typename type1>
void displayCursor(type1& window, RectangleShape& candy, Event event)
{
    if (isMouseOver(window, candy))
    {
        cout << "the left button was pressed" << endl;
        cout << "mouse x: " << event.mouseButton.x << endl;
        cout << "mouse y: " << event.mouseButton.y << endl;
        candy.setOutlineThickness(5.f);
        candy.setOutlineColor(Color::Red);
    }
}

//FUNCTION's FOR SWAPPING WITH AID OF EVENT
void swap_by_input(int game_array[9][9], int row_coordinate, int col_coordinate,
    int row_coordinate_of_candy_to_swap_with, int col_coordinate_of_candy_to_swap_with)
    //In  Graphics we need (int row_coordinate, int col_coordinate) in parameters as well..
{                                                                                           //..to Identify what candy was selected
    int temporary_variable;
    temporary_variable = game_array[row_coordinate][col_coordinate];
    game_array[row_coordinate][col_coordinate] = game_array[row_coordinate_of_candy_to_swap_with][col_coordinate_of_candy_to_swap_with];
    game_array[row_coordinate_of_candy_to_swap_with][col_coordinate_of_candy_to_swap_with] = temporary_variable;
}

//To find if there is a match or not
bool found_match_or_not(int game_array[9][9])
{
    int var = 0;
    bool found = false;
    for (int row = 0; row < 9; row++)
    {
        int avail = 0, same = 0;
        avail = game_array[row][0];
        for (int col = 1; col < 9; col++)
        {
            if (var == 0)
            {
                int c = col;
                int d = col;
                int e = col;
                int f = col;
                int g = row;
                if (game_array[row][col] == avail)
                    same++;
                else
                {
                    avail = game_array[row][col];
                    same = 0;
                }
                if (same >= 2)
                {
                    if ((game_array[row][c + 1] == avail) && (game_array[row][c + 1] != game_array[g + 1][0]))
                    {
                        if (game_array[row][c + 2] == avail)
                        {
                            same = 0;
                            var = 1;
                        }
                        else
                        {
                            same = 0;
                            var = 1;
                        }
                    }
                    else
                    {
                        same = 0;
                        var = 1;
                    }
                }
            }
        }
    }

    for (int col = 0; col < 9; col++)
    {
        int avail = 0, same = 0;
        avail = game_array[0][col];
        for (int row = 1; row < 9; row++)
        {
            if (var == 0)
            {
                int c = row;
                int d = row;
                int e = row;
                int f = row;
                int g = col;
                if (game_array[row][col] == avail)
                    same++;
                else
                {
                    avail = game_array[row][col];
                    same = 0;
                }
                if (same >= 2)
                {
                    if ((game_array[c + 1][col] == avail) && (game_array[c + 1][col] != game_array[0][g + 1]))
                    {
                        if (game_array[c + 2][col] == avail)
                        {
                            same = 0;
                            var = 1;
                        }
                        else
                        {
                            same = 0;
                            var = 1;
                        }

                    }
                    else
                    {
                        same = 0;
                        var = 1;
                    }
                }
            }
        }
    }
    if (var == 1)
    {
        return true;
    }
    else if (var == 0)
    {
        return false;
    }
}

//function to put -1 where candies matc
void match_found_and_replace(int game_array[9][9], int row_coordinate, int col_coordinate)
{
    int var2 = 0;
    //To make the value -1 wherever 3, 4 or 5 candies match in rows
    int var = 0;
    //bool found = false;
    if (var2 == 0)
    {
        for (int row = 0; row < 9; row++)
        {
            int avail = 0, same = 0;
            avail = game_array[row][0];
            for (int col = 1; col < 9; col++)
            {
                if (var == 0)
                {
                    int c = col;
                    int d = col;
                    int e = col;
                    int f = col;
                    int g = row;
                    if (game_array[row][col] == avail)
                        same++;
                    else
                    {
                        avail = game_array[row][col];
                        same = 0;
                    }
                    if (same >= 2)
                    {
                        if ((game_array[row][c + 1] == avail) && (game_array[row][c + 1] != game_array[g + 1][0]))
                        {
                            if (game_array[row][c + 2] == avail)
                            {
                                game_array[row][f + 2] = -1;
                                game_array[row][e + 1] = -1;
                                game_array[row][col] = -1;
                                game_array[row][d - 1] = -1;
                                game_array[row][c - 2] = -1;
                                same = 0;
                                var = 1;
                                var2 = 1;
                            }
                            else
                            {
                                temporary_stripe = game_array[row][col];
                                game_array[row][e + 1] = -1;
                                game_array[row][col] = -1;
                                game_array[row][d - 1] = -1;
                                game_array[row][c - 2] = -1;
                                same = 0;
                                var = 1;
                                var2 = 1;
                            }
                        }
                        else
                        {
                            game_array[row][col] = -1;
                            game_array[row][c - 2] = -1;
                            game_array[row][d - 1] = -1;
                            same = 0;
                            var = 1;
                            var2 = 1;
                        }
                    }
                }
            }
        }
    }



    //To make the value -1 wherever 3, 4 or 5 candies match in columns
    if (var2 == 0)
    {
        for (int col = 0; col < 9; col++)
        {
            int avail = 0, same = 0;
            avail = game_array[0][col];
            for (int row = 1; row < 9; row++)
            {
                if (var == 0)
                {
                    int c = row;
                    int d = row;
                    int e = row;
                    int f = row;
                    int g = col;
                    if (game_array[row][col] == avail)
                        same++;
                    else
                    {
                        avail = game_array[row][col];
                        same = 0;
                    }
                    if (same >= 2)
                    {
                        if ((game_array[c + 1][col] == avail) && (game_array[c + 1][col] != game_array[0][g + 1]))
                        {
                            if (game_array[c + 2][col] == avail)
                            {
                                game_array[f + 2][col] = -1;
                                game_array[e + 1][col] = -1;
                                game_array[row][col] = -1;
                                game_array[d - 1][col] = -1;
                                game_array[c - 2][col] = -1;
                                same = 0;
                                var = 1;
                                var2 = 1;
                            }
                            else
                            {
                                temporary_stripe = game_array[row][col];
                                game_array[e + 1][col] = -1;
                                game_array[row][col] = -1;
                                game_array[d - 1][col] = -1;
                                game_array[c - 2][col] = -1;
                                same = 0;
                                var = 1;
                                var2 = 1;
                            }
                        }
                        else
                        {
                            game_array[row][col] = -1;
                            game_array[c - 2][col] = -1;
                            game_array[d - 1][col] = -1;
                            same = 0;
                            var = 1;
                            var2 = 1;
                        }
                    }
                }
            }
        }
    }


    if (var2 == 1)
    {
        for (int row = 0; row < 9; row++)
        {
            int avail = -1, same = 0;
            for (int col = 0; col < 9; col++)
            {
                int c = col;
                int d = col;
                int e = col;
                int f = col;
                int g = row;
                if (game_array[row][col] == avail)
                    same++;
                else
                {
                    same = 0;
                }
                if (same >= 3)
                {
                    if ((game_array[row][c + 1] == avail))
                    {
                        if ((game_array[row][c + 2] == avail))
                        {
                            game_array[row][col] = 16;
                            same = 0;
                            var2 = 1;
                        }
                        else
                        {
                            game_array[row][col] = temporary_stripe + 5;
                            same = 0;
                            var2 = 1;
                        }
                    }
                }
            }
        }
    }

    if (var2 == 1)
    {
        for (int col = 0; col < 9; col++)
        {
            int avail = -1, same = 0;
            for (int row = 0; row < 9; row++)
            {
                int c = row;
                int d = row;
                int e = row;
                int f = row;
                int g = col;
                if (game_array[row][col] == avail)
                    same++;
                else
                {
                    same = 0;
                }
                if (same >= 3)
                {
                    if ((game_array[c + 1][col] == avail))
                    {
                        if (game_array[c + 2][col] == avail)
                        {
                            game_array[row][col] = 16;
                            same = 0;
                            var2 = 1;
                        }
                        else
                        {
                            game_array[row][col] = temporary_stripe + 16;
                            same = 0;
                            var2 = 1;
                        }
                    }
                }
            }
        }
    }
    //gamerule 5
    //blasting stripe candy after computing rows
    if (var2 == 0)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (game_array[row][col] == game_array[row][col + 1] && game_array[row][col + 2] == game_array[row][col + 1] + 5)
                {
                    for (int col2 = 0; col2 < 9; col2++)
                    {
                        game_array[row][col2] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row][col] == game_array[row][col + 1] && game_array[row][col + 2] == game_array[row][col + 1] + 16)
                {
                    game_array[row][col] = -1;
                    game_array[row][col + 1] = -1;
                    for (int row2 = 0; row2 < 9; row2++)
                    {
                        game_array[row2][col + 2] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row][col] == game_array[row][col + 2] && game_array[row][col + 1] == game_array[row][col] + 5)
                {
                    for (int col2 = 0; col2 < 9; col2++)
                    {
                        game_array[row][col2] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row][col] == game_array[row][col + 2] && game_array[row][col + 1] == game_array[row][col] + 16)
                {
                    game_array[row][col] = -1;
                    game_array[row][col + 2] = -1;
                    for (int row2 = 0; row2 < 9; row2++)
                    {
                        game_array[row2][col + 1] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row][col + 1] == game_array[row][col + 2] && game_array[row][col] == game_array[row][col + 1] + 5)
                {
                    for (int col2 = 0; col2 < 9; col2++)
                    {
                        game_array[row][col2] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row][col + 1] == game_array[row][col + 2] && game_array[row][col] == game_array[row][col + 1] + 16)
                {
                    game_array[row][col + 1] = -1;
                    game_array[row][col + 2] = -1;
                    for (int row2 = 0; row2 < 9; row2++)
                    {
                        game_array[row2][col] = -1;
                    }
                    var2 = 1;
                }
            }
        }
    }
    //blasting stripe candy after computing column
    if (var2 == 0)
    {
        for (int col = 0; col < 9; col++)
        {
            for (int row = 0; row < 9; row++)
            {
                if (game_array[row][col] == game_array[row + 1][col] && game_array[row + 2][col] == game_array[row + 1][col] + 5)
                {
                    game_array[row][col] = -1;
                    game_array[row + 1][col] = -1;
                    for (int col2 = 0; col2 < 9; col2++)
                    {
                        game_array[row + 2][col2] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row][col] == game_array[row + 1][col] && game_array[row + 2][col] == game_array[row + 1][col] + 16)
                {
                    for (int row2 = 0; row2 < 9; row2++)
                    {
                        game_array[row2][col] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row][col] == game_array[row + 2][col] && game_array[row + 1][col] == game_array[row][col] + 5)
                {
                    game_array[row][col] = -1;
                    game_array[row + 2][col] = -1;
                    for (int col2 = 0; col2 < 9; col2++)
                    {
                        game_array[row + 1][col2] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row][col] == game_array[row + 2][col] && game_array[row + 1][col] == game_array[row][col] + 16)
                {
                    for (int row2 = 0; row2 < 9; row2++)
                    {
                        game_array[row2][col] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row + 1][col] == game_array[row + 2][col] && game_array[row][col] == game_array[row + 1][col] + 5)
                {
                    game_array[row + 1][col] = -1;
                    game_array[row + 2][col] = -1;
                    for (int col2 = 0; col2 < 9; col2++)
                    {
                        game_array[row][col2] = -1;
                    }
                    var2 = 1;
                }
                else if (game_array[row + 1][col] == game_array[row + 2][col] && game_array[row][col] == game_array[row + 1][col] + 16)
                {
                    for (int row2 = 0; row2 < 9; row2++)
                    {
                        game_array[row2][col] = -1;
                    }
                    var2 = 1;
                }
            }
        }
    }

    //gamerule 6
    //blasting wrapped candy after computing column
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (game_array[row][col - 2] == game_array[row][col - 1] && game_array[row][col] == game_array[row][col - 1] + 10)
            {
                game_array[row - 1][col] = -1;
                game_array[row - 1][col - 1] = -1;
                game_array[row][col - 1] = -1;
                game_array[row + 1][col - 1] = -1;
                game_array[row + 1][col] = -1;
                game_array[row + 1][col + 1] = -1;
                game_array[row][col + 1] = -1;
                game_array[row - 1][col + 1] = -1;
                game_array[row][col] = -1;

                game_array[row][col - 2] = -1;
                var2 = 1;
            }
            else if (game_array[row][col - 1] == game_array[row][col + 1] && game_array[row][col] == game_array[row][col - 1] + 10)
            {
                game_array[row - 1][col] = -1;
                game_array[row - 1][col - 1] = -1;
                game_array[row][col - 1] = -1;
                game_array[row + 1][col - 1] = -1;
                game_array[row + 1][col] = -1;
                game_array[row + 1][col + 1] = -1;
                game_array[row][col + 1] = -1;
                game_array[row - 1][col + 1] = -1;
                game_array[row][col] = -1;

                var2 = 1;
            }
            else if (game_array[row][col + 2] == game_array[row][col + 1] && game_array[row][col] == game_array[row][col + 1] + 10)
            {
                game_array[row - 1][col] = -1;
                game_array[row - 1][col - 1] = -1;
                game_array[row][col - 1] = -1;
                game_array[row + 1][col - 1] = -1;
                game_array[row + 1][col] = -1;
                game_array[row + 1][col + 1] = -1;
                game_array[row][col + 1] = -1;
                game_array[row - 1][col + 1] = -1;
                game_array[row][col] = -1;

                game_array[row][col + 2] = -1;
                var2 = 1;
            }
        }
    }

    for (int col = 0; col < 9; col++)
    {
        for (int row = 0; row < 9; row++)
        {
            if (game_array[row - 2][col] == game_array[row - 1][col] && game_array[row][col] == game_array[row - 1][col] + 10)
            {
                game_array[row - 1][col] = -1;
                game_array[row - 1][col - 1] = -1;
                game_array[row][col - 1] = -1;
                game_array[row + 1][col - 1] = -1;
                game_array[row + 1][col] = -1;
                game_array[row + 1][col + 1] = -1;
                game_array[row][col + 1] = -1;
                game_array[row - 1][col + 1] = -1;
                game_array[row][col] = -1;

                game_array[row - 2][col] = -1;
                var2 = 1;
            }
            else if (game_array[row - 1][col] == game_array[row + 1][col] && game_array[row][col] == game_array[row - 1][col] + 10)
            {
                game_array[row - 1][col] = -1;
                game_array[row - 1][col - 1] = -1;
                game_array[row][col - 1] = -1;
                game_array[row + 1][col - 1] = -1;
                game_array[row + 1][col] = -1;
                game_array[row + 1][col + 1] = -1;
                game_array[row][col + 1] = -1;
                game_array[row - 1][col + 1] = -1;
                game_array[row][col] = -1;

                var2 = 1;
            }
            else if (game_array[row + 1][col] == game_array[row + 2][col] && game_array[row][col] == game_array[row + 1][col] + 10)
            {
                game_array[row - 1][col] = -1;
                game_array[row - 1][col - 1] = -1;
                game_array[row][col - 1] = -1;
                game_array[row + 1][col - 1] = -1;
                game_array[row + 1][col] = -1;
                game_array[row + 1][col + 1] = -1;
                game_array[row][col + 1] = -1;
                game_array[row - 1][col + 1] = -1;
                game_array[row][col] = -1;

                game_array[row + 2][col] = -1;
                var2 = 1;
            }
        }
    }

    int i = row_coordinate, j = col_coordinate;
    //For Structure 1
    if (game_array[i][j] == game_array[i - 1][j] && game_array[i - 1][j] == game_array[i - 2][j] && game_array[i][j] == game_array[i][j + 1] && game_array[i][j + 1] == game_array[j][j + 2])
    {
        var2 = 1;
        if (game_array[i][j] == 1)
        {
            game_array[i][j] = 11;
        }
        else if (game_array[i][j] == 2)
        {
            game_array[i][j] = 12;
        }
        else if (game_array[i][j] == 3)
        {
            game_array[i][j] = 13;
        }
        else if (game_array[i][j] == 4)
        {
            game_array[i][j] = 14;
        }
        else if (game_array[i][j] == 5)
        {
            game_array[i][j] = 15;
        }
        //Removing Matching Candies
        game_array[i][j + 1] = -1;
        game_array[i][j + 2] = -1;
        game_array[i - 1][j] = -1;
        game_array[i - 2][j] = -1;
    }//For Structure 2
    else if (game_array[i][j] == game_array[i - 1][j] && game_array[i - 1][j] == game_array[i - 2][j] && game_array[i][j] == game_array[i][j - 1] && game_array[i][j - 1] == game_array[j][j - 2])
    {
        var2 = 1;
        if (game_array[i][j] == 1)
        {
            game_array[i][j] = 11;
        }
        else if (game_array[i][j] == 2)
        {
            game_array[i][j] = 12;
        }
        else if (game_array[i][j] == 3)
        {
            game_array[i][j] = 13;
        }
        else if (game_array[i][j] == 4)
        {
            game_array[i][j] = 14;
        }
        else if (game_array[i][j] == 5)
        {
            game_array[i][j] = 15;
        }
        //Removing Matching Candies
        game_array[i][j - 1] = -1;
        game_array[i][j - 2] = -1;
        game_array[i - 1][j] = -1;
        game_array[i - 2][j] = -1;
    }//For Structure 3
    else if (game_array[i][j] == game_array[i + 1][j] && game_array[i + 1][j] == game_array[i + 2][j] && game_array[i][j] == game_array[i][j + 1] && game_array[i][j + 1] == game_array[j][j + 2])
    {
        var2 = 1;
        if (game_array[i][j] == 1)
        {
            game_array[i][j] = 11;
        }
        else if (game_array[i][j] == 2)
        {
            game_array[i][j] = 12;
        }
        else if (game_array[i][j] == 3)
        {
            game_array[i][j] = 13;
        }
        else if (game_array[i][j] == 4)
        {
            game_array[i][j] = 14;
        }
        else if (game_array[i][j] == 5)
        {
            game_array[i][j] = 15;
        }
        //Removing Matching Candies
        game_array[i][j + 1] = -1;
        game_array[i][j + 2] = -1;
        game_array[i + 1][j] = -1;
        game_array[i + 2][j] = -1;
    }//For Structure 4
    else if (game_array[i][j] == game_array[i + 1][j] && game_array[i + 1][j] == game_array[i + 2][j] && game_array[i][j] == game_array[i][j - 1] && game_array[i][j - 1] == game_array[j][j - 2])
    {
        var2 = 1;
        if (game_array[i][j] == 1)
        {
            game_array[i][j] = 11;
        }
        else if (game_array[i][j] == 2)
        {
            game_array[i][j] = 12;
        }
        else if (game_array[i][j] == 3)
        {
            game_array[i][j] = 13;
        }
        else if (game_array[i][j] == 4)
        {
            game_array[i][j] = 14;
        }
        else if (game_array[i][j] == 5)
        {
            game_array[i][j] = 15;
        }
        //Removing Matching Candies
        game_array[i][j - 1] = -1;
        game_array[i][j - 2] = -1;
        game_array[i + 1][j] = -1;
        game_array[i + 2][j] = -1;
    }//For Structure 5
    else if (game_array[i][j] == game_array[i][j + 1] && game_array[i][j] == game_array[i][j - 1] && game_array[i][j] == game_array[i + 1][j] && game_array[i + 1][j] == game_array[i + 2][j])
    {
        var2 = 1;
        if (game_array[i][j] == 1)
        {
            game_array[i][j] = 11;
        }
        else if (game_array[i][j] == 2)
        {
            game_array[i][j] = 12;
        }
        else if (game_array[i][j] == 3)
        {
            game_array[i][j] = 13;
        }
        else if (game_array[i][j] == 4)
        {
            game_array[i][j] = 14;
        }
        else if (game_array[i][j] == 5)
        {
            game_array[i][j] = 15;
        }
        //Removing Matching Candies
        game_array[i][j + 1] = -1;
        game_array[i][j - 1] = -1;
        game_array[i + 1][j] = -1;
        game_array[i + 2][j] = -1;

    }//For Structure 6
    else if (game_array[i][j] == game_array[i][j + 1] && game_array[i][j] == game_array[i][j - 1] && game_array[i][j] == game_array[i - 1][j] && game_array[i - 1][j] == game_array[i - 2][j])
    {
        var2 = 1;
        if (game_array[i][j] == 1)
        {
            game_array[i][j] = 11;
        }
        else if (game_array[i][j] == 2)
        {
            game_array[i][j] = 12;
        }
        else if (game_array[i][j] == 3)
        {
            game_array[i][j] = 13;
        }
        else if (game_array[i][j] == 4)
        {
            game_array[i][j] = 14;
        }
        else if (game_array[i][j] == 5)
        {
            game_array[i][j] = 15;
        }
        //Removing Matching Candies
        game_array[i][j + 1] = -1;
        game_array[i][j - 1] = -1;
        game_array[i - 1][j] = -1;
        game_array[i - 2][j] = -1;
    }//For Structure 7 
    else if (game_array[i][j] == game_array[i - 1][j] && game_array[i][j] == game_array[i + 1][j] && game_array[i][j] == game_array[i][j + 1] && game_array[i][j + 1] == game_array[i][j + 2])
    {
        var2 = 1;
        if (game_array[i][j] == 1)
        {
            game_array[i][j] = 11;
        }
        else if (game_array[i][j] == 2)
        {
            game_array[i][j] = 12;
        }
        else if (game_array[i][j] == 3)
        {
            game_array[i][j] = 13;
        }
        else if (game_array[i][j] == 4)
        {
            game_array[i][j] = 14;
        }
        else if (game_array[i][j] == 5)
        {
            game_array[i][j] = 15;
        }
        //Removing Matching Candies
        game_array[i][j + 2] = -1;
        game_array[i][j + 1] = -1;
        game_array[i + 1][j] = -1;
        game_array[i - 1][j] = -1;

    }//For Structure 8
    else if (game_array[i][j] == game_array[i - 1][j] && game_array[i][j] == game_array[i + 1][j] && game_array[i][j] == game_array[i][j - 1] && game_array[i][j - 1] == game_array[i][j - 2])
    {
        var2 = 1;
        if (game_array[i][j] == 1)
        {
            game_array[i][j] = 11;
        }
        else if (game_array[i][j] == 2)
        {
            game_array[i][j] = 12;
        }
        else if (game_array[i][j] == 3)
        {
            game_array[i][j] = 13;
        }
        else if (game_array[i][j] == 4)
        {
            game_array[i][j] = 14;
        }
        else if (game_array[i][j] == 5)
        {
            game_array[i][j] = 15;
        }
        //Removing Matching Candies
        game_array[i][j - 2] = -1;
        game_array[i][j - 1] = -1;
        game_array[i + 1][j] = -1;
        game_array[i - 1][j] = -1;
    }


}

//for shifting -1 towards the top and then replacing it with -2
void replace_vert(int matrix[9][9], int row, int col, int length)
{
    for (int i = row + length; i >= 0; i--)
    {
        if (i - length - 1 >= 0)
        {
            matrix[i][col] = matrix[i - length - 1][col];
        }
        else
        {
            matrix[i][col] = -2;
        }
    }
}

void replacing_used_candies(int game_array[9][9])
{
    bool found = false;
    for (int row = 0; row < 9 && !found; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (game_array[row][col] == -1)
            {
                replace_vert(game_array, row, col, 0);
            }
        }
    }
}

//function to genrate new candies where -1 is found
void empty_Find_Replace(int game_array[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (game_array[row][col] == -2)
            {
                game_array[row][col] = rand() % 5 + 1;
            }
        }
    }
}

//game rule functions
//point 7
void game_rule_7(int game_array[9][9], int selected_row_coordinate, int selected_col_coordinate, int swap_col_coordinate, int swap_row_coordinate)
{
    int a = selected_row_coordinate;
    int b = selected_col_coordinate;
    int c = swap_row_coordinate;
    int d = swap_col_coordinate;

    int plain_candies[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; i++)
    {
        if ((game_array[a][b] == plain_candies[i] && game_array[c][d] == 16) || (game_array[c][d] == plain_candies[i] && game_array[a][b] == 16))
        {
            game_array[c][d] = -1;
            game_array[a][b] = -1;
            for (int j = 0; j < 9; j++)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (game_array[j][k] == plain_candies[i])
                    {
                        game_array[j][k] = -1;
                    }
                }
            }
        }
    }
}
//point 8
void game_rule_8(int game_array[9][9], int row_1, int col_1, int row_2, int col_2)
{
    bool check = true;

    //checking if candy in row_1, col_1 and row_2, col_2 are color bombs
    if ((game_array[row_1][col_1] == 16) && (game_array[row_2][col_2] == 16))
    {
        check = true;
    }
    else
    {
        check = false;
    }

    if (check)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                game_array[row][col] = -1;
            }
        }
    }
}
//point 9
void game_rule_9(int game_array[9][9], int row_1, int col_1, int row_2, int col_2)
{
    bool check1 = false, check2 = false, check3 = true;

    //checking if candy in row_1 and col_1 is a color bomb or a striped candy
    if (game_array[row_1][col_1] == 16)
    {
        check1 = true;
        check3 = false;
    }
    else if ((game_array[row_1][col_1] >= 6) && (game_array[row_1][col_1] <= 10))
    {
        check1 = true;
    }
    else if ((game_array[row_1][col_1] >= 17) && (game_array[row_1][col_1] <= 21))
    {
        check1 = true;
    }
    else
    {
        check1 = false;
    }

    //checking if candy in row_2 and col_2 is a color bomb or a striped candy
    if (game_array[row_2][col_2] == 16)
    {
        if (check3 == true)
        {
            check2 = true;
        }
    }
    else if ((game_array[row_2][col_2] >= 6) && (game_array[row_2][col_2] <= 10))
    {
        check2 = true;
    }
    else if ((game_array[row_2][col_2] >= 17) && (game_array[row_2][col_2] <= 21))
    {
        check2 = true;
    }
    else
    {
        check2 = false;
    }

    if ((check1 == true) && (check2 == true))
    {
        int stripped_candy_col = 0, stripped_candy_row = 0;
        int color_bomb_col = 0, color_bomb_row = 0;

        //figuring out the locations of color bomb and stripped candy
        if (game_array[row_2][col_2] == 16)
        {
            color_bomb_col = col_2;
            color_bomb_row = row_2;

            stripped_candy_col = col_1;
            stripped_candy_row = row_1;
        }
        else
        {
            color_bomb_col = col_1;
            color_bomb_row = row_1;

            stripped_candy_col = col_2;
            stripped_candy_row = row_2;
        }

        int candy_to_replace = 0;

        //Finding which color candy to replace
        if ((game_array[stripped_candy_row][stripped_candy_col] == 6) || (game_array[stripped_candy_row][stripped_candy_col] == 17))
        {
            candy_to_replace = 1;
        }
        else if ((game_array[stripped_candy_row][stripped_candy_col] == 7) || (game_array[stripped_candy_row][stripped_candy_col] == 18))
        {
            candy_to_replace = 2;
        }
        else if ((game_array[stripped_candy_row][stripped_candy_col] == 8) || (game_array[stripped_candy_row][stripped_candy_col] == 19))
        {
            candy_to_replace = 3;
        }
        else if ((game_array[stripped_candy_row][stripped_candy_col] == 9) || (game_array[stripped_candy_row][stripped_candy_col] == 20))
        {
            candy_to_replace = 4;
        }
        else if ((game_array[stripped_candy_row][stripped_candy_col] == 10) || (game_array[stripped_candy_row][stripped_candy_col] == 21))
        {
            candy_to_replace = 5;
        }

        //To check if striped candy is vertically striped or horizontally striped
        bool check_vertical_or_horizontal_stripped = true;
        if ((game_array[stripped_candy_row][stripped_candy_col] >= 6) && (game_array[stripped_candy_row][stripped_candy_col] <= 10))
        {
            //is horizontally striped
            check_vertical_or_horizontal_stripped = true;
        }
        else
        {
            //is vertically striped
            check_vertical_or_horizontal_stripped = false;
        }

        int candy_copy = game_array[stripped_candy_row][stripped_candy_col];

        if (check_vertical_or_horizontal_stripped == true)
        {
            for (int row = 0; row < 9; row++)
            {
                for (int col = 0; col < 9; col++)
                {
                    if (game_array[row][col] == candy_to_replace)
                    {
                        game_array[row][col] = candy_copy;

                        for (int col_for_replacement = 0; col_for_replacement < 9; col_for_replacement++)
                        {
                            game_array[row][col_for_replacement] = -1;
                        }

                    }
                }
            }
        }

        else if (check_vertical_or_horizontal_stripped == false)
        {
            for (int row = 0; row < 9; row++)
            {
                for (int col = 0; col < 9; col++)
                {
                    if (game_array[row][col] == candy_to_replace)
                    {
                        game_array[row][col] = candy_copy;

                        for (int row_for_replacement = 0; row_for_replacement < 9; row_for_replacement++)
                        {
                            game_array[row_for_replacement][col] = -1;
                        }

                    }
                }
            }
        }
    }
}
//point 10
void game_rule_10(int game_array[9][9], int row_1, int col_1, int row_2, int col_2)
{
    bool check = false;

    //checking if candy in row_1 and col_1 is a color bomb or a wrapped candy
    if (game_array[row_1][col_1] != 16)
    {
        if ((game_array[row_1][col_1] >= 11) && (game_array[row_1][col_1] <= 15))
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }

    //checking if candy in row_2 and col_2 is a color bomb or a wrapped candy
    if (game_array[row_2][col_2] != 16)
    {
        if ((game_array[row_2][col_2] >= 11) && (game_array[row_2][col_2] <= 15))
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }

    if (check)
    {
        int wrapped_candy_col = 0, wrapped_candy_row = 0;
        int color_bomb_col = 0, color_bomb_row = 0;

        //figuring out the locations of color bomb and wrapped candy
        if (game_array[row_2][col_2] == 16)
        {
            color_bomb_col = col_2;
            color_bomb_row = row_2;

            wrapped_candy_col = col_1;
            wrapped_candy_row = row_1;
        }
        else
        {
            color_bomb_col = col_1;
            color_bomb_row = row_1;

            wrapped_candy_col = col_2;
            wrapped_candy_row = row_2;
        }

        int candy_to_replace = game_array[wrapped_candy_row][wrapped_candy_col] - 10;

        int candy_copy = game_array[wrapped_candy_row][wrapped_candy_col];

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (game_array[row][col] == candy_to_replace)
                {
                    game_array[row][col] = candy_copy;

                    if (row - 1 >= 0)
                    {
                        game_array[row - 1][col] = -1;
                    }
                    if ((row - 1 >= 0) && (col - 1 >= 0))
                    {
                        game_array[row - 1][col - 1] = -1;
                    }
                    if (col - 1 >= 0)
                    {
                        game_array[row][col - 1] = -1;
                    }
                    if ((row + 1 <= 9) && (col - 1 >= 0))
                    {
                        game_array[row + 1][col - 1] = -1;
                    }
                    if (row + 1 <= 9)
                    {
                        game_array[row + 1][col] = -1;
                    }
                    if ((row + 1 <= 9) && (col + 1 <= 9))
                    {
                        game_array[row + 1][col + 1] = -1;
                    }
                    if (col + 1 <= 9)
                    {
                        game_array[row][col + 1] = -1;
                    }
                    if ((row - 1 >= 0) && (col + 1 <= 9))
                    {
                        game_array[row - 1][col + 1] = -1;
                    }

                    game_array[row][col] = -1;
                }
            }
        }
    }
}
//point 11
void Striped_Wrapped(int array[9][9], int selected_row_coordinate, int selected_col_coordinate, int swap_col_coordinate, int swap_row_coordinate)
{
    int a = selected_row_coordinate;
    int b = selected_col_coordinate;
    int c = swap_row_coordinate;
    int d = swap_col_coordinate;

    int striped_candies[10] = { 6, 7, 8, 9, 10, 17, 18, 19, 20, 21 };
    int wrapped_candies[5] = { 11, 12, 13, 14, 15 };


    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((array[a][b] == wrapped_candies[i] && array[c][d] == striped_candies[j]) || (array[a][b] == striped_candies[j] && array[c][d] == wrapped_candies[i]))
            {
                if ((a != 0 && b != 0) || (a != 0 && b != 1) || (a != 0 && b != 2) || (a != 0 && b != 3) || (a != 0 && b != 4) || (a != 0 && b != 5) || (a != 0 && b != 6) || (a != 0 && b != 7) || (a != 0 && b != 8) || (a != 8 && b != 0) || (a != 8 && b != 1) || (a != 8 && b != 2) || (a != 8 && b != 3) || (a != 8 && b != 4) || (a != 8 && b != 5) || (a != 8 && b != 6) || (a != 8 && b != 7) || (a != 8 && b != 8) || (a != 1 && b != 0) || (a != 2 && b != 0) || (a != 3 && b != 0) || (a != 4 && b != 0) || (a != 5 && b != 0) || (a != 6 && b != 0) || (a != 7 && b != 0) || (a != 1 && b != 8) || (a != 2 && b != 8) || (a != 3 && b != 8) || (a != 4 && b != 8) || (a != 5 && b != 8) || (a != 6 && b != 8) || (a != 7 && b != 8))
                {
                    //Crushing Candies Downwards
                    for (int k = a; k < 9; k++)
                    {
                        array[k][b] = -1;
                        array[k][b - 1] = -1;
                        array[k][b + 1] = -1;
                    }
                    //Crushing Candies Upwards
                    for (int k = a; k >= 0; k--)
                    {
                        array[k][b] = -1;
                        array[k][b - 1] = -1;
                        array[k][b + 1] = -1;
                    }
                    //Crushing Candies to the Right
                    for (int k = b; k < 9; k++)
                    {
                        array[a][k] = -1;
                        array[a - 1][k] = -1;
                        array[a + 1][k] = -1;
                    }
                    //Crushing Candies to the Left
                    for (int k = b; k >= 0; k--)
                    {
                        array[a][k] = -1;
                        array[a - 1][k] = -1;
                        array[a + 1][k] = -1;
                    }
                }
                else if (a == 0 && b == 0) //Top Left Corner
                {
                    for (int k = a; k < 9; k++)
                    {
                        array[k][b] = -1;
                        array[k][b + 1] = -1;
                    }
                    for (int k = b; k < 9; k++)
                    {
                        array[a][k] = -1;
                        array[a + 1][k] = -1;
                    }
                }
                else if (a == 0 && b == 8) //Top Right Corner
                {
                    for (int k = a; k < 9; k++)
                    {
                        array[k][b] = -1;
                        array[k][b - 1] = -1;
                    }
                    for (int k = b; k >= 0; k--)
                    {
                        array[a][k] = -1;
                        array[a + 1][k] = -1;
                    }
                }
                else if (a == 8 && b == 0) //Bottom Left Corner
                {
                    for (int k = a; k >= 0; k--)
                    {
                        array[k][b] = -1;
                        array[k][b + 1] = -1;
                    }
                    for (int k = b; k < 9; k++)
                    {
                        array[a][k] = -1;
                        array[a - 1][k] = -1;
                    }
                }
                else if (a == 8 && b == 8) //Bottom Right Corner
                {
                    for (int k = a; k >= 0; k--)
                    {
                        array[k][b] = -1;
                        array[k][b + 1] = -1;
                    }
                    for (int k = b; k >= 0; k--)
                    {
                        array[a][k] = -1;
                        array[a - 1][k] = -1;
                    }
                }
                else if ((a == 1 && b == 0) || (a == 2 && b == 0) || (a == 3 && b == 0) || (a == 4 && b == 0) || (a == 5 && b == 0) || (a == 6 && b == 0) || (a == 7 && b == 0))
                {
                    for (int k = b; k < 9; k++)
                    {
                        array[a][k] = -1;
                        array[a - 1][k] = -1;
                        array[a + 1][k] = -1;
                    }
                    for (int k = a; k < 9; k++)
                    {
                        array[k][b] = -1;
                        array[k][b + 1] = -1;
                    }
                }
                else if ((a == 1 && b == 8) || (a == 2 && b == 8) || (a == 3 && b == 8) || (a == 4 && b == 8) || (a == 5 && b == 8) || (a == 6 && b == 8) || (a == 7 && b == 8))
                {
                    for (int k = a; k < 9; k++)
                    {
                        array[k][b] = -1;
                        array[k][b - 1] = -1;
                    }
                    for (int k = b; k >= 0; k--)
                    {
                        array[a][k] = -1;
                        array[a - 1][k] = -1;
                        array[a + 1][k] = -1;
                    }
                }
            }
        }
    }
}
//point 12
void Wrapped_Wrapped(int array[9][9], int selected_row_coordinate, int selected_col_coordinate, int swap_col_coordinate, int swap_row_coordinate)
{
    int a = selected_row_coordinate;
    int b = selected_col_coordinate;
    int c = swap_row_coordinate;
    int d = swap_col_coordinate;

    int wrapped_candies_1[5] = { 11, 12, 13, 14, 15 };
    int wrapped_candies_2[5] = { 11, 12, 13, 14, 15 };


    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((array[a][b] == wrapped_candies_1[i] && array[c][d] == wrapped_candies_2[j]) || (array[a][b] == wrapped_candies_2[j] && array[c][d] == wrapped_candies_1[i]))
            {
                if ((a == 2 && b == 2) || (a == 2 && b == 3) || (a == 2 && b == 4) || (a == 2 && b == 5) || (a == 2 && b == 6) || (a == 3 && b == 2) || (a == 3 && b == 3) || (a == 3 && b == 4) || (a == 3 && b == 5) || (a == 3 && b == 6) || (a == 4 && b == 2) || (a == 4 && b == 3) || (a == 4 && b == 4) || (a == 4 && b == 5) || (a == 4 && b == 6) || (a == 5 && b == 2) || (a == 5 && b == 3) || (a == 5 && b == 4) || (a == 5 && b == 5) || (a == 5 && b == 6) || (a == 6 && b == 2) || (a == 6 && b == 3) || (a == 6 && b == 4) || (a == 6 && b == 5) || (a == 6 && b == 6))
                    //Bottom Right Square
                    for (int k = a; k < a + 2; k++)
                    {
                        for (int g = b; g < b + 2; g++)
                        {
                            array[k][g] = -1;
                        }
                    }
                //Top Right Square
                for (int k = a; k > a - 2; k--)
                {
                    for (int g = b; g < b + 2; g++)
                    {
                        array[k][g] = -1;
                    }
                }
                //Bottom Left Square
                for (int k = a; k < a + 2; k++)
                {
                    for (int g = b; g > b - 2; g--)
                    {
                        array[k][g] = -1;
                    }
                }
                //Top Left Square
                for (int k = a; k > a - 2; k--)
                {
                    for (int g = b; g > b - 2; g--)
                    {
                        array[k][g] = -1;
                    }
                }
            }
        }
    }
}

//function to implement game rules
void game_rules(int game_array[9][9], int selected_row_coordinate, int selected_col_coordinate, int swap_col_coordinate, int swap_row_coordinate)
{
    //point 7 function
    game_rule_7(game_array, selected_row_coordinate, selected_col_coordinate, swap_col_coordinate, swap_row_coordinate);
    //point 8
    game_rule_8(game_array, selected_row_coordinate, selected_col_coordinate, swap_row_coordinate, swap_col_coordinate);
    //point 9 function
    game_rule_9(game_array, selected_row_coordinate, selected_col_coordinate, swap_row_coordinate, swap_col_coordinate);
    //point 10 function
    game_rule_10(game_array, selected_row_coordinate, selected_col_coordinate, swap_row_coordinate, swap_col_coordinate);
    //point 11 function
    Striped_Wrapped(game_array, selected_row_coordinate, selected_col_coordinate, swap_col_coordinate, swap_row_coordinate);
    //point 12 function
    Wrapped_Wrapped(game_array, selected_row_coordinate, selected_col_coordinate, swap_col_coordinate, swap_row_coordinate);
}

int main()
{
    //hi
    cout << "loading.....!";

    //loading and playing music
    Music music;
    music.openFromFile("Candy Crush Intro2.ogg");
    music.setVolume(70);

    //mainscreen shown count
    int number_of_times_mainscreen_shown = 0;

    //variables for the position of candies
    float x = 225.f, y = 39.f;

    //variables for moves and score
    int number_of_moves = 20;
    int current_score = 0;

    //checking that if swapping is possible
    bool swapping_possible = false, swapping_happened = false;

    //checking mainscreen buttons clicked or not
    bool play_button_pressed = false, load_game_button_pressed = false;

    //check that if the game is still running or player has won or lost
    bool game_playable = true;

    //variables for co_ordinates
    int row_coordinate_of_candy = 0, col_coordinate_of_candy = 0, row_coordinate_of_candy_to_swap_with = 0, col_coordinate_of_candy_to_swap_with = 0;

    //randomizing the position array for candies and removing the pairs of candies
    srand(time(0));

    //declaring main game array
    int game_array[9][9] = { 0 };

    //activating antialiasing
    ContextSettings settings;
    settings.antialiasingLevel = 4;

    //creating window
    RenderWindow window(VideoMode(800, 600), "Candy Crush ;)", Style::Default, settings);

    //textures to load mainscreen image
    Texture texture, new_game_button, load_game_button, save_button,
        ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16,
        ct17, ct18, ct19, ct20, ct21;
    Texture candy;
    Sprite sprite;
    RectangleShape new_game_sprite, load_game_sprite, save_game_sprite;

    //shapes for printing/drawing/displaying -> candies(tiles)
    RectangleShape t1(Vector2f(55.f, 50.f)), t2(Vector2f(55.f, 50.f)), t3(Vector2f(55.f, 50.f)), t4(Vector2f(55.f, 50.f)), t5(Vector2f(55.f, 50.f)), t6(Vector2f(55.f, 50.f)), t7(Vector2f(55.f, 50.f)), t8(Vector2f(55.f, 50.f)), t9(Vector2f(55.f, 50.f)), t10(Vector2f(55.f, 50.f)),
        t11(Vector2f(55.f, 50.f)), t12(Vector2f(55.f, 50.f)), t13(Vector2f(55.f, 50.f)), t14(Vector2f(55.f, 50.f)), t15(Vector2f(55.f, 50.f)), t16(Vector2f(55.f, 50.f)), t17(Vector2f(55.f, 50.f)), t18(Vector2f(55.f, 50.f)), t19(Vector2f(55.f, 50.f)), t20(Vector2f(55.f, 50.f)),
        t21(Vector2f(55.f, 50.f)), t22(Vector2f(55.f, 50.f)), t23(Vector2f(55.f, 50.f)), t24(Vector2f(55.f, 50.f)), t25(Vector2f(55.f, 50.f)), t26(Vector2f(55.f, 50.f)), t27(Vector2f(55.f, 50.f)), t28(Vector2f(55.f, 50.f)), t29(Vector2f(55.f, 50.f)), t30(Vector2f(55.f, 50.f)),
        t31(Vector2f(55.f, 50.f)), t32(Vector2f(55.f, 50.f)), t33(Vector2f(55.f, 50.f)), t34(Vector2f(55.f, 50.f)), t35(Vector2f(55.f, 50.f)), t36(Vector2f(55.f, 50.f)), t37(Vector2f(55.f, 50.f)), t38(Vector2f(55.f, 50.f)), t39(Vector2f(55.f, 50.f)), t40(Vector2f(55.f, 50.f)),
        t41(Vector2f(55.f, 50.f)), t42(Vector2f(55.f, 50.f)), t43(Vector2f(55.f, 50.f)), t44(Vector2f(55.f, 50.f)), t45(Vector2f(55.f, 50.f)), t46(Vector2f(55.f, 50.f)), t47(Vector2f(55.f, 50.f)), t48(Vector2f(55.f, 50.f)), t49(Vector2f(55.f, 50.f)), t50(Vector2f(55.f, 50.f)),
        t51(Vector2f(55.f, 50.f)), t52(Vector2f(55.f, 50.f)), t53(Vector2f(55.f, 50.f)), t54(Vector2f(55.f, 50.f)), t55(Vector2f(55.f, 50.f)), t56(Vector2f(55.f, 50.f)), t57(Vector2f(55.f, 50.f)), t58(Vector2f(55.f, 50.f)), t59(Vector2f(55.f, 50.f)), t60(Vector2f(55.f, 50.f)),
        t61(Vector2f(55.f, 50.f)), t62(Vector2f(55.f, 50.f)), t63(Vector2f(55.f, 50.f)), t64(Vector2f(55.f, 50.f)), t65(Vector2f(55.f, 50.f)), t66(Vector2f(55.f, 50.f)), t67(Vector2f(55.f, 50.f)), t68(Vector2f(55.f, 50.f)), t69(Vector2f(55.f, 50.f)), t70(Vector2f(55.f, 50.f)),
        t71(Vector2f(55.f, 50.f)), t72(Vector2f(55.f, 50.f)), t73(Vector2f(55.f, 50.f)), t74(Vector2f(55.f, 50.f)), t75(Vector2f(55.f, 50.f)), t76(Vector2f(55.f, 50.f)), t77(Vector2f(55.f, 50.f)), t78(Vector2f(55.f, 50.f)), t79(Vector2f(55.f, 50.f)), t80(Vector2f(55.f, 50.f)),
        t81(Vector2f(55.f, 50.f));

    //loading mainscreen
    if (!texture.loadFromFile("NEW MAIN.png"))
        cout << "error";
    texture.setSmooth(true);
    sprite.setTexture(texture);

    //new game button
    if (!new_game_button.loadFromFile("new game button.png"))
        cout << "error";
    new_game_button.setSmooth(true);
    new_game_sprite.setPosition(300.9431f, 440.6449f);
    new_game_sprite.setSize(Vector2f(176.0831f, 45.9773));
    new_game_sprite.setTexture(&new_game_button);

    //load game button
    if (!load_game_button.loadFromFile("load game button.png"))
        cout << "error";
    load_game_button.setSmooth(true);
    load_game_sprite.setPosition(287.226f, 500.3176f);
    load_game_sprite.setSize(Vector2f(206.4086f, 45.9773f));
    load_game_sprite.setTexture(&load_game_button);

    //save game button
    if (!save_button.loadFromFile("save button.png"))
        cout << "error";
    save_button.setSmooth(true);
    save_game_sprite.setPosition(5.2661f, 531.2577f);
    save_game_sprite.setSize(Vector2f(206.4086f, 45.9773f));
    save_game_sprite.setTexture(&save_button);

    //hello comment
    system("cls");
    cout << "Welcome to Candy Crush.";

    //now playing music
    music.play();

    // fonts are used to display text on screen
    Font font_element;
    font_element.loadFromFile("comic.ttf");

    // texts are used to display strings on screen
    //targetscore text
    Text targetscore;
    targetscore.setCharacterSize(22);
    targetscore.setFillColor(Color(255, 105, 180));
    targetscore.setFont(font_element);
    targetscore.setPosition(80.f, 125.f);
    targetscore.setStyle(Text::Bold);
    targetscore.setString("1000");

    //current score text
    Text score;
    score.setCharacterSize(22);
    score.setFillColor(Color(255, 105, 180));
    score.setFont(font_element);
    score.setPosition(103.f, 260.f);
    score.setStyle(Text::Style::Bold);

    //total moves
    Text moves;
    moves.setCharacterSize(22);
    moves.setFillColor(Color(255, 105, 180));
    moves.setFont(font_element);
    moves.setPosition(94.f, 395.f);
    moves.setStyle(Text::Bold);

    //main gameloop
    while (window.isOpen())
    {
        //setting music on loop so that i never ends
        music.setLoop(true);

        //loading candies
        //red candy
        if (!ct1.loadFromFile("red.png"))
            cout << "error";
        //blue candy
        if (!ct2.loadFromFile("Blue.png"))
            cout << "error";
        //green candy
        if (!ct3.loadFromFile("Green.png"))
            cout << "error";
        //yellow candy
        if (!ct4.loadFromFile("Yellow.png"))
            cout << "error";
        //orange candy
        if (!ct5.loadFromFile("Orange.png"))
            cout << "error";
        //red stripped candy
        if (!ct6.loadFromFile("Striped red.png"))
            cout << "error";
        //blue stripped candy
        if (!ct7.loadFromFile("Striped blue.png"))
            cout << "error";
        //green stripped candy
        if (!ct8.loadFromFile("Striped green.png"))
            cout << "error";
        //yellow stripped candy
        if (!ct9.loadFromFile("Striped yellow.png"))
            cout << "error";
        //orange stripped candy
        if (!ct10.loadFromFile("Striped orange.png"))
            cout << "error";
        //red wrapped candy
        if (!ct11.loadFromFile("Wrapped_red.png"))
            cout << "error";
        //blue wrapped candy
        if (!ct12.loadFromFile("Wrapped_blue.png"))
            cout << "error";
        //green wrapped candy
        if (!ct13.loadFromFile("Wrapped_green.png"))
            cout << "error";
        //yellow wrapped candy
        if (!ct14.loadFromFile("Wrapped_yellow.png"))
            cout << "error";
        //orange wrapped candy
        if (!ct15.loadFromFile("Wrapped_orange.png"))
            cout << "error";
        //color bomb candy
        if (!ct16.loadFromFile("color bomb.png"))
            cout << "error";
        //red stripped candy
        if (!ct17.loadFromFile("Striped_red_h.png"))
            cout << "error";
        //blue stripped candy
        if (!ct18.loadFromFile("Striped_blue_h.png"))
            cout << "error";
        //green stripped candy
        if (!ct19.loadFromFile("Striped_green_h.png"))
            cout << "error";
        //yellow stripped candy
        if (!ct20.loadFromFile("Striped_yellow_h.png"))
            cout << "error";
        //orange stripped candy
        if (!ct21.loadFromFile("Striped_orange_h.png"))
            cout << "error";

        if (swapping_happened == true)
        {
            x = 225.f;
            y = 39.f;
            //loading textures(candies) in shapes -> tiles
            int tiles = 1;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++, tiles++)
                {
                    cout << game_array[i][j] << " ";
                    if (tiles == 1)
                        setTex(t1, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 2)
                        setTex(t2, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 3)
                        setTex(t3, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 4)
                        setTex(t4, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 5)
                        setTex(t5, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 6)
                        setTex(t6, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 7)
                        setTex(t7, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 8)
                        setTex(t8, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 9)
                        setTex(t9, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 10)
                        setTex(t10, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 11)
                        setTex(t11, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 12)
                        setTex(t12, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 13)
                        setTex(t13, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 14)
                        setTex(t14, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 15)
                        setTex(t15, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 16)
                        setTex(t16, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 17)
                        setTex(t17, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 18)
                        setTex(t18, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 19)
                        setTex(t19, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 20)
                        setTex(t20, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 21)
                        setTex(t21, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 22)
                        setTex(t22, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 23)
                        setTex(t23, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 24)
                        setTex(t24, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 25)
                        setTex(t25, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 26)
                        setTex(t26, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 27)
                        setTex(t27, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 28)
                        setTex(t28, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 29)
                        setTex(t29, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 30)
                        setTex(t30, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 31)
                        setTex(t31, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 32)
                        setTex(t32, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 33)
                        setTex(t33, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 34)
                        setTex(t34, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 35)
                        setTex(t35, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 36)
                        setTex(t36, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 37)
                        setTex(t37, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 38)
                        setTex(t38, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 39)
                        setTex(t39, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 40)
                        setTex(t40, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 41)
                        setTex(t41, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 42)
                        setTex(t42, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 43)
                        setTex(t43, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 44)
                        setTex(t44, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 45)
                        setTex(t45, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 46)
                        setTex(t46, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 47)
                        setTex(t47, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 48)
                        setTex(t48, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 49)
                        setTex(t49, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 50)
                        setTex(t50, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 51)
                        setTex(t51, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 52)
                        setTex(t52, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 53)
                        setTex(t53, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 54)
                        setTex(t54, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 55)
                        setTex(t55, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 56)
                        setTex(t56, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 57)
                        setTex(t57, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 58)
                        setTex(t58, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 59)
                        setTex(t59, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 60)
                        setTex(t60, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 61)
                        setTex(t61, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 62)
                        setTex(t62, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 63)
                        setTex(t63, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 64)
                        setTex(t64, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 65)
                        setTex(t65, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 66)
                        setTex(t66, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 67)
                        setTex(t67, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 68)
                        setTex(t68, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 69)
                        setTex(t69, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 70)
                        setTex(t70, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 71)
                        setTex(t71, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 72)
                        setTex(t72, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 73)
                        setTex(t73, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 74)
                        setTex(t74, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 75)
                        setTex(t75, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 76)
                        setTex(t76, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 77)
                        setTex(t77, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 78)
                        setTex(t78, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 79)
                        setTex(t79, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 80)
                        setTex(t80, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                    else if (tiles == 81)
                        setTex(t81, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);

                }
                cout << endl;
            }
            //loading number of moves and score
            score.setString(to_string(current_score));
            moves.setString(to_string(number_of_moves));
            swapping_happened = false;
        }

        //handling events
        Event event;
        while (window.pollEvent(event))
        {
            //event to close the window
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape))
                window.close();

            //checking that if the mouse is over the new game button
            if (isMouseOver(window, new_game_sprite)) {
                new_game_sprite.setSize(Vector2f(196.0831f, 50.9773));
                if (event.mouseButton.button == Mouse::Left)
                {
                    play_button_pressed = true;
                    swapping_possible = false;
                    //randomizing the array
                    for (int row = 0; row < 9; row++)
                    {
                        for (int col = 0; col < 9; col++)
                        {
                            game_array[row][col] = rand() % 5 + 1;
                        }
                    }
                    //removing pairs at the start of the game
                    while (found_match_or_not(game_array))
                    {
                        match_found_and_replace(game_array, row_coordinate_of_candy_to_swap_with, col_coordinate_of_candy_to_swap_with);
                        replacing_used_candies(game_array);
                        empty_Find_Replace(game_array);
                    }
                    //Saving game
                    ofstream fout;
                    fout.open("Load.txt");
                    for (int row = 0; row < 9; row++)
                    {
                        for (int col = 0; col < 9; col++)
                        {
                            fout << game_array[row][col] << endl;
                        }
                    }
                    fout << current_score << endl;
                    fout << number_of_moves;
                }
            }
            else
                new_game_sprite.setSize(Vector2f(176.0831f, 45.9773));

            //checking that if the mouse is over the load game button
            if (isMouseOver(window, load_game_sprite)) {
                load_game_sprite.setSize(Vector2f(226.0831f, 50.9773));
                if (event.mouseButton.button == Mouse::Left)
                {
                    load_game_button_pressed = true;
                    swapping_possible = false;
                    //Loading game
                    ifstream fin;
                    fin.open("Load.txt");
                    if (!fin)
                    {
                        cout << "Error: Cannot open file" << endl;
                    }
                    else
                    {
                        for (int row = 0; row < 9; row++)
                        {
                            for (int col = 0; col < 9; col++)
                            {
                                fin >> game_array[row][col];
                            }
                            cout << endl;
                        }
                        fin >> current_score;
                        fin >> number_of_moves;
                        fin.close();
                    }
                }
            }
            else
                load_game_sprite.setSize(Vector2f(206.0831f, 45.9773));

            //checking that if the mouse is over the save game button
            if (isMouseOver(window, save_game_sprite)) {
                save_game_sprite.setSize(Vector2f(220.0831f, 50.9773));
                if (event.mouseButton.button == Mouse::Left)
                {
                    //Saving game
                    ofstream fout;
                    fout.open("Load.txt");
                    for (int row = 0; row < 9; row++)
                    {
                        for (int col = 0; col < 9; col++)
                        {
                            fout << game_array[row][col] << endl;
                        }
                    }
                    fout << current_score << endl;
                    fout << number_of_moves;
                    fout.close();
                    window.close();
                }
            }
            else
            {
                save_game_sprite.setSize(Vector2f(206.0831f, 45.9773));
            }

            if ((play_button_pressed || load_game_button_pressed) && game_playable)
            {
                //handling keyboard and mouse events
                if (Keyboard::isKeyPressed || Mouse::isButtonPressed)
                {
                    if (number_of_times_mainscreen_shown == 0)
                    {
                        number_of_times_mainscreen_shown++;
                        //loading textures(candies) in shapes -> tiles
                        int tiles = 1;
                        for (int i = 0; i < 9; i++)
                        {
                            for (int j = 0; j < 9; j++, tiles++)
                            {
                                cout << game_array[i][j] << " ";
                                if (tiles == 1)
                                    setTex(t1, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 2)
                                    setTex(t2, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 3)
                                    setTex(t3, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 4)
                                    setTex(t4, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 5)
                                    setTex(t5, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 6)
                                    setTex(t6, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 7)
                                    setTex(t7, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 8)
                                    setTex(t8, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 9)
                                    setTex(t9, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 10)
                                    setTex(t10, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 11)
                                    setTex(t11, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 12)
                                    setTex(t12, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 13)
                                    setTex(t13, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 14)
                                    setTex(t14, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 15)
                                    setTex(t15, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 16)
                                    setTex(t16, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 17)
                                    setTex(t17, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 18)
                                    setTex(t18, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 19)
                                    setTex(t19, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 20)
                                    setTex(t20, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 21)
                                    setTex(t21, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 22)
                                    setTex(t22, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 23)
                                    setTex(t23, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 24)
                                    setTex(t24, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 25)
                                    setTex(t25, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 26)
                                    setTex(t26, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 27)
                                    setTex(t27, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 28)
                                    setTex(t28, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 29)
                                    setTex(t29, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 30)
                                    setTex(t30, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 31)
                                    setTex(t31, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 32)
                                    setTex(t32, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 33)
                                    setTex(t33, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 34)
                                    setTex(t34, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 35)
                                    setTex(t35, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 36)
                                    setTex(t36, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 37)
                                    setTex(t37, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 38)
                                    setTex(t38, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 39)
                                    setTex(t39, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 40)
                                    setTex(t40, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 41)
                                    setTex(t41, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 42)
                                    setTex(t42, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 43)
                                    setTex(t43, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 44)
                                    setTex(t44, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 45)
                                    setTex(t45, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 46)
                                    setTex(t46, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 47)
                                    setTex(t47, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 48)
                                    setTex(t48, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 49)
                                    setTex(t49, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 50)
                                    setTex(t50, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 51)
                                    setTex(t51, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 52)
                                    setTex(t52, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 53)
                                    setTex(t53, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 54)
                                    setTex(t54, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 55)
                                    setTex(t55, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 56)
                                    setTex(t56, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 57)
                                    setTex(t57, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 58)
                                    setTex(t58, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 59)
                                    setTex(t59, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 60)
                                    setTex(t60, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 61)
                                    setTex(t61, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 62)
                                    setTex(t62, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 63)
                                    setTex(t63, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 64)
                                    setTex(t64, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 65)
                                    setTex(t65, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 66)
                                    setTex(t66, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 67)
                                    setTex(t67, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 68)
                                    setTex(t68, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 69)
                                    setTex(t69, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 70)
                                    setTex(t70, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 71)
                                    setTex(t71, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 72)
                                    setTex(t72, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 73)
                                    setTex(t73, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 74)
                                    setTex(t74, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 75)
                                    setTex(t75, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 76)
                                    setTex(t76, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 77)
                                    setTex(t77, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 78)
                                    setTex(t78, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 79)
                                    setTex(t79, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 80)
                                    setTex(t80, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                                else if (tiles == 81)
                                    setTex(t81, tiles, game_array, i, j, x, y, ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14, ct15, ct16, ct17, ct18, ct19, ct20, ct21);
                            }
                            cout << endl;
                        }
                        //loading number of moves and score
                        score.setString(to_string(current_score));
                        moves.setString(to_string(number_of_moves));
                        //loading candies and candy board
                        if (!texture.loadFromFile("home.png"))
                        {
                            cout << "error";
                        }
                        texture.setSmooth(true);
                        sprite.setTexture(texture);
                    }
                }

                //to check mouse over a candy 
                Vector2i position = Mouse::getPosition(window);
                if (event.type == Event::MouseButtonPressed && ((position.x > 220 || position.x < 800) || (position.y > 35 || position.y < 550)))
                {
                    t1.setOutlineThickness(0.f);
                    t2.setOutlineThickness(0.f);
                    t3.setOutlineThickness(0.f);
                    t4.setOutlineThickness(0.f);
                    t5.setOutlineThickness(0.f);
                    t6.setOutlineThickness(0.f);
                    t7.setOutlineThickness(0.f);
                    t8.setOutlineThickness(0.f);
                    t9.setOutlineThickness(0.f);
                    t10.setOutlineThickness(0.f);
                    t11.setOutlineThickness(0.f);
                    t12.setOutlineThickness(0.f);
                    t13.setOutlineThickness(0.f);
                    t14.setOutlineThickness(0.f);
                    t15.setOutlineThickness(0.f);
                    t16.setOutlineThickness(0.f);
                    t17.setOutlineThickness(0.f);
                    t18.setOutlineThickness(0.f);
                    t19.setOutlineThickness(0.f);
                    t20.setOutlineThickness(0.f);
                    t21.setOutlineThickness(0.f);
                    t22.setOutlineThickness(0.f);
                    t23.setOutlineThickness(0.f);
                    t24.setOutlineThickness(0.f);
                    t25.setOutlineThickness(0.f);
                    t26.setOutlineThickness(0.f);
                    t27.setOutlineThickness(0.f);
                    t28.setOutlineThickness(0.f);
                    t29.setOutlineThickness(0.f);
                    t30.setOutlineThickness(0.f);
                    t31.setOutlineThickness(0.f);
                    t32.setOutlineThickness(0.f);
                    t33.setOutlineThickness(0.f);
                    t34.setOutlineThickness(0.f);
                    t35.setOutlineThickness(0.f);
                    t36.setOutlineThickness(0.f);
                    t37.setOutlineThickness(0.f);
                    t38.setOutlineThickness(0.f);
                    t39.setOutlineThickness(0.f);
                    t40.setOutlineThickness(0.f);
                    t41.setOutlineThickness(0.f);
                    t42.setOutlineThickness(0.f);
                    t43.setOutlineThickness(0.f);
                    t44.setOutlineThickness(0.f);
                    t45.setOutlineThickness(0.f);
                    t46.setOutlineThickness(0.f);
                    t47.setOutlineThickness(0.f);
                    t48.setOutlineThickness(0.f);
                    t49.setOutlineThickness(0.f);
                    t50.setOutlineThickness(0.f);
                    t51.setOutlineThickness(0.f);
                    t52.setOutlineThickness(0.f);
                    t53.setOutlineThickness(0.f);
                    t54.setOutlineThickness(0.f);
                    t55.setOutlineThickness(0.f);
                    t56.setOutlineThickness(0.f);
                    t57.setOutlineThickness(0.f);
                    t58.setOutlineThickness(0.f);
                    t59.setOutlineThickness(0.f);
                    t60.setOutlineThickness(0.f);
                    t61.setOutlineThickness(0.f);
                    t62.setOutlineThickness(0.f);
                    t63.setOutlineThickness(0.f);
                    t64.setOutlineThickness(0.f);
                    t65.setOutlineThickness(0.f);
                    t66.setOutlineThickness(0.f);
                    t67.setOutlineThickness(0.f);
                    t68.setOutlineThickness(0.f);
                    t69.setOutlineThickness(0.f);
                    t70.setOutlineThickness(0.f);
                    t71.setOutlineThickness(0.f);
                    t72.setOutlineThickness(0.f);
                    t73.setOutlineThickness(0.f);
                    t74.setOutlineThickness(0.f);
                    t75.setOutlineThickness(0.f);
                    t76.setOutlineThickness(0.f);
                    t77.setOutlineThickness(0.f);
                    t78.setOutlineThickness(0.f);
                    t79.setOutlineThickness(0.f);
                    t80.setOutlineThickness(0.f);
                    t81.setOutlineThickness(0.f);
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        displayCursor(window, t1, event);
                        displayCursor(window, t2, event);
                        displayCursor(window, t3, event);
                        displayCursor(window, t4, event);
                        displayCursor(window, t5, event);
                        displayCursor(window, t6, event);
                        displayCursor(window, t7, event);
                        displayCursor(window, t8, event);
                        displayCursor(window, t9, event);
                        displayCursor(window, t10, event);
                        displayCursor(window, t11, event);
                        displayCursor(window, t12, event);
                        displayCursor(window, t13, event);
                        displayCursor(window, t14, event);
                        displayCursor(window, t15, event);
                        displayCursor(window, t16, event);
                        displayCursor(window, t17, event);
                        displayCursor(window, t18, event);
                        displayCursor(window, t19, event);
                        displayCursor(window, t20, event);
                        displayCursor(window, t21, event);
                        displayCursor(window, t22, event);
                        displayCursor(window, t23, event);
                        displayCursor(window, t24, event);
                        displayCursor(window, t25, event);
                        displayCursor(window, t26, event);
                        displayCursor(window, t27, event);
                        displayCursor(window, t28, event);
                        displayCursor(window, t29, event);
                        displayCursor(window, t30, event);
                        displayCursor(window, t31, event);
                        displayCursor(window, t32, event);
                        displayCursor(window, t33, event);
                        displayCursor(window, t34, event);
                        displayCursor(window, t35, event);
                        displayCursor(window, t36, event);
                        displayCursor(window, t37, event);
                        displayCursor(window, t38, event);
                        displayCursor(window, t39, event);
                        displayCursor(window, t40, event);
                        displayCursor(window, t41, event);
                        displayCursor(window, t42, event);
                        displayCursor(window, t43, event);
                        displayCursor(window, t44, event);
                        displayCursor(window, t45, event);
                        displayCursor(window, t46, event);
                        displayCursor(window, t47, event);
                        displayCursor(window, t48, event);
                        displayCursor(window, t49, event);
                        displayCursor(window, t50, event);
                        displayCursor(window, t51, event);
                        displayCursor(window, t52, event);
                        displayCursor(window, t53, event);
                        displayCursor(window, t54, event);
                        displayCursor(window, t55, event);
                        displayCursor(window, t56, event);
                        displayCursor(window, t57, event);
                        displayCursor(window, t58, event);
                        displayCursor(window, t59, event);
                        displayCursor(window, t60, event);
                        displayCursor(window, t61, event);
                        displayCursor(window, t62, event);
                        displayCursor(window, t63, event);
                        displayCursor(window, t64, event);
                        displayCursor(window, t65, event);
                        displayCursor(window, t66, event);
                        displayCursor(window, t67, event);
                        displayCursor(window, t68, event);
                        displayCursor(window, t69, event);
                        displayCursor(window, t70, event);
                        displayCursor(window, t71, event);
                        displayCursor(window, t72, event);
                        displayCursor(window, t73, event);
                        displayCursor(window, t74, event);
                        displayCursor(window, t75, event);
                        displayCursor(window, t76, event);
                        displayCursor(window, t77, event);
                        displayCursor(window, t78, event);
                        displayCursor(window, t79, event);
                        displayCursor(window, t80, event);
                        displayCursor(window, t81, event);
                        if (swapping_possible == false)
                        {
                            if (isMouseOver(window, t1))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t2))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t3))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t4))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t5))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t6))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t7))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t8))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t9))
                            {
                                row_coordinate_of_candy = 0;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t10))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t11))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t12))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t13))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t14))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t15))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t16))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t17))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t18))
                            {
                                row_coordinate_of_candy = 1;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t19))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t20))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t21))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t22))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t23))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t24))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t25))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t26))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t27))
                            {
                                row_coordinate_of_candy = 2;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t28))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t29))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t30))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t31))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t32))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t33))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t34))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t35))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t36))
                            {
                                row_coordinate_of_candy = 3;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t37))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t38))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t39))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t40))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t41))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t42))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t43))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t44))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t45))
                            {
                                row_coordinate_of_candy = 4;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t46))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t47))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t48))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t49))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t50))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t51))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t52))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t53))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t54))
                            {
                                row_coordinate_of_candy = 5;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t55))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t56))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t57))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t58))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t59))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t60))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t61))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t62))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t63))
                            {
                                row_coordinate_of_candy = 6;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t64))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t65))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t66))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t67))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t68))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t69))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t70))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t71))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t72))
                            {
                                row_coordinate_of_candy = 7;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t73))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 0;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t74))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 1;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t75))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 2;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t76))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 3;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t77))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 4;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t78))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 5;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t79))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 6;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t80))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 7;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                            else if (isMouseOver(window, t81))
                            {
                                row_coordinate_of_candy = 8;
                                col_coordinate_of_candy = 8;
                                swapping_possible = true;
                                swapping_happened = false;
                            }
                        }
                        else if (swapping_possible == true)
                        {
                            if (isMouseOver(window, t1)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t2)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t3)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t4)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t5)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t6)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t7)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t8)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t9)) {
                                row_coordinate_of_candy_to_swap_with = 0;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            else if (isMouseOver(window, t10)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t11)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t12)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t13)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t14)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t15)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t16)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t17)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t18)) {
                                row_coordinate_of_candy_to_swap_with = 1;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            else if (isMouseOver(window, t19)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t20)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t21)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t22)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t23)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t24)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t25)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t26)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t27)) {
                                row_coordinate_of_candy_to_swap_with = 2;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            else if (isMouseOver(window, t28)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t29)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t30)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t31)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t32)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t33)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t34)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t35)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t36)) {
                                row_coordinate_of_candy_to_swap_with = 3;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            else if (isMouseOver(window, t37)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t38)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t39)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t40)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t41)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t42)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t43)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t44)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t45)) {
                                row_coordinate_of_candy_to_swap_with = 4;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            else if (isMouseOver(window, t46)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t47)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t48)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t49)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t50)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t51)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t52)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t53)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t54)) {
                                row_coordinate_of_candy_to_swap_with = 5;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            else if (isMouseOver(window, t55)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t56)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t57)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t58)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t59)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t60)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t61)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t62)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t63)) {
                                row_coordinate_of_candy_to_swap_with = 6;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            else if (isMouseOver(window, t64)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t65)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t66)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t67)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t68)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t69)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t70)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t71)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t72)) {
                                row_coordinate_of_candy_to_swap_with = 7;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            else if (isMouseOver(window, t73)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 0;
                            }
                            else if (isMouseOver(window, t74)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 1;
                            }
                            else if (isMouseOver(window, t75)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 2;
                            }
                            else if (isMouseOver(window, t76)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 3;
                            }
                            else if (isMouseOver(window, t77)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 4;
                            }
                            else if (isMouseOver(window, t78)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 5;
                            }
                            else if (isMouseOver(window, t79)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 6;
                            }
                            else if (isMouseOver(window, t80)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 7;
                            }
                            else if (isMouseOver(window, t81)) {
                                row_coordinate_of_candy_to_swap_with = 8;
                                col_coordinate_of_candy_to_swap_with = 8;
                            }
                            if ((row_coordinate_of_candy == row_coordinate_of_candy_to_swap_with) || (col_coordinate_of_candy == col_coordinate_of_candy_to_swap_with)
                                && swapping_possible)
                            {
                                swap_by_input(game_array, row_coordinate_of_candy, col_coordinate_of_candy, row_coordinate_of_candy_to_swap_with,
                                    col_coordinate_of_candy_to_swap_with);
                                if (found_match_or_not(game_array))
                                {
                                    while (found_match_or_not(game_array))
                                    {
                                        match_found_and_replace(game_array, row_coordinate_of_candy_to_swap_with, row_coordinate_of_candy_to_swap_with);
                                        replacing_used_candies(game_array);
                                        empty_Find_Replace(game_array);
                                        current_score += 30;
                                        if (current_score >= 1000) {
                                            game_playable = false;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    game_rules(game_array, row_coordinate_of_candy, col_coordinate_of_candy, col_coordinate_of_candy_to_swap_with,
                                        row_coordinate_of_candy_to_swap_with);
                                    replacing_used_candies(game_array);
                                    empty_Find_Replace(game_array);
                                    while (found_match_or_not(game_array))
                                    {
                                        match_found_and_replace(game_array, row_coordinate_of_candy_to_swap_with, row_coordinate_of_candy_to_swap_with);
                                        replacing_used_candies(game_array);
                                        empty_Find_Replace(game_array);
                                    }
                                    current_score += 30;
                                    if (current_score >= 1000) {
                                        game_playable = false;
                                        break;
                                    }
                                }
                                number_of_moves--;
                                if (number_of_moves <= 0)
                                {
                                    game_playable = false;
                                    break;
                                }
                                swapping_happened = true;
                                swapping_possible = false;
                            }
                        }
                    }
                }
            }
            else if (game_playable == false)
            {
                if (current_score >= 1000 && number_of_moves >= 0)
                {
                    //loading you won screen
                    if (!texture.loadFromFile("you won.png"))
                    {
                        cout << "error";
                    }
                    texture.setSmooth(true);
                    sprite.setTexture(texture);
                }
                else if (current_score < 1000 || number_of_moves < 0)
                {
                    //loading you lost screen
                    if (!texture.loadFromFile("you lost.png"))
                    {
                        cout << "error";
                    }
                    texture.setSmooth(true);
                    sprite.setTexture(texture);
                }
            }
        }
        //displaying mainscreen untill user presses any key
        if (number_of_times_mainscreen_shown == 0)
        {
            window.clear();
            window.draw(sprite);
            window.draw(new_game_sprite);
            window.draw(load_game_sprite);
            window.display();
        }

        //displaying homescreen and other stuff like candies and text etc..
        else if (number_of_times_mainscreen_shown != 0 && game_playable)
        {
            window.clear();
            window.draw(sprite);
            window.draw(targetscore);
            window.draw(score);
            window.draw(moves);
            window.draw(save_game_sprite);
            window.draw(t1);
            window.draw(t2);
            window.draw(t3);
            window.draw(t4);
            window.draw(t5);
            window.draw(t6);
            window.draw(t7);
            window.draw(t8);
            window.draw(t9);
            window.draw(t10);
            window.draw(t11);
            window.draw(t12);
            window.draw(t13);
            window.draw(t14);
            window.draw(t15);
            window.draw(t16);
            window.draw(t17);
            window.draw(t18);
            window.draw(t19);
            window.draw(t20);
            window.draw(t21);
            window.draw(t22);
            window.draw(t23);
            window.draw(t24);
            window.draw(t25);
            window.draw(t26);
            window.draw(t27);
            window.draw(t28);
            window.draw(t29);
            window.draw(t30);
            window.draw(t31);
            window.draw(t32);
            window.draw(t33);
            window.draw(t34);
            window.draw(t35);
            window.draw(t36);
            window.draw(t37);
            window.draw(t38);
            window.draw(t39);
            window.draw(t40);
            window.draw(t41);
            window.draw(t42);
            window.draw(t43);
            window.draw(t44);
            window.draw(t45);
            window.draw(t46);
            window.draw(t47);
            window.draw(t48);
            window.draw(t49);
            window.draw(t50);
            window.draw(t51);
            window.draw(t52);
            window.draw(t53);
            window.draw(t54);
            window.draw(t55);
            window.draw(t56);
            window.draw(t57);
            window.draw(t58);
            window.draw(t59);
            window.draw(t60);
            window.draw(t61);
            window.draw(t62);
            window.draw(t63);
            window.draw(t64);
            window.draw(t65);
            window.draw(t66);
            window.draw(t67);
            window.draw(t68);
            window.draw(t69);
            window.draw(t70);
            window.draw(t71);
            window.draw(t72);
            window.draw(t73);
            window.draw(t74);
            window.draw(t75);
            window.draw(t76);
            window.draw(t77);
            window.draw(t78);
            window.draw(t79);
            window.draw(t80);
            window.draw(t81);
            window.display();
        }
        else if (!game_playable)
        {
            window.clear();
            window.draw(sprite);
            window.display();
        }
    }
}
