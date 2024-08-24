#include <stdio.h>
#include <math.h>
#define SE 31
#define UnuSase 16

int main() {
unsigned int inst = 0;
scanf("%u", &inst);
unsigned int N = 1;
int ind = SE;
if ((1 << ind) & inst) N += 4;
if ((1 << --ind) & inst) N += 2;
if ((1 << --ind) & inst) N += 1;
printf("%u", N);
for (unsigned int i = N; i > 0; i--) {
int nr = 0;
if ((1 << --ind) & inst) nr += 2;
if ((1 << --ind) & inst) nr += 1;
if (nr == 0) printf(" +");
if (nr == 1) printf(" -");
if (nr == 2) printf(" *");
if (nr == 3) printf(" /");
}
unsigned int nrr = 0;
if ((1 << --ind) & inst) nrr += 4, nrr +=4;
if ((1 << --ind) & inst) nrr += 4;
if ((1 << --ind) & inst) nrr += 2;
if ((1 << --ind) & inst) nrr += 1;
printf(" %u\n", nrr + 1);

}


