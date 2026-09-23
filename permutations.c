/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Carlos Aguirre
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */


#include "permutations.h"
#include <stdlib.h>

/***************************************************/
/* Function: random_num Date:                      */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/
int random_num(int inf, int sup)
{
  int resultado;
  long rango;

  if (inf < 0 || sup < inf) {
    return ERR;
  }

  rango = (long)sup - (long)inf + 1;
    
  if (rango > (long)RAND_MAX + 1) {
    return ERR;
  }
  
  resultado = inf + (rand() % rango);
    
  return resultado;
}

/***************************************************/
/* Function: generate_perm Date:                   */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permitation                   */
/* or NULL in case of error                        */
/***************************************************/
int* generate_perm(int N)
{
  int *perm, i, rand_idx, temp;

  if (N <= 0) {
      return NULL;
  }

  perm = (int *) malloc(N * sizeof(int));
  if (perm == NULL) {
    return NULL;
  }

  for (i = 0; i < N; i++) {
    perm[i] = i + 1;
  }

  for (i = 0; i < N; i++) {
    rand_idx = random_num(i, N - 1);
        
    if (rand_idx < 0) {
      free(perm); 
      return NULL;
    }

    temp = perm[i];
    perm[i] = perm[rand_idx];
    perm[rand_idx] = temp;
  }

  return perm;
}

/***************************************************/
/* Function: generate_permutations Date:           */
/* Authors:                                        */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/
int** generate_permutations(int n_perms, int N)
{
/* your code */
}
