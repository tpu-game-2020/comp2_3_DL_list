#include "Windows.h"                    // Windows API の機能定義
#include "../include/liblist.h"

//
// 先頭にdataの値を持つノードを追加する
//
void add_front(list* l, int data)
{
	// ToDo: headにdataの値を持つノードを追加する
}

//
// 末尾にdataの値を持つノードを追加する
//
void add_back(list* l, int data)
{
	// ToDo: tailにdataの値を持つノードを追加する
}

//
// pの後のノードを取得する
//
node* get_next(node* p)
{
	// ToDo: 次の要素を返してください
	return NULL;
}

//
// pの前のノードを取得する
//
node* get_prev(node* p)
{
	// ToDo: 前の要素を返してください
	return NULL;
}

//
// ノードを取り除く（今回はメモリ解放も行う）
//
node* depend(node* p, list* l)
{
	// ToDo: pをリストから取り外す
	// 返り値は次の要素
	return NULL;
}

//
// 使用メモリの全解放
//
void delete_all(list* p)
{
	// ToDo: pで始まるリストのメモリを解放してください
}

//
// リストの初期化
//
void initialize_list(list* l)
{
	l->head = l->tail = NULL;
}

