/*

    MIT License

    Copyright (c) 2021 Kento Oki

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

*/

#pragma once
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

namespace console
{
    inline static HANDLE std_handle;

    //
    // credit: klutt
    // https://stackoverflow.com/a/62784810/15472612
    //
    bool enable_ansi_escape()
    {
        DWORD console_mode = 0;
        std_handle = GetStdHandle( STD_OUTPUT_HANDLE );

        if ( std_handle == INVALID_HANDLE_VALUE )
            return false;

        if ( !GetConsoleMode( std_handle, &console_mode ) )
            return false;

        // enable ANSI escape codes
        console_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

        if ( !SetConsoleMode( std_handle, console_mode ) )
            return false;

        return true;
    }
}