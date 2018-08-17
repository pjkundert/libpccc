/*
 * Copyright (C) 2007 Jason Valenzuela
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Design Systems Partners
 * Attn: Jason Valenzuela
 * 2516 JMT Industrial Drive, Suite 112
 * Apopka, FL  32703
 * jvalenzuela <at> dspfl <dot> com
 */

#ifndef _COMMON_H
#define _COMMON_H

#include <arpa/inet.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <unistd.h>

/*
 * Message types between server and client.
 * Valid messages must start with one of these.
 */
#define MSG_SOH 1 /* New message, followed by length byte. */
#define MSG_ACK 6 /* Single byte message. */
#define MSG_NAK 15 /* Single byte message. */

typedef struct _buf
{
  uint8_t *data;
  size_t max;
  size_t len;
  size_t index; /* Current read/write location. */
} BUF;

extern BUF *buf_new(size_t bytes);
extern int buf_append_buf(BUF *dst, const BUF *src);
extern int buf_append_byte(BUF *dst, uint8_t src);
extern int buf_append_word(BUF *dst, uint16_t src);
extern int buf_append_long(BUF *dest, uint32_t src);
extern int buf_append_str(BUF *dst, const char *src);
extern int buf_append_blob(BUF *dst, void *src, size_t len);
extern int buf_get_byte(BUF *src, uint8_t *dst);
extern int buf_get_word(BUF *src, uint16_t *dst);
extern int buf_get_long(BUF *src, uint32_t *dst);
extern ssize_t buf_read(int fd, BUF *dst);
extern int buf_write_ready(const BUF *buf);
extern ssize_t buf_write(int fd, BUF *src);
extern void buf_empty(BUF *buf);
extern void buf_free(BUF *buf);

extern uint16_t ltohs(uint16_t linkshort);
extern uint16_t htols(uint16_t hostshort);
extern uint32_t ltohl(uint32_t linklong);
extern uint32_t htoll(uint32_t hostlong);

#endif /* _COMMON_H */
