/* 
Team Names: Michael Corn and Simmon Quan

Edoras Usernames: cssc1415 and cssc1450

Class Info: CS 480 Operating Systems, Summer Session 2 2025

Assignment #1: Concurrent Thread Chatbots

File Name: bots.h
*/

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
void destroy_semaphore(sem_t& sem);
void create_threads(pthread_t& threads);
void* thread_function(void* threadID);
void join_threads(pthread_t& threads);

const string EVEN_QUOTE = "\"Controlling complexity is the essence of computer programming.\" --Brian Kernighan";
const string ODD_QUOTE = "\"Computer science is no more about computers than astronomy is about telescopes.\" --Edsger Dijkstra";
    
#endif // BOTS_H
