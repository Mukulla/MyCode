#ifndef MY_CALCULATOR_H
#define MY_CALCULATOR_H

#include "MainHeader.h"
// Executive unit of calculation
struct Str_ExecUnit	{int Action; double Value;};
// Available actions
enum En_Actions	{AC_ADD, AC_SUBSTRACT, AC_MULTIPLY, AC_DIVIDE, AC_POWER};
// Borders of a substring
struct Str_Borders	{const char *Min, *Max;};

//My calculator
//Evaluating expressions in a string
// Main function
double Calculate(std::string String001);

// Collect only allowed characters in a string
void PrepareString(std::string& Original, std::string& Recycled);
// Calculate the substring
double CalculateSubString(Str_Borders& StringBorders);
// Fill List Of Executive Units
std::list<Str_ExecUnit> FillList(Str_Borders& BordersString);
const char* SkipHooks(Str_Borders& BordersString, const char* Iterator);
// Write the actions to an array, usually the first two characters that come to the left of the numeric
void FillAction(Str_Borders& BordersString001, const char* Iterator, int* ArrayActions, int Length001);
// Get the character before the number based on the array with actions
int GetSign(int* ArrayActions, int Length001);
// Get an action based on an array with actions
int GetAction(int* ArrayActions, int Length001);
// Get the action number by character
int NumberAction(char Symbol001);
// Collect numeric characters into irrational number
std::string CollectNumbers(Str_Borders& BordersString001, const char* Iterator);
double StringToDouble(std::string String001);
// Calculate all executive units taking into account priority
double CalculateList(std::list<Str_ExecUnit>& List001);
void DoAction(double& Hoarder, Str_ExecUnit& ExecUnit001);
// raise to any degree
double MyPower(double Number001, double Power001);
// Does the character match any of the given sequence?
bool Compare(char Symbol001, const char* AlphaToCompare);

#endif