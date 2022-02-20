#include "AdditionalFunctions.h"
#include "Game.h"


int main()
{
	srand(time(NULL));
	Game game;
	game.Run();
	Sleep(1000);
	system("cls");
	CoutCenteredText("YOU LOST!",20);
	while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_SPACE))) == 0) {}
}

