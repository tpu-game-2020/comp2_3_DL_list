#include "Windows.h"                    // Windows API の機能定義
#include "../include/liblist.h"

//
// 先頭にdataの値を持つノードを追加する
//
void add_front(list* l, int data)
{
	// ToDo: headにdataの値を持つノードを追加する

	node* p = (node*)malloc(sizeof(node));
	if (p == NULL)return;


	p->data = data;
	p->next = l->head;
	p->prev = NULL;

	l->head = p;
	if (p->next != NULL) {
		p->next->prev = p;
	}
	else {
		l->tail = p;
	}
}


//
// 末尾にdataの値を持つノードを追加する
//
void add_back(list* l, int data)
{
	// ToDo: tailにdataの値を持つノードを追加する

	node* p = (node*)malloc(sizeof(node));
	if (p == NULL)return;

	p->data = data;
	p->next = NULL;
	p->prev = l->tail;
	l->tail = p;

	if (p->prev != NULL) {
		p->prev->next = p;
	}
	else {
		l->head = p;
	}
}

//
// pの後のノードを取得する
//
node* get_next(node* p)
{
	// ToDo: 次の要素を返してください

	return p->next;
}

//
// pの前のノードを取得する
//
node* get_prev(node* p)
{
	// ToDo: 前の要素を返してください

	return p->prev;
}

//
// ノードを取り除く（今回はメモリ解放も行う）
//
node* depend(node* p, list* l)
{
	node* next = p->next;
	if (p->prev != NULL) {
		p->prev->next = p->next;
	}
	else {
		l->head = p->next;
	}

	if (p->next != NULL) {
		p->next->prev = p->prev;
	}
	else {
		l->tail = p->prev;
	}
	free(p);
	// ToDo: pをリストから取り外す
	// 返り値は次の要素
	return next;
}

//
// 使用メモリの全解放
//
void delete_all(list* l)
{
	// ToDo: pで始まるリストのメモリを解放してください
	node* p = l->head;
	while (p != NULL) {
		node* n = p->next;
		free(p);
		p = n;
	}
}

//
// リストの初期化
//
void initialize_list(list* l)
{
	l->head = l->tail = NULL;
}

