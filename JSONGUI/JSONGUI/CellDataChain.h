#pragma once

/*�T�v�FJSON�f�[�^���`�F�C���\���ɂ��Ĉ������߂̃N���X
�쐬���F2017.9.20
�쐬�ҁFK.Asada*/
public class CellDataChain {
	//�f�t�H���g�R���X�g���N�^
	CellDataChain() {

	}
public:
	//�o�����`�F�C���f�[�^�̍\����
	typedef struct cellchain {
		char* key;					//�L�[��
		char* value;				//�L�[�ɑΉ������l
		struct cellchain* next;		//��ւ̃|�C���^
		struct cellchain* prev;		//�Z�ւ̃|�C���^
		struct cellchain* upper;	//�e�ւ̃|�C���^
		struct cellchain* lower;	//�q�ւ̃|�C���^
	};

	/*�T�v�F�e�փf�[�^��A������֐�
	�����Fchar*�F�e�֘A������\���̂̃L�[��
		�@char*�F�e�֘A������\���̂̒l
		  cellchain*�F�A���Ώۂ̍\����
	�߂�l�Fcellchain*�F�A����̍\����
	�쐬���F2017.9�D20
	�쐬�ҁFK.Asada*/
	cellchain* ChainParent(char* key, char* value, cellchain* target) {
		cellchain* chain;		//�A���p�̍\���̂�錾
		chain->key = key;		//�A������\���̂̃L�[�����i�[
		chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
		//�A���Ώۂɐe�����邩�𒲂ׂ�
		if (target->upper != nullptr) {
			//���̐e�̎q�Ƃ��ĘA���p�̍\���̂�A������
			target->upper->lower = chain;
			//�A���p�̍\���̂̐e�Ƃ��Č��̐e��A������
			chain->upper = target->upper;
		}//�e�����Ȃ��ꍇ
		else
		{
			//�A���p�̍\���̂̐e�����݂��Ȃ����Ƃ��i�[����
			chain->upper = nullptr;
		}
		//�Ώۂ̐e�Ƃ��ĘA���p�̍\���̂�A��
		target->upper = chain;
		//�A���p�̍\���̂̎q�Ƃ��đΏۂ̍\���̂�A��
		chain->lower = target;
		//�Z�����Ȃ����Ƃ��i�[����
		chain->prev = nullptr;
		//�킪���Ȃ����Ƃ��i�[����
		chain->next = nullptr;
		//�Ώۂ̐e�ɐV���ȍ\���̂�A���������\���̂�Ԃ�
		return target;
	}

	/*�T�v�F�q�փf�[�^��A������֐�
	�����Fchar*�F�q�֘A������\���̂̃L�[��
	�@char*�F�q�֘A������\���̂̒l
	 cellchain*�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain*�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada*/
	cellchain* ChainChild(char* key, char* value, cellchain* target) {
		cellchain* chain;		//�A���p�̍\���̂�錾
		chain->key = key;		//�A������\���̂̃L�[�����i�[
		chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
		//�A���ΏۂɎq�����邩�𒲂ׂ�
		if (target->lower != nullptr) {
			//���̎q�̐e�Ƃ��ĘA���p�̍\���̂�A������
			target->lower->upper = chain;
			//�A���p�̍\���̂̎q�Ƃ��Č��̎q��A������
			chain->lower = target->lower;
		}//�q�����Ȃ��ꍇ
		else
		{
			//�A���p�̍\���̂̎q�����݂��Ȃ����Ƃ��i�[����
			chain->lower = nullptr;
		}
		//�Ώۂ̎q�Ƃ��ĘA���p�̍\���̂�A��
		target->lower = chain;
		//�A���p�̍\���̂̐e�Ƃ��đΏۂ̍\���̂�A��
		chain->upper = target;
		//�Z�����Ȃ����Ƃ��i�[����
		chain->prev = nullptr;
		//�킪���Ȃ����Ƃ��i�[����
		chain->next = nullptr;
		//�Ώۂ̎q�ɐV���ȍ\���̂�A���������\���̂�Ԃ�
		return target;
	}

	/*�T�v�F�Z�փf�[�^��A������֐�
	�����Fchar*�F�Z�֘A������\���̂̃L�[��
	�@char*�F�Z�֘A������\���̂̒l
	 cellchain*�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain*�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada*/
	cellchain* ChainElderBrother(char* key, char* value, cellchain* target) {
		cellchain* chain;		//�A���p�̍\���̂�錾
		chain->key = key;		//�A������\���̂̃L�[�����i�[
		chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
		//�A���ΏۂɌZ�����邩�𒲂ׂ�
		if (target->prev != nullptr) {
			//���̌Z�̒�Ƃ��ĘA���p�̍\���̂�A������
			target->prev->next = chain;
			//�A���p�̍\���̂̌Z�Ƃ��Č��̌Z��A������
			chain->prev = target->prev;
		}//�Z�����Ȃ��ꍇ
		else
		{
			//�A���p�̍\���̂̌Z�����݂��Ȃ����Ƃ��i�[����
			chain->prev = nullptr;
		}
		//�Ώۂ̌Z�Ƃ��ĘA���p�̍\���̂�A��
		target->prev = chain;
		//�A���p�̍\���̂̒�Ƃ��đΏۂ̍\���̂�A��
		chain->next = target;
		//�e�����Ȃ����Ƃ��i�[����
		chain->upper = nullptr;
		//�q�����Ȃ����Ƃ��i�[����
		chain->lower = nullptr;
		//�Ώۂ̌Z�ɐV���ȍ\���̂�A���������\���̂�Ԃ�
		return target;
	}

	/*�T�v�F��փf�[�^��A������֐�
	�����Fchar*�F��֘A������\���̂̃L�[��
	�@char*�F��֘A������\���̂̒l
	 cellchain*�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain*�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada*/
	cellchain* ChainYoungBrother(char* key, char* value, cellchain* target) {
		cellchain* chain;		//�A���p�̍\���̂�錾
		chain->key = key;		//�A������\���̂̃L�[�����i�[
		chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
		//�A���Ώۂɒ킪���邩�𒲂ׂ�
		if (target->next != nullptr) {
			//���̒�̌Z�Ƃ��ĘA���p�̍\���̂�A������
			target->next->prev = chain;
			//�A���p�̍\���̂̒�Ƃ��Č��̒��A������
			chain->next = target->next;
		}//�킪���Ȃ��ꍇ
		else
		{
			//�A���p�̍\���̂̒킪���݂��Ȃ����Ƃ��i�[����
			chain->next = nullptr;
		}
		//�Ώۂ̒�Ƃ��ĘA���p�̍\���̂�A��
		target->next = chain;
		//�A���p�̍\���̂̌Z�Ƃ��đΏۂ̍\���̂�A��
		chain->prev = target;
		//�e�����Ȃ����Ƃ��i�[����
		chain->upper = nullptr;
		//�q�����Ȃ����Ƃ��i�[����
		chain->lower = nullptr;
		//�Ώۂ̒�ɐV���ȍ\���̂�A���������\���̂�Ԃ�
		return target;
	}
};