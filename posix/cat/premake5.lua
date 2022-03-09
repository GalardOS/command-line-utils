project "cat"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("./")
    objdir("bin/")

    files {"src/**.cc", "src/**.hh"}
    includedirs {"lib/include", "src"}

    filter "configurations:Debug"
        symbols "on"
        optimize "off"
    filter "configurations:Release"
        optimize "on"
        symbols "off"
        runtime "Release"
