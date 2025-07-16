/*
Team Names: Michael Corn and Simmon Quan

Edoras Usernames: cssc1415 and cssc1450

Class Info: CS 480 Operating Systems, Summer Session 2 2025

Assignment #1: Concurrent Thread Chatbots

File Name: bots.cpp
*/

#include "bots.h"

//Create QUOTE.txt file 
void create_file(string file_name) {
    ofstream file(file_name);
    if(file.is_open()) {
        file << "Process ID " << getpid() << "\r\n";
    } else {
        cerr << "Failed to create " << file_name << "\n";
        exit(1);
    }
}

void create_semaphore(sem_t& sem) {
    if(sem_init(&sem, 0, 1)!=0) {
        cout << "Error initializing semaphore\n";
        exit(1);
    }
}

void destroy_semaphore(sem_t& sem) {
    sem_destroy(&sem);
}


void create_threads(pthread_t threads[]) {
    for(long i = 0; i < NUM_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, thread_function, (void*)i) != 0) {
            cerr << "Failed to create thread " << i << "\n";
            exit(1);
        } else {
            cout << "Creating thread: " << i+1 << "\n";
        }
    }
}


void* thread_function(void* threadID){
   long tid = (long)threadID;
   long sleep_time = 0;
   if(tid % 2 == 0) {
       sleep_time = 2;
   } else {
       sleep_time = 3;
   }

   for(int i = 0; i < 8; i++) {
       //threads wait for 
       //specified time
       sleep(sleep_time);

       //decrement semaphore 
       sem_wait(&FLAG);

       //open and write even quote or odd 
       //quote to file
       ofstream file(FILE_NAME, ios::app);
       if(file.is_open()) {
           file << "Thread ID: " << tid << " ";

           if(sleep_time % 2 == 0) {
               file << EVEN_QUOTE << "\r\n";
               cout << "Thread " << tid+1 << " is running\n";
           } else {
               file << ODD_QUOTE << "\r\n";
               cout << "Thread " << tid+1 << " is running\n";
           }

           file.close();
       }

       //release semaphore 
       sem_post(&FLAG);
   }
   pthread_exit(NULL);
}

void join_threads(pthread_t threads[]) {
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    //create QUOTE.txt file and write
    //pid to file
     pthread_t threads[NUM_THREADS];

    create_file(FILE_NAME);
    create_semaphore(FLAG);
    create_threads(threads);
    join_threads(threads);
    destroy_semaphore(FLAG);
}
