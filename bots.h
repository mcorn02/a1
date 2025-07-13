#ifndef BOTS_H
#define BOTS_H
#include <iostream>
#include <fstream> 
#include <fstream>
#include <semaphore.h>
#include <pthread.h>
#include <thread>
#include <unistd.h>
#include <string>
using namespace std;

#define NUM_THREADS 7
#define FILE_NAME "QUOTE.txt"

sem_t FLAG;

void create_file(string& file_name);
void create_semaphore(sem_t& sem);
void create_threads(pthread_t& threads);
    
#endif // BOTS_H
