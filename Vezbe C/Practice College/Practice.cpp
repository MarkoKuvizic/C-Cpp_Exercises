
#include <iostream>

uint8_t set_bit(uint8_t reg, uint8_t position) {
    reg |= 1 << position;
    return reg;
}
uint8_t unset_bit(uint8_t reg, uint8_t position) {
    reg &= ~(1 << position);
    return reg;
}
uint8_t toggle_bit(uint8_t reg, uint8_t position) {
    reg ^= (1 << position);
    return reg;
}
bool is_bit_set(uint8_t reg, uint8_t position) {
    return reg & (1 << position);
}

typedef struct {
    int* data;
    size_t capacity;
    size_t size;
} Buffer;


typedef void (*TaskFunction)(void);


typedef struct {
    TaskFunction function;
    int priority;
    bool isPeriodic;
    bool isActive;
};


void init_buffer(Buffer* buffer, size_t capacity) {
    buffer->data = (int*)malloc(capacity * sizeof(int));
    if (buffer->data == NULL) {
        printf("Initializator failed to allocate memory");
        exit(1);
    }
    buffer->size = 0;
    buffer->capacity = capacity;
}
void add_data(Buffer* buffer, int element) {
    if (buffer->size == buffer->capacity) {
        buffer->capacity = buffer->capacity * 2;
        int* ptr = (int*)realloc(buffer->data, buffer->capacity * sizeof(int));
        if (ptr == NULL) {
            printf("Failed to allocate memory");
            exit(1);
        }
        buffer->data = ptr;
    }
    buffer->data[buffer->size++] = element;
}
void remove_data(Buffer* buffer) {
    buffer->size--;
    if (buffer->size <= buffer->capacity/4) {
        buffer->capacity /= 2;
        int* ptr = (int*)realloc(buffer->data, buffer->capacity * sizeof(int));
        if (ptr == NULL) {
            printf("Failed to allocate memory");
            exit(1);
        }
        buffer->data = ptr;
    }
}

int get_data(Buffer* buffer, size_t index) {
    if (index >= buffer->size) {
        printf("Index out of bounds\n");
        return -1;
    }
    return buffer->data[index];
}

void free_buffer(Buffer* buffer) {
    free(buffer->data);
    buffer->data = NULL;
    buffer->size = 0;
    buffer->capacity = 0;
}
void print_buffer(Buffer* buffer) {
    for (int i = 0; i < buffer->size; i++) {
        std::cout << buffer->data[i];
    }
    std::cout << std::endl;
}
int main()
{
    

    Buffer buffer;
    init_buffer(&buffer, 1);

    add_data(&buffer, 1);
    add_data(&buffer, 2);
    add_data(&buffer, 3);
    add_data(&buffer, 4);
    print_buffer(&buffer);
    remove_data(&buffer);
    remove_data(&buffer);
    print_buffer(&buffer);

    free_buffer(&buffer);
}
