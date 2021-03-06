#ifndef  _GLOBAL_DEFINE_H_
#define  _GLOBAL_DEFINE_H_

#define BACKGROUND_ROW 20
#define BACKGROUND_COL 10
#define BACKGROUND_ROW_CODE ((1<<BACKGROUND_COL)-1)
#define BACKGROUND_ROW_MASK (~BACKGROUND_ROW_CODE)

enum TetrominoShape{
	TS_SQUARE = 0, //方形
	TS_T      = 1, //T型
	TS_1      = 2, //1型
	TS_L      = 3, //L形
	TS_R_L    = 4, //反L形
	TS_Z      = 5, //Z形
	TS_R_Z    = 6 //反Z形

};

const int g_tetrominoShapeCode[][4][4]=
{
	{{0x3,0x3,0x0,0x0},{0x3,0x3,0x0,0x0},{0x3,0x3,0x0,0x0},{0x3,0x3,0x0,0x0}}, //方形
	{{0x2,0x7,0x0,0x0},{0x1,0x3,0x1,0x0},{0x7,0x2,0x0,0x0},{0x2,0x3,0x2,0x0}}, //T型
	{{0x1,0x1,0x1,0x1},{0xf,0x0,0x0,0x0},{0x1,0x1,0x1,0x1},{0xf,0x0,0x0,0x0}}, //1型
	{{0x3,0x2,0x2,0x0},{0x4,0x7,0x0,0x0},{0x1,0x1,0x3,0x0},{0x7,0x1,0x0,0x0}}, //L形
	{{0x3,0x1,0x1,0x0},{0x7,0x4,0x0,0x0},{0x2,0x2,0x3,0x0},{0x1,0x7,0x0,0x0}}, //反L形
	{{0x3,0x6,0x0,0x0},{0x2,0x3,0x1,0x0},{0x3,0x6,0x0,0x0},{0x2,0x3,0x1,0x0}}, //Z形
	{{0x6,0x3,0x0,0x0},{0x1,0x3,0x2,0x0},{0x6,0x3,0x0,0x0},{0x1,0x3,0x2,0x0}}  //反Z形
};

//触碰事件的触点偏移
const int g_touchCorrect[][4]=
{
	{1,1,1,1}, //方形
	{1,1,1,1}, //T型
	{0,2,0,2}, //1型
	{1,1,1,1}, //L形
	{1,1,1,1}, //反L形
	{1,1,1,1}, //Z形
	{1,1,1,1}  //反Z形
};

//旋转事件的方块偏移
const int g_rotateCorrect[][4]=
{
	{0,  0,  0, 0}, //方形
	{0,  0,  0, 0}, //T型
	{-1, 1, -1, 1}, //1型
	{0,  0,  0, 0}, //L形
	{0,  0,  0, 0}, //反L形
	{0,  0,  0, 0}, //Z形
	{0,  0,  0, 0}, //反Z形
};

const char* const g_fnBlockText[7] = {
	"block.png",
	"block.png",
	"block.png",
	"block.png",
	"block.png",
	"block.png",
	"block.png"
};

#endif