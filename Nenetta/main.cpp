#include <iostream>

#include <nenetta/core/utility/allocator.hpp>

int main(int argc, char* argv[]) {
    nenetta::util::allocator<int> alloc;
    auto* p = alloc.allocate(5);

    std::cout << p << std::endl;
}
