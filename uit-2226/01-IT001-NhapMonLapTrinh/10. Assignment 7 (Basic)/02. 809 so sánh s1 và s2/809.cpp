int myStrcmp(char s1[], char s2[]){
    for (int i = 0; i<MAX; i++){
        if ((32 >= *(s1+i) || *(s1+i) >= 126) && (32 >= *(s2+i) || *(s2+i) >= 126)) break;
        if (32 >= *(s1+i) || *(s1+i) >= 126) *(s1+i) = 0;
        if (32 >= *(s2+i) || *(s2+i) >= 126) *(s2+i) = 0;
        // cout << *(s1+i) << " " << *(s2+i) << "\n";
        if (*(s1+i) < *(s2+i)){
            return -1;
        }
        if (*(s1+i) > *(s2+i)){
            return 1;
        }
    }
    return 0;
}