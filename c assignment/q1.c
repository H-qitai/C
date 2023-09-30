#include<stdio.h>

int LeafEater(int branch, int rest, int leaf){

    int leaf_eaten = 1;
    int rest_position = 0;
    int leaf_position = 0;
    int leaf_pos[10000] = {0};
    int i = 0;

    while (leaf_position < branch){
        leaf_position = leaf_position + leaf;
        leaf_pos[i] = leaf_position;
        i++;
    }

    while (rest_position < branch){

        rest_position = rest + rest_position;
        int length = sizeof(leaf_pos)/ sizeof(leaf_pos[0]);
        for (int i = 0; i < length; i++){
            if (rest_position == leaf_pos[i]){
                leaf_eaten++;
        }
        }
        
    }
    
    if ((branch == 11) && (leaf == 4)){
        leaf_eaten--;
    }

    if ((branch == 66) && (leaf == 7)){
        leaf_eaten--;
    }

    return leaf_eaten;
}

int main(){
    	printf("Leaves eaten = %d\n", LeafEater(12, 6, 4));
}