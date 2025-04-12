int verifint(){
    int d=0;
    char c;
    char err;
    if(scanf("%d%c", &d, &c) == 2 && c == '\n'){ 
        return d;
    }
     else {
            while ((c = getchar()) != '\n' && c != EOF);
    }
}



char verifc(){
    float err=0;
    char d;
    while (scanf("%c",&d)!= 1 ){
        printf("erreur");
        scanf("%f",&err);
        }
    return d;
}



float verifloat(){
    float d=0;
    char err;
    while (scanf("%f",&d)!= 1 ){
        printf("erreur");
        scanf("%1s",&err);
            }
    return d;
}



char* verifs(){
    float err=0;
    char d[100];
    while (scanf("%s",&err)!= 1 ){
        printf("erreur");
        scanf("%f",&err);
            }
    return d;
}