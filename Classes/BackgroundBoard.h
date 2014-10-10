#ifndef _BACKGROUND_BOARD_H_
#define _BACKGROUND_BOARD_H_

#include "cocos2d.h"
#include "GlobalDefine.h"
#include "Tetromino.h"
#include "Block.h"

USING_NS_CC;

typedef void (CCObject::*SEL_ClearLine)(int numLine);
#define clearLine_selector(_SELECTOR) (SEL_ClearLine)(&_SELECTOR)

typedef void (CCObject::*SEL_GameOver)();
#define gameOver_selector(_SELECTOR) (SEL_GameOver)(&_SELECTOR)

/**
 *  �װ�
 */
class BackgroundBoard : public CCNode,public CCTouchDelegate
{
public:
	///��Ϸ��ʼ,�����¿�ʼ��ʱ����,��ͣ���������continueDrop
	void start();

	void pasueDrop();     ///<��ͣ��Ϸ
	void continueDrop();  ///<������Ϸ

	void curTetrominoMove(); ///<�ǰ�ķ������½���,��һ���ص�����
	void setNextTetromino(); ///<�����µķ���,��һ���ص�����

	
	void setClearLineListener(CCObject*,SEL_ClearLine);  ///<�����������Ļص�
	void setGameOverListener(CCObject*,SEL_GameOver);    ///<����GameOver�Ļص�
	
	///��������һ��ĵȴ�ʱ��
	void setDropDelayTime(float dropDur)		 {m_dropDelayTime = dropDur;}

	bool isPause()								 {return m_isPause;}

	virtual bool init(float blockSize,char* fnBlockTex);
	virtual void onEnter();
    virtual void onExit();
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	static BackgroundBoard* create(float blockSize,char* fnBlockTex);
private:
	char* m_fnBlockTex;
	float m_dropDelayTime;
	bool  m_bAccAction;
	bool  m_bGameOver;
	bool  m_isPause;
	int   m_blockSize;
	int   m_bgInfo[BACKGROUND_ROW];
	CCPoint       m_touchPos;
	CCNode*       m_blockSprRow[BACKGROUND_ROW];
	Tetromino*    m_curTetromino;
	CCNode*       m_targetBlock;
	CCObject*     m_clearLineListener;
	SEL_ClearLine m_clearLineCallback;
	CCObject*     m_gameOverListener;
	SEL_GameOver  m_gameOverCallback;


	int  clearLine();          ///<�������������
	bool addToBg();            ///<����ǰ�ķ���ӵ��װ�����������
	void addNewTetromino();    ///<�����µķ���
	void setTargetBlockPos();  ///<������������ʾ�����λ��
	void gotoTargetPos();      ///<ֱ�ӽ��䵽������
	void onGameOver();
};

inline void BackgroundBoard::setClearLineListener(CCObject* pObject,SEL_ClearLine callback)
{
	m_clearLineListener   = pObject;
	m_clearLineCallback  = callback;
}

inline void BackgroundBoard::setGameOverListener(CCObject* pObject,SEL_GameOver callback)
{
	m_gameOverListener  = pObject;
	m_gameOverCallback = callback;
}

#endif