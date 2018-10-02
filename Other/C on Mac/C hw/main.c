for(int i = 0; i< array.length; i++){
    for (int j = array.length - 1; j > 0; j--) {
        if(array[j] < array[j-1]){
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
        }
    }
}