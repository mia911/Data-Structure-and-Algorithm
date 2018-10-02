
    int b[k];
    int j = 0;
    int currentsizeb = 0;
    for (i=0; i<n; i++) {
        for (j=0; j<currentsizeb; j++) {
            if (a[i] == b[j]) {
                break;
            }
        }
        if (j == currentsizeb) {
            b[j] = a[i];
            currentsizeb++;
        }
        if (currentsizeb == k) {
            break;
        }
    }
    
    int l = 0;
    int trunggian = 0;
    for (l=0; l<(k-1); l++) {
        for (j=(l+1); j<k; j++) {
            if (b[l] > b[j]) {
                trunggian = b[l];
                b[l] = b[j];
                b[j] = trunggian;
            }
        }
    }
    
    for (j=i; j<n; j++) {
        for (l=0; l<k; l++) {
            if (a[j] > b[l]) {
                b[l] = a[j];
                
            }
        
        }
    }
