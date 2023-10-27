#ifndef TEXCEPTION_HPP
#define TEXCEPTION_HPP

#include <exception>

#include "TStrDefine.hpp"

namespace mrn {

    class TEXCEPTION : public std::exception {
    public:
        explicit TEXCEPTION(const std::string& info,
            const std::string& locate = T_EMPTY) {
            exception_info_ = locate + " | " + info;
        }

        const char* what() const noexcept override {
            return exception_info_.c_str();
        }

    private:
        std::string exception_info_;
    };

}

#endif //TEXCEPTION_HPP