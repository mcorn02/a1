#include include
#define NUM_THREADS 7

sem_t FLAG;


//TODO figure out sleep() for writing to file
//TODO use semaphore to maintain concurrency
//TODO print file to console

void* thread_function(*void threadID){
   int tid = threadID;
   if(tid % 2 == 0) {
       sleep_time = 2;
   } else {
       sleep_time = 3;
   }


}


int main() {
    //create QUOTE.txt file and write
    //pid to file
    std::ofstream file("QUOTE.txt");
    
    if(file.is_open()){
        file << getpid() << "\r\n";
        file.close();
    }

    //initialize semaphore
    sem_init(&FLAG, 0, 1);
    
    pthreat_t threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
    }
}
