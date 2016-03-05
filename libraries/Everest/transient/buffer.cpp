#include "buffer.h"

#include <stdlib.h>
#include <string.h>

void buffer_init(Buffer *buf) {
  memset(buf, 0, sizeof(Buffer));
}

void buffer_insert(Buffer *buf, int value) {
  buf->index = (buf->index + 1) % BUF_SIZE;
  int old_value = buf->buffer[buf->index];
  buf->buffer[buf->index] = value;
  buf->sum += value - old_value;
}

int inline buffer_avg(Buffer *buf) {
  return buf->sum / BUF_SIZE;
}

int buffer_has_jumped(Buffer *buf, int threshold) {
  int count = 0;      // Track how many elements we've processed so far.
  int half1_sum = 0;  // Sum of elements in the first half of the buffer.
  int half2_sum = 0;  // Sum of elements in the second half of the buffer.

  // Process current position to the end (less recent elements).
  for (int i = buf->index; i < BUF_SIZE; ++i) {
    if (count++ < BUF_SIZE / 2) {
      half1_sum += buf->buffer[i];
    } else {
      half2_sum += buf->buffer[i];
    }
  }

  // Process start to current position (more recent elements).
  for (int i = 0; i < buf->index; ++i) {
    if (count++ < BUF_SIZE / 2) {
      half1_sum += buf->buffer[i];
    } else {
      half2_sum += buf->buffer[i];
    }
  }

  // Check if the difference between the two halves exceeds the threshold.
  if (abs(half1_sum - half2_sum) * 2 / BUF_SIZE >= threshold) {
    return half1_sum > half2_sum ? 1 : 2;
  } else {
    return 0;
  }
}