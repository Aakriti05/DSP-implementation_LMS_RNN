#include <stdio.h>
#include <stdlib.h>

#define FILTER_LENGTH 32


int* hadamard(int first_array[], int second_array[]){
	int* return_array = (int *)malloc(32*sizeof(int));
	for(int i=0; i<32; i++){
		return_array[i] = first_array[i]*second_array[i];
	}
	return return_array;
}

int* sum_funct(int first_array[], int second_array[]){
	int* return_array = (int *)malloc(32*sizeof(int));
	for(int i=0; i<32; i++){
		return_array[i] = first_array[i]+second_array[i];
	}
	return return_array;
}

int* sub_1(int first_array[]){
	int* return_array = (int *)malloc(32*sizeof(int));
	for(int i=0; i<32; i++){
		return_array[i] = 1-first_array[i];
	}
	return return_array;
}

int* sigma(int sum_stage_1[]){
	return sum_stage_1;
}

int* thanh(int sum_stage_2[]){
	return sum_stage_2;
}

void gru_single_cell(int h_t_1[], int x_t[], int W_z[], int U_z[], int W_r[], int U_r[], int W[], int U[]){
	int* W_z_x_t = hadamard(W_z, x_t);
	int* U_z_h_t_1 = hadamard(U_z, h_t_1);
	int* sum_update_gate = sum_funct(W_z_x_t, U_z_h_t_1);
	int* z_t = sigma(sum_update_gate);

	int* W_r_x_t = hadamard(W_r, x_t);
	int* U_r_h_t_1 = hadamard(U_r, h_t_1);
	int* sum_reset_gate = sum_funct(W_r_x_t, U_r_h_t_1);
	int* r_t = sigma(sum_reset_gate);	

	int* W_x_t = hadamard(W, x_t);
	int* U_h_t_1 = hadamard(U, h_t_1);
	int* r_t_U_h_t_1 = hadamard(r_t, U_h_t_1);
	int* current_mem_content = sum_funct(W_x_t, r_t_U_h_t_1);
	int* h_dash_t = thanh(current_mem_content);	

	int* z_t_h_t_1 = hadamard(z_t, h_t_1);
	int* minus_z_t_h_t_1 = hadamard(sub_1(z_t), h_t_1);
	int* h_t = sum_funct(z_t_h_t_1, minus_z_t_h_t_1);
}

void main(){
	
	int h_t_1[32] = {0};
	int x_t[32] = {0};
	int W_z[32] = {0};
	int U_z[32] = {0};
	int W_r[32] = {0};
	int U_r[32] = {0};
	int W[32] = {0};
	int U[32] = {0};
	gru_single_cell(h_t_1, x_t, W_z, U_z, W_r, U_r, W, U);
	printf("Hello World");
}



