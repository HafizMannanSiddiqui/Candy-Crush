#pragma once
#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Candyfunctions.h"
#include "Button.h"
#include <time.h>
#include <sstream>
#pragma warning(disable : 4996)
using namespace sf;
using namespace std;

void func(int x, int y);
void intializing(int array[1000][10]);
void clickingcandies(Button btn00, Button btn01, Button btn02, Button btn03, Button btn04, Button btn05, Button btn06,
                     Button btn07, Button btn08, Button btn09, Button btn10, Button btn11, Button btn12, Button btn13, Button btn14,
                     Button btn15, Button btn16, Button btn17, Button btn18, Button btn19, Button btn20, Button btn21, Button btn22,
                     Button btn23, Button btn24, Button btn25, Button btn26, Button btn27, Button btn28, Button btn29, Button btn30,
                     Button btn31, Button btn32, Button btn33, Button btn34, Button btn35, Button btn36, Button btn37, Button btn38,
                     Button btn39, Button btn40, Button btn41, Button btn42, Button btn43, Button btn44, Button btn45, Button btn46,
                     Button btn47, Button btn48, Button btn49, Button btn50, Button btn51, Button btn52, Button btn53, Button btn54,
                     Button btn55, Button btn56, Button btn57, Button btn58, Button btn59, Button btn60, Button btn61, Button btn62,
                     Button btn63, Button btn64, Button btn65, Button btn66, Button btn67, Button btn68, Button btn69, Button btn70,
                     Button btn71, Button btn72, Button btn73, Button btn74, Button btn75, Button btn76, Button btn77, Button btn78,
                     Button btn79, Button btn80, Button btn81, Button btn82, Button btn83, Button btn84, Button btn85, Button btn86,
                     Button btn87, Button btn88, Button btn89, Button btn90, Button btn91, Button btn92, Button btn93, Button btn94,
                     Button btn95, Button btn96, Button btn97, Button btn98, Button btn99, int count, int &row_val, int &col_val,
                     int &rowswap, int &colswap, RenderWindow &window);

void outputarray(int array[1000][10]);
void swap1(int array[1000][10], int &row_val, int &col_val, int &rowswap, int &colswap, int &swapdone, int &swapfail);
void CandyMatchAndScore(int array[1000][10], int &ScoreAdded, int &TotalScore);
void THREECANDIESCRUSH(int array[1000][10]);
void INITIALSWAP(int array[1000][10]);

void func(int x, int y)
{
    cout << "olaalalalalal";
}

void intializing(int array[1000][10])
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[i][j] = rand() % 5;
        }
    }
}

void clickingcandies(Button btn00, Button btn01, Button btn02, Button btn03, Button btn04, Button btn05, Button btn06,
                     Button btn07, Button btn08, Button btn09, Button btn10, Button btn11, Button btn12, Button btn13, Button btn14,
                     Button btn15, Button btn16, Button btn17, Button btn18, Button btn19, Button btn20, Button btn21, Button btn22,
                     Button btn23, Button btn24, Button btn25, Button btn26, Button btn27, Button btn28, Button btn29, Button btn30,
                     Button btn31, Button btn32, Button btn33, Button btn34, Button btn35, Button btn36, Button btn37, Button btn38,
                     Button btn39, Button btn40, Button btn41, Button btn42, Button btn43, Button btn44, Button btn45, Button btn46,
                     Button btn47, Button btn48, Button btn49, Button btn50, Button btn51, Button btn52, Button btn53, Button btn54,
                     Button btn55, Button btn56, Button btn57, Button btn58, Button btn59, Button btn60, Button btn61, Button btn62,
                     Button btn63, Button btn64, Button btn65, Button btn66, Button btn67, Button btn68, Button btn69, Button btn70,
                     Button btn71, Button btn72, Button btn73, Button btn74, Button btn75, Button btn76, Button btn77, Button btn78,
                     Button btn79, Button btn80, Button btn81, Button btn82, Button btn83, Button btn84, Button btn85, Button btn86,
                     Button btn87, Button btn88, Button btn89, Button btn90, Button btn91, Button btn92, Button btn93, Button btn94,
                     Button btn95, Button btn96, Button btn97, Button btn98, Button btn99, int count, int &row_val, int &col_val,
                     int &rowswap, int &colswap, RenderWindow &window)

{
    cout << "count=" << count << endl;

    if (btn00.isMouseOver(window))
    {

        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 0;
        }
    }

    if (btn01.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 1;
        }
    }

    if (btn02.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 2;
        }
    }
    if (btn03.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 3;
        }
    }
    if (btn04.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 4;
        }
    }
    if (btn05.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 5;
        }
    }
    if (btn06.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 6;
        }
    }
    if (btn07.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 7;
        }
    }

    if (btn08.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 8;
        }
    }
    if (btn09.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 700;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 700;
            colswap = 9;
        }
    }

    if (btn10.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 0;
        }
    }

    if (btn11.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 1;
        }
    }

    if (btn12.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 2;
        }
    }
    if (btn13.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 3;
        }
    }
    if (btn14.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 4;
        }
    }
    if (btn15.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 5;
        }
    }
    if (btn16.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 6;
        }
    }
    if (btn17.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 7;
        }
    }
    if (btn18.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 8;
        }
    }
    if (btn19.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 701;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 701;
            colswap = 9;
        }
    }

    if (btn20.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 0;
        }
    }

    if (btn21.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 1;
        }
    }

    if (btn22.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 2;
        }
    }

    if (btn23.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 3;
        }
    }
    if (btn24.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 4;
        }
    }
    if (btn25.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 5;
        }
    }
    if (btn26.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 6;
        }
    }
    if (btn27.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 7;
        }
    }
    if (btn28.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 8;
        }
    }
    if (btn29.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 702;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 702;
            colswap = 9;
        }
    }

    if (btn30.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 0;
        }
    }
    if (btn31.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 1;
        }
    }
    if (btn32.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 2;
        }
    }
    if (btn33.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 3;
        }
    }
    if (btn34.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 4;
        }
    }
    if (btn35.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 5;
        }
    }
    if (btn36.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 6;
        }
    }
    if (btn37.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 7;
        }
    }
    if (btn38.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 8;
        }
    }
    if (btn39.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 703;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 703;
            colswap = 9;
        }
    }

    if (btn40.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 0;
        }
    }
    if (btn41.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 1;
        }
    }
    if (btn42.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 2;
        }
    }
    if (btn43.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 3;
        }
    }
    if (btn44.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 4;
        }
    }
    if (btn45.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 5;
        }
    }
    if (btn46.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 6;
        }
    }
    if (btn47.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 7;
        }
    }
    if (btn48.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 8;
        }
    }
    if (btn49.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 704;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 704;
            colswap = 9;
        }
    }
    if (btn50.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 0;
        }
    }
    if (btn51.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 1;
        }
    }
    if (btn52.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 2;
        }
    }
    if (btn53.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 3;
        }
    }
    if (btn54.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 4;
        }
    }
    if (btn55.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 5;
        }
    }
    if (btn56.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 6;
        }
    }
    if (btn57.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 7;
        }
    }
    if (btn58.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 8;
        }
    }
    if (btn59.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 705;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 705;
            colswap = 9;
        }
    }
    if (btn60.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 0;
        }
    }
    if (btn61.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 1;
        }
    }
    if (btn62.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 2;
        }
    }
    if (btn63.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 3;
        }
    }
    if (btn64.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 4;
        }
    }
    if (btn65.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 5;
        }
    }
    if (btn66.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 6;
        }
    }
    if (btn67.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 7;
        }
    }
    if (btn68.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 8;
        }
    }

    if (btn69.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 706;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 706;
            colswap = 9;
        }
    }

    if (btn70.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 0;
        }
    }

    if (btn71.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 1;
        }
    }

    if (btn72.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 2;
        }
    }

    if (btn73.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 3;
        }
    }
    if (btn74.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 4;
        }
    }

    if (btn75.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 5;
        }
    }
    if (btn76.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 6;
        }
    }

    if (btn77.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 7;
        }
    }

    if (btn78.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 8;
        }
    }

    if (btn79.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 707;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 707;
            colswap = 9;
        }
    }
    if (btn80.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 0;
        }
    }
    if (btn81.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 1;
        }
    }
    if (btn82.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 2;
        }
    }
    if (btn83.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 3;
        }
    }
    if (btn84.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 4;
        }
    }
    if (btn85.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 5;
        }
    }
    if (btn86.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 6;
        }
    }
    if (btn87.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 7;
        }
    }
    if (btn88.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 8;
        }
    }
    if (btn88.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 8;
        }
    }
    if (btn89.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 708;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 708;
            colswap = 9;
        }
    }
    if (btn90.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 0;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 0;
        }
    }
    if (btn91.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 1;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 1;
        }
    }
    if (btn92.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 2;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 2;
        }
    }
    if (btn93.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 3;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 3;
        }
    }
    if (btn94.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 4;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 4;
        }
    }
    if (btn95.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 5;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 5;
        }
    }
    if (btn96.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 6;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 6;
        }
    }
    if (btn97.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 7;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 7;
        }
    }
    if (btn98.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 8;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 8;
        }
    }
    if (btn99.isMouseOver(window))
    {
        if (count % 2 != 0)
        {
            row_val = 709;
            col_val = 9;
        }
        if (count % 2 == 0)
        {
            rowswap = 709;
            colswap = 9;
        }
    }
}

