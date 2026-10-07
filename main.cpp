#include <iostream>
#include <optional>
#include <vector>
#include <array>
#include <cstddef>
#include <climits>

std::optional<int> GetNext(
    const std::vector<int>& list1,
    const std::vector<int>& list2,
    const std::vector<int>& list3,
    std::array<std::size_t, 3>& positions)
{
    if (list1.size() > positions[0] &&
        (list2.size() == positions[1] || list1[positions[0]] < list2[positions[1]]) &&
        (list3.size() == positions[2] || list1[positions[0]] < list3[positions[2]]))
    {
        positions[0]++;
        return list1[positions[0] - 1];
    }
    else if (list2.size() > positions[1] &&
             (list3.size() == positions[2] || list2[positions[1]] < list3[positions[2]]))
    {
        positions[1]++;
        return list2[positions[1] - 1];
    }
    else if (list3.size() > positions[2])
    {
        positions[2]++;
        return list3[positions[2] - 1];
    }
    return std::nullopt;
}

int main(int, char**){
    std::vector<int> list1 = {1, 8, 15, 16, 35};
    std::vector<int> list2 = {2, 7, 12, 63};
    std::vector<int> list3 = {10, 13, 14, 42};
    std::array<std::size_t, 3> pos = {0, 0, 0};

    while (true)
    {
        auto result = GetNext(list1, list2, list3, pos);

        if (result.has_value())
        {
            std::cout << *result << " ";
        }
        else
        {
            break;
        }
    }
    std::cout << '\n';
}
