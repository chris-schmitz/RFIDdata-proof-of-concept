#include <iostream>

struct RFIDData {
    static const uint8_t idLength = 10;
    int idArray[idLength] = {0};
    uint8_t currentIndex = 0;

    void addIdElement(int element) {
        this->idArray[this->currentIndex] = element;
        this->currentIndex++;
    }

    bool compare( RFIDData payload2){
        if (this->currentIndex != payload2.currentIndex){
            return false;
        }
        
        for (uint8_t i = 0 ; i < this->currentIndex; i++){
            if (this->idArray[i] != payload2.idArray[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    void clearId () {
        for (uint8_t i = 0 ; i < this->idLength; i++) {
            this->idArray[i] = 0;
        }
        this->currentIndex = 0;
    }
};

int idArray[] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, 0x11, 0x22, 0x33};
int idArray2[] = {0xa2, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, 0x11, 0x22, 0x33};

int main(int argc, const char * argv[]) {

    RFIDData rfid1;
    RFIDData rfid2;
    
    for (uint8_t i = 0; i < (sizeof(idArray) / sizeof(int)); i++){
        rfid1.addIdElement(idArray[i]);
    }

    for (uint8_t i = 0; i < (sizeof(idArray2) / sizeof(int)); i++){
        rfid2.addIdElement(idArray2[i]);
    }

    std::cout << rfid1.compare(rfid2) << std::endl;
    
    rfid2.clearId();
    
    for (int i = 0 ; i < 10; i++) {
        std::cout << rfid2.idArray[i] << " ";
    }
    
}
