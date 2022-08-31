/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/30 22:00:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int				_index;
int				expected;
t_ht_item		*item;
t_hash_table	*table;

static void	test_ht_item(t_ht_item *_item,
							char *expected_key,
							char *expected_value)
{
	mu_check(_item != NULL);
	mu_assert_string_eq(expected_key, _item->key);
	mu_assert_string_eq(expected_value, _item->value);
}

static void	seed_hash_table_1(void)
{
	_index = 42;

	ht_insert_in_index(table, "foo", "bar", _index);
	mu_check(table->count == 1);
	ht_insert_in_index(table, "baz", "fizz", _index);
	mu_check(table->count == 2);
	ht_insert_in_index(table, "buzz", "crash", _index);
	mu_check(table->count == 3);
}

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(index_tst)
{
	_index = ht_get_index("abc");
	expected = (int)(md5_sum("abc") % HASH_TABLE_SIZE);
	mu_assert_int_eq(expected, _index);
}

MU_TEST(init_tst)
{
	table = ht_init();
	mu_check(table != NULL);
	mu_check(table->size == HASH_TABLE_SIZE);
	mu_check(table->count == 0);
	free(table->index_lists);
	free(table);
}

MU_TEST(destroy_tst)
{
	table = ht_init();
	mu_check(table != NULL);
	ht_destroy(&table);
	mu_check(table == NULL);
}

MU_TEST(new_item_tst)
{
	item = ht_new_item("abc", "value");
	test_ht_item(item, "abc", "value");

	free(item->value);
	free(item->key);
	free(item);
}

MU_TEST(destroy_item_tst)
{
	item = ht_new_item("bananas", "pajamas");
	test_ht_item(item, "bananas", "pajamas");

	ht_destroy_item(&item);
	mu_check(item == NULL);
}

MU_TEST(insert_one_tst)
{
	table = ht_init();
	ht_insert(table, "chave", "value");

	mu_check(table->count == 1);
	_index = ht_get_index("chave");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "chave", "value");

	ht_destroy(&table);
}

MU_TEST(insert_two_tst)
{
	table = ht_init();
	ht_insert(table, "mario", "luigi");
	mu_check(table->count == 1);
	ht_insert(table, "mamma", "mia");
	mu_check(table->count == 2);

	_index = ht_get_index("mario");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "mario", "luigi");

	_index = ht_get_index("mamma");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "mamma", "mia");

	ht_destroy(&table);
}

MU_TEST(reinsertion_tst)
{
	table = ht_init();
	ht_insert(table, "chave", "a");
	ht_insert(table, "chave", "b");

	mu_check(table->count == 1);
	_index = ht_get_index("chave");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "chave", "b");

	ht_destroy(&table);
}

MU_TEST(collision_tst)
{
	table = ht_init();
	seed_hash_table_1();

	item = table->index_lists[_index]->content;
	test_ht_item(item, "buzz", "crash");

	item = table->index_lists[_index]->next->content;
	test_ht_item(item, "baz", "fizz");

	item = table->index_lists[_index]->next->next->content;
	test_ht_item(item, "foo", "bar");

	ht_destroy(&table);
}

MU_TEST(collision_reinsertion_tst)
{
	table = ht_init();
	seed_hash_table_1();

	ht_insert_in_index(table, "baz", "crash", _index);
	mu_check(table->count == 3);

	item = table->index_lists[_index]->next->content;
	test_ht_item(item, "baz", "crash");

	ht_destroy(&table);
}

MU_TEST_SUITE(hash_table_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);
	MU_RUN_TEST(index_tst);
	MU_RUN_TEST(init_tst);
	MU_RUN_TEST(destroy_tst);
	MU_RUN_TEST(new_item_tst);
	MU_RUN_TEST(destroy_item_tst);
	MU_RUN_TEST(insert_one_tst);
	MU_RUN_TEST(insert_two_tst);
	MU_RUN_TEST(reinsertion_tst);
	MU_RUN_TEST(collision_tst);
	MU_RUN_TEST(collision_reinsertion_tst);
}

int	main(void)
{
	MU_RUN_SUITE(hash_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
