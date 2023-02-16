#ifndef MACSN_H
#define MACSN_H

struct __attribute__ ((__packed__)) MAC_SN
{
    u8 date[6];
    u8 version; // macsn format version
    u8 hwrev[2];
    u8 sn[17];
    u8 key_size;
    u8 key[97];
    u32 crc;
    u8 padding[122];
    u8 mac[6];
};

struct MAC_SN* read_macsn(void);
int save_macsn(void);

#endif // MACSN_H
