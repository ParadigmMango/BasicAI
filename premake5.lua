workspace "BasicAI"
    configurations {"Debug", "Release", "Dist"}

project "ElementaryNN"
    location "ElementaryNN"
    kind "ConsoleApp"

    language "C++"
    staticruntime "On"

    symbols "On" -- On for breakpoints & debug/Off for optimization

    targetdir ("bin/%{prj.name}")
    objdir ("bin-int/%{prj.name}") -- int = intermediate binaries
    
    files {
        "%{prj.location}/src/**.cc"
    }

    includedirs {
        "ElementaryNN/src"
    }
