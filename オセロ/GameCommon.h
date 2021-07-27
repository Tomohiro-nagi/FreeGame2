#pragma once

//�X�N���[���T�C�Y
#define SCREEN_SIZE_X (800)
#define SCREEN_SIZE_Y (800)

//�Q�[���J�n�G���A
#define GAME_AREA_X (100)

//�u���b�N�̃T�C�Y
#define BLOCK_IMG_SIZE (64)

//�u���b�N�̐�
#define SIZE (8)

//���̐�
#define SIZE_WIDTH (SIZE)

//�����̐�
#define SIZE_HEIGHT (SIZE)

#define PieceMAX (2)

enum BlockType {
	BLOCK_NONE = -1,
	BLOCK_BLACK = 0,
	BLOCK_WHITE = 1,
	BLOCK_MAX
};

enum {
	DIRECTION_UP ,
	DIRECTION_UP_LEFT,
	DIRECTION_LEFT,
	DIRECTION_DOWN_LEFT,
	DIRECTION_DOWN,
	DIRECTION_DOWN_RIGHT,
	DIRECTION_RIGHT,
	DIRECTION_UP_RIGHT,
	DIRECTION_MAX
};


