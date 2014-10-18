#ifndef  _TETROMINO_H_
#define  _TETROMINO_H_

#include "cocos2d.h"
#include "GlobalDefine.h"
#include "Block.h"

#define TetrominoEffect(n) (ES_USER_DEFINED+n)

#define TargetTetrominoEffect(n) (ES_USER_DEFINED+n+7)

USING_NS_CC;

struct TetrominoSize
{
	int _row;
	int _col;
};

/**
 * �߸���״�ķ���,������ǰλ�õľ����������λ�õ���ʾ����
 * ע�⣺1��ԭ�������½�,����ĵ������������
 *       2������������ʾ������Ҫ�� getTargetBlockNode ��ã����� getTargetRow ���������
 */
class Tetromino : public CCNode
{
public:
	Tetromino();
	~Tetromino();
	bool clockwiseRotate(const int* bgInfo);  ///<˳ʱ����ת
	bool move(bool bLeft,const int* bgInfo);  ///<�����ƶ�
	bool drop(const int* bgInfo);             ///<�½�

	bool setCol(int c,int* bgInfo);
	bool setRow(int r,int* bgInfo);

	int getCol()       {return m_col;}
	int getRow()       {return m_row;}
	int getRotate()    {return m_rotate;}
	int getShape()     {return m_shape;}

	///��ȡ�������У����Խ��������µ�һ�У�,�к���ת�Ǻ͵�ǰ��һ����
	int getTargetRow() {return m_targetRow;}  

	///ֱ�ӽ��䵽���Խ��������µ�һ��
	int gotoTargetPos();

	///�õ���С
	TetrominoSize getTetrominoSize();

	///�ж��Ƿ�����������
	bool isTouch(CCPoint worldCoord);

	///�жϴ����Ƿ��ڷ�������·�
	bool isUnderTetromino(CCPoint worldCoord);

	///�жϴ����Ƿ��ڷ��������
	bool isBesideTetromino(CCPoint worldCoord);
	
	///�õ����ս���λ�õ���ʾ����ľ���
	//CCNode* getTargetBlockNode(const int* bgInfo,const char* fnBlockTexture);
	///�õ����ս���λ�õ���ʾ����ľ���
	bool createTargetBlockNode(const int* bgInfo,const char* fnBlockTexture,CCNode* parent);
	void removeTargetBlockNode();

	void setTargetNodePos(const CCPoint& pos){m_targetBlockNode->setPosition(pos);}

	bool init(int shape,float blockSize,const char* fnBlockTexture);

	static Tetromino* create(int shape,float blockSize,const char* fnBlockTexture);

protected:
	int   m_col;        ///<���鵱ǰλ�õ���
	int   m_row;        ///<���鵱ǰλ�õ���
	int   m_targetRow;  ///<�����������У����Խ��������µ�һ�У�
	int   m_rotate;     ///<����˳ʱ����ת�Ĵ���
	int   m_shape;      ///<�������״
	float m_blockSize;  ///<����Ĵ�С���߳���

	Block*  m_blockSprite[4];         ///<��ǰ����λ�õ���ʾ����
	Block*  m_targetBlockSprite[4];   ///<�������ս���λ�õ���ʾ����
	CCNode* m_targetBlockNode;        ///<�������ս���λ�õ���ʾ����͹���������

	void setBlockSprPos();            ///<���÷��鵱ǰλ�õ���ʾ�����λ��(�ڵ�����ϵ�е�)
	void setTargetBlockSprPos();      ///<�������ս���λ�õ���ʾ�����λ��(�ڵ�����ϵ�е�)
	bool testDrop(const int* bgInfo); ///<���ڼ��㷽�����ս���λ��

	///�жϷ����Ƿ���װ������������ײ
	bool isCollision(int col,int row,int rotate,const int* bgInfo);

	bool testRotate(int rotate,const int* bgInfo);
};

inline Tetromino::Tetromino():
m_col(0),
m_row(BACKGROUND_ROW),
m_rotate(0),
m_shape(0),
m_blockSize(0.0f)
{
}

inline int Tetromino::gotoTargetPos()
{
	m_row = m_targetRow;
	return m_row;
}

#endif