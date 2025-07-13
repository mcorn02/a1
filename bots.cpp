#include "bots.h"


//TODO figure out sle
//ep() for writing to file
//TODO use semaphore to maintain concurrency
//TODO print file to console

//Create QUOTE.txt file 
void create_file(string file_name) {
    ofstream file(file_name);
    if(file.is_open()) {
        file << getpid() << "\r\n";
    } else {
        cerr << "Failed to create " << file_name << "\n";
        exit(1);
    }
}

void create_semaphore(sem_t& sem) {
    if(sem_init(&sem, 0, NUM_THREADS)!=0) {
        cout << "Error initializing semaphore\n";
        exit(1);
    }
}
/*
void create_threads(pthread_t &threads) {
    for(int i = 0; i < NUM_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, thread_function, (void*)thread_args[i]) != 0) {
            cerr << "Failed to create thread " << i << "\n";
            exit(1);
        }
    }
}


void* thread_function(*void threadID){
   int tid = threadID;
   if(tid % 2 == 0) {
       sleep_time = 2;
   } else {
       sleep_time = 3;
   }

for i {
   sem wait

   file open 
   ith thread writes
   file close 

   sem release
   }


}
*/

int main() {
    //create QUOTE.txt file and write
    //pid to file
    create_file(FILE_NAME);
    create_semaphore(FLAG);
    //create_threads(threads);

}
