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
		//�쐬����JSON�t�@�C���̕ۑ����I������Ƃ��ɕ\�����郁�b�Z�[�W
		System::String^ OUT_PATH_MESSAGE = "JSON�t�@�C���̕ۑ����I�����Ă��������B\n";
		//�t�@�C���p�X�����͂���Ă��Ȃ��Ƃ��ɕ\�����郁�b�Z�[�W
		System::String^ NOT_PATH_MESSAGE = "�t�@�C���p�X�����͂���Ă��܂���B\n";
		//�N�G�������͂���Ă��Ȃ��Ƃ��ɕ\�����郁�b�Z�[�W
		System::String^ NOT_QUERY_MESSAGE = "�N�G�������͂���Ă��܂���B\n";
		//�G���[�������������Ƀ��[�U�[���ɕ\�����郁�b�Z�[�W
		System::String^ MESSAGE_STRING = "�G���[���������܂����B�����𒆒f���܂��B\n�G���[���e�̓R���\�[�������m�F���������B";
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
		//�ϊ��Ώۂ��Ȃ��Ƃ��ɕ\�����郁�b�Z�[�W
		System::String^ CONV_ERROR_MESSAGE = "JSON�̏o�͂Ɏ��s���܂����B\n�ϊ��Ώۂ����݂��Ă��܂���B";
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
		//�s�E����폜����Ƃ��ɐ擪����͍폜�ł��Ȃ����Ƃ�\�����郁�b�Z�[�W
		System::String^ DELETE_ERROR_STRING = "�擪�͍폜�ł��܂���B";
		//�폜�Ώۂ����݂��Ă��Ȃ��Ƃ��ɕ\�����郁�b�Z�[�W
		System::String^ NOT_FOUND_ERROR = "�Ώۂ����݂��Ă��܂���B\n";
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
		System::String^ CHAIN_KEY_STRING = "key";
		//�\���̂�V�K�ō쐬����Ƃ��̏����l�ƂȂ�l
		System::String^ CHAIN_VALUE_STRING = "value";
		//�ėp�G���[������
		System::String^ ERROR_STRING = "�G���[";
		//���C����ʂ̍s���e�L�X�g�{�b�N�X�̒��g�̏����l
		System::String^ INITIAL_ROW_STRING = "0";
		//���C����ʂ̗񐔃e�L�X�g�{�b�N�X�̒��g�̏����l
		System::String^ INITIAL_COLUMN_STRING = "0";
		//0�������ϐ�
		System::Int32 ZERO = 0;
		//-1�������ϐ��I�����W�̏����l�Ƃ��ė��p
		System::Int32 INITIAL_INDEX = -1;
		//�\�摜��̃Z���������̕�
		System::Int32^ RCT_WIDTH = 150;
		//�\�摜��̃Z���������̍���
		System::Int32^ RCT_HEIGHT = 100;
		//���C����ʂɂĕ\�摜��u���ʒu
		System::Drawing::Point TABLE_LOCATION = System::Drawing::Point(10, 150);
		//�\�摜�̑I���ӏ����n�C���C�g����Ƃ��̐F
		System::Drawing::Brush^ SELECT_COLOR = gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(100, System::Drawing::Color::Yellow));
		//�\�摜�̔w�i�F
		System::Drawing::Brush^ BACK_COLOR = gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(255, System::Drawing::Color::White));
		//�\�摜�̕`��Ώۂ��I�u�W�F�N�g�ł��邱�Ƃ������F
		System::Drawing::Brush^ OBJECT_COLOR = gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(100, System::Drawing::Color::Blue));
		//�\�摜��ɕ�����`�悷��Ƃ��̃t�H���g�ݒ�
		System::Drawing::Font^ TABLE_FONT = gcnew System::Drawing::Font(System::Drawing::FontFamily::GenericSansSerif, 14, System::Drawing::FontStyle::Regular);
	};
}