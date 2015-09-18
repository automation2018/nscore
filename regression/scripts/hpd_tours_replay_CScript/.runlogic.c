
#include "../../include/runlogic.h"


LogicBlockElement elementsCtrBlock_1 [] = {
	{1, 1, 0},
};

LogicBlockElement elementsCtrBlock_2 [] = {
	{0, 0, 0},
	{0, 1, 1},
	{0, 2, 2},
	{0, 3, 3},
	{0, 4, -1},
};

LogicBlockCtrl ctrlBlock[] = {
	{ "MorePages", NS_CTRLBLOCK_WHILE, 1, elementsCtrBlock_1, 0, "cav_replay_more_pages"},
	{ "NextPages", NS_CTRLBLOCK_SWITCH, 5, elementsCtrBlock_2, 0, "cav_replay_page_id"},
};

int numCtrlBlocks = 2;

int switchBlockDefaultValue = -1;
