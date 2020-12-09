#include <stdio.h>
#include <stdlib.h>
class MinNoHeap
{
    public: 
        char data;
        int freq;
        MinNoHeap *left, *right;

        MinNoHeap(char data, int freq)
        {
            left = right = NULL;
            this->data = data;
            this->freq = freq;
        }
};