void outputarray(int array[1000][10])
{
    for (int j = 0; j < 1000; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
}

void swap1(int array[1000][10], int &row_val, int &col_val, int &rowswap, int &colswap, int &swapdone, int &swapfail)
{
    if (rowswap > -1 && colswap > -1 && row_val > -1 && col_val > -1)
    {
        if ((row_val == rowswap && colswap == (col_val + 1)) || (row_val == rowswap && colswap == (col_val - 1)) || (col_val == colswap && rowswap == (row_val - 1)) || (col_val == colswap && rowswap == (row_val + 1)))
        {
            cout << "yes";
            int swap = array[row_val][col_val];
            array[row_val][col_val] = array[rowswap][colswap];
            array[rowswap][colswap] = swap;
            swapdone = 1;

            if (swapdone == 1)

            {
                if ((array[row_val][col_val] == array[row_val + 1][col_val] && array[row_val][col_val] == array[row_val + 2][col_val]) || (array[row_val][col_val] == array[row_val - 1][col_val] && array[row_val][col_val] == array[row_val - 2][col_val]) || (array[row_val][col_val] == array[row_val + 1][col_val] && array[row_val][col_val] == array[row_val - 1][col_val])

                    || (array[row_val][col_val] == array[row_val][col_val + 1] && array[row_val][col_val] == array[row_val][col_val + 2]) || (array[row_val][col_val] == array[row_val][col_val - 1] && array[row_val][col_val] == array[row_val][col_val - 2]) || (array[row_val][col_val] == array[row_val][col_val - 1] && array[row_val][col_val] == array[row_val][col_val + 1])

                    || (array[rowswap][colswap] == array[rowswap + 1][colswap] && array[rowswap][colswap] == array[rowswap + 2][colswap]) || (array[rowswap][colswap] == array[rowswap - 1][colswap] && array[rowswap][colswap] == array[rowswap - 2][colswap]) || (array[rowswap][colswap] == array[rowswap + 1][colswap] && array[rowswap][colswap] == array[rowswap - 1][colswap])

                    || (array[rowswap][colswap] == array[rowswap][colswap + 1] && array[rowswap][colswap] == array[rowswap][colswap + 2]) || (array[rowswap][colswap] == array[rowswap][colswap - 1] && array[rowswap][colswap] == array[rowswap][colswap - 2]) || (array[rowswap][colswap] == array[rowswap][colswap - 1] && array[rowswap][colswap] == array[rowswap][colswap + 1]))

                {
                    swapfail = 0;
                }
                else
                {
                    swapfail = 1;
                    cout << "false";
                    int temp = array[row_val][col_val];
                    array[row_val][col_val] = array[rowswap][colswap];
                    array[rowswap][colswap] = temp;
                }
            }
            swapdone = 1;
            row_val = -1;
            col_val = -1;
            rowswap = -1;
            colswap = -1;
        }
    }
}

void CandyMatchAndScore(int array[1000][10], int &ScoreAdded, int &TotalScore)
{

    // this is to remove same value before 700 row
    // check1
    // for (int x = 690; x < 700; x++)
    //{
    //     for (int y = 0; y < 10; y++)
    //     {
    //         if ((array[x][y] == array[x][y + 1] && array[x][y] == array[x][y + 2]))
    //         {
    //             array[x][y] = 1;
    //             array[x][y + 1] = 3;
    //             array[x][y + 2] = 4;

    //        }
    //        else if((array[x][y] == array[x + 1][y] && array[x][y] == array[x + 2][y]))
    //        {
    //            array[x][y] = 0;
    //            array[x + 1][y] = 3;
    //            array[x + 2][y] = 2;
    //        }
    //    }
    //}
    ////check2 agin
    // for (int x = 690; x < 700; x++)
    //{
    //     for (int y = 0; y < 10; y++)
    //     {
    //         if ((array[x][y] == array[x][y + 1] && array[x][y] == array[x][y + 2]))
    //         {
    //             array[x][y] = 1;
    //             array[x][y + 1] = 3;
    //             array[x][y + 2] = 4;

    //        }
    //        else if ((array[x][y] == array[x + 1][y] && array[x][y] == array[x + 2][y]))
    //        {
    //            array[x][y] = 0;
    //            array[x + 1][y] = 3;
    //            array[x + 2][y] = 2;
    //        }
    //    }
    //}

    for (int i = 0; i < 10; i++)
    {
        for (int j = 700; j < 710; j++)
        {
            if (true)
            {
                if ((array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j][i + 1] && array[j][i] == array[j][i + 2] && j < 708))
                {
                    array[j + 1][i] = -201;
                    array[j + 2][i] = -202;
                    array[j][i + 1] = -203;
                    array[j][i + 2] = -204;
                }

                if ((array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j][i - 1] && array[j][i] == array[j][i - 2] && j < 708))
                {
                    array[j + 1][i] = -205;
                    array[j + 2][i] = -206;
                    array[j][i - 1] = -207;
                    array[j][i - 2] = -208;
                }

                if ((array[j][i] == array[j - 1][i] && array[j][i] == array[j - 2][i] && array[j][i] == array[j][i + 1] && array[j][i] == array[j][i + 2] && j > 701))
                {
                    array[j - 1][i] = -209;
                    array[j - 2][i] = -210;
                    array[j][i + 1] = -211;
                    array[j][i + 2] = -212;
                }

                if ((array[j][i] == array[j - 1][i] && array[j][i] == array[j - 2][i] && array[j][i] == array[j][i - 1] && array[j][i] == array[j][i - 2] && j > 701))
                {
                    array[j - 1][i] = -217;
                    array[j - 2][i] = -218;
                    array[j][i - 1] = -219;
                    array[j][i - 2] = -220;
                }

                if ((array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j][i - 1] && array[j][i] == array[j][i + 1] && j < 708))
                {
                    array[j + 1][i] = -213;
                    array[j + 2][i] = -214;
                    array[j][i - 1] = -215;
                    array[j][i + 1] = -216;
                }
                if ((array[j][i] == array[j - 1][i] && array[j][i] == array[j - 2][i] && array[j][i] == array[j][i - 1] && array[j][i] == array[j][i + 1] && j > 701))
                {
                    array[j - 1][i] = -221;
                    array[j - 2][i] = -222;
                    array[j][i - 1] = -223;
                    array[j][i + 1] = -224;
                }
                if ((array[j][i] == array[j - 1][i] && array[j][i] == array[j + 1][i] && array[j][i] == array[j][i + 1] && array[j][i] == array[j][i + 2] && j > 700))
                {
                    array[j - 1][i] = -225;
                    array[j + 1][i] = -226;
                    array[j][i + 1] = -227;
                    array[j][i + 2] = -228;
                }
                if ((array[j][i] == array[j - 1][i] && array[j][i] == array[j + 1][i] && array[j][i] == array[j][i - 1] && array[j][i] == array[j][i - 2] && j > 700))
                {
                    array[j - 1][i] = -225;
                    array[j + 1][i] = -226;
                    array[j][i - 1] = -227;
                    array[j][i - 2] = -228;
                }
                if (array[j][i] == 0)
                {
                    array[j][i] = 30;
                    ScoreAdded = 50 * 6;
                }
                else if (array[j][i] == 1)
                {
                    array[j][i] = 31;
                    ScoreAdded = 30 * 6;
                }
                else if (array[j][i] == 2)
                {
                    array[j][i] = 32;
                    ScoreAdded = 60 * 6;
                }
                else if (array[j][i] == 3)
                {
                    array[j][i] = 33;
                    ScoreAdded = 40 * 6;
                }
                else if (array[j][i] == 4)
                {
                    array[j][i] = 34;
                    ScoreAdded = 30 * 6;
                }
            }
            else if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] != array[j + 3][i])
            {
                // CANDIES SIMILAR IN COLUMN
                // BLUE CANDY 0
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == 0)
                {
                    array[j][i] = -1;
                    array[j + 1][i] = -2;
                    array[j + 2][i] = -3;
                    ScoreAdded = 150;
                }
                // RED CANDY 1
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == 1)
                {
                    array[j][i] = -4;
                    array[j + 1][i] = -5;
                    array[j + 2][i] = -6;
                    ScoreAdded = 90;
                }
                // ORANGE CANDY 2
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == 2)
                {
                    array[j][i] = -7;
                    array[j + 1][i] = -8;
                    array[j + 2][i] = -9;
                    ScoreAdded = 180;
                }
                // GREEN CANDY 3
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == 3)
                {
                    array[j][i] = -10;
                    array[j + 1][i] = -11;
                    array[j + 2][i] = -12;
                    ScoreAdded = 120;
                }
                // YELlOW CANDY 4
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == 4)
                {
                    cout << "yellow" << endl;
                    array[j][i] = -13;
                    array[j + 1][i] = -14;
                    array[j + 2][i] = -15;
                    ScoreAdded = 90;
                }
            }

            // FOUR SIMILAR CANDIES in column
            if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j + 3][i] && array[j][i] != array[j + 4][i])
            {
                // four blue candies
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j + 3][i] && array[j][i] == 0)
                {
                    array[j][i] = 10;
                    array[j + 1][i] = -16;
                    array[j + 2][i] = -17;
                    array[j + 3][i] = -18;
                    ScoreAdded = 200;
                }

                // four red candies
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j + 3][i] && array[j][i] == 1)
                {
                    array[j][i] = 11;
                    array[j + 1][i] = -19;
                    array[j + 2][i] = -20;
                    array[j + 3][i] = -21;
                    ScoreAdded = 120;
                }
                // four orange candies
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j + 3][i] && array[j][i] == 2)
                {
                    array[j][i] = 12;
                    array[j + 1][i] = -22;
                    array[j + 2][i] = -23;
                    array[j + 3][i] = -24;
                    ScoreAdded = 240;
                }

                // four green candies
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j + 3][i] && array[j][i] == 3)
                {
                    array[j][i] = 13;
                    array[j + 1][i] = -26;
                    array[j + 2][i] = -27;
                    array[j + 3][i] = -28;
                    ScoreAdded = 160;
                }

                // four yellow candies
                if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j + 3][i] && array[j][i] == 4)
                {
                    array[j][i] = 14;
                    array[j + 1][i] = -26;
                    array[j + 2][i] = -27;
                    array[j + 3][i] = -28;
                    ScoreAdded = 120;
                }
            }

            // FIVE SIMILAR CANDIES in column
            if (array[j][i] == array[j + 1][i] && array[j][i] == array[j + 2][i] && array[j][i] == array[j + 3][i] && array[j][i] == array[j + 4][i])
            {
                if (array[j][i] == 0)
                    ScoreAdded = 50 * 5;
                else if (array[j][i] == 1)
                    ScoreAdded = 90 * 5;
                else if (array[j][i] == 2)
                    ScoreAdded = 60 * 5;
                else if (array[j][i] == 3)
                    ScoreAdded = 40 * 5;
                else if (array[j][i] == 4)
                    ScoreAdded = 30 * 5;

                array[j][i] = 9;
                array[j + 1][i] = -29;
                array[j + 2][i] = -30;
                array[j + 3][i] = -31;
                array[j + 4][i] = -32;
            }
        }
    }

    for (int r = 700; r < 710; r++)
    {
        for (int c = 0; c < 10; c++)
        {

            if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] != array[r][c + 3])
            {
                // blue
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == 0)
                {
                    array[r][c] = -40;
                    array[r][c + 1] = -41;
                    array[r][c + 2] = -42;
                    ScoreAdded = 150;
                }

                // red
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == 1)
                {
                    array[r][c] = -43;
                    array[r][c + 1] = -44;
                    array[r][c + 2] = -45;
                    ScoreAdded = 90;
                }

                // orange
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == 2)
                {
                    array[r][c] = -47;
                    array[r][c + 1] = -48;
                    array[r][c + 2] = -46;
                    ScoreAdded = 180;
                }

                // green
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == 3)
                {
                    array[r][c] = -43;
                    array[r][c + 1] = -44;
                    array[r][c + 2] = -45;
                    ScoreAdded = 120;
                }

                // yellow
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == 4)
                {
                    cout << "yellow" << endl;
                    array[r][c] = -49;
                    array[r][c + 1] = -50;
                    array[r][c + 2] = -51;
                    ScoreAdded = 90;
                }
            }
            if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == array[r][c + 3] && array[r][c] != array[r][c + 4])
            {
                // blue
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == array[r][c + 3] && array[r][c] == 0)
                {
                    array[r][c] = 20;
                    array[r][c + 1] = -53;
                    array[r][c + 2] = -54;
                    array[r][c + 3] = -55;
                    ScoreAdded = 50 * 4;
                }
                // red
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == array[r][c + 3] && array[r][c] == 1)
                {
                    array[r][c] = 21;
                    array[r][c + 1] = -56;
                    array[r][c + 2] = -57;
                    array[r][c + 3] = -58;
                    ScoreAdded = 30 * 4;
                }
                // orange
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == array[r][c + 3] && array[r][c] == 2)
                {
                    array[r][c] = 22;
                    array[r][c + 1] = -59;
                    array[r][c + 2] = -60;
                    array[r][c + 3] = -61;
                    ScoreAdded = 60 * 4;
                }
                // green
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == array[r][c + 3] && array[r][c] == 3)
                {
                    array[r][c] = 23;
                    array[r][c + 1] = -62;
                    array[r][c + 2] = -63;
                    array[r][c + 3] = -64;
                    ScoreAdded = 40 * 4;
                }

                // yellow
                if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == array[r][c + 3] && array[r][c] == 3)
                {
                    array[r][c] = 24;
                    array[r][c + 1] = -65;
                    array[r][c + 2] = -66;
                    array[r][c + 3] = -67;
                    ScoreAdded = 30 * 4;
                }
            }

            if (array[r][c] == array[r][c + 1] && array[r][c] == array[r][c + 2] && array[r][c] == array[r][c + 3] && array[r][c] == array[r][c + 4])
            {
                if (array[r][c] == 0)
                    ScoreAdded = 50 * 5;
                else if (array[r][c] == 1)
                    ScoreAdded = 90 * 5;
                else if (array[r][c] == 2)
                    ScoreAdded = 60 * 5;
                else if (array[r][c] == 3)
                    ScoreAdded = 40 * 5;
                else if (array[r][c] == 4)
                    ScoreAdded = 30 * 5;

                array[r][c] = -72;
                array[r][c + 1] = -71;
                array[r][c + 2] = 9;
                array[r][c + 3] = -73;
                array[r][c + 4] = -74;
            }
        }
    }

    // checking three candies again

    // for (int j = 0; j < 10; j++)
    //{
    //     for (int i = 700; i < 710; i++)
    //     {
    //         if (array[i][j] == array[i - 1][j] && array[i][j] == array[i + 1][j])
    //         {
    //             array[i][j] = -150;
    //             array[i-1][j] = -151;
    //             array[i+1][j] = -152;
    //         }

    //    }
    //}

    // for (int i = 700; i < 710; i++)
    //{
    //     for (int j = 0; j < 10; j++)
    //     {
    //         if (array[i][j] == array[i][j+1] && array[i][j] == array[i][j-1])
    //         {
    //             array[i][j] = -153;
    //             array[i][j+1] = -154;
    //             array[i][j-1] = -155;
    //         }

    //    }
    //}
}

