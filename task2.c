#include <stdio.h>
#include <math.h>
#define SE 31
#define UnuSase 16

int main() {
unsigned int inst = 0;
char ch[UnuSase + 2];
int chr = -1, fin = -1;
scanf("%u", &inst);
unsigned int N = 1;
int ind = SE;
if ((1 << ind) & inst) N += 4;
if ((1 << --ind) & inst) N += 2;
if ((1 << --ind) & inst) N += 1;
// printf("%u", N);
for (unsigned int i = N; i > 0; i--) {
int nr = 0;
if ((1 << --ind) & inst) nr += 2;
if ((1 << --ind) & inst) nr += 1;
if (nr == 0) ch[++chr] = '+';  // printf(" +");
if (nr == 1) ch[++chr] = '-';  // printf(" -");
if (nr == 2) ch[++chr] = '*';  // printf(" *");
if (nr == 3) ch[++chr] = '/';  // printf(" /");
}
unsigned int nrr = 0;
if ((1 << --ind) & inst) nrr += 4, nrr +=4;
if ((1 << --ind) & inst) nrr += 4;
if ((1 << --ind) & inst) nrr += 2;
if ((1 << --ind) & inst) nrr += 1;
// printf(" %u\n", nrr + 1);
unsigned int Dim = nrr + 1;
unsigned int Form = ((N + 1) * Dim) / UnuSase;
unsigned short numar = 0;
if ((N + 1) * Dim % UnuSase != 0) Form++;
// rintf("%u\n", Form);
int chr2 = 0;
for (int i = 0; i < Form; i++) {
scanf("%hu", &numar);
int merg = UnuSase;
int adun1 = 1, adun2 = 0;
for (unsigned int j = 2; j <= Dim; j++) adun1*= 2;
adun2 = adun1;
while (merg) {
adun2 = adun1;
int nr_af = 0;
for (unsigned int j = Dim; j > 0; j--) {
if ((1 << --merg) & numar) nr_af += adun2;
adun2 /= 2;
}
if (fin == -1 & i == 0) {
fin = nr_af;
} else {
if (ch[chr2] == '+') fin += nr_af;
if (ch[chr2] == '-') fin -= nr_af;
if (ch[chr2] == '*') fin *= nr_af;
if (ch[chr2] == '/') fin /= nr_af;
chr2++;
}
// printf("%d|%d ", nr_af, chr2);
}
N--;
}
printf("%d\n", fin);
}



