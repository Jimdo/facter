/**
 * @file
 * Declares the Linux operating system fact resolver.
 */
#ifndef FACTER_FACTS_LINUX_OPERATING_SYSTEM_RESOLVER_HPP_
#define FACTER_FACTS_LINUX_OPERATING_SYSTEM_RESOLVER_HPP_

#include "../posix/operating_system_resolver.hpp"
#include "../scalar_value.hpp"

namespace facter { namespace facts { namespace linux {

    /**
     * Responsible for resolving operating system facts.
     */
    struct operating_system_resolver : posix::operating_system_resolver
    {
     protected:
        /**
         * Called to determine the operating system name.
         * @param facts The fact collection that is resolving facts.
         * @returns Returns a string representing the operating system name.
         */
        virtual std::string determine_operating_system(collection &facts);
        /**
         * Called to determine the operating system release.
         * @param facts The fact collection that is resolving facts.
         * @param operating_system The name of the operating system.
         * @returns Returns a string representing the operating system release.
         */
        virtual std::string determine_operating_system_release(collection& facts, std::string const& operating_system);
        /**
         * Called to determine the operating system major release.
         * @param facts The fact collection that is resolving facts.
         * @param operating_system The name of the operating system.
         * @param os_release The version of the operating system.
         * @returns Returns a string representing the operating system major release.
         */
        virtual std::string determine_operating_system_major_release(collection& facts, std::string const& operating_system, std::string const& os_release);
        /**
         * Called to determine the operating system minor release.
         * @param facts The fact collection that is resolving facts.
         * @param operating_system The name of the operating system.
         * @param os_release The version of the operating system.
         * @returns Returns a string representing the operating system minor release.
         */
        virtual std::string determine_operating_system_minor_release(collection& facts, std::string const& operating_system, std::string const& os_release);

     private:
        static std::string check_cumulus_linux();
        static std::string check_debian_linux(string_value const* dist_id);
        static std::string check_oracle_linux();
        static std::string check_redhat_linux();
        static std::string check_suse_linux();
        static std::string check_other_linux();
    };

}}}  // namespace facter::facts::linux

#endif  // FACTER_FACTS_LINUX_OPERATING_SYSTEM_RESOLVER_HPP_

