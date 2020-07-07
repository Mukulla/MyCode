#include "Calculator.h"

double Calculate(std::string String001)
{
	// If the line is empty, then pass zero
	if (String001 == "")
	{
		return 0;
	}
	// Add a null character if it is not
	if (String001[String001.length() - 1] != '\0')
	{
		String001 += '\0';
	}
	std::string PreparedStirng = "";

	// Fill with allowed characters
	PrepareString(String001, PreparedStirng);
	// If this line is empty, then pass zero
	if (PreparedStirng == "")
	{
		return 0;
	}

	Str_Borders FullStringBorders;
	FullStringBorders.Min = PreparedStirng.c_str();
	FullStringBorders.Max = PreparedStirng.c_str() + PreparedStirng.length();

	return CalculateSubString(FullStringBorders);
}
void PrepareString(std::string& Original, std::string& Recycled)
{
	const char* Pointer = Original.c_str();
	// Search for allowed characters and add them to the string
	while (*Pointer)
	{
		if (Compare(*Pointer, "0123456789,.") || Compare(*Pointer, "+-*/^") || Compare(*Pointer, "()"))
		{
			Recycled += *Pointer;
		}
		++Pointer;
	}
}
double CalculateSubString(Str_Borders& StringBorders)
{
	std::list< Str_ExecUnit > List001 = FillList(StringBorders);
	return CalculateList(List001);
}
std::list< Str_ExecUnit > FillList(Str_Borders& BordersString)
{
	std::list< Str_ExecUnit > List001;

	Str_ExecUnit Transfer;
	Transfer.Action = 0;
	Transfer.Value = 0;
	const char* IteratorString = BordersString.Min;
	int Sign = 1;

	// Since there can be a maximum of only two characters on the left and the closest of the two is necessarily minus,
	// then create an array with two action values
	// The default values are negative, since there are no such action indices
	int Actions[] = { -1, -1 };

	// Borders of substring
	Str_Borders HookBorders;

	// Search for the first numeric character
	// or skip all non-numeric to the next numeric
	while (IteratorString < BordersString.Max)
	{
		if (*IteratorString == '(')
		{
			// Fill the array with actions, get the sign and number of the action
			FillAction(BordersString, IteratorString, &Actions[0], 2);
			Sign = GetSign(&Actions[0], 2);
			Transfer.Action = GetAction(&Actions[0], 2);

			// Skip starting the current parenthesis to the next closing one, including those that are inside
			HookBorders.Min = (IteratorString + 1);
			IteratorString = SkipHooks(BordersString, IteratorString);
			HookBorders.Max = IteratorString;

			// Calculate the expression in brackets and add to the list
			Transfer.Value = CalculateSubString(HookBorders);
			List001.push_back(Transfer);
		}
		if (Compare(*IteratorString, "0123456789,."))
		{
			// Fill the array with actions, get the sign and number of the action
			FillAction(BordersString, IteratorString, &Actions[0], 2);
			Sign = GetSign(&Actions[0], 2);
			Transfer.Action = GetAction(&Actions[0], 2);

			// Get the total number and add to the list
			Transfer.Value = Sign * StringToDouble(CollectNumbers(BordersString, IteratorString));
			List001.push_back(Transfer);

			// Pass to the following sign of action
			while (Compare(*IteratorString, "0123456789,.") && IteratorString < BordersString.Max)
			{
				++IteratorString;
			}
		}
		++IteratorString;
	}
	return List001;
}
const char* SkipHooks(Str_Borders& BordersString, const char* Iterator)
{
	int Count = 0;
	while (Iterator < BordersString.Max)
	{
		if (*Iterator == '(')
		{
			++Count;
		}
		if (*Iterator == ')')
		{
			--Count;
		}
		if (!Count)
		{
			break;
		}
		++Iterator;
	}
	return Iterator;
}
void FillAction(Str_Borders& BordersString001, const char* Iterator, int* ArrayActions, int Length001)
{
	// Reset
	ArrayActions[0] = -1;
	ArrayActions[1] = -1;
	// Counter and index of array
	int Counter = 1, Access = 0;
	// Look for the signs to the left of the number and write the first two of them to the first symbol of the number or the left end of the line
	while ((Iterator - Counter) >= BordersString001.Min)
	{
		// If this action
		if ( Compare(*(Iterator - Counter), "+-*/^"))
		{
			ArrayActions[Access] = NumberAction(*(Iterator - Counter));
			++Access;
			if (Access > (Length001 - 1))
			{
				break;
			}
		}
		// As soon as the first numeric character comes across, reset
		if (Compare(*(Iterator - Counter), "0123456789,."))
		{
			break;
		}
		++Counter;
	}
}
int GetSign(int* ArrayActions, int Length001)
{
	if (ArrayActions[0] == AC_SUBSTRACT && ArrayActions[1] < 0)
	{
		return 1;
	}
	if (ArrayActions[0] == AC_SUBSTRACT && ArrayActions[1] > -1)
	{
		return -1;
	}
	return 1;
}
int GetAction(int* ArrayActions, int Length001)
{
	if (ArrayActions[0] < 0)
	{
		return 0;
	}
	if (ArrayActions[0] == AC_SUBSTRACT && ArrayActions[1] < 0)
	{
		return ArrayActions[0];
	}
	if (ArrayActions[0] == AC_SUBSTRACT && ArrayActions[1] > -1)
	{
		return ArrayActions[1];
	}
	return ArrayActions[0];
}
int NumberAction(char Symbol001)
{
	const char* Alpha = "+-*/^";
	int Iterator = 0;
	while (*Alpha)
	{
		if (*Alpha == Symbol001)
		{
			return Iterator;
		}
		++Iterator;
		++Alpha;
	}
	return -1;
}
std::string CollectNumbers(Str_Borders& BordersString001, const char* Iterator)
{
	std::string TempoString = "";
	// Finded dot or comma
	bool Finded = false;
	while (Iterator < BordersString001.Max)
	{
		// Find first of it
		if (!Finded && Compare(*Iterator, ",."))
		{
			TempoString += *Iterator;
			Finded = true;
			continue;
		}
		if (Compare(*Iterator, "0123456789"))
		{
			TempoString += *Iterator;
		}
		if (!Compare(*Iterator, "0123456789,."))
		{
			break;
		}
		++Iterator;
	}
	return TempoString;
}
double StringToDouble(std::string String001)
{
	double Value = 0;
	unsigned int Length = String001.length();
	unsigned int NumberDot = 0;
	for (unsigned int i = 0; i < Length; ++i)
	{
		if (Compare(String001[i], ",."))
		{
			NumberDot = i;
			break;
		}
	}

	// If integer
	if (!NumberDot)
	{
		for (unsigned int i = 0; i < Length; ++i)
		{
			Value += (double)(String001[i] - '0') * MyPower(10.0, (double)(Length - i - 1));
		}
	}
	else
	{
		// Int part
		for (unsigned int i = 0; i < NumberDot; ++i)
		{
			Value += (double)(String001[i] - '0') * MyPower(10.0, (double)(NumberDot - i - 1));

		}
		// Fractional part
		for (unsigned int i = NumberDot + 1; i < Length; ++i)
		{
			Value += (double)(String001[i] - '0') / MyPower(10.0, (double)(i - NumberDot));
		}
	}
	return Value;
}
double CalculateList(std::list< Str_ExecUnit> &List001)
{
	double Hoarder = 0.0, TempoHoarder = 0.0;
	auto Next = List001.begin();
	//Calclualte
	for (auto Current = List001.begin(); Current != List001.end(); ++Current)
	{
		if (Next != List001.end())
		{
			++Next;
		}
		if (Current->Action > -1)
		{
			if (Next != List001.end())
			{
				// Chaeck priority
				if (Current->Action < AC_MULTIPLY && Next->Action > AC_SUBSTRACT)
				{
					DoAction(TempoHoarder, *Current);
					while (Next->Action > AC_SUBSTRACT)
					{
						DoAction(TempoHoarder, *Next);
						++Next;
						++Current;
						if (Next == List001.end())
						{
							break;
						}
					}
					Hoarder += TempoHoarder;
					TempoHoarder = 0;
					continue;
				}
			}
		}
		DoAction(Hoarder, *Current);
	}
	return Hoarder;
}
void DoAction(double& Hoarder, Str_ExecUnit& ExecUnit001)
{
	// Select and execute
	switch (ExecUnit001.Action)
	{
	case AC_ADD:
		Hoarder += ExecUnit001.Value;
		break;
	case AC_SUBSTRACT:
		Hoarder -= ExecUnit001.Value;
		break;
	case AC_MULTIPLY:
		Hoarder *= ExecUnit001.Value;
		break;
	case AC_DIVIDE:
		Hoarder /= ExecUnit001.Value;
		break;
	case AC_POWER:
		Hoarder = MyPower(Hoarder, ExecUnit001.Value);
		break;
	}
}
double MyPower(double Number001, double Power001)
{
	double Hoarder = 1.0;
	if (Power001 < 0)
	{
		for (int i = 0; i < Power001; ++i)
		{
			Hoarder /= Number001;
		}
		return Hoarder;
	}
	if (Power001 >= 1)
	{
		for (int i = 0; i < Power001; ++i)
		{
			Hoarder *= Number001;
		}
		return Hoarder;
	}
	if (Power001 > 0 && Power001 < 1)
	{
		Hoarder = exp(Power001 * log(Number001));
	}
	return Hoarder;
}
bool Compare(char Symbol001, const char* AlphaToCompare)
{
	while (*AlphaToCompare)
	{
		if (Symbol001 == *AlphaToCompare)
		{
			return true;
		}
		AlphaToCompare++;
	}
	return false;
}
