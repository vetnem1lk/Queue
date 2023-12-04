#include "Queue.h"
#include <iostream>

Queue::Queue(uint16_t iSize) : Head(0), Tail(0), Size(iSize) {
    hData = new uint8_t[Size];
}

Queue::~Queue() {
    delete[] hData;
}

uint16_t Queue::Put(const uint8_t *data, uint16_t dataSize) {
    if (dataSize == 0 || dataSize > (Size - GetSize())) {
        return 0;  // Невозможно добавить данные, недостаточно места в очереди
    }

    uint16_t addedBytes = 0;
    while (addedBytes < dataSize) {
        hData[Head] = data[addedBytes];
        Head = (Head + 1) % Size;
        addedBytes++;
    }

    return addedBytes;
}

uint16_t Queue::GetSize() const {
    return (Head >= Tail) ? (Head - Tail) : (Size - Tail + Head);
}

uint16_t Queue::Get(uint8_t *data, uint16_t dataSize) {
    uint16_t bytesRead = 0;
    while (bytesRead < dataSize && Tail != Head) {
        data[bytesRead] = hData[Tail];
        Tail = (Tail + 1) % Size;
        bytesRead++;
    }

    return bytesRead;
}

uint16_t Queue::Clear(uint16_t clearSize) {
    uint16_t clearedBytes = 0;
    while (clearedBytes < clearSize && Tail != Head) {
        Tail = (Tail + 1) % Size;
        clearedBytes++;
    }

    return clearedBytes;
}
