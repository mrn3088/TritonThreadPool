#ifndef TFUNCTYPE_HPP
#define TFUNCTYPE_HPP

#include <functional>

#include "TStatus.hpp"

namespace mrn {

    using T_DEFAULT_FUNCTION = std::function<void()>;
    using T_DEFAULT_CONST_FUNCTION_REF = const std::function<void()>&;
    using T_TSTATUS_FUNCTION = std::function<TSTATUS()>;
    using T_TSTATUS_CONST_FUNCTION_REF = const std::function<TSTATUS()>&;
    using T_CALLBACK_FUNCTION = std::function<void(TSTATUS)>;
    using T_CALLBACK_CONST_FUNCTION_REF = const std::function<void(TSTATUS)>&;


    enum class TFunctionType {
        INIT = 1,
        RUN = 2,
        DESTROY = 3,
    };

#define T_FUNCTION_BEGIN                                           \
    TStatus status;                                                     \

#define T_FUNCTION_END                                             \
    return status;                                                      \

#define T_EMPTY_FUNCTION                                           \
    return TStatus();                                                   \

#define T_GET_LOCATE                                               \
    (std::string(__FILE__) + " | " + std::string(__FUNCTION__)          \
    + " | line = [" + ::std::to_string( __LINE__) + "]")

#define TErrStatus(info)                                                \
    TStatus(info, T_GET_LOCATE)                                    \

#define T_RETURN_ERROR_STATUS(info)                                \
    return TErrStatus(info);                                            \

#define T_RETURN_ERROR_STATUS_BY_CONDITION(cond, info)             \
    if (unlikely(cond)) { T_RETURN_ERROR_STATUS(info); }           \

#define T_NO_SUPPORT                                               \
    return TErrStatus(T_FUNCTION_NO_SUPPORT);                      \

#define T_NO_ALLOWED_COPY(TType)                                   \
    TType(const TType &) = delete;                                      \
    const TType &operator=(const TType &) = delete;                     \

#define T_THROW_EXCEPTION(info)                                    \
    throw TException(info, T_GET_LOCATE);                          \

#define T_THROW_EXCEPTION_BY_STATUS(status)                        \
    if (unlikely((status).isErr())) {                                   \
        T_THROW_EXCEPTION((status).getInfo());                     \
    }                                                                   \

#define T_THROW_EXCEPTION_BY_CONDITION(cond, info)                 \
    if (unlikely(cond)) { T_THROW_EXCEPTION(info); }               \

}
#endif //TFUNCTYPE_HPP