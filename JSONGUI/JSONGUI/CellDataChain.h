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
			if (target == nullptr) {
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
			if (target == nullptr) {
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
	 作成者：K.Asada
	 更新内容：長男に兄を追加するときには親もつなぎ変えるように変更
	 更新日：2017.9.28
	 更新者：K.Asada
	 更新内容：繋ぎ変える対象がおかしくバグが出ていたので修正
	 更新日：2017.9.30
	 更新者：K.Asada*/
	cellchain^ ChainElderBrother(System::String^ key, System::String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
			if (target == nullptr) {
				return chain;
			}
			//連結対象に兄がいるかを調べる
			if (target->prev != nullptr) {
				//元の兄の弟として連結用の構造体を連結する
				target->prev->next = chain;
				//連結用の構造体の兄として元の兄を連結する
				chain->prev = target->prev;
				//親がいないことを格納する
				chain->upper = nullptr;
			}//兄がいない場合
			else
			{
				//連結用の構造体の親を対象の親につなぎ変える
				chain->upper = target->upper;
				//親の子として連結用のこうぞうたいを連結する
				chain->upper->lower = chain;
				//対象の親へにチェインを削除する
				target->upper = nullptr;
				//連結用の構造体の兄が存在しないことを格納する
				chain->prev = nullptr;
			}
			//対象の兄として連結用の構造体を連結
			target->prev = chain;
			//連結用の構造体の弟として対象の構造体を連結
			chain->next = target;
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
			if (target == nullptr) {
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
	作成者：K.Asada
	更新日2017.9.29
	更新者：K.Asada
	更新内容：関数名を変更、指定された箇所の子要素も親が存在しなくなるため削除するように変更、対象に親がいたときの処理方法も変更*/
	System::Void DeleteChain(cellchain^ delchain) {
		try {
			//削除対象に子がいるかを調べる
			if (delchain->lower != nullptr) {
				//子がいる場合は親に当たる構造体が削除されるため必要なくなるので削除する
				this->DeleteYounger(delchain->lower);
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
			}//弟しか存在しないときは元の構造体に親がいるかを調べる
			else if (delchain->next != nullptr) {
				//親がいる場合は親の参照を変える
				if (delchain->upper != nullptr) {
					//親がいる場合は弟に引き継ぐ
					delchain->upper->lower = delchain->next;
					//弟に親を渡す
					delchain->next->upper = delchain->upper;
				}
					//弟の兄への参照を外す
					delchain->next->prev = nullptr;
			}//兄弟がおらずに親のみが存在する場合
			else if (delchain->upper != nullptr) {
				//親の子を削除する
				delchain->upper->lower = nullptr;
			}
			//親子、兄弟から参照が外れた構造体を削除する
			delchain = nullptr;
			delete delchain;
			return;
		}
		catch (System::NullReferenceException^ e) {
			System::Console::WriteLine(e);
		}
		catch (System::ArgumentNullException^ e) {
			System::Console::WriteLine(e);
		}
	}
	
	/*概要：対象の構造体より若い構造体（子、弟）をすべて削除する関数
	引数：cellchain^ parent：削除対象の構造体
	戻り値：なし
	作成日：2017.9.29
	作成者：K.Asada*/
	System::Void DeleteYounger(cellchain^ parent) {
		//構造体をつなぎ変えるときにNULLを指す恐れがあるので例外処理
		try {
			//対象に子がいるかを調べる
			if (parent->lower != nullptr) {
				//子がいるときは再帰してさらに削除していく
				this->DeleteYounger(parent->lower);
			}
			//対象に弟がいる場合はすべて削除する
			if (parent->next != nullptr) {
				//弟がなくなるまで走査する
				for (; parent->next != nullptr;) {
					//再帰して弟を削除する
					this->DeleteChain(parent->next);
				}
			}
			if (parent->next != nullptr && parent->prev != nullptr) {
				//兄の弟として弟を連結する
				parent->prev->next = parent->next;
				//弟の兄として兄を連結する
				parent->next->prev = parent->prev;
			}//兄しか存在しないときは参照をはずす
			else if (parent->prev != nullptr) {
				//兄の弟への参照を外す
				parent->prev->next = nullptr;
			}//弟しか存在しないときは元の構造体に親がいるかを調べる
			else if (parent->next != nullptr) {
				//親がいる場合は親の参照を変える
				if (parent->upper != nullptr) {
					//親がいる場合は弟に引き継ぐ
					parent->upper->lower = parent->next;
					//弟に親を渡す
					parent->next = parent->upper;
				}
				//弟の兄への参照を外す
				parent->next->prev = nullptr;
			}//兄弟がおらずに親のみが存在する場合
			else if (parent->upper != nullptr) {
				//親の子を削除する
				parent->upper->lower = nullptr;
			}
			//周りとの参照、子が全て削除されたら対象を必要ないとして削除する
			parent = nullptr;
			delete parent;
		}
		//NULL関係の例外を捕捉
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
	作成者：K.Asada
	更新内容：取得対象の構造体が存在していないときはnullptrを返すように変更
	更新日：2017.9.27
	更新者：K.Asada*/
	cellchain^ GetColumnChain(System::Int32 rowindex, System::Int32 colindex, cellchain^ parent) {
		//取得した構造体を格納するための返却用の構造体
		cellchain^ colchain = gcnew cellchain();
		//親要素から取得対象の行の構造体を取得する
		colchain = GetRowChain(rowindex, parent);
		//列座標が1以下であれば親要素の構造体を返却する
		if(colindex >= 1 && colchain != nullptr){
			//行の要素（子）が存在していれば対象の構造体を探す
			if (colchain->lower != nullptr) {
				//子を取得
				colchain = colchain->lower;
			}//存在していなければnullptrを格納
			else {
				colchain = nullptr;
			}
			//取得対象の構造体まで移動する
			for (int i = 1; i < colindex; i++) {
				//取得対象の構造体が存在していなければ中断する
				if (colchain != nullptr && colchain->next != nullptr) {
					//弟が存在していれば弟に移動する
					colchain = colchain->next;
				}
				//存在していなければnullptrを格納
				else {
					colchain = nullptr;
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
	作成者：K.Asada
	更新内容：取得対象の構造体が存在していないときはnullptrを返すように変更
	更新日：2017.9.27
	更新者：K.Asada*/
	cellchain^ GetRowChain(System::Int32 rowindex, cellchain^ parent) {
		//返却用の構造体を宣言する
		cellchain^ rowchain = parent;
		//取得対象の構造体の位置まで移動する
		for (int i = 0; i < rowindex; i++) {
			//移動先がなくなったときは構造体を取得できなかったとしてnullptrを取得
			if (rowchain != nullptr && rowchain->next != nullptr) {
				//弟の構造体に移動する
				rowchain = rowchain->next;
			}
			else {//ない場合はnullptrを取得してループを抜ける
				rowchain = nullptr;
				//ループを抜ける
				break;
			}
		}
		//取得した構造体を返却する
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

	/*概要：指定した箇所に構造体を挿入する関数
	引数：Int32 rowindex：挿入する行座標
		：Int32 columnindex：列座標
		：String^ setdata：挿入する構造体にセットする文字列
		：cellchain^ elem：挿入対象の構造体
	戻り値：なし
	作成日：2017.9.27
	作成者：K.Asada
	更新内容：行の先頭を編集した時に選択箇所の子が編集されるバグがあったので修正、関数を追加
	更新日：2017.9.30
	更新者：K.Asada*/
	cellchain^ SetChainCell(System::Int32 rowindex, System::Int32 columnindex, System::String^ setdata, cellchain^ elem, System::Boolean editkey, System::Boolean editvalue) {
		//構造体のnull関係の例外を捕捉するための例外処理
		try {
			cellchain^ scan = elem;			//対象の構造体を取得する
			//対象に子がいるかを調べる
			scan = this->CheckChild(scan);
			//対象の行の構造体へ移動する
			for (int i = 0; i < rowindex; i++) {
				//弟がいるかを判定する関数を呼び出す
				scan = this->CheckBrother(scan);
			}
			//対象が行の先頭ならすでに行の先頭を取得しているので値の代入動作へ移動
			if (columnindex > 0) {
				//対象の構造体に行の先頭に続く要素があるかを調べる
				scan = this->CheckChild(scan);
				//行の要素の構造体を移動して対象の挿入対象の構造体を取得する
				for (int i = 1; i < columnindex; i++) {
					//次の構造体があるかを調べる
					scan = this->CheckBrother(scan);
				}
			}
			//構造体の状態を判別して対応した場所に文字列を格納する関数を呼び出す
			this->SetCellData(setdata, scan, editkey, editvalue);
			//作成した構造体を返却する
			return scan;
		}
		//null参照例外を捕捉
		catch (System::NullReferenceException^ e) {
			//例外をコンソール上に表示、表にはメイン画面の例外処理で表示する
			System::Console::WriteLine(e);
		}
		//null引数例外を捕捉
		catch (System::ArgumentNullException^ e) {
			//例外をコンソール上に表示、表にはメイン画面の例外処理で表示する
			System::Console::WriteLine(e);
		}
	}

	/*概要：対象の構造体の一番弟の構造体を取得する関数
	引数；対象の構造体
	戻り値：対象の一番弟の構造体
	作成日：2017.9.27
	作成者：K.Asada*/
	cellchain^ GetYoungChain(cellchain^ scan) {
		try {
			//対象の一番弟まで移動する
			for (; scan->next != nullptr; scan = scan->next) {

			}
			//取得した弟を返す
			return scan;
		}
		//null参照例外を捕捉
		catch (System::NullReferenceException^ e) {
			//例外をコンソール上に表示、表にはメイン画面の例外処理で表示する
			System::Console::WriteLine(e);
		}
		//null引数例外を捕捉
		catch (System::ArgumentNullException^ e) {
			//例外をコンソール上に表示、表にはメイン画面の例外処理で表示する
			System::Console::WriteLine(e);
		}
	}

	/*概要：対象の構造体に子がいるかを確認する関数
	引数：cellchain^ family：対象の構造体
	戻り値：cellchain^ family：対象の子供
	作成日：2017.9.30
	作成者：K.Asada*/
	cellchain^ CheckChild(cellchain^ family) {
		//構造体でのnull関係の例外処理
		try {
			//子がいるかを調べなければ作る
			if (family->lower != nullptr) {
				//子がいる場合はそのまま子を返す
				family = family->lower;
			}
			//子がいない場合は作る
			else {
				//子供として空の構造体を連結する
				family = this->ChainChild("", "", family);
			}
			//取得した子供を返す
			return family;
		}
		//null参照例外を捕捉
		catch (System::NullReferenceException^ e) {
			//例外をコンソール上に表示、表にはメイン画面の例外処理で表示する
			System::Console::WriteLine(e);
		}
		//null引数例外を捕捉
		catch (System::ArgumentNullException^ e) {
			//例外をコンソール上に表示、表にはメイン画面の例外処理で表示する
			System::Console::WriteLine(e);
		}
	}

	/*概要：対象に弟がいるかを調べる関数
	引数：cellchain^ family：対象の構造体
	戻り値：cellchain^ family：対象の弟
	作成日：2017.9.30
	作成者：K.Asada*/
	cellchain^ CheckBrother(cellchain^ family) {
		//構造体でのnull関係の例外を捕捉するための例外処理
		try {
			//弟がいるかを調べ、なければ作る
			if (family->next != nullptr) {
				//そのまま弟を取得する
				family = family->next;
			}
			//いなければ弟を作る
			else {
				family = ChainYoungBrother("", "", family);
			}
			//対象の弟を返却する
			return family;
		}
		//null参照例外を捕捉
		catch (System::NullReferenceException^ e) {
			//例外をコンソール上に表示、表にはメイン画面の例外処理で表示する
			System::Console::WriteLine(e);
		}
		//null引数例外を捕捉
		catch (System::ArgumentNullException^ e) {
			//例外をコンソール上に表示、表にはメイン画面の例外処理で表示する
			System::Console::WriteLine(e);
		}
	}

	/*概要：対象の状態を判別して対象の構造体の値またはキー名に文字列を代入する関数
	引数：String^ setdata：構造体に代入する文字列
		：cellchain^ scan：対象の構造体
		：Boolean editkey：キー名を編集するかどうかの判定
		：Boolean editvalue：値を編集するかどうかの判定
	戻り値：なし
	作成日：2017.10.2
	作成者：K.Asada*/
	System::Void SetCellData(System::String^ setdata, cellchain^ scan, System::Boolean editkey, System::Boolean editvalue){
		//キー編集モードであれば
		if (editkey) {
			//対象の構造体のキー名に文字列を代入する
			scan->key = setdata;
		}//値編集モードであれば
		else if (editvalue) {
			//対象の構造体の値に文字列を代入する
			scan->value = setdata;
		}//編集モードが指定されておらず対象の構造体に子が存在していれば
		else if (scan->lower != nullptr) {
			//通常通りキー名に文字列を代入する
			scan->key = setdata;
		}//編集モードが指定されておらず対象の構造体に子がいなければ
		else {
			//値に文字列を代入する
			scan->value = setdata;
		}
		//編集を終える
		return;
	}

	/*概要：対象の状態を判別してキー名または値のどちらかを返却する関数
	引数：cellchain^ cell：対象の構造体
		：Boolean getkey：キー名を取得するかどうかの判定
		：Boolean getvalue：値を取得するかどうかの判定
	戻り値：対象から取得した文字列
	作成日：2017.10.2
	作成者：K.Asada*/
	System::String^ GetCellString(cellchain^ cell, System::Boolean getkey, System::Boolean getvalue) {
		System::String^ data = "";			//返却用の文字列を格納するための文字列
		//対象の構造体が存在していなければ
		if (cell == nullptr) {
			//空文字を返却する
			data = "";
		}//キー名取得状態であれば
		else if (getkey) {
			//キー名を取得する
			data = cell->key;
		}//値取得状態であれば
		else if (getvalue) {
			//値を取得する
			data = cell->value;
		}//どちらでもなく構造体に子が存在していれば
		else if (cell->lower != nullptr) {
			//通常通りキー名を取得する
			data = cell->key;
		}//どちらでもなく構造体に子が存在していなければ
		else {
			data = cell->value;
		}
		//取得した文字列を返却する
		return data;
	}

};