#pragma once

/*概要：JSONデータをチェイン構造にして扱うためのクラス
作成日：2017.9.20
作成者：K.Asada*/
public class CellDataChain {
	//デフォルトコンストラクタ
	CellDataChain() {

	}
public:
	//双方向チェインデータの構造体
	typedef struct cellchain {
		char* key;					//キー名
		char* value;				//キーに対応した値
		struct cellchain* next;		//弟へのポインタ
		struct cellchain* prev;		//兄へのポインタ
		struct cellchain* upper;	//親へのポインタ
		struct cellchain* lower;	//子へのポインタ
	};

	/*概要：親へデータを連結する関数
	引数：char*：親へ連結する構造体のキー名
		　char*：親へ連結する構造体の値
		  cellchain*：連結対象の構造体
	戻り値：cellchain*：連結後の構造体
	作成日：2017.9．20
	作成者：K.Asada*/
	cellchain* ChainParent(char* key, char* value, cellchain* target) {
		cellchain* chain;		//連結用の構造体を宣言
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
		//対象の親に新たな構造体を連結をした構造体を返す
		return target;
	}

	/*概要：子へデータを連結する関数
	引数：char*：子へ連結する構造体のキー名
	　char*：子へ連結する構造体の値
	 cellchain*：連結対象の構造体
	 戻り値：cellchain*：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain* ChainChild(char* key, char* value, cellchain* target) {
		cellchain* chain;		//連結用の構造体を宣言
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
		//対象の子に新たな構造体を連結をした構造体を返す
		return target;
	}

	/*概要：兄へデータを連結する関数
	引数：char*：兄へ連結する構造体のキー名
	　char*：兄へ連結する構造体の値
	 cellchain*：連結対象の構造体
	 戻り値：cellchain*：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain* ChainElderBrother(char* key, char* value, cellchain* target) {
		cellchain* chain;		//連結用の構造体を宣言
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
		//対象の兄に新たな構造体を連結をした構造体を返す
		return target;
	}

	/*概要：弟へデータを連結する関数
	引数：char*：弟へ連結する構造体のキー名
	　char*：弟へ連結する構造体の値
	 cellchain*：連結対象の構造体
	 戻り値：cellchain*：連結後の構造体
	 作成日：2017.9．20
	 作成者：K.Asada*/
	cellchain* ChainYoungBrother(char* key, char* value, cellchain* target) {
		cellchain* chain;		//連結用の構造体を宣言
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
		//対象の弟に新たな構造体を連結をした構造体を返す
		return target;
	}
};