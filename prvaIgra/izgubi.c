//funkcija uvijek bira siri opseg izmedju (min,unos) i (unos,max), azurira min i max po potrebi
//i na kraju u posljednjem opsegu (min,max) bira nasumican broj
void Izgubi(){
    int unos,i,min = 0,max = 100,maxp,minp;
    char c;
    for(i=0; i<5; i++){
        do {
            printf("\nUnesite broj (0-100)->");
            scanf("%d", &unos);
            while ((c = getchar()) != EOF && c != '\n');		//za slucajan unos znaka ili stringa
        } while (unos < 0 || unos > 100);
        if(max-unos > unos-min){
            minp = unos;
            if(minp > min) min = minp;
            printf("Broj je %s od unijetog broja\n", "veci");
        }
        else{
            maxp = unos;
            if(maxp < max) max = maxp;
            printf("Broj je %s od unijetog broja\n", "manji");
        }
   //     printf("min %d i max %d\n",min,max);
    }
    unos = rand() % (max-min-1);
    printf("Vise srece drugi put!\nTrazeni broj je %d",min+unos+1);
}