// if (((array[i][j] != array[i - 1][j] && array[i][j] != array[i + 1][j] && array[i][j] != array[i][j + 1] && array[i][j] != array[i][j + 2]) || (array[i][j] != array[i - 1][j] && array[i][j] != array[i + 1][j] && array[i][j] != array[i][j - 1] && array[i][j] != array[i][j - 2])
//     || (array[i][j] != array[i][j + 1] && array[i][j] != array[i][j - 1] && array[i][j] != array[i + 1][j] && array[i][j] != array[i + 2][j]) || (array[i][j] != array[i][j + 1] && array[i][j] != array[i][j - 1] && array[i][j] != array[i - 1][j] && array[i][j] != array[i - 2][j]))
//     || ((array[i][j] != array[i - 1][j] && array[i][j] != array[i - 2][j] && array[i][j] != array[i][j + 1] && array[i][j] != array[i][j + 2]) || (array[i][j] != array[i - 1][j] && array[i][j] != array[i - 2][j] && array[i][j] != array[i][j - 1] && array[i][j] != array[i][j - 2])
//         || (array[i][j] != array[i + 1][j] && array[i][j] != array[i + 2][j] && array[i][j] != array[i][j + 1] && array[i][j] != array[i][j + 2]) || (array[i][j] != array[i + 1][j] && array[i][j] != array[i + 2][j] && array[i][j] != array[i][j - 1] && array[i][j] != array[i][j - 2])))
//{

