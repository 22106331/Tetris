#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "BackgroundBoard.h"
#include "FragmentEffect.h"
#include "RankList.h"
#include "Tetromino.h"
#include "WidgetManager.h"
#include <list>

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class GamesScence : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static CCScene* scene();

	/*��ť�Ļص�����*/
	///�˵���ť
	void btMenuCallback(CCObject* pSender,TouchEventType type);

	///��ʼ��ť
    void btStartCallback(CCObject* pSender,TouchEventType type);

	///���¿�ʼ��ť
	void btRestartCallback(CCObject* pSender,TouchEventType type);

	///������Ϸ��ť
	void btContinueCallback(CCObject* pSender,TouchEventType type);

	///���а�ť
	void btRankListCallback(CCObject* pSender,TouchEventType type);

	///������ť
	void btHelpCallback(CCObject* pSender,TouchEventType type);

	///�뿪��Ϸ��ť
	void btLeaveCallback(CCObject* pSender,TouchEventType type);

	///ȷ����ť���ϴ�������
	void btConfirmationCallback(CCObject* pSender,TouchEventType type);

	///ȡ����ť���ϴ�������
	void btCancelCallback(CCObject* pSender,TouchEventType type);

	/*BackgroundBoard����Ϣ�ص�*/
	///�ӷ֣���һ�л���б�������
    void onAddScore(int numLineCleared);

	///��ʾ�¸��������״
	void onNextBlock(int* next3Blocks);

	///GameOver
	void onGameOver();

	/*HttpTool����Ϣ�ص�*/
	///�õ������Ļص�
	void getPositionResponse(int score);

	///�ϴ������Ļص�
	void uploadScoreResponse(bool b);

    CREATE_FUNC(GamesScence);

private:

	///�˵������а�gameover�㡢�ϴ�������Щ��һ��ֻ�ܳ���һ��,����������
	WidgetManager    m_panelManager;

	///<��Ϸ�װ�,����Ľ��䡢�����ƶ�����ת�ȵȵ��߼���������ʵ��
	BackgroundBoard* m_bgBpard;       

	UILayer*         m_uiLayer;       ///<��cocostudio���ص���ϷUI
	UILabelAtlas*    m_scoreLabel;    ///<��ʾ����
	UILabelAtlas*    m_highestLabel;  ///<��ʾ��߷�
	UILabelAtlas*    m_numCLearLabel; ///<��ʾ�����˶�����
	UIButton*        m_btMenu;        ///<�˵���ť
	UITextField*     m_nickNameInput; ///<�����ǳƵ������
	UIImageView*     m_imgFrame;      ///<��Ϸ�װ���ݺ���
	RankList*        m_list;          ///<���а񣨹�����,��������Ľ���������ʵ�֣�

	std::list<Tetromino*> m_next3Tetrominos; ///<�������������ʾ����ʾ��״��

	int   m_score;          ///<����
	float m_blockSize;      ///<����Ĵ�С����Щ�����εı߳���
	float m_dropDelayTime;  ///<����ÿ�½�һ����ӳ�ʱ��
	int   m_clearLineCount; ///<����еļ���
	bool  m_isGgameRunning; ///<��Ϸ�Ƿ����������У����ھ����ǿ�ʼ��Ϸ���Ǽ�����Ϸ��
	CCPoint m_nextTipPos;       ///<��һ���������ʾλ��
	CCSize m_nextTipSize;      ///<��һ���������ʾ��С
	///���ø�����״�ķ������ɫ�������Ծ���ʵ�֣�
	void setEffectMatrix();

	void startGame();
};

#endif 
