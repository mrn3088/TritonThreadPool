#ifndef TSTDEX_HPP
#define TSTDEX_HPP

#include <memory>
#include <type_traits>

// adapt std::enable_if_t for c++11
template <bool B, typename T = void>
using t_enable_if_t = typename std::enable_if<B, T>::type;

// adapt std::make_unique for c++11
template <typename T, typename... Args>
typename std::unique_ptr<T> t_make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif //TSTDEX_HPP