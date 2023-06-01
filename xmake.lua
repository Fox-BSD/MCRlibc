add_rules("mode.debug", "mode.release")

set_toolset("cxx", "clang")
set_toolset("ld", "clang++")

target("mcrlibc")
    set_kind("object")
    add_includedirs("include")
    add_files("lib/**.c")
    add_cflags("-nostdlib", "-nostdinc", "-ffreestanding")

target("test")
  set_kind("binary")
  add_includedirs("test/include_test/", "include")
  add_files("test/lib_test/*.c", "test/main.c")
  add_cflags("-nostdlib", "-nostdinc", "-ffreestanding")
