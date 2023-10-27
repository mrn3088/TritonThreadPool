#ifndef TStatus_HPP
#define TStatus_HPP

#include <string>

#include "TBasicDefine.hpp"
#include "TStrDefine.hpp"

namespace mrn {

    /**
     * Note:
     * return 0 means normal logic
     * return negative integer means error logic, program terminate
     * return your own value, please obey the above convention
     */
    static const int STATUS_OK = 0;
    static const int STATUS_ERR = -1;
    static const int STATUS_CRASH = -996;
    static const char* STATUS_ERROR_INFO_CONNECTOR = " && ";
    class TSTATUS {
    public:
        explicit TSTATUS() = default;

        explicit TSTATUS(const std::string& errorInfo, const std::string& errorLocate = T_EMPTY) :
            error_code_(STATUS_ERR), error_info_(errorInfo), error_locate_(errorLocate) {}

        explicit TSTATUS(int errorCode, const std::string& errorInfo, const std::string& errorLocate = T_EMPTY) :
            error_code_(errorCode), error_info_(errorInfo), error_locate_(errorLocate) {}

        TSTATUS(const TSTATUS& status) :
            error_code_(status.error_code_), error_info_(status.error_info_), error_locate_(status.error_locate_) {}

        TSTATUS(TSTATUS&& status) noexcept :
            error_code_(status.error_code_), error_info_(std::move(status.error_info_)), error_locate_(std::move(status.error_locate_)) {}

        TSTATUS& operator=(const TSTATUS& status) = default;

        TSTATUS& operator+=(const TSTATUS& other) {

        }

        int getCode() const {
            return error_code_;
        }

        const std::string& getInfo() const {
            return error_info_;
        }

        const std::string& getLocate() const {
            return error_locate_;
        }

        bool isOK() const {
            return error_code_ == STATUS_OK;
        }

        bool isErr() const {
            return error_code_ < STATUS_OK;
        }

        bool isCrash() const {
            return error_code_ == STATUS_CRASH;
        }

    private:
        int error_code_ = STATUS_OK;
        std::string error_info_;
        std::string error_locate_;
    };

}

#endif //TStatus_HPP