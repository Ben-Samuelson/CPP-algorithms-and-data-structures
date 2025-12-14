#include <vector>

struct Partition
{
    std::size_t left;
    std::size_t right;
};

template <Ordered T, RandomAccess<T> L>
void swap(L &array, std::size_t i, std::size_t j)
{
    T temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

template <Ordered T, RandomAccess<T> L>
std::size_t partition_array(L &array, Partition partition)
{
    const T &pivot_element = array[partition.right];
    std::size_t i = partition.left;

    for (std::size_t j = partition.left; j < partition.right; j++)
    {
        if (array[j] <= pivot_element)
        {
            swap<T, L>(array, i, j);
            i++;
        }
    }

    swap<T, L>(array, i, partition.right);
    return i;
}

template <Ordered T, RandomAccess<T> L>
void quick_sort(L &array)
{
    std::vector<Partition> partition_stack;
    partition_stack.push_back(Partition {0, array.size() - 1});

    while (!partition_stack.empty())
    {
        Partition partition = partition_stack.back();
        partition_stack.pop_back();

        std::size_t pivot = partition_array<T, L>(array, partition);

        // avoid underflow
        if (partition.left + 1 < pivot)
            partition_stack.push_back(Partition {partition.left, pivot - 1});

        if (pivot + 1 < partition.right)
            partition_stack.push_back(Partition {pivot + 1, partition.right});
    }
}
