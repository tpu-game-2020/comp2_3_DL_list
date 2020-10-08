#pragma once

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct node {
		int data;
		struct node* prev;
		struct node* next;
	}node;

	typedef struct list {
		struct node* head;
		struct node* tail;
	}list;


	// 先頭にdataの値を持つノードを追加する
	void add_front(list* l, int data);

	// 末尾にdataの値を持つノードを追加する
	void add_back(list* l, int data);
	
	// pの後のノードを取得する
	node* get_next(node* p);

	// pの前のノードを取得する
	node* get_prev(node* p);

	// ノードを取り除く（今回はメモリ解放も行う）
	node* depend(node* p, list* l);

	// 使用メモリの全解放
	void delete_all(list* l);

	void initialize_list(list* l)
	{
		l->head = l->tail = NULL;
	}
	
// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
