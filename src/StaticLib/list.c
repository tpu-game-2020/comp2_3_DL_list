#include "Windows.h"                    // Windows API の機能定義
#include "../include/liblist.h"

//
// 先頭にdataの値を持つノードを追加する
//
void add_front(list* l, int data)
{
	node* p = (node*)malloc(sizeof(node));
	if (p == NULL) return;

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
	node* p = (node*)malloc(sizeof(node));
	if (p == NULL) return;

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
	return p->next;
}

//
// pの前のノードを取得する
//
node* get_prev(node* p)
{
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

	return next;	// 返り値は次の要素
}

//
// 使用メモリの全解放
//
void delete_all(list* l)
{
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

