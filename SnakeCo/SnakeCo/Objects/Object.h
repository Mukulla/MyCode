#ifndef OBJECT_H
#define OBJECT_H

#include "stdafx.h"

#include "Lib/Structures.h"

struct Str_Object
{
	Str_Geminus< unsigned int > Koordinates;
	std::string Name;
};

#endif