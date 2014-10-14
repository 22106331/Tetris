#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "BackgroundBoard.h"
#include "FragmentEffect.h"
#include "RankList.h"
#include "Tetromino.h"
#include "WidgetManager.h"

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
	void onNextBlock(int next);

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
	UILabelAtlas*    m_levelLabel;    ///<��ʾ�Ѷ�
	UIButton*        m_btMenu;        ///<�˵���ť
	UITextField*     m_nickNameInput; ///<�����ǳƵ������
	UIImageView*     m_imgFrame;      ///<��Ϸ�װ���ݺ���
	UIImageView*     m_levelTip;      ///<�Ѷȵ���ʾ�װ�
	UIImageView*     m_nextTip;       ///<��һ���������ʾ�װ壨ֻ���ṩһ��λ�úʹ�С����Ϣ��
	Tetromino*       m_nextTetromino; ///<��һ���������ʾ����ʾ��״��
	RankList*        m_list;          ///<���а񣨹�����,��������Ľ���������ʵ�֣�

	int   m_score;          ///<����
	float m_blockSize;      ///<����Ĵ�С����Щ�����εı߳���
	float m_dropDelayTime;  ///<����ÿ�½�һ����ӳ�ʱ��
	int   m_level;          ///<�Ѷ�
	int   m_clearLineCount; ///<����еļ���
	bool  m_isGgameRunning; ///<��Ϸ�Ƿ����������У����ھ����ǿ�ʼ��Ϸ���Ǽ�����Ϸ��

	///���ø�����״�ķ������ɫ�������Ծ���ʵ�֣�
	void setEffectMatrix();

	void startGame();

	///��ʾ����Ŀɼ������ɼ�,����ʾ����ʾ��,���Ѷȡ���Щ�֣�
	void setTipBoardVisible(bool bVisible);
};

#endif 
