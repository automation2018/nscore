
#include "../../include/runlogic.h"


LogicBlockElement elementsCtrBlock_1 [] = {
	{1, 1, 0},
};

LogicBlockElement elementsCtrBlock_2 [] = {
	{1, 2, 0},
};

LogicBlockElement elementsCtrBlock_3 [] = {
	{1, 3, 0},
	{0, 6, 0},
};

LogicBlockElement elementsCtrBlock_4 [] = {
	{1, 4, 100},
};

LogicBlockElement elementsCtrBlock_5 [] = {
	{0, 0, 50},
	{1, 5, 50},
};

LogicBlockElement elementsCtrBlock_6 [] = {
	{1, 6, 0},
};

LogicBlockElement elementsCtrBlock_7 [] = {
	{1, 7, 0},
};

LogicBlockElement elementsCtrBlock_8 [] = {
	{1, 8, 0},
	{0, 5, 0},
};

LogicBlockElement elementsCtrBlock_9 [] = {
	{1, 9, 0},
	{1, 10, 1},
	{1, 11, 2},
	{1, 12, -1},
};

LogicBlockElement elementsCtrBlock_10 [] = {
	{0, 1, 0},
	{0, 2, 0},
};

LogicBlockElement elementsCtrBlock_11 [] = {
	{0, 3, 0},
	{0, 2, 0},
};

LogicBlockElement elementsCtrBlock_12 [] = {
	{0, 0, 0},
	{0, 2, 0},
};

LogicBlockElement elementsCtrBlock_13 [] = {
	{0, 4, 0},
	{0, 2, 0},
};

LogicBlockCtrl ctrlBlock[] = {
	{ "Parent", NS_CTRLBLOCK_SEQUENCE, 1, elementsCtrBlock_1, 0, ""},
	{ "DoWhileBlock", NS_CTRLBLOCK_DOWHILE, 1, elementsCtrBlock_2, 0, "var_dowhile"},
	{ "Seq1", NS_CTRLBLOCK_SEQUENCE, 2, elementsCtrBlock_3, 0, ""},
	{ "Weight", NS_CTRLBLOCK_WEIGHT, 1, elementsCtrBlock_4, 0, ""},
	{ "Percentage", NS_CTRLBLOCK_PERCENT, 2, elementsCtrBlock_5, 0, ""},
	{ "Count", NS_CTRLBLOCK_COUNT, 1, elementsCtrBlock_6, 1, ""},
	{ "while", NS_CTRLBLOCK_WHILE, 1, elementsCtrBlock_7, 0, "var_while"},
	{ "SeqW", NS_CTRLBLOCK_SEQUENCE, 2, elementsCtrBlock_8, 0, ""},
	{ "Switch", NS_CTRLBLOCK_SWITCH, 4, elementsCtrBlock_9, 0, "var_switch"},
	{ "Seq2", NS_CTRLBLOCK_SEQUENCE, 2, elementsCtrBlock_10, 0, ""},
	{ "Seq3", NS_CTRLBLOCK_SEQUENCE, 2, elementsCtrBlock_11, 0, ""},
	{ "Seq4", NS_CTRLBLOCK_SEQUENCE, 2, elementsCtrBlock_12, 0, ""},
	{ "Seq5", NS_CTRLBLOCK_SEQUENCE, 2, elementsCtrBlock_13, 0, ""},
};

int numCtrlBlocks = 13;

int switchBlockDefaultValue = -1;
