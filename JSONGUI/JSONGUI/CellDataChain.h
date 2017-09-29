#pragma once

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
			if (target == nullptr) {
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
				//�Ώۂ̐e�ւɃ`�F�C�����폜����
				target->upper = nullptr;
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
			if (target == nullptr) {
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
	�쐬�ҁFK.Asada*/
	System::Void ChainDelete(cellchain^ delchain) {
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
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
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
	�쐬�ҁFK.Asada
	�X�V���e�F�擾�Ώۂ̍\���̂����݂��Ă��Ȃ��Ƃ���nullptr��Ԃ��悤�ɕύX
	�X�V���F2017.9.27
	�X�V�ҁFK.Asada*/
	cellchain^ GetColumnChain(System::Int32 rowindex, System::Int32 colindex, cellchain^ parent) {
		//�擾�����\���̂��i�[���邽�߂̕ԋp�p�̍\����
		cellchain^ colchain = gcnew cellchain();
		//�e�v�f����擾�Ώۂ̍s�̍\���̂��擾����
		colchain = GetRowChain(rowindex, parent);
		//����W��1�ȉ��ł���ΐe�v�f�̍\���̂�ԋp����
		if(colindex >= 1 || colchain == nullptr){
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
					colchain = nullptr;
				}
			}
		}
		return colchain;
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
		//�ԋp�p�̍\���̂�錾����
		cellchain^ rowchain = parent;
		//�擾�Ώۂ̍\���̂̈ʒu�܂ňړ�����
		for (int i = 0; i < rowindex; i++) {
			//�ړ��悪�Ȃ��Ȃ����Ƃ��͍\���̂��擾�ł��Ȃ������Ƃ���nullptr���擾
			if (rowchain->next != nullptr) {
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

	cellchain^ FirstChain(cellchain^ chain) {
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
			parent = this->FirstChain(parent);
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
	�쐬�ҁFK.Asada*/
	System::Void SetChainCell(System::Int32 rowindex, System::Int32 columnindex, System::String^ setdata, cellchain^ elem) {
		cellchain^ scan = elem;			//�Ώۂ̍\���̂��擾����
		//�Ώۂ̍s�̍\���̂ֈړ�����
		for (int i = 0; i < rowindex; i++) {
			//���̍s�̍\���̂����݂��Ă����
			if (scan->next != nullptr) {
				//���̍\���̂��擾����
				scan = scan->next;
			}//�Ȃ��ꍇ�͐V�K�ŋ󕶎��̓������\���̂�A������
			else {
				scan = this->ChainYoungBrother("", "", scan);
			}
		}
		//�Ώۂ̍\���̂ɍs�̐擪�ɑ����v�f�����邩�𒲂ׂ�
		if (scan->lower != nullptr) {
			//�v�f�̐擪�̍\���̂��擾����
			scan = scan->lower;
		}//�Ȃ��ꍇ�͐V�K�ŋ󕶎��̓������\���̂�A������
		else {
			scan = this->ChainChild("", "", scan);
		}
		//�s�̗v�f�̍\���̂��ړ����đΏۂ̑}���Ώۂ̍\���̂��擾����
		for (int i = 1; i < columnindex; i++) {
			//���̍\���̂����邩�𒲂ׂ�
			if (scan->next != nullptr) {
				//���̍\���̂��擾����
				scan = scan->next;
			}//�Ȃ��ꍇ�͐V�K�ŋ󕶎��̓������\���̂�A�����Ď擾����
			else {
				scan = this->ChainYoungBrother("", "", scan);
			}
		}
		//�}���Ώۂ̍\���̂��I�u�W�F�N�g�������Ă����
		if (scan->lower != nullptr) {
			//�Ώۂ̍\���̂̃L�[���ɕ������}������
			scan->key = setdata;
		}
		else {
			//�Ώۂ̍\���̂̒l�ɕ������}������
			scan->value = setdata;
		}
		return;
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
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}
};