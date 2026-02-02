#pragma once

#include <concepts>

template <typename A, typename B>
concept less_sizeof = (sizeof(A) < sizeof(B));


template <typename... types>
struct type_list {};


// T는 인서트할 자리를 찾는 객체
template<typename T, typename List>
struct insert_sorted;

template <typename T>
struct insert_sorted<T, type_list<>>
{
	using type = type_list<T>;
};

template <typename T, typename Head, typename... Tail>
// 원소와, typelist의 비교 원소를 재귀하면서 다음 타입으로 넘어감
struct insert_sorted<T, type_list<Head, Tail...>>
{
	// 들고 있는 타입과 현재 위치한 원소보다 사이즈가 작다면
	using type = std::conditional_t<less_sizeof<T, Head>,
		// T를 그대로 둔체 리스트를 만듬 (올바른 위치)
		type_list<T, Head, Tail...>,
		// 헤드를 T에 두고 T로 다시 LIST를 만듬 (다른 위치)
		type_list<Head, typename insert_sorted<T, type_list<Tail...>>::type
		>
	>;
};

template <typename List>
struct sort;

template<>
struct sort<type_list<>>
{
	using type = type_list<>;
};

template <typename Head, typename... Tail>
struct sort<type_list<Head, Tail...>>
{
	// type_list를 순회하면서 선택정렬하는 tmp
	using type =
		// 선택정렬 실행 0 ~ end 번째 인덱스부터 1 ~ end 2 ~ end 이런식으로
		typename insert_sorted<
		Head, typename sort<type_list<Tail...>>::type>::type;
};

template <typename List>
struct to_tuple;

template <typename... Ts>
struct to_tuple<type_list<Ts...>> {
	using type = std::tuple<Ts...>;
};