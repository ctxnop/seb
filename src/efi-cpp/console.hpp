#pragma once
#pragma clang diagnostic ignored "-Wwritable-strings"

extern "C" {
    #include <efi.h>
}

namespace efi
{

    class console final
    {
    public:
        console(SIMPLE_TEXT_OUTPUT_INTERFACE* out);
        
        console(const console&) = default;
        console& operator=(const console&) = default;

        console(console&&) = default;
        console& operator=(console&&) = default;

        ~console() {}

        console& operator<<(wchar_t* msg);
        console& operator<<(UINTN Attribute);

    private:
        SIMPLE_TEXT_OUTPUT_INTERFACE* m_out;
    };

}
