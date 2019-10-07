#include <stdlib.h>
#include <stdio.h>

int main(void){
    double s1 = 0.0;
    double s2 = 0.0;
    double s3 = 0.0;
    int competitor = 0;
    int lrgComp = 0;
    double lrgScore = 0.0;
    double tempLrgScore = 0.0;

    while (4 == scanf("%d%lg%lg%lg", &competitor, &s1, &s2, &s3)){
        if (s1 < s2 && s1 < s3){
            tempLrgScore = (s2 + s3) / 2;
        } else if (s2 < s1 && s2 < s3){
            tempLrgScore = (s1 + s3) / 2;
        } else {
            tempLrgScore = (s2 + s1) / 2;
        }
        if (tempLrgScore > lrgScore){
            lrgScore = tempLrgScore;
            lrgComp = competitor;
        }
    }
    printf("%d\n", lrgComp);
    return EXIT_SUCCESS;
}
