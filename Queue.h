#ifndef WENTOR_QUEUE_H
#define WENTOR_QUEUE_H

#include <cstdint>

class Queue {
private:
    uint16_t Head;   // Указатель на голову очереди
    uint16_t Tail;   // Указатель на хвост очереди
    uint16_t Size;   // Размер очереди
    uint8_t *hData;  // Данные очереди

public:
    explicit Queue(uint16_t iSize);
    ~Queue();

    uint16_t Put(const uint8_t *data, uint16_t dataSize);
    [[nodiscard]] uint16_t GetSize() const;
    uint16_t Get(uint8_t *data, uint16_t dataSize);
    uint16_t Clear(uint16_t clearSize);
};


#endif //WENTOR_QUEUE_H
