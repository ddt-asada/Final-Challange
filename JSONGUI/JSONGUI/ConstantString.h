#pragma once

namespace CONSTANTS {

	/*�T�v�F�萔�N���X
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
	public ref class ConstantString {
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
		//�L�[������̎��ɕ`�悷��z��ł��邱�Ƃ�����������
		System::String^ ARRAY_STRING = "�z��";
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