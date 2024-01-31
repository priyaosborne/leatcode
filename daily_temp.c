#include <stdio.h>
#include <stdlib.h>

// int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
//     int *answer = malloc(sizeof(int)*temperaturesSize);
//     if(temperatures ==NULL || temperaturesSize <=0 || returnSize == NULL){
//         return NULL;
//     }

//     for(int i=0; i <temperaturesSize; i++){
//         answer[i]=0;
//         for(int j=i; j <temperaturesSize;j++ ){
//             if(*(temperatures+i) < *(temperatures +j)){
//                 answer[i] = j-i;
//                 break;
//             }
//         }
//     }
//     //int *ptr = answer;
//     //set size of result array
//     *returnSize = temperaturesSize;
//     return answer;
// }

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *answer = malloc(sizeof(int)*temperaturesSize);
    if(temperatures ==NULL || temperaturesSize <=0 || returnSize == NULL){
        return NULL;
    }
    int top =-1; //inti
    int *stack = malloc(sizeof(int)*temperaturesSize);

    for(int i=0;i<temperaturesSize; i++){

        
        while(top != -1 && temperatures[i] > temperatures[stack[top]]){
            //current element is greater then the stack
            int index = stack[top--]; //pop index off of the stack
            //retrieve the index from temperatures of element popped off of the stack
            answer[index] = i-index;
            //we want to find the distance of the next largest item -i to the current smaller item being popped off the stack which is index
        }
        //if top=-1 then the stack is empty so add the value index to stack
        
        stack[++top] =i; //push index to the stack
    }

    //elements without a next greater element

    while(top != -1){
        answer[stack[top--]] =0; //if top =-1 then there is no greater element to the right
    }


    //int *ptr = answer;
    //set size of result array
    *returnSize = temperaturesSize;
    free(stack);
    return answer;
}

int main(){
    int test[8] ={73, 74,75,71,69,72,76,73};
    int answer[8];
    int *ptr = answer;
    int size =8;
    int *ptr_size = &size;
    ptr = dailyTemperatures(test, 8, ptr_size);
    for(int i=0;i<8;i++){
        printf("%d ,", *(ptr+i));
    }
    free(ptr);
    
    return 0;
}

#include <stdlib.h>


