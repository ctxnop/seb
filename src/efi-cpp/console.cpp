#include <efi-cpp/console.hpp>

namespace efi
{
    console::console(SIMPLE_TEXT_OUTPUT_INTERFACE* out)
        : m_out{out}
    {
    }

    console::~console()
    {
        // Nothing to do.
    }

    EFI_STATUS EFIAPI console::reset(BOOLEAN extendedVerification) const
    {
        return m_out->Reset(m_out, extendedVerification);
    }

    EFI_STATUS EFIAPI console::output(CHAR16* str) const
    {
        return m_out->OutputString(m_out, str);
    }

    EFI_STATUS EFIAPI console::test_string(CHAR16* str) const
    {
        return m_out->TestString(m_out, str);
    }

    EFI_STATUS EFIAPI console::query_mode(UINTN mode, UINTN* columns, UINTN* rows) const
    {
        return m_out->QueryMode(m_out, mode, columns, rows);
    }

    EFI_STATUS EFIAPI console::set_mode(UINTN mode) const
    {
        return m_out->SetMode(m_out, mode);
    }

    EFI_STATUS EFIAPI console::set_attribute(UINTN attr) const
    {
        return m_out->SetAttribute(m_out, attr);
    }

    EFI_STATUS EFIAPI console::clear_screen() const
    {
        return m_out->ClearScreen(m_out);
    }

    EFI_STATUS EFIAPI console::set_cursor_position(UINTN col, UINTN row) const
    {
        return m_out->SetCursorPosition(m_out, col, row);
    }

    EFI_STATUS EFIAPI console::enable_cursor(BOOLEAN enable) const
    {
        return m_out->EnableCursor(m_out, enable);
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
