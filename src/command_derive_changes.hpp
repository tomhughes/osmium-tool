#ifndef COMMAND_DERIVE_CHANGES_HPP
#define COMMAND_DERIVE_CHANGES_HPP

/*

Osmium -- OpenStreetMap data manipulation command line tool
https://osmcode.org/osmium-tool/

Copyright (C) 2013-2025  Jochen Topf <jochen@topf.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include "cmd.hpp" // IWYU pragma: export

#include <osmium/io/writer.hpp>
#include <osmium/memory/buffer.hpp>
#include <osmium/osm/object.hpp>

#include <string>
#include <vector>

class CommandDeriveChanges : public CommandWithMultipleOSMInputs, public with_osm_output {

    osmium::memory::Buffer m_buffer{128};

    bool m_keep_details = false;
    bool m_update_timestamp = false;
    bool m_increment_version = false;

public:

    explicit CommandDeriveChanges(const CommandFactory& command_factory) :
        CommandWithMultipleOSMInputs(command_factory) {
    }

    bool setup(const std::vector<std::string>& arguments) override final;

    void show_arguments() override final;

    void write_deleted(osmium::io::Writer& writer, osmium::OSMObject& object);

    bool run() override final;

    const char* name() const noexcept override final {
        return "derive-changes";
    }

    const char* synopsis() const noexcept override final {
        return "osmium derive-changes [OPTIONS] OSM-FILE1 OSM-FILE2";
    }

}; // class CommandDeriveChanges


#endif // COMMAND_DERIVE_CHANGES_HPP
