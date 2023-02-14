#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Quad.h"
#include "Matrix3x3.h"
#include "Circle.h"
#include "Randam.h"

static const int SCREEN_WIDTH = 1280;
static const int SCREEN_HEIGHT = 720;
const int Floor = 0;

class Screen
{
public:

	Matrix3x3 cameraMatrix;
	Matrix3x3 viewMatrix;
	Matrix3x3 orthoMatrix;
	Matrix3x3 viewportMatrix;
	Matrix3x3 wvpVpMatrix;
	Quad cameraQuad;
	Quad screenQuad;
	Quad viewportQuad;

	int width;
	int height;
	Vec2 worldCenter;
	Vec2 initialCameraPos;
	Vec2 scroll;
	Vec2 screenShake;
	Vec2 screenShakeNum;
	Vec2 screenSaveShakeNum;
	int shakeFrame;
	//�ǂ�����X�N���[�����邩
	Vec2 scrollFixedValue;
	//�}�b�v�̉������X�N���[���̕������Ԃ�
	int mapSheetsNum;


	Vec2 zoom;

	Screen();
	//�X�N���[��
	void Update(Vec2 player, int stageWidth);
	//�V�F�C�N
	void SetShake(int x, int y , int frame);
	void ShakeSetZero();
	//�|�[�Y
	bool isPause;

	/// <summary>
	/// �l�p�`��`�悷��
	/// </summary>
	/// <param name="x">�`�悷��l�p�`�̍�����W X</param>
	/// <param name="y">�`�悷��l�p�`�̍�����W Y</param>
	/// <param name="w">�`�悷��l�p�`�̉���</param>
	/// <param name="h">�`�悷��l�p�`�̏c��</param>
	/// <param name="angle">�`�悷��l�p�`�̉�]�p</param>
	/// <param name="color">�`�悷��l�p�`�̐F</param>
	/// <param name="fillMode">�h��Ԃ����[�h</param>
	/// <param name="shake">shake���邩</param>
	void DrawBox(float x, float y, int w, int h, float angle, unsigned int color, FillMode fillMode,bool shake = true);
	
	/// <summary>
	/// �l�p�`��`�悷��
	/// </summary>
	/// <param name="quad">�`�悷��l�p�`</param>
	/// <param name="angle">�`�悷��l�p�`�̉�]�p</param>
	/// <param name="color">�`�悷��l�p�`�̐F</param>
	/// <param name="fillMode">�h��Ԃ����[�h</param>
	/// <param name="shake">shake���邩</param>
	void DrawBox(const Quad& quad, float angle, unsigned int color, FillMode fillMode, bool shake = true);

