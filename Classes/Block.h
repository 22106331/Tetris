#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cocos2d.h"
#include "FragmentEffect.h"

USING_NS_CC;

enum BlockType{
	BT_RED     = 0,
	BT_GREEN   = 1,
	BT_BLUE    = 2,
	BT_ORANGE  = 3,
	BT_VIOLET  = 4,
	BT_PINK    = 5,
	BT_GOLDEN  = 6
};

/**
 * С������,�ĸ��������һ����״�Ķ���˹����
 */
class Block : public CCSprite
{
public:
	static Block* create(const char *pszFileName);
	bool initWithFile(const char *pszFilename);
	void setEffect(unsigned int effectSel);
	void setBlockSize(float size);

private:
	int m_index;
};

#endif