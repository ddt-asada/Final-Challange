#pragma once

namespace CONSTANTS {

	/*�T�v�F�萔�N���X
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
	static public ref class ConstantString {
	public:
		ConstantString() {
		}

		//�ėp�I�ɗ��p����󕶎�
		System::String^ EMPTY_STRING = "";
		//0������������
		System::String^ ZERO_STRING = "0";
		//�G���[�������������Ƀ��[�U�[���ɕ\�����郁�b�Z�[�W
		System::String^ MESSAGE_STRING = "�G���[���������܂����B�����𒆒f���܂��B";
		//���C����ʂ̓W�J�{�^�����N���b�N���ꂽ�Ƃ��ɓW�J���Ȃ������Ƃ��ɕ\�����郁�b�Z�[�W
		System::String^ EXPANSION_STRING = "�W�J���ׂ���񂪂���܂���B";
		//���͓��e�������������Ƃ�\�����郁�b�Z�[�W
		System::String^ INPUT_ERROR_STRING = "���͏����m�F���Ă��������B\n";
		//�摜�̕`��Ɏ��s�������ɕ\�����郁�b�Z�[�W
		System::String^ IMAGE_ERROR_STRING = "�摜�̕`��Ɏ��s���܂����B\n";
		//�`��Ώۂ����݂��Ă��Ȃ����Ƃ�\�����郁�b�Z�[�W
		System::String^ DRAW_ERROR_STRING = "�`��Ώۂ��s���ł��B\n";
		//�`�悷��Z���̑傫�����I�[�o�[�t���E�����Ƃ��̃��b�Z�[�W
		System::String^ RECT_ERROR_STRING = "�`�悷��Z�����傫�����܂��B\n";
		//�t�@�C���ǂݍ��݃G���[�������ɕ\�����郁�b�Z�[�W
		System::String^ LOAD_ERROR_STRING = "�t�@�C���ǂݍ��݃G���[�B\n";
		//�ϊ��������ɕ\�����郁�b�Z�[�W
		System::String^ SUCCES_STRING = "JSON�t�@�C���̏o�͂��������܂����B";
		//����𒆒f�������ɕ\�����郁�b�Z�[�W
		System::String^ CANCEL_STRING = "���삪���f����܂���";
		//JSON�t�@�C����ǂݍ��񂾂��Ƃ�\�����郁�b�Z�[�W
		System::String^ LOAD_STRING = "JSON�t�@�C���̓ǂݍ��݂��������܂����B";
		//�V�K�ŕ\�𐶐�����Ƃ��̈ē����b�Z�[�W
		System::String^ NEW_STRING = "�V�K��JSON���쐬���܂��B\n�ŏ�ʂƂȂ�L�[������͂��Ă��������B";
		//�\�̐����ɐ����������Ƃ�\�����郁�b�Z�[�W
		System::String^ TABLE_STRING = "�\����������܂����B";
		//DB�Ƃ̒ʐM���s�������Ƃ�\�����郁�b�Z�[�W
		System::String^ DB_STRING = "DB�Ƃ̒ʐM���ʂ��\���o�͂��܂����B";
		//�\�Ɋւ��f�[�^�����������ꂽ���Ƃ�\�����郁�b�Z�[�W
		System::String^ INITIAL_STRING = "����������܂����B";
		//�s�E���ǉ�����Ƃ��ɐ擪����ɂ͒ǉ��ł��Ȃ����Ƃ�\�����郁�b�Z�[�W
		System::String^ ADD_ERROR_STRING = "�擪����ɂ͒ǉ��ł��܂���B";
		//�L�[������̎��ɕ`�悷��z��ł��邱�Ƃ�����������
		System::String^ ARRAY_STRING = "�z��";
		//�E������������
		System::String^ RIGHT_STRING = "�E";
		//��������������
		System::String^ LEFT_STRING = "��";
		//�������������
		System::String^ TOP_STRING = "��";
		//��������������
		System::String^ UNDER_STRING = "��";
		//��������ʂł��邱�Ƃ������{�^���̖��O
		System::String^ ELDER_BUTTON_STRING = "ElderButton";
		//������艺�ʂł��邱�Ƃ������{�^���̖��O
		System::String^ YOUNG_BUTTON_STRING = "YoungButton";
		//�L�����Z���{�^���̖��O
		System::String^ CANCEL_BUTTON_STRING = "CancelButton";
		//�\���̂�V�K�ō쐬����Ƃ��̏����l�ƂȂ�L�[��
		System::String^ CHAIN_KEY_STRING = "";
		//�\���̂�V�K�ō쐬����Ƃ��̏����l�ƂȂ�l
		System::String^ CHAIN_VALUE_STRING = "";
		//�ėp�G���[������
		System::String^ ERROR_STRING = "�G���[";
		//���C����ʂ̍s���e�L�X�g�{�b�N�X�̒��g�̏����l
		System::String^ INITIAL_ROW_STRING = "0";
		//���C����ʂ̗񐔃e�L�X�g�{�b�N�X�̒��g�̏����l
		System::String^ INITIAL_COLUMN_STRING = "0";
		//0�������ϐ�
		System::Int32 ZERO = 0;
	};
}