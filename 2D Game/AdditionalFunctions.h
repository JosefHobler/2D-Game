#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <time.h>;
#include <string>
#include <iomanip>
using namespace std;


void CoutCenteredText(string word, int size_to_center);
string CenteredText(string word, int size_to_center);
int ChangeArrowinText(vector<string>& buffer, int xmax);
int ChangeArrowinTextWithText(vector<string>& buffer, int xmax, string constant_message);
