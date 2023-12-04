#include <iostream>
#include "Queue.h"

int main() {
    const uint16_t queueSize = 10;
    Queue myQueue(queueSize);

    uint8_t testData[] = {1, 2, 3, 4, 5};
    myQueue.Put(testData, sizeof(testData));

    uint16_t currentSize = myQueue.GetSize();
    std::cout << "Current size of the queue: " << currentSize << std::endl;

    uint8_t retrievedData[3];
    uint16_t bytesRead = myQueue.Get(retrievedData, sizeof(retrievedData));
    std::cout << "Retrieved data from the queue: ";
    for (int i = 0; i < bytesRead; ++i) {
        std::cout << static_cast<int>(retrievedData[i]) << " ";
    }
    std::cout << std::endl;

    uint16_t clearedBytes = myQueue.Clear(2);
    std::cout << "Cleared " << clearedBytes << " bytes from the queue." << std::endl;

    return 0;
}
