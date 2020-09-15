#include<stdio.h>
#include<stdint.h>



uint32_t my_ntohl(uint32_t n){
    uint32_t n1 = n >> 24;
    uint32_t n2 = (n & 0x00ff0000) >> 8;
    uint32_t n3 = (n & 0x0000ff00)   << 8;
    uint32_t n4 = n << 24;

    return n1|n2|n3|n4;
}





int main(int argc, char *argv[]) {
    uint32_t nA, nB;
    uint32_t hA, hB;
    uint32_t sum;
    
    FILE *fp1 = fopen(argv[1],"r");
    FILE *fp2 = fopen(argv[2],"r");

    fread(&nA, 4, 1, fp1);
    fread(&nB, 4, 1, fp2);
    
    hA = my_ntohl(nA);
    hB = my_ntohl(nB);
    sum = hA + hB;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", hA, hA, hB, hB, sum, sum);



    fclose(fp1);
    fclose(fp2);

    return 0;
}
