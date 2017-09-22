#pragma once

using namespace System;

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
		String^ key;					//キー名
		String^ value;				//キーに対応した値
		ref struct cellchain^ next;		//弟へのポインタ
		ref struct cellchain^ prev;		//兄へのポインタ
		ref struct cellchain^ upper;	//親へのポインタ
		ref struct cellchain^ lower;	//子へのポインタ
	};

	//デフォルトコンストラクタ
	CellDataChain() {

	}

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
	cellchain^ ChainParent(String^ key, String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
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
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
		//対象の親に新たな構造体を連結をした構造体を返す
		return target;
	}

	/*概要：子へデータを連結する関数
	引数：String^：子へ連結する構造体のキー名
	　String^：子へ連結する構造体の値
	 cellchain^：連結対象の構造体
	 戻り値：cellchain^：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain^ ChainChild(String^ key, String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
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
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
		//対象の子に新たな構造体を連結をした構造体を返す
		return target;
	}

	/*概要：兄へデータを連結する関数
	引数：String^：兄へ連結する構造体のキー名
	　String^：兄へ連結する構造体の値
	 cellchain^：連結対象の構造体
	 戻り値：cellchain^：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain^ ChainElderBrother(String^ key, String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
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
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
		//対象の兄に新たな構造体を連結をした構造体を返す
		return target;
	}

	/*概要：弟へデータを連結する関数
	引数：String^：弟へ連結する構造体のキー名
	　String^：弟へ連結する構造体の値
	 cellchain^：連結対象の構造体
	 戻り値：cellchain^：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain^ ChainYoungBrother(String^ key, String^ value, cellchain^ target) {
		try {
			cellchain^ chain = gcnew cellchain();		//連結用の構造体を宣言
			chain->key = key;		//連結する構造体のキー名を格納
			chain->value = value;	//連結する構造体のキー名に対応した値を格納
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
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
		//対象の弟に新たな構造体を連結をした構造体を返す
		return target;
	}

	/*指定された箇所の要素をチェイン構造から削除する関数
	引数：cellchain^ declchain：削除対象の構造体
	戻り値：なし
	作成日：2017.9.22
	作成者：K.Asada*/
	Void ChainDelete(cellchain^ delchain) {
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
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
	}

	/*概要：指定された箇所の要素をチェイン構造より取得する関数
	引数：Int32：取得したい要素の行座標
		：Int32：取得したい要素の列座標
	作成日：2017.9.22
	作成者：K.Asada*/
	String^ GetChainData(Int32 rowindex, Int32 columnindex, cellchain^ grandparent) {
		try {
			cellchain^ scan = grandparent;		//走査用の構造体を宣言
			String^ ret = "";					//返却用の文字列を宣言
			//構造体の行方向への移動を行う
			scan = scan->lower;
			for (int i = 0; i < rowindex; i++) {
				//弟を取得する
				scan = scan->next;
			}
			//既に要素があれば
			if (scan->value != "") {
				//返却用文字列に値を代入
				ret = scan->value;
			}//さらに走査を行う
			else {
				//子を取得する
				scan = scan->lower;
				//弟へ移動していく
				for (int i = 0; i < columnindex; i++) {
					//弟を取得する
					scan = scan->next;
				}
				//値をとりだす
				ret = scan->value;
			}
			return ret;
		}
		catch (NullReferenceException^ e) {
			Console::WriteLine(e);
		}
		catch (ArgumentNullException^ e) {
			Console::WriteLine(e);
		}
	}
};