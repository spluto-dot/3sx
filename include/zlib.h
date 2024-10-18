#ifndef ZLIB_H
#define ZLIB_H

// MARK: - Macros

#define ZLIB_VERSION "1.1.4"

// MARK: - Types

struct z_stream_s {
    // total size: 0x48
    unsigned char *next_in;                              // offset 0x0, size 0x4
    unsigned int avail_in;                               // offset 0x4, size 0x4
    unsigned long total_in;                              // offset 0x8, size 0x4
    unsigned char *next_out;                             // offset 0x10, size 0x4
    unsigned int avail_out;                              // offset 0x14, size 0x4
    unsigned long total_out;                             // offset 0x18, size 0x4
    char *msg;                                           // offset 0x20, size 0x4
    struct internal_state *state;                        // offset 0x24, size 0x4
    void *(*zalloc)(void *, unsigned int, unsigned int); // offset 0x28, size 0x4
    void (*zfree)(void *, void *);                       // offset 0x2C, size 0x4
    void *opaque;                                        // offset 0x30, size 0x4
    int data_type;                                       // offset 0x34, size 0x4
    unsigned long adler;                                 // offset 0x38, size 0x4
    unsigned long reserved;                              // offset 0x40, size 0x4
}; // offset 0x4C, size 0x2C

// MARK: - Functions

int inflateEnd(struct z_stream_s *z);                                   // Range: 0x3BC100 -> 0x3BC1E0
int inflateInit_(struct z_stream_s *z, char *version, int stream_size); // Range: 0x3BC440 -> 0x3BC47C
int inflate(struct z_stream_s *z, int f);                               // Range: 0x3BC480 -> 0x3BCE1C

#endif
