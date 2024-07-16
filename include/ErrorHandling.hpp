#pragma once

    #include <exception>

namespace Engine
{
    class GLFWInitException : public std::exception
    {
        public:
            const char *what() const noexcept override
            {
                return ("GLFW initialization failed");
            }
    };
    class GladLoadException : public std::exception
    {
        public:
            const char *what() const noexcept override
            {
                return ("Failed to load GLAD");
            }
    };
    class FileException : public std::exception
    {
        public:
            const char *what() const noexcept override
            {
                return ("Failed to open file");
            }
    };
}