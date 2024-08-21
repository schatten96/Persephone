#ifndef NENETTA_ALLOCATOR_HPP
#define NENETTA_ALLOCATOR_HPP

#include <exception>
#include <limits>

namespace nenetta::util {

template <class T>
struct allocator {

    typedef T value_type;

    allocator() = default;
    
    template <class U>
    constexpr allocator(const allocator<U>&) noexcept {}

    /**
     * @brief   Allocates (n * sizeof(T)) bytes if possible
     * @param n Amount of objects type T
     * @return  Pointer to allocated memory
     * @example std::allocator_traits<nenetta::util::allocator>::allocate(_alloc, 10)
     */
    [[nodiscard]] T* allocate(unsigned long n) {
        if (n > std::numeric_limits<unsigned long>::max() / sizeof(T))
            throw std::bad_alloc();

        if (auto p = static_cast<T*>(std::malloc(n * sizeof(T))))
            return p;

        throw std::bad_alloc();
    }

    /**
     * @brief   Frees memory pointed by p
     * @param p Pointer where memory should be deallocated
     * @param - Number of elements to free [unused]
     * @example std::allocator_traits<nenetta::util::allocator>::deallocate(_alloc, p)
     */
    void deallocate(T* p, unsigned long) noexcept {
        std::free(p);
    }

    /**
     * @brief           Calls placement new in p with arguments args
     * @tparam ...Args  Parameters of constructor T
     * @param p         Place where object should be constructed
     * @param ...args   Arguments of the T::T()
     * @example         std::allocator_traits<nenetta::util::allocator>::construct(_alloc, p, 10, std::string(), somevariable)
     */
    template <class... Args>
    void construct(T* p, Args&&... args) {
        new (p) T(std::forward<Args>(args)...);
    }

    /**
     * @brief   Calls ~T() in the memory pointed by p
     * @param p Pointer to object of type T
     * @example std::allocator_traits<nenetta::util::allocator>::destroy(_alloc, p)
     */
    void destroy(T* p) noexcept { p->~T(); }

    /**
     * @brief       Rebinds Allocator<T> to another type U
     * @tparam U    Binding type
     * @example     using NodeAlloc = typename nenetta::util::allocator::rebind<Node>::other
     */
    template <class U>
    struct rebind {
        typedef allocator<U> other;
    };
};

} // namespace nenetta::util

#endif // NENETTA_ALLOCATOR_HPP
