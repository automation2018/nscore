
#include "../../include/runlogic.h"


LogicBlockElement elementsCtrBlock_1 [] = {
	{1, 1, 0},
};

LogicBlockElement elementsCtrBlock_2 [] = {
	{0, 0, 0},
	{0, 1, 0},
};

LogicBlockCtrl ctrlBlock[] = {
	{ "DoWhile", NS_CTRLBLOCK_DOWHILE, 1, elementsCtrBlock_1, 0, "var_dowhile"},
	{ "Seq", NS_CTRLBLOCK_SEQUENCE, 2, elementsCtrBlock_2, 0, ""},
};

int numCtrlBlocks = 2;

int switchBlockDefaultValue = -1;