	/// <summary>
	/// �O�p�`��`�悷��
	/// </summary>
	/// <param name="x1">�`�悷��O�p�`�̒��_1 X</param>
	/// <param name="y1">�`�悷��O�p�`�̒��_1 Y</param>
	/// <param name="x2">�`�悷��O�p�`�̒��_2 X</param>
	/// <param name="y2">�`�悷��O�p�`�̒��_2 Y</param>
	/// <param name="x3">�`�悷��O�p�`�̒��_3 X</param>
	/// <param name="y3">�`�悷��O�p�`�̒��_3 Y</param>
	/// <param name="color">�`�悷��O�p�`�̐F</param>
	/// <param name="fillMode">�h��Ԃ����[�h</param>
	/// <param name="shake">shake���邩</param>
	void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned int color, FillMode fillMode, bool shake = true);
	/// <summary>
	/// ����`�悷��
	/// </summary>
	/// <param name="x1">�`�悷����̎n�_���W X</param>
	/// <param name="y1">�`�悷����̎n�_���W Y</param>
	/// <param name="x2">�`�悷����̏I�_���W X</param>
	/// <param name="y2">�`�悷����̏I�_���W Y</param>
	/// <param name="color">�`�悷��O�p�`�̐F</param>
	/// <param name="shake">shake���邩</param>
	void DrawLine(float x1, float y1, float x2, float y2, unsigned int color, bool shake = true);
	/// <summary>
	/// �ȉ~��`�悷��
	/// </summary>
	/// <param name="x">�ȉ~�̒��S���W X</param>
	/// <param name="y">�ȉ~�̒��S���W Y</param>
	/// <param name="radiusX">�ȉ~�̔��a X</param>
	/// <param name="radiusY">�ȉ~�̔��a Y</param>
	/// <param name="angle">�ȉ~�̉�]�p(rad)</param>
	/// <param name="color">�ȉ~�̐F</param>
	/// <param name="shake">shake���邩</param>
	void DrawEllipse(float x, float y, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode, bool shake = true);
	/// <summary>
	/// �ȉ~��`�悷��
	/// </summary>
	/// <param name="a">�ȉ~�̒��S���W </param>
	/// <param name="radiusX">�ȉ~�̔��a X</param>
	/// <param name="radiusY">�ȉ~�̔��a Y</param>
	/// <param name="angle">�ȉ~�̉�]�p(rad)</param>
	/// <param name="color">�ȉ~�̐F</param>
	/// <param name="shake">shake���邩</param>
	void DrawEllipse(const Vec2& a, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode, bool shake = true);
	/// <summary>
	/// �ȉ~��`�悷��
	/// </summary>
	/// <param name="a">�ȉ~�̒��S���W </param>
	/// <param name="angle">�ȉ~�̉�]�p(rad)</param>
	/// <param name="color">�ȉ~�̐F</param>
	/// <param name="shake">shake���邩</param>
	void DrawEllipse(const Circle& a, float angle, unsigned int color, FillMode fillMode, bool shake = true);
	/// <summary>
	/// �X�v���C�g��`�悷��
	/// </summary>
	/// <param name="x">�`�悷��X�v���C�g�̍�����W X</param>
	/// <param name="y">�`�悷��X�v���C�g�̍�����W Y</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="scale">�`�悷��X�v���C�g�̔{�� X</param>
	/// <param name="scale">�`�悷��X�v���C�g�̔{�� Y</param>
	/// <param name="angle">�`�悷��X�v���C�g�̉�]�p</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="shake">shake���邩</param>
	void DrawSprite(int x, int y, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color, bool shake = true);
	/// <summary>
	/// �X�v���C�g�̎w���`�����݂̂�`���`�悷��
	/// </summary>
	/// <param name="x">�`�悷��X�v���C�g�̍�����W X</param>
	/// <param name="y">�`�悷��X�v���C�g�̍�����W X</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="scale">�`�悷��X�v���C�g�̔{�� X</param>
	/// <param name="scale">�`�悷��X�v���C�g�̔{�� Y</param>
	/// <param name="angle">�`�悷��X�v���C�g�̉�]�p</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="shake">shake���邩</param>
	void DrawSpriteRect(int x, int y, int srcX, int srcY, int srcW, int srcH, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color, bool shake = true);
	/// <summary>
	/// �l�p�`�`��
	/// </summary>
	/// <param name="x1">�`�悷��l�p�`�̍�����W X</param>
	/// <param name="y1">�`�悷��l�p�`�̍�����W Y</param>
	/// <param name="x2">�`�悷��l�p�`�̉E����W X</param>
	/// <param name="y2">�`�悷��l�p�`�̉E����W Y</param>
	/// <param name="x3">�`�悷��l�p�`�̍������W X</param>
	/// <param name="y3">�`�悷��l�p�`�̍������W Y</param>
	/// <param name="x4">�`�悷��l�p�`�̉E�����W X</param>
	/// <param name="y4">�`�悷��l�p�`�̉E�����W Y</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="shake">shake���邩</param>
	void DrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool shake = true);
	/// <summary>
	/// �l�p�`�`��
	/// </summary>
	/// <param name="quad">�`�悷��l�p�`</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="isFlip">���]���邩</param>
	/// <param name="shake">shake���邩</param>
	void DrawQuad(const Quad& quad, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool isFlip = false, bool shake = true);
	/// <summary>
	/// �X�N���[�����W�Ŏl�p�`�`��
	/// </summary>
	/// <param name="quad">�`�悷��l�p�`</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="shake">shake���邩</param>
	void ScreenDrawQuad(const Quad& quad, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool shake = true);
	/// <summary>
	/// �A�j���[�V�����l�p�`�`��
	/// </summary>
	/// <param name="quad">�`�悷��l�p�`</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X�i�ϐ��j</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
	/// <param name="sheets">�摜����</param>
	/// <param name="frame">���t���[���Ő؂�ւ��邩</param>
	/// <param name="animationframe">���Z���Ă���t���[���̕ϐ�</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="isFlip">���]���邩</param>
	/// <param name="isAdd">�A�j���[�V�����t���[�������Z���邩</param>
	/// <param name="isloop">���[�v���邩</param>
	/// <param name="shake">shake���邩</param>
	void DrawQuadAnime(const Quad& quad, int& srcX, int srcY, int srcW, int srcH, int sheets, int frame, int& animationframe, int textureHandle, unsigned int color, bool isFlip = false ,bool isAdd = true ,bool isloop = true, bool shake = true);
	

	/// <summary>
	/// �X�N���[�����W�ŃA�j���[�V�����l�p�`�`��
	/// </summary>
	/// <param name="quad">�`�悷��l�p�`</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X�i�ϐ��j</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
	/// <param name="sheets">�摜����</param>
	/// <param name="frame">���t���[���Ŏ��̘A�ԉ摜�Ɉڂ邩</param>
	/// <param name="animationframe">���Z���Ă���t���[���̕ϐ�</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
	/// <param name="isFlip">���]�����邩</param>
	/// <param name="isAdd">�A�j���[�V�����t���[�������Z���邩</param>
	/// <param name="shake">shake���邩</param>
	void ScreenDrawQuadAnime(const Quad& quad, int& srcX, int srcY, int srcW, int srcH, int sheets, int frame, int& animationframe, int textureHandle, unsigned int color, bool hanten = false, bool isAdd = true, bool shake = true);
};


