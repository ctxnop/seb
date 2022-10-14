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
        EFIAPI console(SIMPLE_TEXT_OUTPUT_INTERFACE* out);
        EFIAPI ~console();

        // Interface wrapping
        EFI_STATUS EFIAPI reset(BOOLEAN extendedVerification) const;
        EFI_STATUS EFIAPI output(CHAR16* str) const;
        EFI_STATUS EFIAPI test_string(CHAR16* str) const;
        EFI_STATUS EFIAPI query_mode(UINTN mode, UINTN* columns, UINTN* rows) const;
        EFI_STATUS EFIAPI set_mode(UINTN mode) const;
        EFI_STATUS EFIAPI set_attribute(UINTN attr) const;
        EFI_STATUS EFIAPI clear_screen() const;
        EFI_STATUS EFIAPI set_cursor_position(UINTN col, UINTN row) const;
        EFI_STATUS EFIAPI enable_cursor(BOOLEAN enable) const;

        // High level API
        console& EFIAPI operator<<(wchar_t* msg);
        console& EFIAPI operator<<(UINTN Attribute);
        
        // Defaulted copy/move
        EFIAPI console(const console&) = default;
        console& EFIAPI operator=(const console&) = default;

        EFIAPI console(console&&) = default;
        console& EFIAPI operator=(console&&) = default;
    private:
        SIMPLE_TEXT_OUTPUT_INTERFACE* m_out;
    };
}
