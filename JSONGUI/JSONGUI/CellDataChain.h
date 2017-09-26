#pragma once

using namespace System;

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
		String^ key;					//�L�[��
		String^ value;				//�L�[�ɑΉ������l
		ref struct cellchain^ next;		//��ւ̃|�C���^
		ref struct cellchain^ prev;		//�Z�ւ̃|�C���^
		ref struct cellchain^ upper;	//�e�ւ̃|�C���^
		ref struct cellchain^ lower;	//�q�ւ̃|�C���^
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
	cellchain^ ChainParent(String^ key, String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//�A���p�̍\���̂�錾
			chain->key = key;		//�A������\���̂̃L�[�����i�[
			chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
			if (target->key == nullptr && target->value == nullptr) {
				return chain;
			}
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
			return chain;
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
	}

	/*�T�v�F�q�փf�[�^��A������֐�
	�����FString^�F�q�֘A������\���̂̃L�[��
	�@String^�F�q�֘A������\���̂̒l
	 cellchain^�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain^�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada*/
	cellchain^ ChainChild(String^ key, String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//�A���p�̍\���̂�錾
			chain->key = key;		//�A������\���̂̃L�[�����i�[
			chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
			//�Ώۂ���̏ꍇ�͘A���p�̍\���̂����̂܂ܕԂ�
			if (target->key == nullptr && target->value == nullptr) {
				return chain;
			}
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
			return chain;
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
	}

	/*�T�v�F�Z�փf�[�^��A������֐�
	�����FString^�F�Z�֘A������\���̂̃L�[��
	�@String^�F�Z�֘A������\���̂̒l
	 cellchain^�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain^�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada*/
	cellchain^ ChainElderBrother(String^ key, String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//�A���p�̍\���̂�錾
			chain->key = key;		//�A������\���̂̃L�[�����i�[
			chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
			if (target->key == nullptr && target->value == nullptr) {
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
			return chain;
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
	}

	/*�T�v�F��փf�[�^��A������֐�
	�����FString^�F��֘A������\���̂̃L�[��
	�@String^�F��֘A������\���̂̒l
	 cellchain^�F�A���Ώۂ̍\����
	 �߂�l�Fcellchain^�F�A����̍\����
	 �쐬���F2017.9�D20
	 �쐬�ҁFK.Asada*/
	cellchain^ ChainYoungBrother(String^ key, String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//�A���p�̍\���̂�錾
			chain->key = key;		//�A������\���̂̃L�[�����i�[
			chain->value = value;	//�A������\���̂̃L�[���ɑΉ������l���i�[
			if (target->key == nullptr && target->value == nullptr) {
				return chain;
			}
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
			return chain;
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
	}

	/*�w�肳�ꂽ�ӏ��̗v�f���`�F�C���\������폜����֐�
	�����Fcellchain^ declchain�F�폜�Ώۂ̍\����
	�߂�l�F�Ȃ�
	�쐬���F2017.9.22
	�쐬�ҁFK.Asada*/
	Void ChainDelete(cellchain^ delchain) {
		try {
			//�폜�Ώۂ̍\���̂ɐe�Ǝq���������݂��Ă�����e�Ǝq��A��������
			if (delchain->upper != nullptr && delchain->lower != nullptr) {
				//�e�̎q�Ƃ��Ďq��A������
				delchain->upper->lower = delchain->lower;
				//�q�̐e�Ƃ��Đe��A������
				delchain->lower->upper = delchain->upper;
			}//�e�������݂��Ȃ��Ƃ��͐e�̎q�ւ̎Q�Ƃ��O��
			else if (delchain->upper != nullptr) {
				//�e�̎q�ւ̎Q�Ƃ��O��
				delchain->upper->lower = nullptr;
			}//�q�������݂��Ȃ��Ƃ��͎q�̐e�ւ̎Q�Ƃ��O��
			else if (delchain->lower != nullptr) {
				//�q�̐e�ւ̎Q�Ƃ��O��
				delchain->lower->upper = nullptr;
			}
			//�폜�Ώۂ̍\���̂ɌZ�ƒ헼�������݂��Ă�����Z�ƒ��A��������
			if (delchain->next != nullptr && delchain->prev != nullptr) {
				//�Z�̒�Ƃ��Ē��A������
				delchain->prev->next = delchain->next;
				//��̌Z�Ƃ��ČZ��A������
				delchain->next->prev = delchain->prev;
			}//�Z�������݂��Ȃ��Ƃ��͎Q�Ƃ��͂���
			else if (delchain->prev != nullptr) {
				//�Z�̒�ւ̎Q�Ƃ��O��
				delchain->prev->next = nullptr;
			}//�킵�����݂��Ȃ��Ƃ��͎Q�Ƃ��O��
			else if (delchain->next != nullptr) {
				//��̌Z�ւ̎Q�Ƃ��O��
				delchain->next->prev = nullptr;
			}
			//�e�q�A�Z�킩��Q�Ƃ��O�ꂽ�\���̂��폜����
			delete delchain;
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
	}

	/*�T�v�F�w�肳�ꂽ�ӏ��̗v�f���`�F�C���\�����擾����֐�
	�����FInt32�F�擾�������v�f�̍s���W
		�FInt32�F�擾�������v�f�̗���W
	�쐬���F2017.9.22
	�쐬�ҁFK.Asada*/
	cellchain^ GetChainData(Int32 rowindex, Int32 columnindex, cellchain^ grandparent) {
		try {
			cellchain^ scan = grandparent;		//�����p�̍\���̂�錾
			cellchain^ ret = gcnew cellchain();					//�ԋp�p�̕������錾
			//�\���̂̍s�����ւ̈ړ����s��
			scan = scan->lower;
			for (int i = 0; i < rowindex; i++) {
				//����擾����
				scan = scan->next;
			}
			//���ɗv�f�������
			if (scan->value != "") {
				//�����J�E���g
				if (this->getcount == columnindex) {
					//�擾�������v�f�̈ʒu�𓯂��ł������ꍇ�͎擾����
					ret = %*scan;
				}
				else {
					//�����J�E���g����
					this->getcount += 1;
				}
			}//�q�𑖍�����֐����Ăяo��
			else if(scan->lower != nullptr){
				//�q�𑖍����ăf�[�^���擾
				ret = GetValue(columnindex, scan->lower);
			}
			//�����܂łŎw�肵���ꏊ�ɗv�f�����݂��Ă��Ȃ����
			if (ret == nullptr) {
				ret = ChainYoungBrother("", "", grandparent);
			}
			this->getcount = 0;
			return %*ret;
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
	}

	/*�T�v�F�\�ɕ\������v�f���擾���邽�߂̍ċA�֐�
	�����FInt32 columnindex�F��
		�Fcellchain^ parent�F�����Ώۂ̍\����
	�쐬���F2017.9.24
	�쐬�ҁFK.Asada*/
	cellchain^ GetValue(Int32 columnindex, cellchain^ parent) {
		cellchain^ retdata = gcnew cellchain();
		for (; this->getcount <= columnindex && parent != nullptr; parent = parent->next) {
			//�擾���ׂ��v�f���������ꍇ
			if (parent->value != "") {
				//�����J�E���g
				if (this->getcount == columnindex) {
					//�擾�������v�f�̈ʒu�𓯂��ł������ꍇ�͎擾����
					retdata = %*parent;
				}
				else {
					//�����J�E���g����
					this->getcount += 1;
				}
			}
			if (retdata->value != nullptr) {
				break;
			}
			else if (parent->lower != nullptr) {
				retdata = this->GetValue(columnindex, parent->lower);
			}
		}

		return %*retdata;
	}

	/*�T�v�F�Ώۂ̍\���̂̂��ׂĂ̐e�L�[���擾���ĘA�������\���̂����֐�
	�����Fcellchain^ child�F�e�L�[���擾�������\����
	�߂�l�Fcellchain^ child�F�Ώۂ̐e�L�[�����ׂĘA�������\����
	�쐬���F2017.9.25
	�쐬�ҁFK.Asad*/
	cellchain^ GetParents(cellchain^ child) {
		//�擾�����e�L�[���i�[���邽�߂̍\����
		cellchain^ parent = gcnew cellchain();
		//�Ώۂ̍\���̂̒��j�܂ňړ�����
		for (; child->prev != nullptr; child = child->prev) {
			//�Z�Ɉړ����Ă���
		}
		//���j�ɐe�����݂��Ă����ꍇ
		if (child->upper != nullptr) {
			//�ċA���Đe�̐e�L�[���Ȃ����𒲂ׂĎ擾
			parent = GetParents(child->upper);
			//�擾�����e�L�[�̎q�Ƃ��Č��݂̍\���̂�A������
			child = ChainChild(child->key, child->value, parent);
		}
		//�e�L�[��A�������\���̂�ԋp����
		return child;
	}

	/*�T�v�F�s�̗v�f�̍\���̂��擾���邽�߂̊֐�
	�����FInt32�Frowindex�F�擾�Ώۂ̍s
		�FInt32�Fcolindex�F�擾�Ώۂ̍��W
		�Fcellchain^ parent�F�v�f���܂܂ꂽ�\����
	�߂�l�F�v�f�̍\����
	�쐬���F2017.9.25
	�쐬�ҁFK.Asada*/
	cellchain^ GetColumnChain(Int32 rowindex, Int32 colindex, cellchain^ parent) {
		int i = 0;
		//�擾�����\���̂��i�[���邽�߂̕ԋp�p�̍\����
		cellchain^ colchain = gcnew cellchain();
		//�e�v�f����擾�Ώۂ̍s�̍\���̂��擾����
		parent = GetRowChain(rowindex, parent);
		//�s�̗v�f�i�q�j�����݂��Ă���ΑΏۂ̍\���̂�T��
		if (parent->lower != nullptr) {
			//�q���擾
			parent = parent->lower;
			//�擾�Ώۂ̍\���̂܂ňړ�����
			for (; i < colindex; i++) {
				//�擾�Ώۂ̍\���̂����݂��Ă��Ȃ���Β��f����
				if (parent->next != nullptr) {
					//�킪���݂��Ă���Β�Ɉړ�����
					parent = parent->next;
				}
				else {
					//���[�v�𔲂���
					break;
				}
			}
			//�Ώۂ̍\���̂܂ňړ��ł��Ȃ������Ƃ�
			if (i != colindex) {
				//�V���ɒ��A�����ĘA����̍\���̂��擾����
				colchain = this->ChainYoungBrother("", "", parent);
			}
			else {
				//�擾�ł��Ă���΍\���̂�ԋp����
				colchain = parent;
			}
		}//�q�����Ȃ���Ύq�����
		else {
			colchain = this->ChainChild("", "", parent);
		}
		return colchain;
	}

	/*�T�v�F�s�̐擪�̍\���̂��擾���邽�߂̊֐�
	�����FInt32 rowindex�F�擾�Ώۂ̍s
		�Fcellchain^ parent�F�e�̍\����
	�߂�l�Fcellchain^ rowchain�F�擾�Ώۂ̍\����
	�쐬���F2017.9.25
	�쐬�ҁFK.Asada*/
	cellchain^ GetRowChain(Int32 rowindex, cellchain^ parent) {
		//�ԋp�p�̍\���̂�錾����
		cellchain^ rowchain = gcnew cellchain();
		//�����p�̕ϐ�
		int i = 0;
		//�擾�Ώۂ̍\���̂̈ʒu�܂ňړ�����
		for (; i < rowindex; i++) {
			//�ړ��悪�Ȃ��Ȃ����Ƃ��͒��f����
			if (parent->next != nullptr) {
				parent = parent->next;
			}
			else {
				break;
			}
		}
		//�Ώۂ̈ʒu�܂ňړ��ł��Ă����
		if (i != rowindex) {
			//�V���ɒ�Ƃ��č\���̂�A������
			rowchain = this->ChainYoungBrother("", "", parent);
		}
		else {
			//�擾�Ώۂ̍\���̂��擾����
			rowchain = parent;
		}
		//�擾�����\���̂�ԋp����
		return rowchain;
	}

	cellchain^ FirstChain(cellchain^ chain) {
		for (; chain->prev != nullptr; chain = chain->prev) {
		}
		return chain;
	}
};