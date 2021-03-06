/**
 * @file        crcFast.c
 * @brief       Cyclic Redundancy Check - CRC calculator
 * @author      pankajpatro703
 * @date        23.08.2020      //created
 * @date        12.09.2020      //modified
 * @version     1.0.1
 * @copyright   Copyright (C) 2020 Pankajkumar Patro
 * @license     GNU Lesser GPL v3.0+
 * @see         https://github.com/pankajpatro703/digitalCom-lib
 *
 * crcFast.c - Description file to calculate high speed 8,16,32,64-bit CRC Hash value.
 *
 * Copyright (C) 2020 Pankajkumar Patro
 *
 * This file is part of digitalCom-lib.
 *
 * digitalCom-lib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * digitalCom-lib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with digitalCom-lib.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "crc.h"

crcparam8 CRC8_AUTOSAR          = {.poly=0x2F, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0xFF};
crcparam8 CRC8_BLUETOOTH        = {.poly=0xA7, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_CDMA2000         = {.poly=0x9B, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_DARC             = {.poly=0x39, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_DVB_S2           = {.poly=0xD5, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_EBU              = {.poly=0x1D, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_GSM_A            = {.poly=0x1D, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_GSM_B            = {.poly=0x49, .init=0x00, .refIn=false, .refOut=false, .xorOut=0xFF};
crcparam8 CRC8_ITU              = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x55};
crcparam8 CRC8_I_CODE           = {.poly=0x1D, .init=0xFD, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_LTE              = {.poly=0x9B, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_MAXIM            = {.poly=0x31, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_MIFARE_MAD       = {.poly=0x1D, .init=0xC7, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_NRSC_5           = {.poly=0x31, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_OPENSAFETY       = {.poly=0x2F, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_ROHC             = {.poly=0x07, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_SAE_J1850        = {.poly=0x1D, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0xFF};
crcparam8 CRC8_SMBUS            = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_WCDMA            = {.poly=0x9B, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};

crcparam16 CRC16_A              = {.poly=0x1021, .init=0xC6C6, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_ARC            = {.poly=0x8005, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_AUG_CCITT      = {.poly=0x1021, .init=0x1D0F, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_B              = {.poly=0x1021, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crcparam16 CRC16_CCITT_FALSE    = {.poly=0x1021, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_CDMA2000       = {.poly=0xC867, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_CMS            = {.poly=0x8005, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_DDS_110        = {.poly=0x8005, .init=0x800D, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_DECT_R         = {.poly=0x0589, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0001};
crcparam16 CRC16_DECT_X         = {.poly=0x0589, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_DNP            = {.poly=0x3D65, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crcparam16 CRC16_EN_13757       = {.poly=0x3D65, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crcparam16 CRC16_GENIBUS        = {.poly=0x1021, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crcparam16 CRC16_GSM            = {.poly=0x1021, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crcparam16 CRC16_KERMIT         = {.poly=0x1021, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_LJ1200         = {.poly=0x6F63, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_MAXIM          = {.poly=0x8005, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crcparam16 CRC16_MCRF4XX        = {.poly=0x1021, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_MODBUS         = {.poly=0x8005, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_NRSC_5         = {.poly=0x080B, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_OPENSAFETY_A   = {.poly=0x5935, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_OPENSAFETY_B   = {.poly=0x755B, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_PROFIBUS       = {.poly=0x1DCF, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crcparam16 CRC16_RIELLO         = {.poly=0x1021, .init=0xB2AA, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_T10_DIF        = {.poly=0x8BB7, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_TELEDISK       = {.poly=0xA097, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_TMS37157       = {.poly=0x1021, .init=0x89EC, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_UMTS           = {.poly=0x8005, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_USB            = {.poly=0x8005, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crcparam16 CRC16_XMODEM         = {.poly=0x1021, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};

crcparam32 CRC32_ADCCP          = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crcparam32 CRC32_AUTOSAR        = {.poly=0xF4ACFB13, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crcparam32 CRC32_BZIP2          = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF};
crcparam32 CRC32_C              = {.poly=0x1EDC6F41, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crcparam32 CRC32_CD_ROM_EDC     = {.poly=0x8001801B, .init=0x00000000, .refIn=true,  .refOut=true,  .xorOut=0x00000000};
crcparam32 CRC32_D              = {.poly=0xA833982B, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crcparam32 CRC32_JAMCRC         = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0x00000000};
crcparam32 CRC32_MPEG2          = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0x00000000};
crcparam32 CRC32_POSIX          = {.poly=0x04C11DB7, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF};
crcparam32 CRC32_Q              = {.poly=0x814141AB, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000};
crcparam32 CRC32_XFER           = {.poly=0x000000AF, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000};

crcparam64 CRC64_ECMA_182       = {.poly=0x42F0E1EBA9EA3693, .init=0x0000000000000000, .refIn=false, .refOut=false, .xorOut=0x0000000000000000};
crcparam64 CRC64_GO_ISO         = {.poly=0x000000000000001B, .init=0xFFFFFFFFFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFFFFFFFFFF};
crcparam64 CRC64_WE             = {.poly=0x42F0E1EBA9EA3693, .init=0xFFFFFFFFFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFFFFFFFFFF};
crcparam64 CRC64_XZ             = {.poly=0x42F0E1EBA9EA3693, .init=0xFFFFFFFFFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFFFFFFFFFF};

uint8_t table8[256];
uint16_t table16[256];
uint32_t table32[256];
uint64_t table64[256];

uint8_t reverseBits8(uint8_t num) {
    uint8_t revnum = 0;
    for (uint8_t i = 0; i < 8; ++i) {
        if(num & ((uint8_t)1 << i))
            revnum |= ((uint8_t)1 << (7 - i));
    }
    return revnum;
}
uint16_t reverseBits16(uint16_t num) {
    uint16_t revnum = 0;
    for (uint8_t i = 0; i < 16; ++i) {
        if(num & ((uint16_t)1 << i))
            revnum |= ((uint16_t)1 << (15 - i));
    }
    return revnum;
}
uint32_t reverseBits32(uint32_t num) {
    uint32_t revnum = 0;
    for (uint8_t i = 0; i < 32; ++i) {
        if(num & ((uint32_t)1 << i))
            revnum |= ((uint32_t)1 << (31 - i));
    }
    return revnum;
}
uint64_t reverseBits64(uint64_t num) {
    uint64_t revnum = 0;
    for (uint8_t i = 0; i < 64; ++i) {
        if(num & ((uint64_t)1 << i))
            revnum |= ((uint64_t)1 << (63 - i));
    }
    return revnum;
}

void gentable8(crcparam8* paramlist) {
    if(paramlist -> refIn) {
        for(uint16_t i = 0; i < 256; ++i) {
            table8[i] = i;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table8[i] & 1)
                    table8[i] = (table8[i] >> 1) ^ reverseBits8(paramlist -> poly);
                else
                    table8[i] >>= 1;
            }
        }
    }
    else {
        for(uint16_t i = 0; i < 256; ++i) {
            table8[i] = (uint8_t)i;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table8[i] & ((uint8_t)1 << 7))
                    table8[i] = (table8[i] << 1) ^ paramlist -> poly;
                else
                    table8[i] <<= 1;
            }
        }
    }
}
void gentable16(crcparam16* paramlist) {
    if(paramlist -> refIn) {
        for(uint16_t i = 0; i < 256; ++i) {
            table16[i] = i;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table16[i] & 1)
                    table16[i] = (table16[i] >> 1) ^ reverseBits16(paramlist -> poly);
                else
                    table16[i] >>= 1;
            }
        }
    }
    else {
        for(uint16_t i = 0; i < 256; ++i) {
            table16[i] = (uint16_t)i << 8;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table16[i] & ((uint16_t)1 << 15))
                    table16[i] = (table16[i] << 1) ^ paramlist -> poly;
                else
                    table16[i] <<= 1;
            }
        }
    }
}
void gentable32(crcparam32* paramlist) {
    if(paramlist -> refIn) {
        for(uint16_t i = 0; i < 256; ++i) {
            table32[i] = i;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table32[i] & 1)
                    table32[i] = (table32[i] >> 1) ^ reverseBits32(paramlist -> poly);
                else
                    table32[i] >>= 1;
            }
        }
    }
    else {
        for(uint16_t i = 0; i < 256; ++i) {
            table32[i] = (uint32_t)i << 24;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table32[i] & ((uint32_t)1 << 31))
                    table32[i] = (table32[i] << 1) ^ paramlist -> poly;
                else
                    table32[i] <<= 1;
            }
        }
    }
}
void gentable64(crcparam64* paramlist) {
    if(paramlist -> refIn) {
        for(uint16_t i = 0; i < 256; ++i) {
            table64[i] = i;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table64[i] & 1)
                    table64[i] = (table64[i] >> 1) ^ reverseBits64(paramlist -> poly);
                else
                    table64[i] >>= 1;
            }
        }
    }
    else {
        for(uint16_t i = 0; i < 256; ++i) {
            table64[i] = (uint64_t)i << 56;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table64[i] & ((uint64_t)1 << 63))
                    table64[i] = (table64[i] << 1) ^ paramlist -> poly;
                else
                    table64[i] <<= 1;
            }
        }
    }
}

uint8_t initCRC8(crcparam8* paramlist) {
    return paramlist -> refIn ? reverseBits8(paramlist -> init) : paramlist -> init;
}
uint16_t initCRC16(crcparam16* paramlist) {
    return paramlist -> refIn ? reverseBits16(paramlist -> init) : paramlist -> init;
}
uint32_t initCRC32(crcparam32* paramlist) {
    return paramlist -> refIn ? reverseBits32(paramlist -> init) : paramlist -> init;
}
uint64_t initCRC64(crcparam64* paramlist) {
    return paramlist -> refIn ? reverseBits64(paramlist -> init) : paramlist -> init;
}

uint8_t updateCRC8(uint8_t* s, uint8_t crc_val, crcparam8* paramlist) {
    return table8[(crc_val & 0xff) ^ *s];
}
uint16_t updateCRC16(uint8_t* s, uint16_t crc_val, crcparam16* paramlist) {
    if(paramlist -> refOut)
        return ((crc_val >> 8) & 0xff) ^ table16[(crc_val & 0xff) ^ *s];
    else
        return ((crc_val << 8) & 0xff00) ^ table16[((crc_val >> 8) & 0xff) ^ *s];
}
uint32_t updateCRC32(uint8_t* s, uint32_t crc_val, crcparam32* paramlist) {
    if(paramlist -> refOut)
        return ((crc_val >> 8) & 0xffffff) ^ table32[(crc_val & 0xff) ^ *s];
    else
        return ((crc_val << 8) & 0xffffff00) ^ table32[((crc_val >> 24) & 0xff) ^ *s];
}
uint64_t updateCRC64(uint8_t* s, uint64_t crc_val, crcparam64* paramlist) {
    if(paramlist -> refOut)
        return ((crc_val >> 8) & 0xffffffffffffff) ^ table64[(crc_val & 0xff) ^ *s];
    else
        return ((crc_val << 8) & 0xffffffffffffff00) ^ table64[((crc_val >> 56) & 0xff) ^ *s];
}

uint8_t fetchCRC8(uint8_t crc_val, crcparam8* paramlist) {
    return crc_val ^ paramlist -> xorOut;
}
uint16_t fetchCRC16(uint16_t crc_val, crcparam16* paramlist) {
    return crc_val ^ paramlist -> xorOut;
}
uint32_t fetchCRC32(uint32_t crc_val, crcparam32* paramlist) {
    return crc_val ^ paramlist -> xorOut;
}
uint64_t fetchCRC64(uint64_t crc_val, crcparam64* paramlist) {
    return crc_val ^ paramlist -> xorOut;
}

uint8_t getCRC8(uint8_t* s, crcparam8* paramlist, size_t length) {
    gentable8(paramlist);
    uint8_t crc_val = initCRC8(paramlist);
    for(size_t i = 0; i < length; ++i)
        crc_val = updateCRC8(s + i, crc_val, paramlist);
    return fetchCRC8(crc_val, paramlist);
}
uint16_t getCRC16(uint8_t* s, crcparam16* paramlist, size_t length) {
    gentable16(paramlist);
    uint16_t crc_val = initCRC16(paramlist);
    for(size_t i = 0; i < length; ++i)
        crc_val = updateCRC16(s + i, crc_val, paramlist);
    return fetchCRC16(crc_val, paramlist);
}
uint32_t getCRC32(uint8_t* s, crcparam32* paramlist, size_t length) {
    gentable32(paramlist);
    uint32_t crc_val = initCRC32(paramlist);
    for(size_t i = 0; i < length; ++i)
        crc_val = updateCRC32(s + i, crc_val, paramlist);
    return fetchCRC32(crc_val, paramlist);
}
uint64_t getCRC64(uint8_t* s, crcparam64* paramlist, size_t length) {
    gentable64(paramlist);
    uint64_t crc_val = initCRC64(paramlist);
    for(size_t i = 0; i < length; ++i)
        crc_val = updateCRC64(s + i, crc_val, paramlist);
    return fetchCRC64(crc_val, paramlist);
}
