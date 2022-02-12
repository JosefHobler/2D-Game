#include "AdditionalFunctions.h"


void CoutCenteredText(string word, int size_to_center)
{
    bool space = true;
    for (int i = 0; i < size_to_center; i++)
    {
        cout << "-";
    }
    cout << "\n";
    for (int i = word.size(); i < size_to_center; i++)
    {
        if (space)
        {
            word += ' ';
        }
        else
        {
            word = ' ' + word;
        }
        space = !space;
    }
    cout << word << "\n";
    for (int i = 0; i < size_to_center; i++)
    {
        cout << "-";
    }
    cout << "\n";
}


string CenteredText(string word, int size_to_center)
{
    bool space = true;
    for (int i = word.size(); i < size_to_center; i++)
    {
        if (space)
        {
            word += ' ';
        }
        else
        {
            word = ' ' + word;
        }
        space = !space;
    }
    return word;
}


int ChangeArrowinText(vector<string>& buffer, int xmax)
{
    int x = 0;
    int frequency = 10;
    while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_SPACE))) == 0)
    {
        system("cls");
        if ((0x8000 & GetAsyncKeyState((unsigned char)('W'))) != 0 && frequency <= 0)
        {
            frequency = 10;
            x--;
        }
        if ((0x8000 & GetAsyncKeyState((unsigned char)('S'))) != 0 && frequency <= 0)
        {
            frequency = 10;
            x++;
        }
        frequency--;
        if (x > xmax - 1)
        {
            x = 0;
        }
        if (x < 0)
        {
            x = xmax - 1;
        }
        for (int i = 0; i < xmax; i++)
        {
            if (x == i)
            {
                cout << "<< " + buffer[i];
            }
            else
            {
                cout << buffer[i];
            }
            cout << "\n";
        }
    }
    system("cls");
    return x;
}


int ChangeArrowinTextWithText(vector<string>& buffer, int xmax, string constant_message)
{
    int x = 0;
    int frequency = 10;
    while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_SPACE))) == 0)
    {
        system("cls");
        if ((0x8000 & GetAsyncKeyState((unsigned char)('W'))) != 0 && frequency <= 0)
        {
            frequency = 10;
            x--;
        }
        if ((0x8000 & GetAsyncKeyState((unsigned char)('S'))) != 0 && frequency <= 0)
        {
            frequency = 10;
            x++;
        }
        frequency--;
        if (x > xmax - 1)
        {
            x = 0;
        }
        if (x < 0)
        {
            x = xmax - 1;
        }
        cout << constant_message;
        cout << "\n\n";
        for (int i = 0; i < xmax; i++)
        {
            if (x == i)
            {
                cout << "<< " + buffer[i];
            }
            else
            {
                cout << buffer[i];
            }
            cout << "\n";
        }
    }
    system("cls");
    return x;
}