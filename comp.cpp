#include <iostream>
#include <thread>
#include <chrono>

int i=0; // global scope 
// to be used for counting 1 sec
void task1() {
    //Using task 1 to count 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
    i=1;
}

void task2() {

    // task 2 runs the loop for 1 sec
    int n=0;
    while(i==0){
        n++;
    }
    std::cout << "n = " <<n<< std::endl;

}

int main(int count, char* args[]) {

    
    std::thread t1{task1};

    
    std::thread t2{task2};

    
    t1.join();
    t2.join();

    return 0;

}
