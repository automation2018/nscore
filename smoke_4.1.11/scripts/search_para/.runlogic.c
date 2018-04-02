
#include "../../include/runlogic.h"


LogicBlockElement elementsCtrBlock_1 [] = {
	{0, 0, 0},
	{0, 1, 0},
	{0, 2, 0},
	{0, 3, 0},
	{0, 4, 0},
	{0, 5, 0},
	{0, 6, 0},
};

LogicBlockCtrl ctrlBlock[] = {
	{ "Block1", NS_CTRLBLOCK_SEQUENCE, 7, elementsCtrBlock_1, 0, ""},
};

int numCtrlBlocks = 1;
