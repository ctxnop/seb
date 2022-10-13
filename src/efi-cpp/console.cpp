#include <efi-cpp/console.hpp>

namespace efi
{
    console::console(SIMPLE_TEXT_OUTPUT_INTERFACE* out)
        : m_out{out}
    {
    }

    console& console::operator<<(wchar_t* msg)
    {
        m_out->OutputString(m_out, reinterpret_cast<CHAR16*>(msg));
        return *this;
    }

    console& console::operator<<(UINTN Attribute)
    {
        m_out->SetAttribute(m_out, Attribute);
        return *this;
    }

}
