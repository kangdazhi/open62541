/* This work is licensed under a Creative Commons CCZero 1.0 Universal License.
 * See http://creativecommons.org/publicdomain/zero/1.0/ for more information. */

#include "ua_util.h"

#include <ctype.h>
#include <stdio.h>
void UA_dump_hex_pkg(UA_Byte* buffer, size_t bufferLen) {
    printf("--------------- HEX Package Start ---------------\n");
    char ascii[17];
    memset(ascii,0,17);
    for (size_t i = 0; i < bufferLen; i++)
    {
        if (i == 0)
            printf("%08zx ", i);
        else if (i%16 == 0)
            printf("|%s|\n%08zx ", ascii, i);
        if (isprint((int)(buffer[i])))
            ascii[i%16] = (char)buffer[i];
        else
            ascii[i%16] = '.';
        printf("%02X ", (unsigned char)buffer[i]);
    }
    size_t fillPos = bufferLen %16;
    ascii[fillPos] = 0;
    for (size_t i=fillPos; i<16; i++) {
        printf("   ");
    }
    printf("|%s|\n%08zx\n", ascii, bufferLen);
    printf("--------------- HEX Package END ---------------\n");
}