#include "pch.h"

// メモリリークのキャプチャ
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "CppUnitTest.h"
#include "../include/liblist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_MODULE_CLEANUP(test_module_cleanup) {
		Assert::IsFalse(_CrtDumpMemoryLeaks());// メモリリークチェック
	}

	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(front_added)
		{
			list l;
			initialize_list(&l);
			add_front(&l, 1);
			Assert::AreEqual(1, l.head->data);

			delete_all(&l);
		}

		// 最後のノードはNULL
		TEST_METHOD(back_added)
		{
			list l;
			initialize_list(&l);
			add_back(&l, 1);

			Assert::AreEqual(1, l.tail->data);

			delete_all(&l);
		}

		// 最初の前ノードはNULL
		TEST_METHOD(next_get)
		{
			list l;
			initialize_list(&l);
			add_front(&l, 1);
			add_back(&l, 2);

			Assert::AreEqual(2, get_next(l.head)->data);

			delete_all(&l);
		}

		// 最初の前ノードはNULL
		TEST_METHOD(prev_get)
		{
			list l;
			initialize_list(&l);
			add_front(&l, 1);
			add_back(&l, 2);

			Assert::AreEqual(1, get_prev(l.tail)->data);

			delete_all(&l);
		}


		// 最初の前ノードはNULL
		TEST_METHOD(middle_node_depended)
		{
			list l;
			initialize_list(&l);
			add_front(&l, 1);
			add_back(&l, 2);
			add_back(&l, 3);

			depend(get_prev(l.tail) , &l);// 真ん中の要素を削除

			node* p = l.head;
			Assert::AreEqual(1, p->data);
			p = p->next;
			Assert::AreEqual(3, p->data);
			p = p->next;
			Assert::IsNull(p);

			delete_all(&l);
		}

	};
}
