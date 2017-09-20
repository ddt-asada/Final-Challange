#pragma once

namespace CONSTANTS {

	/*概要：定数クラス
	作成日：2017.9.20
	作成者：K.Asada*/
	public ref class ConstantString {
		ConstantString() {
		}

	public:
		System::String^ EMPTY_STRING = "";
		System::String^ ZERO_STRING = "0";
		System::String^ ERROR_STRING = "入力項目を確認してください";
		System::Int32^ ZERO = 0;

	};
}