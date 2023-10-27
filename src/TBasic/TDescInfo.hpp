#ifndef TDESCINFO_HPP
#define TDESCINFO_HPP

#include <string>

#include "TBasicInclude.hpp"

namespace mrn {

    class TDescInfo {
    public:
        const std::string& getName() const {
            return name_;
        }

        const std::string& getSession() const {
            return session_;
        }

        const std::string& getDescription() const {
            return description_;
        }

        virtual auto setName(const std::string& name) -> decltype(this) {
            name_ = name;
            return this;
        }

        virtual auto setSession(const std::string& session) -> decltype(this) {
            session_ = session;
            return this;
        }

        virtual auto setDescription(const std::string& description) -> decltype(this) {
            description_ = description;
            return this;
        }

        virtual ~TDescInfo() = default;

    protected:
        std::string name_;
        std::string session_;
        std::string description_;
    };

}

#endif //TDESCINFO_HPP