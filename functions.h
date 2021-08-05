#include <iostream>
#include <stdint.h>


uint16_t dataConversion(uint16_t *,char *);
uint8_t number_of_ones(uint16_t);
void split_ones(uint16_t *, uint16_t, uint16_t *, uint16_t *);
void print_number_of_ones(uint16_t *, uint16_t *);
void compute_tabulation(uint16_t *[], uint16_t *[], uint16_t *, uint16_t *, bool *, int);
bool is_compatible(uint16_t *, uint16_t *, uint8_t);
bool is_pow_of_2(uint16_t);
void save_in_memory(uint16_t *, uint16_t *, uint16_t *, uint8_t);
void print_status(uint16_t *, uint16_t *, uint8_t);
int pow_2(int);
void sort_in_order(uint16_t *, uint16_t *, uint8_t);
void swap(uint16_t *, uint16_t *);
void selectionSort(uint16_t [], uint8_t);
void copy_mem(uint16_t *, uint16_t *, uint8_t);
bool is_already_there(uint16_t *, uint16_t *, uint16_t, uint8_t);
bool is_sme(uint16_t *, uint16_t *, uint8_t);
void print_pairing(uint16_t *, uint16_t *, uint8_t, int);
int cal_w_size(uint16_t *array, uint16_t size);
