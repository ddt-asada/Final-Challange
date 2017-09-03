#pragma once

#include <iostream>;

/*作成日：2017年9月1日
定数文字列クラス。
作成者：K.Asada
*/

namespace constantstring {

	ref class CONSTANTSTRING {
	private:

	public:
		CONSTANTSTRING() {
		};
		System::String^ EMPTY_STRING = "";
		System::String^ ZERO_STRING = "0";
		System::Int32^ ZERO = 0;
	};
}