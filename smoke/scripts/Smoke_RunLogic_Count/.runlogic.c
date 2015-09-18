
#include "../../include/runlogic.h"


LogicBlockElement elementsCtrBlock_1 [] = {
	{0, 0, 0},
};

LogicBlockCtrl ctrlBlock[] = {
	{ "Count", NS_CTRLBLOCK_COUNT, 1, elementsCtrBlock_1, 2, ""},
};

int numCtrlBlocks = 1;

int switchBlockDefaultValue = -1;
