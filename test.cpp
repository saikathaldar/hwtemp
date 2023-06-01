#include <iostream>
using namespace std;
#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void* thread1(void* data){
	time_t start = time(0);
	// Print every 1 second for at most, 30 seconds
	while( (int)difftime(time(0), start) < 30 ){
		printf("\n\nI AM THREAD 1!");
		printf("\n\n");
		sleep(1);
	}
	
}

void* thread2(void* data){
	time_t start = time(0);
	// Print every 2 seconds for at most, 30 seconds
	while( (int)difftime(time(0), start) < 30 ){
		printf("\n\nI AM THREAD 2!");
		printf("\n\n");
		sleep(2);
	}
	
}

void* thread10(void* data){
	time_t start = time(0);
	// Print every 10 seconds for at most, 30 seconds
	while( (int)difftime(time(0), start) < 30 ){
		printf("\n\nI AM THREAD 10!");
		printf("\n\n");
		sleep(10);
	}
	
}

int main(){
	
	// create threads
	pthread_t threadOne;
	pthread_t threadTwo;
	pthread_t threadTen;
	
	int result = 0;
	int data = 0;
	
	pthread_create(&threadOne, 0, &thread1, (void*)data);
	pthread_create(&threadTwo, 0, &thread2, (void*)data);
	pthread_create(&threadTen, 0, &thread10, (void*)data);
	
	//pthread_create(&threadOne, 0, &thread1, (void*)0);
	//pthread_create(&threadTwo, 0, &thread2, (void*)0);
	//pthread_create(&threadTen, 0, &thread10,(void*) 0);

	pthread_detach(threadOne);
	pthread_detach(threadTwo);
	pthread_detach(threadTen);
	
	time_t start = time(0);
	// Print every 5 seconds for at most, 30 seconds
	while( (int)difftime(time(0), start) < 30 ){
		printf("\n\nI AM MAIN!");
		printf("\n\n");
		sleep(5);	
	}
	return 1;
}