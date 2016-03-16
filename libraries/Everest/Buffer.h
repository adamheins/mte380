#pragma once

class Buffer {
  public:
    Buffer(int len);
    ~Buffer();
    void insert(int value);
    int average();
    void reset();
    bool edge();

  private:
    int *arr;
    unsigned int len;
    unsigned int index;
    long sum;
    bool filled;
};

