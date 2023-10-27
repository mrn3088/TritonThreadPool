#ifndef TOBJECT_HPP
#define TOBJECT_HPP

#include "TBasicDefine.hpp"
#include "TValType.hpp"
#include "TFuncType.hpp"

namespace mrn {

    class TObject {
    public:
        explicit TObject() = default;

        virtual TStatus init() {
            T_EMPTY_FUNCTION
        }

        virtual TStatus run() = 0;

        virtual TStatus destroy() {
            T_EMPTY_FUNCTION
        }

        virtual ~TObject() = default;
    };

}

#endif // TOBJECT_HPP