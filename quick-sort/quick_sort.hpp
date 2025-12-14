#pragma once
#include <vector>

#include <concepts>

template <typename T>
concept Ordered = requires(T a, T b)
{
    { a <= b } -> std::convertible_to<bool>;
};

template <typename L, typename T>
concept RandomAccess = requires(L l, std::size_t i)
{
    { l.size() } -> std::same_as<std::size_t>;
    { l[i]     } -> std::same_as<T &>;
};

template <Ordered T, RandomAccess<T> L>
void quick_sort(L &array);

#include "quick_sort.cpp"
