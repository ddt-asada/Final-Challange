#pragma once

namespace process {
	using namespace System;

	//�쐬���F2017.9.2
	//�쐬�ҁFK.Asada
	//���������������֐��Q�N���X�B
	ref class StringProcess {
	public:
		//�f�t�H���g�R���X�g���N�^
		StringProcess() {
		};

		//�t�@�C���p�X��蕶������擾���Ă��̕����񂩂�s���A�񐔁A������𔲂��o���B
		String^ ReadyString(String^ JSONPath) {
			String^ ret = "";
			//�󂯎�����t�@�C���p�X��蕶������擾����֐����Ăяo���B
			ret = LoadJSON(JSONPath);
			return ret;
		}

		//�t�@�C����蕶������擾����֐�
		//�쐬���F2017.9�D2
		//�쐬�ҁFK.Asada
		String^ LoadJSON(String^ Path) {
			//�t�@�C�����J�����߂̃N���X���C���X�^���X��
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(Path);
			//�t�@�C���ɒ��g�����݂��邩���m�F����B
			if (!reader->EndOfStream) {
				//�e�X�g�p�B
				System::Windows::Forms::MessageBox::Show(reader->ReadToEnd());
			}
			//�ǂݎ��Ȃ���΃G���[��Ԃ��B
			else {
				//�t�@�C���̒��g�����݂��Ă��Ȃ��G���[��\������B
			}
			return "aaa";
		}
	};
}