void THREECANDIESCRUSH(int array[1000][10])
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = 690; i < 700; i++)
        {
            if (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j])
            {
                array[i][j] = -8081;
                array[i + 2][j] = -9091;
                array[i + 1][j] = -1010;
            }
        }
    }

    for (int j = 690; j < 700; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (array[j][i] == array[j][i + 1] && array[j][i] == array[j][i + 2])
            {
                array[j][i] = -6780;
                array[j][i + 1] = -5512;
                array[j][i + 2] = -3313;
            }
        }
    }
}

void INITIALSWAP(int array[1000][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < 1000; j++)
        {
            if (array[j][i] < 0)
            {
                int temp = array[j][i];
                array[j][i] = array[j - 1][i];
                array[j - 1][i] = temp;
            }
        }
    }
}

// global_variables

// variables for computation of candies to  swap
int row_val = -1;
int col_val = -1;
int rowswap = -1;
int colswap = -1;

// click for glow
int glowclick = 1;

// score
int ScoreAdded = 0;
int TotalScore = 0;

// variable to set postion of candies
float xfor = 0.0f; // moving forward to next postion on xaxis (candies setup)
float yfor = 0.0f; // moving forward to next postion on yaxis (candies setup)

// frames to control speed
int frame = 0;
int frame1 = 0;
int frame2 = 0;
int frame3 = 0;
int frame4 = 0;
int frame5 = 0;
int frame6 = 0;

// swaping
int swapdone = -1;
int swapfail = 0;

// mouseinputclicks
int click = 0;

// run variables
int run = 0;

