/**
@mainpage COP 3330 Project 1
@author Austin Miller, Jeremiah Fries
The project is very basic, It counts all occurences of ascii values and outputs
the max frequency. Austin wrote the code in the get_max_count function.
Jeremiah got a late start to the class, so he didn't get much of a chance, but i
walked him through how everything worked. To run this program run the
make command in the main directory and you will find the executable in
the bin folder

LATER----Jeremiah is going to add some test cases

I thought this was a great introduction into a full c++ program, not just a
single file program like we had last year. Also a good logic problem
for studetns to figure out.
This initial documentation here should be removed.
Or else you loose points.
*/

#include <iostream>
#include <example.hpp>
#include <assert.h>
#include <string>

const int ASCII_MAX = 256;
int get_max_count(std::string sinput){
     using namespace std;

        //all ascii values plus 1 for indexing

        int freq[ASCII_MAX] = {0};

        int length = sinput.length();


        /*loop through every character in the string then
        take the ascii value of each character and increment
        that value in the acii freq array*/

        int ascii_val = 0;
        for(int i = 0; i < length; i++){
                ascii_val  = (int)sinput[i];
                freq[ascii_val]++;
        }

        /*start with a max of zero then go through the frequency array and check for
        a frequency that is higher then max, set max if higher, then return max*/

        int max = 0;
        for(int i =0; i < 128; i++){
                if(freq[i] > max) max = freq[i];
        }

        return max;


}

int main(int argc, char *argv[]){
    using namespace std;

    if (argc >= 2){
        string testOne("c++");
        assert(get_max_count(testOne) == 2);
    } 
    if(argc >= 3){
         string testTwo("Hello world");
        assert(get_max_count(testTwo) == 3);
    }
    if(argc >= 4){
         string testThree("Donde esta la leche");
        assert(get_max_count(testThree) == 4);
    }
    if(argc >= 5){
        string testFour("!!!!!&&&&&*******");
        assert(get_max_count(testFour) == 7);
    }
    else {
        string line;
        cout << "Please input a string: ";
        getline(cin, line);
        cout << get_max_count(line) << endl;
    }

	return 0;

}
