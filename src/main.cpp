#include <efi-cpp/efi.hpp>

EFI_STATUS EFIAPI efi_main(EFI_HANDLE handle, EFI_SYSTEM_TABLE* st)
{
    efi::console cout{st->ConOut};
    cout.clear_screen();

    cout << L"Welcome to "
        << EFI_RED      << L"S" << EFI_LIGHTGRAY << L"imple "
        << EFI_GREEN    << L"E" << EFI_LIGHTGRAY << L"fi "
        << EFI_BLUE     << L"B" << EFI_LIGHTGRAY << L"ootloader\n";
    return EFI_SUCCESS;
}