int main()
{
    char text[100];
    int count = 0;
    xfor = 485;
    yfor = 145;
    srand(time(0));
    int array[1000][10];
    RenderWindow window(sf::VideoMode(1319, 896), "CandyCrush", sf::Style::Close | sf::Style::Titlebar); // First window shape
    RectangleShape playbutton(sf::Vector2f(350.0f, 112.0f));                                             // button1 pictue.
    RectangleShape back1(sf::Vector2f(1319.0f, 896.0f));                                                 // background of first window
    RectangleShape back2(sf::Vector2f(1319.0f, 896.0f));                                                 // background of second window
    RectangleShape grid(sf::Vector2f(720.0f, 700.0f));                                                   // grid

    Music music;
    if (!music.openFromFile("CandyCrushOST.ogg"))
    {
        cout << "Error loading music" << endl;
    }
    int polo = 0;
    std::ostringstream ssScore;
    ssScore << ScoreAdded;

    Font font;
    font.loadFromFile("assets/CandyCrush.ttf");
    Text Score;
    Score.setFont(font);
    Score.setColor(Color::White);
    Score.setString(ssScore.str());
    Score.setPosition({235, 450});

    Texture back1Texture;
    back1Texture.loadFromFile("assets/back1.png");
    back1.setTexture(&back1Texture);

    Texture back2Texture;
    back2Texture.loadFromFile("assets/back2.png");
    back2.setTexture(&back2Texture);

    Texture gridTexture;
    gridTexture.loadFromFile("assets/grid.png");
    grid.setTexture(&gridTexture);
    grid.setPosition({475, 142});

    RectangleShape glow(sf::Vector2f(127.0f, 127.0f)); // button1 pictue.
    Texture glowTexture;
    glowTexture.loadFromFile("assets/glow.png");
    glow.setTexture(&glowTexture);
    glow.setFillColor(Color::Transparent);
    // glow.setPosition({ 450,115 });

    RectangleShape cursor(sf::Vector2f(67.0f, 69.0f));
    Texture cursortexture;
    cursortexture.loadFromFile("assets/cursor.png");
    cursor.setTexture(&cursortexture);
    cursor.setPosition({485, 145});

    RectangleShape scoreboard(sf::Vector2f(390.0f, 775.0f));
    Texture scoreboardtexture;
    scoreboardtexture.loadFromFile("assets/scoreboard.png");
    scoreboard.setTexture(&scoreboardtexture);
    scoreboard.setPosition({8, 80});

    // candiesbasic
    RectangleShape a(sf::Vector2f(67.0f, 67.0f));
    Texture atexture;
    atexture.loadFromFile("assets/a.png");
    a.setTexture(&atexture);

    RectangleShape b(sf::Vector2f(67.0f, 67.0f));
    Texture btexture;
    btexture.loadFromFile("assets/b.png");
    b.setTexture(&btexture);

    RectangleShape c(sf::Vector2f(64.0f, 64.0f));
    Texture ctexture;
    ctexture.loadFromFile("assets/c.png");
    c.setTexture(&ctexture);

    RectangleShape d(sf::Vector2f(67.0f, 67.0f));
    Texture dtexture;
    dtexture.loadFromFile("assets/d.png");
    d.setTexture(&dtexture);

    RectangleShape e(sf::Vector2f(67.0f, 67.0f));
    Texture etexture;
    etexture.loadFromFile("assets/e.png");
    e.setTexture(&etexture);

    // candiesStrippedHorizontaly
    RectangleShape aa(sf::Vector2f(67.0f, 67.0f));
    Texture aatexture;
    aatexture.loadFromFile("assets/aa.png");
    aa.setTexture(&aatexture);

    RectangleShape bb(sf::Vector2f(67.0f, 67.0f));
    Texture bbtexture;
    bbtexture.loadFromFile("assets/bb.png");
    bb.setTexture(&bbtexture);

    RectangleShape cc(sf::Vector2f(64.0f, 64.0f));
    Texture cctexture;
    cctexture.loadFromFile("assets/cc.png");
    cc.setTexture(&cctexture);

    RectangleShape dd(sf::Vector2f(67.0f, 67.0f));
    Texture ddtexture;
    ddtexture.loadFromFile("assets/dd.png");
    dd.setTexture(&ddtexture);

    RectangleShape ee(sf::Vector2f(67.0f, 67.0f));
    Texture eetexture;
    eetexture.loadFromFile("assets/ee.png");
    ee.setTexture(&eetexture);

    // candiesStrippedVertically
    RectangleShape aaa(sf::Vector2f(67.0f, 67.0f));
    Texture aaatexture;
    aaatexture.loadFromFile("assets/aaa.png");
    aaa.setTexture(&aaatexture);

    RectangleShape bbb(sf::Vector2f(67.0f, 67.0f));
    Texture bbbtexture;
    bbbtexture.loadFromFile("assets/bbb.png");
    bbb.setTexture(&bbbtexture);

    RectangleShape ccc(sf::Vector2f(64.0f, 64.0f));
    Texture ccctexture;
    ccctexture.loadFromFile("assets/ccc.png");
    ccc.setTexture(&ccctexture);

    RectangleShape ddd(sf::Vector2f(67.0f, 67.0f));
    Texture dddtexture;
    dddtexture.loadFromFile("assets/ddd.png");
    ddd.setTexture(&dddtexture);

    RectangleShape eee(sf::Vector2f(67.0f, 67.0f));
    Texture eeetexture;
    eeetexture.loadFromFile("assets/eee.png");
    eee.setTexture(&eeetexture);

    RectangleShape colorbomb(sf::Vector2f(60.0f, 60.0f));
    Texture colorbombtexture;
    colorbombtexture.loadFromFile("assets/colorbomb.png");
    colorbomb.setTexture(&colorbombtexture);

    // wrapped candies
    RectangleShape redpacket(sf::Vector2f(67.0f, 67.0f));
    Texture redpackettexture;
    redpackettexture.loadFromFile("assets/redpacket.png");
    redpacket.setTexture(&redpackettexture);

    RectangleShape bluepacket(sf::Vector2f(67.0f, 67.0f));
    Texture bluepackettexture;
    bluepackettexture.loadFromFile("assets/bluepacket.png");
    bluepacket.setTexture(&bluepackettexture);

    RectangleShape greenpacket(sf::Vector2f(67.0f, 67.0f));
    Texture greenpackettexture;
    greenpackettexture.loadFromFile("assets/greenpacket.png");
    greenpacket.setTexture(&greenpackettexture);

    RectangleShape orangepacket(sf::Vector2f(67.0f, 67.0f));
    Texture orangepackettexture;
    orangepackettexture.loadFromFile("assets/orangepacket.png");
    orangepacket.setTexture(&orangepackettexture);

    RectangleShape yellowpacket(sf::Vector2f(67.0f, 67.0f));
    Texture yellowpackettexture;
    yellowpackettexture.loadFromFile("assets/yellowpacket.png");
    yellowpacket.setTexture(&yellowpackettexture);

    Texture playbuttontexture;
    playbuttontexture.loadFromFile("assets/play.png"); // playbutton image
    playbutton.setTexture(&playbuttontexture);
    playbutton.setPosition({454, 548});

    // other function buttons
    Button btnplay("START NEW GAME", {340, 112}, 20, Color::Green, Color::Black);
    btnplay.setPosition({489, 570}); // buttonplay

    // Row 3 buttons
    Button btn00("00", {70, 70}, 3, Color::Red, Color::Black);
    btn00.setPosition({485, 145});
    Button btn01("01", {70, 70}, 3, Color::Red, Color::Black);
    btn01.setPosition({555, 145});
    Button btn02("02", {70, 70}, 3, Color::Red, Color::Black);
    btn02.setPosition({625, 145});
    Button btn03("03", {70, 70}, 3, Color::Red, Color::Black);
    btn03.setPosition({695, 145});
    Button btn04("04", {70, 70}, 3, Color::Red, Color::Black);
    btn04.setPosition({765, 145});
    Button btn05("05", {70, 70}, 3, Color::Red, Color::Black);
    btn05.setPosition({835, 145});
    Button btn06("06", {70, 70}, 3, Color::Red, Color::Black);
    btn06.setPosition({905, 145});
    Button btn07("07", {70, 70}, 3, Color::Red, Color::Black);
    btn07.setPosition({975, 145});
    Button btn08("08", {70, 70}, 3, Color::Red, Color::Black);
    btn08.setPosition({1045, 145});
    Button btn09("09", {70, 70}, 3, Color::Red, Color::Black);
    btn09.setPosition({1115, 145});

    // Row 2 buttons
    Button btn10("10", {70, 70}, 3, Color::Red, Color::Black);
    btn10.setPosition({485, 215});
    Button btn11("11", {70, 70}, 3, Color::Red, Color::Black);
    btn11.setPosition({555, 215});
    Button btn12("12", {70, 70}, 3, Color::Red, Color::Black);
    btn12.setPosition({625, 215});
    Button btn13("13", {70, 70}, 3, Color::Red, Color::Black);
    btn13.setPosition({695, 215});
    Button btn14("14", {70, 70}, 3, Color::Red, Color::Black);
    btn14.setPosition({765, 215});
    Button btn15("15", {70, 70}, 3, Color::Red, Color::Black);
    btn15.setPosition({835, 215});
    Button btn16("16", {70, 70}, 3, Color::Red, Color::Black);
    btn16.setPosition({905, 215});
    Button btn17("17", {70, 70}, 3, Color::Red, Color::Black);
    btn17.setPosition({975, 215});
    Button btn18("18", {70, 70}, 3, Color::Red, Color::Black);
    btn18.setPosition({1045, 215});
    Button btn19("19", {70, 70}, 3, Color::Red, Color::Black);
    btn19.setPosition({1115, 215});

    // Row3 buttons
    Button btn20("20", {70, 70}, 3, Color::Red, Color::Black);
    btn20.setPosition({485, 285});
    Button btn21("21", {70, 70}, 3, Color::Red, Color::Black);
    btn21.setPosition({555, 285});
    Button btn22("21", {70, 70}, 3, Color::Red, Color::Black);
    btn22.setPosition({625, 285});
    Button btn23("23", {70, 70}, 3, Color::Red, Color::Black);
    btn23.setPosition({695, 285});
    Button btn24("24", {70, 70}, 3, Color::Red, Color::Black);
    btn24.setPosition({765, 285});
    Button btn25("25", {70, 70}, 3, Color::Red, Color::Black);
    btn25.setPosition({835, 285});
    Button btn26("16", {70, 70}, 3, Color::Red, Color::Black);
    btn26.setPosition({905, 285});
    Button btn27("17", {70, 70}, 3, Color::Red, Color::Black);
    btn27.setPosition({975, 285});
    Button btn28("18", {70, 70}, 3, Color::Red, Color::Black);
    btn28.setPosition({1045, 285});
    Button btn29("19", {70, 70}, 3, Color::Red, Color::Black);
    btn29.setPosition({1115, 285});

    // Row4 buttons
    Button btn30("30", {70, 70}, 3, Color::Red, Color::Black);
    btn30.setPosition({485, 355});
    Button btn31("31", {70, 70}, 3, Color::Red, Color::Black);
    btn31.setPosition({555, 355});
    Button btn32("31", {70, 70}, 3, Color::Red, Color::Black);
    btn32.setPosition({625, 355});
    Button btn33("33", {70, 70}, 3, Color::Red, Color::Black);
    btn33.setPosition({695, 355});
    Button btn34("34", {70, 70}, 3, Color::Red, Color::Black);
    btn34.setPosition({765, 355});
    Button btn35("35", {70, 70}, 3, Color::Red, Color::Black);
    btn35.setPosition({835, 355});
    Button btn36("36", {70, 70}, 3, Color::Red, Color::Black);
    btn36.setPosition({905, 355});
    Button btn37("37", {70, 70}, 3, Color::Red, Color::Black);
    btn37.setPosition({975, 355});
    Button btn38("38", {70, 70}, 3, Color::Red, Color::Black);
    btn38.setPosition({1045, 355});
    Button btn39("39", {70, 70}, 3, Color::Red, Color::Black);
    btn39.setPosition({1115, 355});

    // Row5 buttons
    Button btn40("40", {70, 70}, 3, Color::Red, Color::Black);
    btn40.setPosition({485, 425});
    Button btn41("41", {70, 70}, 3, Color::Red, Color::Black);
    btn41.setPosition({555, 425});
    Button btn42("41", {70, 70}, 3, Color::Red, Color::Black);
    btn42.setPosition({625, 425});
    Button btn43("43", {70, 70}, 3, Color::Red, Color::Black);
    btn43.setPosition({695, 425});
    Button btn44("44", {70, 70}, 3, Color::Red, Color::Black);
    btn44.setPosition({765, 425});
    Button btn45("45", {70, 70}, 3, Color::Red, Color::Black);
    btn45.setPosition({835, 425});
    Button btn46("46", {70, 70}, 3, Color::Red, Color::Black);
    btn46.setPosition({905, 425});
    Button btn47("47", {70, 70}, 3, Color::Red, Color::Black);
    btn47.setPosition({975, 425});
    Button btn48("48", {70, 70}, 3, Color::Red, Color::Black);
    btn48.setPosition({1045, 425});
    Button btn49("49", {70, 70}, 3, Color::Red, Color::Black);
    btn49.setPosition({1115, 425});

    // Row6 buttons
    Button btn50("50", {70, 70}, 3, Color::Red, Color::Black);
    btn50.setPosition({485, 495});
    Button btn51("51", {70, 70}, 3, Color::Red, Color::Black);
    btn51.setPosition({555, 495});
    Button btn52("51", {70, 70}, 3, Color::Red, Color::Black);
    btn52.setPosition({625, 495});
    Button btn53("53", {70, 70}, 3, Color::Red, Color::Black);
    btn53.setPosition({695, 495});
    Button btn54("54", {70, 70}, 3, Color::Red, Color::Black);
    btn54.setPosition({765, 495});
    Button btn55("55", {70, 70}, 3, Color::Red, Color::Black);
    btn55.setPosition({835, 495});
    Button btn56("56", {70, 70}, 3, Color::Red, Color::Black);
    btn56.setPosition({905, 495});
    Button btn57("57", {70, 70}, 3, Color::Red, Color::Black);
    btn57.setPosition({975, 495});
    Button btn58("58", {70, 70}, 3, Color::Red, Color::Black);
    btn58.setPosition({1045, 495});
    Button btn59("59", {70, 70}, 3, Color::Red, Color::Black);
    btn59.setPosition({1115, 495});

    // Row7 buttons
    Button btn60("60", {70, 70}, 3, Color::Red, Color::Black);
    btn60.setPosition({485, 565});
    Button btn61("61", {70, 70}, 3, Color::Red, Color::Black);
    btn61.setPosition({555, 565});
    Button btn62("62", {70, 70}, 3, Color::Red, Color::Black);
    btn62.setPosition({625, 565});
    Button btn63("63", {70, 70}, 3, Color::Red, Color::Black);
    btn63.setPosition({695, 565});
    Button btn64("64", {70, 70}, 3, Color::Red, Color::Black);
    btn64.setPosition({765, 565});
    Button btn65("65", {70, 70}, 3, Color::Red, Color::Black);
    btn65.setPosition({835, 565});
    Button btn66("66", {70, 70}, 3, Color::Red, Color::Black);
    btn66.setPosition({905, 565});
    Button btn67("67", {70, 70}, 3, Color::Red, Color::Black);
    btn67.setPosition({975, 565});
    Button btn68("68", {70, 70}, 3, Color::Red, Color::Black);
    btn68.setPosition({1045, 565});
    Button btn69("69", {70, 70}, 3, Color::Red, Color::Black);
    btn69.setPosition({1115, 565});

    // Row8 buttons
    Button btn70("70", {70, 70}, 3, Color::Red, Color::Black);
    btn70.setPosition({485, 635});
    Button btn71("71", {70, 70}, 3, Color::Red, Color::Black);
    btn71.setPosition({555, 635});
    Button btn72("72", {70, 70}, 3, Color::Red, Color::Black);
    btn72.setPosition({625, 635});
    Button btn73("73", {70, 70}, 3, Color::Red, Color::Black);
    btn73.setPosition({695, 635});
    Button btn74("74", {70, 70}, 3, Color::Red, Color::Black);
    btn74.setPosition({765, 635});
    Button btn75("75", {70, 70}, 3, Color::Red, Color::Black);
    btn75.setPosition({835, 635});
    Button btn76("76", {70, 70}, 3, Color::Red, Color::Black);
    btn76.setPosition({905, 635});
    Button btn77("77", {70, 70}, 3, Color::Red, Color::Black);
    btn77.setPosition({975, 635});
    Button btn78("78", {70, 70}, 3, Color::Red, Color::Black);
    btn78.setPosition({1045, 635});
    Button btn79("79", {70, 70}, 3, Color::Red, Color::Black);
    btn79.setPosition({1115, 635});

    // Row9 buttons
    Button btn80("80", {70, 70}, 3, Color::Red, Color::Black);
    btn80.setPosition({485, 705});
    Button btn81("81", {70, 70}, 3, Color::Red, Color::Black);
    btn81.setPosition({555, 705});
    Button btn82("82", {70, 70}, 3, Color::Red, Color::Black);
    btn82.setPosition({625, 705});
    Button btn83("83", {70, 70}, 3, Color::Red, Color::Black);
    btn83.setPosition({695, 705});
    Button btn84("84", {70, 70}, 3, Color::Red, Color::Black);
    btn84.setPosition({765, 705});
    Button btn85("85", {70, 70}, 3, Color::Red, Color::Black);
    btn85.setPosition({835, 705});
    Button btn86("86", {70, 70}, 3, Color::Red, Color::Black);
    btn86.setPosition({905, 705});
    Button btn87("87", {70, 70}, 3, Color::Red, Color::Black);
    btn87.setPosition({975, 705});
    Button btn88("88", {70, 70}, 3, Color::Red, Color::Black);
    btn88.setPosition({1045, 705});
    Button btn89("89", {70, 70}, 3, Color::Red, Color::Black);
    btn89.setPosition({1115, 705});

    // Row10 buttons
    Button btn90("90", {70, 70}, 3, Color::Red, Color::Black);
    btn90.setPosition({485, 775});
    Button btn91("91", {70, 70}, 3, Color::Red, Color::Black);
    btn91.setPosition({555, 775});
    Button btn92("92", {70, 70}, 3, Color::Red, Color::Black);
    btn92.setPosition({625, 775});
    Button btn93("93", {70, 70}, 3, Color::Red, Color::Black);
    btn93.setPosition({695, 775});
    Button btn94("94", {70, 70}, 3, Color::Red, Color::Black);
    btn94.setPosition({765, 775});
    Button btn95("95", {70, 70}, 3, Color::Red, Color::Black);
    btn95.setPosition({835, 775});
    Button btn96("96", {70, 70}, 3, Color::Red, Color::Black);
    btn96.setPosition({905, 775});
    Button btn97("97", {70, 70}, 3, Color::Red, Color::Black);
    btn97.setPosition({975, 775});
    Button btn98("98", {70, 70}, 3, Color::Red, Color::Black);
    btn98.setPosition({1045, 775});
    Button btn99("99", {70, 70}, 3, Color::Red, Color::Black);
    btn99.setPosition({1115, 775});

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::TextEntered:
                if (event.text.unicode < 128)
                    printf("%c", event.text.unicode);
                break;

            case Event::MouseMoved:
                if (btnplay.isMouseOver(window))
                {
                    playbutton.setSize({462, 155});
                    playbutton.setPosition({448, 537});
                    btnplay.setBackColor(Color::White);
                }
                else
                {
                    btnplay.setBackColor(Color::Green);
                    playbutton.setPosition({452, 545});
                    playbutton.setSize({461, 142});
                }
                break;

            case Event::MouseButtonPressed:
                intializing(array);
                THREECANDIESCRUSH(array);

                if (btnplay.isMouseOver(window))
                {
                    sf::RenderWindow window2(sf::VideoMode(1319, 896), "CandyCrush", sf::Style::Close | sf::Style::Titlebar); // Second window shape
                    music.play();
                    while (window2.isOpen())
                    {
                        window2.draw(back2);
                        window2.draw(grid);

                        Event event;
                        while (window2.pollEvent(event))
                        {

                            switch (event.type)
                            {

                            case sf::Event::Closed:
                                window2.close();
                                break;

                            case Event::MouseMoved:
                                // cout << "x::::" << event.mouseMove.x << endl;cout << "y::::" << event.mouseMove.y << endl;
                                if (btn00.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 145);
                                }
                                if (btn01.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 145);
                                }
                                if (btn02.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 145);
                                }
                                if (btn03.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 145);
                                }
                                if (btn04.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 145);
                                }
                                if (btn05.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 145);
                                }
                                if (btn06.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 145);
                                }
                                if (btn07.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 145);
                                }
                                if (btn08.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 145);
                                }
                                if (btn09.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 145);
                                }

                                // row2
                                if (btn10.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 215);
                                }
                                if (btn11.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 215);
                                }
                                if (btn12.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 215);
                                }
                                if (btn13.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 215);
                                }
                                if (btn14.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 215);
                                }
                                if (btn15.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 215);
                                }
                                if (btn16.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 215);
                                }
                                if (btn17.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 215);
                                }
                                if (btn18.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 215);
                                }
                                if (btn19.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 215);
                                }

                                // row3
                                if (btn20.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 285);
                                }
                                if (btn21.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 285);
                                }
                                if (btn22.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 285);
                                }
                                if (btn23.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 285);
                                }
                                if (btn24.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 285);
                                }
                                if (btn25.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 285);
                                }
                                if (btn26.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 285);
                                }
                                if (btn27.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 285);
                                }
                                if (btn28.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 285);
                                }
                                if (btn29.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 285);
                                }

                                // row4
                                if (btn30.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 355);
                                }
                                if (btn31.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 355);
                                }
                                if (btn32.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 355);
                                }
                                if (btn33.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 355);
                                }
                                if (btn34.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 355);
                                }
                                if (btn35.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 355);
                                }
                                if (btn36.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 355);
                                }
                                if (btn37.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 355);
                                }
                                if (btn38.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 355);
                                }
                                if (btn39.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 355);
                                }

                                // row5
                                if (btn40.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 425);
                                }
                                if (btn41.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 425);
                                }
                                if (btn42.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 425);
                                }
                                if (btn43.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 425);
                                }
                                if (btn44.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 425);
                                }
                                if (btn45.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 425);
                                }
                                if (btn46.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 425);
                                }
                                if (btn47.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 425);
                                }
                                if (btn48.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 425);
                                }
                                if (btn49.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 425);
                                }

                                // row6
                                if (btn50.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 495);
                                }
                                if (btn51.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 495);
                                }
                                if (btn52.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 495);
                                }
                                if (btn53.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 495);
                                }
                                if (btn54.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 495);
                                }
                                if (btn55.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 495);
                                }
                                if (btn56.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 495);
                                }
                                if (btn57.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 495);
                                }
                                if (btn58.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 495);
                                }
                                if (btn59.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 495);
                                }

                                // row7
                                if (btn60.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 565);
                                }
                                if (btn61.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 565);
                                }
                                if (btn62.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 565);
                                }
                                if (btn63.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 565);
                                }
                                if (btn64.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 565);
                                }
                                if (btn65.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 565);
                                }
                                if (btn66.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 565);
                                }
                                if (btn67.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 565);
                                }
                                if (btn68.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 565);
                                }
                                if (btn69.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 565);
                                }

                                // row7
                                if (btn70.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 635);
                                }
                                if (btn71.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 635);
                                }
                                if (btn72.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 635);
                                }
                                if (btn73.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 635);
                                }
                                if (btn74.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 635);
                                }
                                if (btn75.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 635);
                                }
                                if (btn76.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 635);
                                }
                                if (btn77.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 635);
                                }
                                if (btn78.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 635);
                                }
                                if (btn79.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 635);
                                }

                                // row8
                                if (btn80.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 705);
                                }
                                if (btn81.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 705);
                                }
                                if (btn82.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 705);
                                }
                                if (btn83.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 705);
                                }
                                if (btn84.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 705);
                                }
                                if (btn85.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 705);
                                }
                                if (btn86.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 705);
                                }
                                if (btn87.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 705);
                                }
                                if (btn88.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 705);
                                }
                                if (btn89.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 705);
                                }

                                // row10
                                if (btn90.isMouseOver(window2))
                                {
                                    cursor.setPosition(485, 775);
                                }
                                if (btn91.isMouseOver(window2))
                                {
                                    cursor.setPosition(555, 775);
                                }
                                if (btn92.isMouseOver(window2))
                                {
                                    cursor.setPosition(625, 775);
                                }
                                if (btn93.isMouseOver(window2))
                                {
                                    cursor.setPosition(695, 775);
                                }
                                if (btn94.isMouseOver(window2))
                                {
                                    cursor.setPosition(765, 775);
                                }
                                if (btn95.isMouseOver(window2))
                                {
                                    cursor.setPosition(835, 775);
                                }
                                if (btn96.isMouseOver(window2))
                                {
                                    cursor.setPosition(905, 775);
                                }
                                if (btn97.isMouseOver(window2))
                                {
                                    cursor.setPosition(975, 775);
                                }
                                if (btn98.isMouseOver(window2))
                                {
                                    cursor.setPosition(1045, 775);
                                }
                                if (btn99.isMouseOver(window2))
                                {
                                    cursor.setPosition(1115, 775);
                                }
                                break;

                            case Event::MouseButtonPressed:
                                count++;

                                if (glowclick % 2 != 0)
                                {
                                    if (btn00.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn01.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn02.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn03.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn04.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn05.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn06.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn07.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn08.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 115});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn09.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 115});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn10.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn11.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn12.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn13.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn14.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn15.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn16.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn17.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn18.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 185});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn19.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 185});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn20.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn21.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn22.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn23.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn24.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn25.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn26.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn27.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn28.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 255});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn29.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 255});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn30.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn31.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn32.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn33.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn34.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn35.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn36.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn37.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn38.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 325});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn39.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 325});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn40.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn41.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn42.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn43.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn44.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn45.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn46.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn47.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn48.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 395});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn49.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 395});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn50.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn51.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn52.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn53.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn54.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn55.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn56.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn57.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn58.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 465});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn59.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 465});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn60.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn61.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn62.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn63.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn64.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn65.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn66.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn67.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn68.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 535});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn69.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 535});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn70.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn71.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn72.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn73.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn74.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn75.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn76.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn77.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn78.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 605});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn79.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 605});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn80.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn81.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn82.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn83.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn84.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn85.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn86.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn87.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn88.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 675});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn89.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 675});
                                        glow.setFillColor(Color::White);
                                    }

                                    if (btn90.isMouseOver(window2))
                                    {
                                        glow.setPosition({450, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn91.isMouseOver(window2))
                                    {
                                        glow.setPosition({520, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn92.isMouseOver(window2))
                                    {
                                        glow.setPosition({590, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn93.isMouseOver(window2))
                                    {
                                        glow.setPosition({660, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn94.isMouseOver(window2))
                                    {
                                        glow.setPosition({730, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn95.isMouseOver(window2))
                                    {
                                        glow.setPosition({800, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn96.isMouseOver(window2))
                                    {
                                        glow.setPosition({870, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn97.isMouseOver(window2))
                                    {
                                        glow.setPosition({940, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn98.isMouseOver(window2))
                                    {
                                        glow.setPosition({1010, 745});
                                        glow.setFillColor(Color::White);
                                    }
                                    if (btn99.isMouseOver(window2))
                                    {
                                        glow.setPosition({1080, 745});
                                        glow.setFillColor(Color::White);
                                    }

                                } // if (count % 2 == 0) {row_val = -1; col_val = -1; rowswap = -1; colswap = -1; }
                                glowclick++;

                                clickingcandies(btn00, btn01, btn02, btn03, btn04, btn05, btn06, btn07, btn08, btn09, btn10, btn11, btn12, btn13, btn14, btn15, btn16, btn17,
                                                btn18, btn19, btn20, btn21, btn22, btn23, btn24, btn25, btn26, btn27, btn28, btn29, btn30, btn31, btn32, btn33, btn34, btn35, btn36, btn37,
                                                btn38, btn39, btn40, btn41, btn42, btn43, btn44, btn45, btn46, btn47, btn48, btn49, btn50, btn51, btn52, btn53, btn54, btn55, btn56, btn57,
                                                btn58, btn59, btn60, btn61, btn62, btn63, btn64, btn65, btn66, btn67, btn68, btn69, btn70, btn71, btn72, btn73, btn74, btn75, btn76, btn77,
                                                btn78, btn79, btn80, btn81, btn82, btn83, btn84, btn85, btn86, btn87, btn88, btn89, btn90, btn91, btn92, btn93, btn94, btn95, btn96, btn97,
                                                btn98, btn99, count, row_val, col_val, rowswap, colswap, window2);
                            }
                        }

                        int p = 0;
                        int k = 0;
                        window2.draw(glow);

                        for (int r = 700; r < 710; r++)
                        {
                            for (int col = 0; col < 10; col++)
                            {
                                if (array[r][col] == 0)
                                {
                                    a.setPosition({xfor + p, yfor + k});
                                    window2.draw(a);
                                }
                                else if (array[r][col] == 1)
                                {
                                    b.setPosition({xfor + p, yfor + k});
                                    window2.draw(b);
                                }
                                else if (array[r][col] == 2)
                                {
                                    c.setPosition({xfor + p, yfor + k});
                                    window2.draw(c);
                                }
                                else if (array[r][col] == 3)
                                {
                                    d.setPosition({xfor + p, yfor + k});
                                    window2.draw(d);
                                }
                                else if (array[r][col] == 4)
                                {
                                    e.setPosition({xfor + p, yfor + k});
                                    window2.draw(e);
                                }
                                else if (array[r][col] == 10)
                                {
                                    aa.setPosition({xfor + p, yfor + k});
                                    window2.draw(aa);
                                }
                                else if (array[r][col] == 11)
                                {
                                    bb.setPosition({xfor + p, yfor + k});
                                    window2.draw(bb);
                                }
                                else if (array[r][col] == 12)
                                {
                                    cc.setPosition({xfor + p, yfor + k});
                                    window2.draw(cc);
                                }
                                else if (array[r][col] == 13)
                                {
                                    dd.setPosition({xfor + p, yfor + k});
                                    window2.draw(dd);
                                }
                                else if (array[r][col] == 14)
                                {
                                    ee.setPosition({xfor + p, yfor + k});
                                    window2.draw(ee);
                                }
                                else if (array[r][col] == 20)
                                {
                                    aaa.setPosition({xfor + p, yfor + k});
                                    window2.draw(aaa);
                                }
                                else if (array[r][col] == 21)
                                {
                                    bbb.setPosition({xfor + p, yfor + k});
                                    window2.draw(bbb);
                                }
                                else if (array[r][col] == 22)
                                {
                                    ccc.setPosition({xfor + p, yfor + k});
                                    window2.draw(ccc);
                                }
                                else if (array[r][col] == 23)
                                {
                                    ddd.setPosition({xfor + p, yfor + k});
                                    window2.draw(ddd);
                                }
                                else if (array[r][col] == 24)
                                {
                                    eee.setPosition({xfor + p, yfor + k});
                                    window2.draw(eee);
                                }
                                else if (array[r][col] == 30)
                                {
                                    bluepacket.setPosition({xfor + p, yfor + k});
                                    window2.draw(bluepacket);
                                }
                                else if (array[r][col] == 31)
                                {
                                    redpacket.setPosition({xfor + p, yfor + k});
                                    window2.draw(redpacket);
                                }

                                else if (array[r][col] == 32)
                                {
                                    orangepacket.setPosition({xfor + p, yfor + k});
                                    window2.draw(orangepacket);
                                }

                                else if (array[r][col] == 33)
                                {
                                    greenpacket.setPosition({xfor + p, yfor + k});
                                    window2.draw(greenpacket);
                                }

                                else if (array[r][col] == 34)
                                {
                                    yellowpacket.setPosition({xfor + p, yfor + k});
                                    window2.draw(yellowpacket);
                                }
                                else if (array[r][col] == 9)
                                {
                                    colorbomb.setPosition({xfor + p, yfor + k});
                                    window2.draw(colorbomb);
                                }

                                p = p + 70;
                            }

                            p = 0;
                            k = k + 70;
                        }

                        swap1(array, row_val, col_val, rowswap, colswap, swapdone, swapfail);

                        /* if (frame6 == 24)
                         {

                         }*/

                        if (swapdone == 1)
                        {
                            glow.setFillColor(Color::Transparent);
                            swapdone = -1;
                            glowclick = glowclick + 2;
                            /* for (int i = 690; i < 712; i++)
                             {
                                 if (i == 699 || i == 710)cout << endl;
                                 for (int j = 0; j < 10; j++)
                                 {
                                     cout << array[i][j] << " ";
                                 }
                                 cout << endl;
                             }*/
                        }

                        if (frame == 50)
                        {
                            CandyMatchAndScore(array, ScoreAdded, TotalScore);
                            cout << ScoreAdded;
                            ssScore.str("");
                            ssScore << ScoreAdded;
                            Score.setString(ssScore.str());
                            // CandyMatchAndScore(array, ScoreAdded, TotalScore);
                        }
                        // cout << "ScoreAdded" << ScoreAdded;

                        frame++;
                        if (frame > 50)
                        {
                            frame = 0;
                        }

                        if (frame2 == 20)
                        {
                            for (int i = 0; i < 10; i++)
                            {
                                for (int j = 1; j < 1000; j++)
                                {
                                    if (array[j][i] < 0)
                                    {
                                        int temp = array[j][i];
                                        array[j][i] = array[j - 1][i];
                                        array[j - 1][i] = temp;
                                    }
                                }
                            }
                        }
                        frame2++;
                        if (frame2 > 20)
                        {
                            frame2 = 0;
                        }

                        run = 1;
                        frame4++;

                        window2.draw(cursor);
                        window2.draw(scoreboard);
                        window2.draw(Score);
                        window2.display();
                    }
                }

                break;
            }
        }

        float x = 0.01f;
        float y = 0.01f;
        window.clear();
        window.draw(back1);
        window.draw(playbutton);
        window.display();
    }

    return 0;
}

class Button
{
public:
    Button() {}
    Button(string t, Vector2f size, int charSize, Color bgcolor, Color textcolor)
    {
        text.setString(t);
        text.setColor(textcolor);
        text.setCharacterSize(charSize);
        button.setSize(size);
        button.setFillColor(bgcolor);
    }

    void setFont(Font &font)
    {
        text.setFont(font);
    }

    void setBackColor(Color color)
    {
        button.setFillColor(color);
    }

    void setTextColor(Color color)
    {
        text.setColor(color);
    }

    void setPosition(Vector2f pos)
    {
        button.setPosition(pos);
        float xPos = (pos.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
        float yPos = (pos.y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);

        text.setPosition({xPos, yPos});
    }

    void drawTo(RenderWindow &window)
    {
        window.draw(button);
        window.draw(text);
    }

    bool isMouseOver(RenderWindow &window)
    {
        float mouseX = Mouse::getPosition(window).x;
        float mouseY = Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
        {
            return true;
        }
        return false;
    }

private:
    RectangleShape button;

    Text text;
};
