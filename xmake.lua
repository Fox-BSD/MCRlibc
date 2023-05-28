add_rules("mode.debug", "mode.release")

set_toolset("cxx", "clang")
set_toolset("ld", "clang++")

target("MCRlibc")
    set_kind("binary")
    add_includedirs("include")
    add_files("lib/**.c")

