#ifndef __UTIL_RINGBUFFER_H__

/** \brief ring buffer api
 *
 *  Ring buffer api for a single writer and a single reader. It uses a
 *  read and write pointer. Only the read ptr needs atomic updating.
 */

#define RING_BUFFER_MRSW_8_SIZE 256

/** Multiple Reader, Single Writer ring buffer, fixed at
 *  256 items so we can use unsigned char's that just
 *  wrap around */
typedef struct RingBufferMrSw8_ {
    unsigned char write;  /**< idx where we put data */
    unsigned char read;   /**< idx where we read data */
    uint8_t shutdown;
    void *array[RING_BUFFER_MRSW_8_SIZE];
} RingBufferMrSw8;

void *RingBufferMrSw8Get(RingBufferMrSw8 *);
int RingBufferMrSw8Put(RingBufferMrSw8 *, void *);
RingBufferMrSw8 *RingBufferMrSw8Init(void);
void RingBufferMrSw8Destroy(RingBufferMrSw8 *);

#define RING_BUFFER_MRSW_SIZE 65536

/** Multiple Reader, Single Writer ring buffer, fixed at
 *  65536 items so we can use unsigned shorts that just
 *  wrap around */
typedef struct RingBufferMrSw_ {
    unsigned short write;  /**< idx where we put data */
    unsigned short read;   /**< idx where we read data */
    uint8_t shutdown;
    void *array[RING_BUFFER_MRSW_SIZE];
} RingBufferMrSw;

void *RingBufferMrSwGet(RingBufferMrSw *);
int RingBufferMrSwPut(RingBufferMrSw *, void *);
RingBufferMrSw *RingBufferMrSwInit(void);
void RingBufferMrSwDestroy(RingBufferMrSw *);

#define RING_BUFFER_SRSW_SIZE 65536

/** Single Reader, Single Writer ring buffer, fixed at
 *  65536 items so we can use unsigned shorts that just
 *  wrap around */
typedef struct RingBufferSrSw_ {
    unsigned short write;  /**< idx where we put data */
    unsigned short read;   /**< idx where we read data */
    uint8_t shutdown;
    void *array[RING_BUFFER_SRSW_SIZE];
} RingBufferSrSw;

void *RingBufferSrSwGet(RingBufferSrSw *);
int RingBufferSrSwPut(RingBufferSrSw *, void *);
RingBufferSrSw *RingBufferSrSwInit(void);
void RingBufferSrSwDestroy(RingBufferSrSw *);

#define RING_BUFFER_MRMW_8_SIZE 256

/** Multiple Reader, Multi Writer ring buffer, fixed at
 *  256 items so we can use unsigned char's that just
 *  wrap around */
typedef struct RingBufferMrMw8_ {
    unsigned char write;  /**< idx where we put data */
    unsigned char read;   /**< idx where we read data */
    uint8_t shutdown;
    SCSpinlock spin;      /**< lock protecting writes */
    void *array[RING_BUFFER_MRMW_8_SIZE];
} RingBufferMrMw8;

void *RingBufferMrMw8Get(RingBufferMrMw8 *);
int RingBufferMrMw8Put(RingBufferMrMw8 *, void *);
RingBufferMrMw8 *RingBufferMrMw8Init(void);
void RingBufferMrMw8Destroy(RingBufferMrMw8 *);

#define RING_BUFFER_MRMW_SIZE 65536

/** Multiple Reader, Multi Writer ring buffer, fixed at
 *  65536 items so we can use unsigned char's that just
 *  wrap around */
typedef struct RingBufferMrMw_ {
    unsigned short write;  /**< idx where we put data */
    unsigned short read;   /**< idx where we read data */
    uint8_t shutdown;
    SCSpinlock spin;      /**< lock protecting writes */
    void *array[RING_BUFFER_MRMW_SIZE];
} RingBufferMrMw;

void *RingBufferMrMwGet(RingBufferMrMw *);
int RingBufferMrMwPut(RingBufferMrMw *, void *);
RingBufferMrMw *RingBufferMrMwInit(void);
void RingBufferMrMwDestroy(RingBufferMrMw *);

#endif /* __UTIL_RINGBUFFER_H__ */
