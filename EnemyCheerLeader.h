#pragma once
#include "gameNode.h"

enum CLSTATE
{
	CLIdle,
	CLBegging,
	CLBlowback,
	CLDazed,
	CLFalling,
	CLHolding,
	CLHoldingrelease,
	CLJump,
	CLKnockdown,
	CLWalk,
	CLRun,
	CLJab,
	CLSpinpom,
	CLDoublepom,
	CLBackflip,
	CLWeaponSwing
};

class EnemyCheerLeader : public gameNode
{
private:
	CLSTATE _ClState;

	animation* _CLAni;

	image* _EnemyShadowImage;	//�׸��� �̹���(�߿���)
	image* _EnemyImage;		//ĳ���� �̹��� ���� �޶�����

	MYRECT _EnemyShadow;				//�� �׸���
	MYRECT _Enemy;						//�� ĳ���� �� �浹ó���� �簢��
	MYRECT _EnemyAttackExploration;		//�÷��̾� ���ý� �����ϴ� ����
	MYRECT _EnemyAttack;				//���� ���ݽ� �浹ó����
	MYRECT _EnemyClSearching;


	float _ClCenterX, _ClCenterY;

	float _ShadowX, _ShadowY; //�׸����� ���� (Enemy�� ���)

	float _EnemyX, _EnemyY; //ĳ������ ����

	float _ChaseAngle; //���߿� �÷��̾� ��ġ���� ���󰥶� ���� �Լ�

	float _Hp;

	bool _IsRight; //���ʿ�����

public:

	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void AniInit();
	void AniSet(CLSTATE state);

	void State();

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ClCenterX; }
	float GetEnemyY() { return _ClCenterY; }
	MYRECT GetEnemyHit() { return _Enemy; } //�ǰݿ���
	MYRECT GetEnemyAttackExploration() { return _EnemyAttackExploration; } //�÷��̾ ���ý� ����
	MYRECT GetCheerLeaderAttack() { return _EnemyAttack; } //���ݽ� ����
	MYRECT GetCheerLeaderSearching() { return _EnemyClSearching; }

	CLSTATE GetClState() { return _ClState; }

	POINTFLOAT GetCLPt() { POINTFLOAT temp; temp.x = _ClCenterX; temp.y = _ClCenterY; return temp; }

	void SetCenterX(float x) { _ClCenterX = x; }
	void SetCenterY(float y) { _ClCenterY = y; }

	void hitHP(float damge);

	float setHP() { return _Hp; }
};