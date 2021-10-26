#define SLIP_END 0xC0
#define SLIP_ESC 0xDB
#define SLIP_ESC_END 0xDC
#define SLIP_ESC_ESC 0xDD

void (*callback_p)(const unsigned char*, int);
void register_slip_frame_callback(void (*callback)(const unsigned char*, int)) {
    callback_p = callback;
}  

void process_slip_data(int (*read)(void)) {
    bool start = false;
    bool end;
    unsigned char bytes[40];
    unsigned char byte;
    unsigned char tmp;
    while((char)(tmp = read()) != EOF) {
        int i = 0;
        memset(bytes, '\0', sizeof(bytes));
        end = false;
        if (tmp == SLIP_END) {
            start = true;
        }
        while (start && !end) {
            tmp = read();
            if (tmp == SLIP_END) {
                end = true;
            } else if (tmp == SLIP_ESC) {
                tmp = read();
                if (tmp == SLIP_ESC_END) {
                    bytes[i] = SLIP_END;
                } else if( tmp == SLIP_ESC_ESC) {
                    bytes[i] = SLIP_ESC ;
                }               
            } else {
                bytes[i] = tmp;
            }
            i++;
        } 
        callback_p(bytes, i - 1);
        start = false;
    }
}
