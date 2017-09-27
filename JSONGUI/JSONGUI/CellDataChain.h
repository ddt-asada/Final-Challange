#pragma once

/*概要：JSONデータをチェイン構造にして扱うためのクラス
作成日：2017.9.20
作成者：K.Asada
更新日：2017.9.22
更新者：K.Asada 
更新内容：マネージ型クラス、構造体に変更、構造体の要素をchar*からString^型へ変更*/
public ref class CellDataChain {
public:
	//双方向チェインデータの構造体
	typedef ref struct cellchain {
		System::String^ key;					//キー名
		System::String^ value;				//キーに対応した値
		ref struct cellchain^ next;		//弟へのポインタ
		ref struct cellchain^ prev;		//兄へのポインタ
		ref struct cellchain^ upper;	//親へのポインタ
		ref struct cellchain^ lower;	//子へのポインタ
	};

	//デフォルトコンストラクタ
	CellDataChain() {

	}

	int getcount = 0;

	/*概要：親へデータを連結する関数
	引数：String^：親へ連結する構造体のキー名
		　String^：親へ連結する構造体の値
		  cellchain^：連結対象の構造体
	戻り値：cellchain^：連結後の構造体
	作成日：2017.9．20
	作成者：K.Asada
	更新日：2017.9.22
	更新者：K.Asada
	更新内容：例外処理を追加*/
	cellchain^ ChainParent(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
			if (target->key == nullptr && target->value == nullptr) {
				return chain;
			}
			//連結対象に親がいるかを調べる
			if (target->upper != nullptr) {
				//元の親の子として連結用の構造体を連結する
				target->upper->lower = chain;
				//連結用の構造体の親として元の親を連結する
				chain->upper = target->upper;
			}//親がいない場合
			else
			{
				//連結用の構造体の親が存在しないことを格納する
				chain->upper = nullptr;
			}
			//対象の親として連結用の構造体を連結
			target->upper = chain;
			//連結用の構造体の子として対象の構造体を連結
			chain->lower = target;
			//兄がいないことを格納する
			chain->prev = nullptr;
			//弟がいないことを格納する
			chain->next = nullptr;
			//対象の親に新たな構造体を連結をした構造体を返す
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*概要：子へデータを連結する関数
	引数：String^：子へ連結する構造体のキー名
	　String^：子へ連結する構造体の値
	 cellchain^：連結対象の構造体
	 戻り値：cellchain^：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain^ ChainChild(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
			//対象が空の場合は連結用の構造体をそのまま返す
			if (target->key == nullptr && target->value == nullptr) {
				return chain;
			}
			//連結対象に子がいるかを調べる
			if (target->lower != nullptr) {
				//元の子の親として連結用の構造体を連結する
				target->lower->upper = chain;
				//連結用の構造体の子として元の子を連結する
				chain->lower = target->lower;
			}//子がいない場合
			else
			{
				//連結用の構造体の子が存在しないことを格納する
				chain->lower = nullptr;
			}
			//対象の子として連結用の構造体を連結
			target->lower = chain;
			//連結用の構造体の親として対象の構造体を連結
			chain->upper = target;
			//兄がいないことを格納する
			chain->prev = nullptr;
			//弟がいないことを格納する
			chain->next = nullptr;
			//対象の子に新たな構造体を連結をした構造体を返す
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*概要：兄へデータを連結する関数
	引数：String^：兄へ連結する構造体のキー名
	　String^：兄へ連結する構造体の値
	 cellchain^：連結対象の構造体
	 戻り値：cellchain^：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain^ ChainElderBrother(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
			if (target->key == nullptr && target->value == nullptr) {
				return chain;
			}
			//連結対象に兄がいるかを調べる
			if (target->prev != nullptr) {
				//元の兄の弟として連結用の構造体を連結する
				target->prev->next = chain;
				//連結用の構造体の兄として元の兄を連結する
				chain->prev = target->prev;
			}//兄がいない場合
			else
			{
				//連結用の構造体の兄が存在しないことを格納する
				chain->prev = nullptr;
			}
			//対象の兄として連結用の構造体を連結
			target->prev = chain;
			//連結用の構造体の弟として対象の構造体を連結
			chain->next = target;
			//親がいないことを格納する
			chain->upper = nullptr;
			//子がいないことを格納する
			chain->lower = nullptr;
			//対象の兄に新たな構造体を連結をした構造体を返す
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*概要：弟へデータを連結する関数
	引数：String^：弟へ連結する構造体のキー名
	　String^：弟へ連結する構造体の値
	 cellchain^：連結対象の構造体
	 戻り値：cellchain^：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain^ ChainYoungBrother(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
			if (target->key == nullptr && target->value == nullptr) {
				return chain;
			}
			//連結対象に弟がいるかを調べる
			if (target->next != nullptr) {
				//元の弟の兄として連結用の構造体を連結する
				target->next->prev = chain;
				//連結用の構造体の弟として元の弟を連結する
				chain->next = target->next;
			}//弟がいない場合
			else
			{
				//連結用の構造体の弟が存在しないことを格納する
				chain->next = nullptr;
			}
			//対象の弟として連結用の構造体を連結
			target->next = chain;
			//連結用の構造体の兄として対象の構造体を連結
			chain->prev = target;
			//親がいないことを格納する
			chain->upper = nullptr;
			//子がいないことを格納する
			chain->lower = nullptr;
			//対象の弟に新たな構造体を連結をした構造体を返す
			return chain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*指定された箇所の要素をチェイン構造から削除する関数
	引数：cellchain^ declchain：削除対象の構造体
	戻り値：なし
	作成日：2017.9.22
	作成者：K.Asada*/
	System::Void ChainDelete(cellchain^ delchain) {
		try {
			//削除対象の構造体に親と子が両方存在していたら親と子を連結させる
			if (delchain->upper != nullptr && delchain->lower != nullptr) {
				//親の子として子を連結する
				delchain->upper->lower = delchain->lower;
				//子の親として親を連結する
				delchain->lower->upper = delchain->upper;
			}//親しか存在しないときは親の子への参照を外す
			else if (delchain->upper != nullptr) {
				//親の子への参照を外す
				delchain->upper->lower = nullptr;
			}//子しか存在しないときは子の親への参照を外す
			else if (delchain->lower != nullptr) {
				//子の親への参照を外す
				delchain->lower->upper = nullptr;
			}
			//削除対象の構造体に兄と弟両方が存在していたら兄と弟を連結させる
			if (delchain->next != nullptr && delchain->prev != nullptr) {
				//兄の弟として弟を連結する
				delchain->prev->next = delchain->next;
				//弟の兄として兄を連結する
				delchain->next->prev = delchain->prev;
			}//兄しか存在しないときは参照をはずす
			else if (delchain->prev != nullptr) {
				//兄の弟への参照を外す
				delchain->prev->next = nullptr;
			}//弟しか存在しないときは参照を外す
			else if (delchain->next != nullptr) {
				//弟の兄への参照を外す
				delchain->next->prev = nullptr;
			}
			//親子、兄弟から参照が外れた構造体を削除する
			delete delchain;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}

	/*概要：対象の構造体のすべての親キーを取得して連結した構造体を作る関数
	引数：cellchain^ child：親キーを取得したい構造体
	戻り値：cellchain^ child：対象の親キーをすべて連結した構造体
	作成日：2017.9.25
	作成者：K.Asad*/
	cellchain^ GetParents(cellchain^ child) {
		//取得した親キーを格納するための構造体
		cellchain^ parent = gcnew cellchain();
		//対象の構造体の長男まで移動する
		for (; child->prev != nullptr; child = child->prev) {
			//兄に移動していく
		}
		//長男に親が存在していた場合
		if (child->upper != nullptr) {
			//再帰して親の親キーがないかを調べて取得
			parent = GetParents(child->upper);
			//取得した親キーの子として現在の構造体を連結する
			child = ChainChild(child->key, child->value, parent);
		}
		//親キーを連結した構造体を返却する
		return child;
	}

	/*概要：行の要素の構造体を取得するための関数
	引数：Int32：rowindex：取得対象の行
		：Int32：colindex：取得対象の座標
		：cellchain^ parent：要素が含まれた構造体
	戻り値：要素の構造体
	作成日：2017.9.25
	作成者：K.Asada*/
	cellchain^ GetColumnChain(System::Int32 rowindex, System::Int32 colindex, cellchain^ parent) {
		int i = 1;
		//取得した構造体を格納するための返却用の構造体
		cellchain^ colchain = gcnew cellchain();
		//親要素から取得対象の行の構造体を取得する
		colchain = GetRowChain(rowindex, parent);
		//列座標が1以下であれば親要素の構造体を返却する
		if(colindex >= 1){
			//行の要素（子）が存在していれば対象の構造体を探す
			if (colchain->lower != nullptr) {
				//子を取得
				colchain = colchain->lower;
			}//存在していなければ子要素を作る
			 //子がいなければ子を作る
			else {
				colchain = this->ChainChild("", "", colchain);
			}
			//取得対象の構造体まで移動する
			for (; i < colindex; i++) {
				//取得対象の構造体が存在していなければ中断する
				if (colchain->next != nullptr) {
					//弟が存在していれば弟に移動する
					colchain = colchain->next;
				}
				//存在していなければ弟を作る
				else {
					colchain = this->ChainYoungBrother("", "", colchain);
				}
			}
		}
		return colchain;
	}

	/*概要：行の先頭の構造体を取得するための関数
	引数：Int32 rowindex：取得対象の行
		：cellchain^ parent：親の構造体
	戻り値：cellchain^ rowchain：取得対象の構造体
	作成日：2017.9.25
	作成者：K.Asada*/
	cellchain^ GetRowChain(System::Int32 rowindex, cellchain^ parent) {
		//返却用の構造体を宣言する
		cellchain^ rowchain = gcnew cellchain();
		//走査用の変数
		int i = 0;
		//取得対象の構造体の位置まで移動する
		for (; i < rowindex; i++) {
			//移動先がなくなったときは中断する
			if (parent->next != nullptr) {
				parent = parent->next;
			}
			else {
				break;
			}
		}
		//対象の位置まで移動できていれば
		if (i != rowindex) {
			//新たに弟として構造体を連結する
			rowchain = this->ChainYoungBrother("", "", parent);
		}
		else {
			//取得対象の構造体を取得する
			rowchain = parent;
		}
		//取得した構造体を返却する
		return rowchain;
	}

	cellchain^ FirstChain(cellchain^ chain) {
		for (; chain->prev != nullptr; chain = chain->prev) {
		}
		return chain;
	}

	/*概要：対象の構造体の親の構造体を取得するための関数
	引数：Int32 parentindex：何番目の親を取得するか
		：cellchain^ child：対象の構造体
	戻り値：親の構造体
	作成日：2017.9.26
	作成者：K.Asada*/
	cellchain^ GetParent(cellchain^ child, System::Int32 parentindex) {
		//取得した親を格納する構造体を宣言する
		cellchain^ parent = child;
		//対象の親の位置まで走査する
		for (int i = 0; i < parentindex; i++) {
			//対象の長男まで移動する
			parent = this->FirstChain(parent);
			//対象の長男に親が存在するか
			if (parent->upper != nullptr) {
				//親を取得する
				parent = parent->upper;
			}
			else {
				//親がなかった場合はnullptrを取得
				parent = nullptr;
				//ループを抜ける
				break;
			}
		}
		//取得した構造体を返却する
		return parent;
	}
};