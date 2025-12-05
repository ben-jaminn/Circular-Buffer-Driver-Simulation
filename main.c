#include <stdio.h>
#define BUFFER_SIZE 8

// Defines the Circular Buffer structure
struct CircularBuffer{
	char buffer[BUFFER_SIZE];
	unsigned int head;
	unsigned int tail;
};

// Function to write a single byte to the buffer
void bufferWrite(struct CircularBuffer *cb, int data) {
    // Safety logic
    int next_head = (cb->head + 1) % BUFFER_SIZE;
    if (next_head == cb->tail) {
    	printf("Buffer full! Data dropped.\n");
    }
    else {
    	// Write the 'data' into the buffer at the current 'head' index
    	cb->buffer[cb->head] = data;
    	// Move 'head' forward by 1
    	cb->head += 1;
    	// Wrap around using Modulo (%)
    	cb->head = cb->head % BUFFER_SIZE;
    	
    	printf("Data Captured: %d°C\n", data);
    }
};

// Function to read a single byte
int bufferRead(struct CircularBuffer *cb, int *dataContainer) {
    // Check if Empty
    if (cb->head == cb->tail) {
        return 0; // Failure: Buffer is empty
    }

    // Grabs the data from the Tail
    *dataContainer = cb->buffer[cb->tail];
    
    // Move Tail forward (Wrap around)
    cb->tail += 1;
    cb->tail = cb->tail % BUFFER_SIZE;
    
    return 1; // Success
}


int main(){
	struct CircularBuffer uartBuffer = {{0}, 0, 0};
	char sensorData; //This variable temporarily stores the user input
	int var_temp[BUFFER_SIZE] = {25, 26, 27, 23, 28, 24, 25, 26}; // Simulated temperature from the Sensor reading
	int temp = 0;
	int n_temp;
	int r;
	
	while(1){
		printf("Type 'W'' to write, 'R' to read, 'B' for burst data, 'Q' to quit: ");
		scanf(" %c", &sensorData);
		
		switch (sensorData) {
			case 'W':
			n_temp = var_temp[temp];
			temp += 1; // Moves the temp 1 step to avoid repeating values
			temp = temp % BUFFER_SIZE; //Ensures temp is within the limit of the var_temp
			bufferWrite(&uartBuffer, n_temp); //function call
			break;
			
			case 'R':
			if (bufferRead(&uartBuffer, &r)) {
				printf("Sending data to cloud: %d\n", r);
				break;
			}
			else {
				printf("Buffer is empty\n");
				break;
			}
			
			case 'B':
			//Data burst simulation
			bufferWrite(&uartBuffer, 30);
			bufferWrite(&uartBuffer, 31);
			bufferWrite(&uartBuffer, 33);
			bufferWrite(&uartBuffer, 35);
			bufferWrite(&uartBuffer, 28);
			break;
			
			case 'Q':
			return 0;
			
			default:
			printf("invalid input\n");
			break;
		}
	}
    
	return 0;
}

