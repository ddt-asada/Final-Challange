#pragma once
#include "ConstantString.h"

/*�T�v�FJSON�f�[�^���`�F�C���\���ɂ��Ĉ������߂̃N���X
�쐬���F2017.9.20
�쐬�ҁFK.Asada
�X�V���F2017.9.22
�X�V�ҁFK.Asada 
�X�V���e�F�}�l�[�W�^�N���X�A�\���̂ɕύX�A�\���̗̂v�f��char*����String^�^�֕ύX*/
public ref class CellDataChain {
public:
	//�o�����`�F�C���f�[�^�̍\����
	typedef ref struct cellchain {
		System::String^ key;					//�L�[��
		System::String^ value;				//�L�[�ɑΉ������l
		ref struct cellchain^ next;		//��ւ̃|�C���^
		ref struct cellchain^ prev;		//�Z�ւ̃|�C���^
		ref struct cellchain^ upper;	//�e�ւ̃|�C���^
		ref struct cellchain^ lower;	//�q�ւ̃|�C���^

		//�\���̂̃f�t�H���g�R���X�g���N�^
		ref struct cellchain() {
			this->key = nullptr;		//�L�[����������
			this->value = nullptr;		//�l��������
			this->next = nullptr;		//��ւ̃|�C���^��������
			this->prev = nullptr;		//�Z�ւ̃|�C���^��������
			this->upper = nullptr;		//�e�ւ̃|�C���^��������
			this->lower = nullptr;		//�q�ւ̃|�C���^��������
		}
	};

	//�f�t�H���g�R���X�g���N�^
	CellDataChain() {
	}


	int getcount = 0;

	/*�T�v�F�e�փf�[�^��A������֐�
	�����FString^�F�e�֘A������\���̂̃L�[��
		�@String^�F�e�֘A������\���̂̒l
		  cellchain^�F�A���Ώۂ̍\����
	�߂�l�Fcellchain^�F�A����̍\����
	�쐬���F2017.9�D20
	�쐬�ҁFK.Asada
	�X�V���F2017.9.22
	�X�V�ҁFK.Asada
	�X�V���e�F��O������ǉ�*/
	cellchain^ ChainParent(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//�A���p�̍\���̂�錾
			chain->key = key;		//�A������\���̂̃L�[�����i�[
			chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
			//�A���Ώۂ̍\���̂����݂��Ȃ��Ƃ��͐V�����\���̂�Ԃ�
			if (target == nullptr) {
				//�󕶎��̓������\���̂�ԋp����
				return chain;
			}
			//�A���Ώۂɐe�����邩�𒲂ׂ�
			if (target->upper != nullptr) {
				//���̐e�̎q�Ƃ��ĘA���p�̍\���̂�A������
				target->upper->lower = chain;
				//�A���p�̍\���̂̐e�Ƃ��Č��̐e��A������
				chain->upper = target->upper;
			}
			//�Ώۂ̐e�Ƃ��ĘA���p�̍\���̂�A��
			target->upper = chain;
			//�A���p�̍\���̂̎q�Ƃ��đΏۂ̍\���̂�A��
			chain->lower = target;
			//�Ώۂ̐e�ɐV���ȍ\���̂�A���������\���̂�Ԃ�
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�q�փf�[�^��A������֐�
	�����FString^�F�q�֘A������\���̂̃L�[��
	�@String^�F�q�֘A������\���̂̒l
	 cellchain^�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain^�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada*/
	cellchain^ ChainChild(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//�A���p�̍\���̂�錾
			chain->key = key;		//�A������\���̂̃L�[�����i�[
			chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
			//�Ώۂ���̏ꍇ�͘A���p�̍\���̂����̂܂ܕԂ�
			if (target == nullptr) {
				//��̂�������������ԋp����
				return chain;
			}
			//�A���ΏۂɎq�����邩�𒲂ׂ�
			if (target->lower != nullptr) {
				//���̎q�̐e�Ƃ��ĘA���p�̍\���̂�A������
				target->lower->upper = chain;
				//�A���p�̍\���̂̎q�Ƃ��Č��̎q��A������
				chain->lower = target->lower;
			}//�q�����Ȃ��ꍇ
			//�Ώۂ̎q�Ƃ��ĘA���p�̍\���̂�A��
			target->lower = chain;
			//�A���p�̍\���̂̐e�Ƃ��đΏۂ̍\���̂�A��
			chain->upper = target;
			//�Ώۂ̎q�ɐV���ȍ\���̂�A���������\���̂�Ԃ�
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�Z�փf�[�^��A������֐�
	�����FString^�F�Z�֘A������\���̂̃L�[��
	�@String^�F�Z�֘A������\���̂̒l
	 cellchain^�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain^�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada
	 �X�V���e�F���j�ɌZ��ǉ�����Ƃ��ɂ͐e���Ȃ��ς���悤�ɕύX
	 �X�V���F2017.9.28
	 �X�V�ҁFK.Asada
	 �X�V���e�F�q���ς���Ώۂ����������o�O���o�Ă����̂ŏC��
	 �X�V���F2017.9.30
	 �X�V�ҁFK.Asada*/
	cellchain^ ChainElderBrother(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//�A���p�̍\���̂�錾
			chain->key = key;		//�A������\���̂̃L�[�����i�[
			chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
			if (target == nullptr) {
				return chain;
			}
			//�A���ΏۂɌZ�����邩�𒲂ׂ�
			if (target->prev != nullptr) {
				//���̌Z�̒�Ƃ��ĘA���p�̍\���̂�A������
				target->prev->next = chain;
				//�A���p�̍\���̂̌Z�Ƃ��Č��̌Z��A������
				chain->prev = target->prev;
			}//�Z�����Ȃ��ꍇ
			else
			{
				//�A���p�̍\���̂̐e��Ώۂ̐e�ɂȂ��ς���
				chain->upper = target->upper;
				//�e�̎q�Ƃ��ĘA���p�̂�������������A������
				chain->upper->lower = chain;
				//�Ώۂ̐e�ւ̃`�F�C�����폜����
				target->upper = nullptr;
			}
			//�Ώۂ̌Z�Ƃ��ĘA���p�̍\���̂�A��
			target->prev = chain;
			//�A���p�̍\���̂̒�Ƃ��đΏۂ̍\���̂�A��
			chain->next = target;
			//�Ώۂ̌Z�ɐV���ȍ\���̂�A���������\���̂�Ԃ�
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F��փf�[�^��A������֐�
	�����FString^�F��֘A������\���̂̃L�[��
	�@String^�F��֘A������\���̂̒l
	 cellchain^�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain^�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada*/
	cellchain^ ChainYoungBrother(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//�A���p�̍\���̂�錾
			chain->key = key;		//�A������\���̂̃L�[�����i�[
			chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
			//�A���Ώۂ̍\���̂����݂��Ă��Ȃ��ꍇ��
			if (target == nullptr) {
				//�V�K�ŋ󕶎��̍\���̂�ԋp����
				return chain;
			}
			//�A���Ώۂɒ킪���邩�𒲂ׂ�
			if (target->next != nullptr) {
				//���̒�̌Z�Ƃ��ĘA���p�̍\���̂�A������
				target->next->prev = chain;
				//�A���p�̍\���̂̒�Ƃ��Č��̒��A������
				chain->next = target->next;
			}
			//�Ώۂ̒�Ƃ��ĘA���p�̍\���̂�A��
			target->next = chain;
			//�A���p�̍\���̂̌Z�Ƃ��đΏۂ̍\���̂�A��
			chain->prev = target;
			//�Ώۂ̒�ɐV���ȍ\���̂�A���������\���̂�Ԃ�
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�w�肳�ꂽ�ӏ��̗v�f���`�F�C���\������폜����֐�
	�����Fcellchain^ declchain�F�폜�Ώۂ̍\����
	�߂�l�F�Ȃ�
	�쐬���F2017.9.22
	�쐬�ҁFK.Asada
	�X�V��2017.9.29
	�X�V�ҁFK.Asada
	�X�V���e�F�֐�����ύX�A�w�肳�ꂽ�ӏ��̎q�v�f���e�����݂��Ȃ��Ȃ邽�ߍ폜����悤�ɕύX�A�Ώۂɐe�������Ƃ��̏������@���ύX
	�X�V���e�F�\���̂��폜���鏈�����T�u���[�`����
	�X�V���F2017.10.3
	�X�V�ҁFK.Asada*/
	System::Void DeleteChain(cellchain^ delchain) {
		try {
			//�폜�ΏۂɎq�����邩�𒲂ׂ�
			if (delchain->lower != nullptr) {
				//�q������ꍇ�͐e�ɓ�����\���̂��폜����邽�ߕK�v�Ȃ��Ȃ�̂ō폜����
				this->DeleteYounger(delchain->lower);
			}
			//�\���̂��폜����֐����Ăяo��
			this->DeleteLink(delchain);
			return;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�Ώۂ̍\���̂̌Z��A�e�Ƃ̘A�����폜���č\���̂��폜����֐�
	�����Fcellchain^ parent�F�폜�Ώۂ̍\����
	�߂�l�F�Ȃ�
	�쐬���F2017.10.3
	�쐬�ҁFK.Asada*/
	System::Void DeleteLink(cellchain^ parent) {
		try {
			//�폜�Ώۂ̍\���̂ɌZ�ƒ헼�������݂��Ă�����Z�ƒ��A��������
			if (parent->next != nullptr && parent->prev != nullptr) {
				//�Z�̒�Ƃ��Ē��A������
				parent->prev->next = parent->next;
				//��̌Z�Ƃ��ČZ��A������
				parent->next->prev = parent->prev;
			}//�Z�������݂��Ȃ��Ƃ��͎Q�Ƃ��͂���
			else if (parent->prev != nullptr) {
				//�Z�̒�ւ̎Q�Ƃ��O��
				parent->prev->next = nullptr;
			}//�킵�����݂��Ȃ��Ƃ��͌��̍\���̂ɐe�����邩�𒲂ׂ�
			else if (parent->next != nullptr) {
				//�e������ꍇ�͐e�̎Q�Ƃ�ς���
				if (parent->upper != nullptr) {
					//�e������ꍇ�͒�Ɉ����p��
					parent->upper->lower = parent->next;
					//��ɐe��n��
					parent->next->upper = parent->upper;
				}
				//��̌Z�ւ̎Q�Ƃ��O��
				parent->next->prev = nullptr;
			}//�Z�킪���炸�ɐe�݂̂����݂���ꍇ
			else if (parent->upper != nullptr) {
				//�e�̎q���폜����
				parent->upper->lower = nullptr;
			}
			//�\���̂̃L�[�����폜����
			parent->key = nullptr;
			//�\���̂̒l���폜����
			parent->value = nullptr;
			//�\���̂���ɂ���
			parent = nullptr;
			//��ɂȂ����\���̂��폜����
			delete parent;
			return;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}
	
	/*�T�v�F�Ώۂ̍\���̂��Ⴂ�\���́i�q�A��j�����ׂč폜����֐�
	�����Fcellchain^ parent�F�폜�Ώۂ̍\����
	�߂�l�F�Ȃ�
	�쐬���F2017.9.29
	�쐬�ҁFK.Asada*/
	System::Void DeleteYounger(cellchain^ parent) {
		//�\���̂��Ȃ��ς���Ƃ���NULL���w�����ꂪ����̂ŗ�O����
		try {
			//�ΏۂɎq�����邩�𒲂ׂ�
			if (parent->lower != nullptr) {
				//�q������Ƃ��͍ċA���Ă���ɍ폜���Ă���
				this->DeleteYounger(parent->lower);
			}
			//�Ώۂɒ킪����ꍇ�͂��ׂč폜����
			if (parent->next != nullptr) {
				//�ċA���Ē���폜����
				this->DeleteYounger(parent->next);
			}
			//�\���̂��폜����֐����Ăяo��
			this->DeleteLink(parent);
			return;
		}
		//NULL�֌W�̗�O��ߑ�
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�s�̗v�f�̍\���̂��擾���邽�߂̊֐�
	�����FInt32�Frowindex�F�擾�Ώۂ̍s
		�FInt32�Fcolindex�F�擾�Ώۂ̍��W
		�Fcellchain^ parent�F�v�f���܂܂ꂽ�\����
	�߂�l�F�v�f�̍\����
	�쐬���F2017.9.25
	�쐬�ҁFK.Asada
	�X�V���e�F�擾�Ώۂ̍\���̂����݂��Ă��Ȃ��Ƃ���nullptr��Ԃ��悤�ɕύX
	�X�V���F2017.9.27
	�X�V�ҁFK.Asada*/
	cellchain^ GetColumnChain(System::Int32 rowindex, System::Int32 colindex, cellchain^ parent) {
		try {
			//�擾�����\���̂��i�[���邽�߂̕ԋp�p�̍\����
			cellchain^ colchain = gcnew cellchain();
			//�e�v�f����擾�Ώۂ̍s�̍\���̂��擾����
			colchain = GetRowChain(rowindex, parent);
			//����W��1�ȉ��ł���ΐe�v�f�̍\���̂�ԋp����
			if (colindex >= 1 && colchain != nullptr) {
				//�s�̗v�f�i�q�j�����݂��Ă���ΑΏۂ̍\���̂�T��
				if (colchain->lower != nullptr) {
					//�q���擾
					colchain = colchain->lower;
				}//���݂��Ă��Ȃ����nullptr���i�[
				else {
					colchain = nullptr;
				}
				//�擾�Ώۂ̍\���̂܂ňړ�����
				for (int i = 1; i < colindex; i++) {
					//�擾�Ώۂ̍\���̂����݂��Ă��Ȃ���Β��f����
					if (colchain != nullptr && colchain->next != nullptr) {
						//�킪���݂��Ă���Β�Ɉړ�����
						colchain = colchain->next;
					}
					//���݂��Ă��Ȃ����nullptr���i�[
					else {
						//��̍\���̂��擾
						colchain = nullptr;
						//���[�v�𔲂���
						break;
					}
				}
			}
			return colchain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�s�̐擪�̍\���̂��擾���邽�߂̊֐�
	�����FInt32 rowindex�F�擾�Ώۂ̍s
		�Fcellchain^ parent�F�e�̍\����
	�߂�l�Fcellchain^ rowchain�F�擾�Ώۂ̍\����
	�쐬���F2017.9.25
	�쐬�ҁFK.Asada
	�X�V���e�F�擾�Ώۂ̍\���̂����݂��Ă��Ȃ��Ƃ���nullptr��Ԃ��悤�ɕύX
	�X�V���F2017.9.27
	�X�V�ҁFK.Asada*/
	cellchain^ GetRowChain(System::Int32 rowindex, cellchain^ parent) {
		try {
			//�ԋp�p�̍\���̂�錾����
			cellchain^ rowchain = parent;
			//�擾�Ώۂ̍\���̂̈ʒu�܂ňړ�����
			for (int i = 0; i < rowindex; i++) {
				//�ړ��悪�Ȃ��Ȃ����Ƃ��͍\���̂��擾�ł��Ȃ������Ƃ���nullptr���擾
				if (rowchain != nullptr && rowchain->next != nullptr) {
					//��̍\���̂Ɉړ�����
					rowchain = rowchain->next;
				}
				else {//�Ȃ��ꍇ��nullptr���擾���ă��[�v�𔲂���
					rowchain = nullptr;
					//���[�v�𔲂���
					break;
				}
			}
			//�擾�����\���̂�ԋp����
			return rowchain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�Ώۂ̍\���̂̒��j���擾���邽�߂̊֐�
	�����Fcellchain^ chain�F�Ώۂ̍\����
	�߂�l�Fcellchain^ chain�F�Ώۂ̍\���̂̒��j
	�쐬���F2017.10.3
	�쐬�ҁFK.Asada*/
	cellchain^ GetElderChain(cellchain^ chain) {
		try {
			for (; chain->prev != nullptr; chain = chain->prev) {
			}
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�Ώۂ̍\���̂̐e�̍\���̂��擾���邽�߂̊֐�
	�����FInt32 parentindex�F���Ԗڂ̐e���擾���邩
		�Fcellchain^ child�F�Ώۂ̍\����
	�߂�l�F�e�̍\����
	�쐬���F2017.9.26
	�쐬�ҁFK.Asada*/
	cellchain^ GetParent(cellchain^ child, System::Int32 parentindex) {
		//�擾�����e���i�[����\���̂�錾����
		cellchain^ parent = child;
		//�Ώۂ̐e�̈ʒu�܂ő�������
		for (int i = 0; i < parentindex; i++) {
			//�Ώۂ̒��j�܂ňړ�����
			parent = this->GetElderChain(parent);
			//�Ώۂ̒��j�ɐe�����݂��邩
			if (parent->upper != nullptr) {
				//�e���擾����
				parent = parent->upper;
			}
			else {
				//�e���Ȃ������ꍇ��nullptr���擾
				parent = nullptr;
				//���[�v�𔲂���
				break;
			}
		}
		//�擾�����\���̂�ԋp����
		return parent;
	}

	/*�T�v�F�w�肵���ӏ��ɍ\���̂�}������֐�
	�����FInt32 rowindex�F�}������s���W
		�FInt32 columnindex�F����W
		�FString^ setdata�F�}������\���̂ɃZ�b�g���镶����
		�Fcellchain^ elem�F�}���Ώۂ̍\����
	�߂�l�F�Ȃ�
	�쐬���F2017.9.27
	�쐬�ҁFK.Asada
	�X�V���e�F�s�̐擪��ҏW�������ɑI���ӏ��̎q���ҏW�����o�O���������̂ŏC���A�֐���ǉ�
	�X�V���F2017.9.30
	�X�V�ҁFK.Asada*/
	cellchain^ SetChainCell(System::Int32 rowindex, System::Int32 columnindex, System::String^ setdata, cellchain^ elem, System::Boolean editkey, System::Boolean editvalue) {
		//�\���̂�null�֌W�̗�O��ߑ����邽�߂̗�O����
		try {
			cellchain^ scan = elem;			//�Ώۂ̍\���̂��擾����
			//�ΏۂɎq�����邩�𒲂ׂ�
			scan = this->CheckChild(scan);
			//�Ώۂ̍s�̍\���̂ֈړ�����
			for (int i = 0; i < rowindex; i++) {
				//�킪���邩�𔻒肷��֐����Ăяo��
				scan = this->CheckBrother(scan);
			}
			//�Ώۂ��s�̐擪�Ȃ炷�łɍs�̐擪���擾���Ă���̂Œl�̑������ֈړ�
			if (columnindex > 0) {
				//�Ώۂ̍\���̂ɍs�̐擪�ɑ����v�f�����邩�𒲂ׂ�
				scan = this->CheckChild(scan);
				//�s�̗v�f�̍\���̂��ړ����đΏۂ̑}���Ώۂ̍\���̂��擾����
				for (int i = 1; i < columnindex; i++) {
					//���̍\���̂����邩�𒲂ׂ�
					scan = this->CheckBrother(scan);
				}
			}
			//�\���̂̏�Ԃ𔻕ʂ��đΉ������ꏊ�ɕ�������i�[����֐����Ăяo��
			this->SetCellData(setdata, scan, editkey, editvalue);
			//�쐬�����\���̂�ԋp����
			return scan;
		}
		//null�Q�Ɨ�O��ߑ�
		catch (System::NullReferenceException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
		//null������O��ߑ�
		catch (System::ArgumentNullException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�Ώۂ̍\���̂̈�Ԓ�̍\���̂��擾����֐�
	�����G�Ώۂ̍\����
	�߂�l�F�Ώۂ̈�Ԓ�̍\����
	�쐬���F2017.9.27
	�쐬�ҁFK.Asada*/
	cellchain^ GetYoungChain(cellchain^ scan) {
		try {
			//�Ώۂ̈�Ԓ�܂ňړ�����
			for (; scan->next != nullptr; scan = scan->next) {

			}
			//�擾�������Ԃ�
			return scan;
		}
		//null�Q�Ɨ�O��ߑ�
		catch (System::NullReferenceException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
		//null������O��ߑ�
		catch (System::ArgumentNullException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�Ώۂ̍\���̂Ɏq�����邩���m�F����֐�
	�����Fcellchain^ family�F�Ώۂ̍\����
	�߂�l�Fcellchain^ family�F�Ώۂ̎q��
	�쐬���F2017.9.30
	�쐬�ҁFK.Asada*/
	cellchain^ CheckChild(cellchain^ family) {
		//�\���̂ł�null�֌W�̗�O����
		try {
			//�q�����邩�𒲂ׂȂ���΍��
			if (family->lower != nullptr) {
				//�q������ꍇ�͂��̂܂܎q��Ԃ�
				family = family->lower;
			}
			//�q�����Ȃ��ꍇ�͍��
			else {
				//�q���Ƃ��ċ�̍\���̂�A������
				family = this->ChainChild("", "", family);
			}
			//�擾�����q����Ԃ�
			return family;
		}
		//null�Q�Ɨ�O��ߑ�
		catch (System::NullReferenceException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
		//null������O��ߑ�
		catch (System::ArgumentNullException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�Ώۂɒ킪���邩�𒲂ׂ�֐�
	�����Fcellchain^ family�F�Ώۂ̍\����
	�߂�l�Fcellchain^ family�F�Ώۂ̒�
	�쐬���F2017.9.30
	�쐬�ҁFK.Asada*/
	cellchain^ CheckBrother(cellchain^ family) {
		//�\���̂ł�null�֌W�̗�O��ߑ����邽�߂̗�O����
		try {
			//�킪���邩�𒲂ׁA�Ȃ���΍��
			if (family->next != nullptr) {
				//���̂܂ܒ���擾����
				family = family->next;
			}
			//���Ȃ���Β�����
			else {
				family = ChainYoungBrother("", "", family);
			}
			//�Ώۂ̒��ԋp����
			return family;
		}
		//null�Q�Ɨ�O��ߑ�
		catch (System::NullReferenceException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
		//null������O��ߑ�
		catch (System::ArgumentNullException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
	}

	/*�T�v�F�Ώۂ̏�Ԃ𔻕ʂ��đΏۂ̍\���̂̒l�܂��̓L�[���ɕ������������֐�
	�����FString^ setdata�F�\���̂ɑ�����镶����
		�Fcellchain^ scan�F�Ώۂ̍\����
		�FBoolean editkey�F�L�[����ҏW���邩�ǂ����̔���
		�FBoolean editvalue�F�l��ҏW���邩�ǂ����̔���
	�߂�l�F�Ȃ�
	�쐬���F2017.10.2
	�쐬�ҁFK.Asada*/
	System::Void SetCellData(System::String^ setdata, cellchain^ scan, System::Boolean editkey, System::Boolean editvalue){
		//�L�[�ҏW���[�h�ł����
		if (editkey) {
			//�Ώۂ̍\���̂̃L�[���ɕ������������
			scan->key = setdata;
		}//�l�ҏW���[�h�ł����
		else if (editvalue) {
			//�Ώۂ̍\���̂̒l�ɕ������������
			scan->value = setdata;
		}//�ҏW���[�h���w�肳��Ă��炸�Ώۂ̍\���̂Ɏq�����݂��Ă����
		else if (scan->lower != nullptr) {
			//�ʏ�ʂ�L�[���ɕ������������
			scan->key = setdata;
		}//�ҏW���[�h���w�肳��Ă��炸�Ώۂ̍\���̂Ɏq�����Ȃ����
		else {
			//�l�ɕ������������
			scan->value = setdata;
		}
		//�ҏW���I����
		return;
	}

	/*�T�v�F�Ώۂ̏�Ԃ𔻕ʂ��ăL�[���܂��͒l�̂ǂ��炩��ԋp����֐�
	�����Fcellchain^ cell�F�Ώۂ̍\����
		�FBoolean getkey�F�L�[�����擾���邩�ǂ����̔���
		�FBoolean getvalue�F�l���擾���邩�ǂ����̔���
	�߂�l�F�Ώۂ���擾����������
	�쐬���F2017.10.2
	�쐬�ҁFK.Asada*/
	System::String^ GetCellString(cellchain^ cell, System::Boolean getkey, System::Boolean getvalue) {
		System::String^ data = "";			//�ԋp�p�̕�������i�[���邽�߂̕�����
		//�Ώۂ̍\���̂����݂��Ă��Ȃ����
		if (cell == nullptr) {
			//�󕶎���ԋp����
			data = "";
		}//�L�[���擾��Ԃł����
		else if (getkey) {
			//�L�[�����擾����
			data = cell->key;
		}//�l�擾��Ԃł����
		else if (getvalue) {
			//�l���擾����
			data = cell->value;
		}//�ǂ���ł��Ȃ��\���̂Ɏq�����݂��Ă����
		else if (cell->lower != nullptr) {
			//�ʏ�ʂ�L�[�����擾����
			data = cell->key;
		}//�ǂ���ł��Ȃ��\���̂Ɏq�����݂��Ă��Ȃ����
		else {
			data = cell->value;
		}
		//�擾�����������ԋp����
		return data;
	}

	/*�T�v�F�`�F�C���\�����R�s�[���邽�߂̊֐�
	�����Fcellchain^ copy�F�R�s�[�Ώۂ̍\����
	�߂�l�Fcellchain^ paste�F�V�K�ɃR�s�[�����\����
	�쐬���F2017.10.3
	�쐬�ҁFK.Asada*/
	cellchain^ CopyChain(cellchain^ copy) {
		try {
			cellchain^ paste = nullptr;		//�R�s�[�����\����
			//�Ώۂ̒��g���Ȃ��Ȃ�܂ő�������
			for (; copy != nullptr; copy = copy->next) {
				//�R�s�[���Ȃ����ɂȂ��ł���
				paste = this->ChainYoungBrother(copy->key, copy->value, paste);
				//�q������ΗD�悵�ď���
				if (copy->lower != nullptr) {
					//�q������ΗD�悵�ď������ăR�s�[����
					paste->lower = this->CopyChain(copy->lower);
					//�q�̐e�Ƃ��ĘA��
					paste->lower->upper = paste;
				}
			}
			//�R�s�[�̏I������\���̂̒��j��ԋp����
			return %*this->GetElderChain(paste);
		}
		catch (System::NullReferenceException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
		//null������O��ߑ�
		catch (System::ArgumentNullException^ e) {
			//��O���R���\�[����ɕ\���A�\�ɂ̓��C����ʂ̗�O�����ŕ\������
			System::Console::WriteLine(e);
		}
	}
};