# Siber Systems C++ test task

`GetNext()` iterates over three sorted lists and returns their elements in ascending order without constructing a merged list. The implementation and demonstration are in `main.cpp`.

## Requirements

- C++17 or later (`std::optional` is used to represent the end of the sequence).
- For the supplied Windows presets: CMake 3.21+ and Visual Studio 2022 with the C++ desktop development tools and a Windows SDK.

## Build and run on Windows x64

Run these commands from the project directory:

```powershell
cmake --preset vs2022-x64
cmake --build --preset x64-debug
.\out\build\vs2022-x64\Debug\Siber_test.exe
```

For Release:

```powershell
cmake --build --preset x64-release
.\out\build\vs2022-x64\Release\Siber_test.exe
```

The included VS Code launch configuration builds and runs the Debug executable with F5. It requires the Microsoft C/C++ extension.

## API and state

```cpp
std::optional<int> GetNext(
    const std::vector<int>& list1,
    const std::vector<int>& list2,
    const std::vector<int>& list3,
    std::array<std::size_t, 3>& positions);
```

The caller owns three positions, initially `{0, 0, 0}`. Each position identifies the next unread element in the corresponding vector. Each successful call returns one integer by value and advances exactly one position.

The function compares the current elements of non-exhausted lists and selects the smallest. Exhausted lists are excluded through short-circuit checks before element access.

When all lists are exhausted, the function returns `std::nullopt`. Further calls return `std::nullopt` without changing the positions. Separate position arrays allow independent traversals; resetting the positions to zero restarts a traversal.

### Preconditions

- Each input list is sorted in ascending order.
- All integers are unique across and within the three lists, as specified in the task.
- Each position is between zero and the corresponding list size, inclusive.
- The same input lists are used throughout a traversal and are not modified during it.

These preconditions are assumed rather than validated. Empty lists are supported. The function does not retain references between calls or modify the input lists.

## Example

```text
List 1: 1, 8, 15, 16, 35
List 2: 2, 7, 12, 63
List 3: 10, 13, 14, 42
```

Output:

```text
1 2 7 8 10 12 13 14 15 16 35 42 63
```

## Complexity

Each call performs a fixed number of comparisons and advances at most one position: O(1) time per call. A complete traversal takes O(N) time, where N is the total number of input elements, and O(1) additional memory. No merged container is created.
