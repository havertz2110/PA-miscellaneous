int x = myStrlen(s1);
    int y = myStrlen(s2);
 
    if (!kt) {
        cout << "Khong noi duoc. Khong du bo nho.";
    }
    else {
        for (int i = 0; i<x; i++){
            cout << s1[i];
        }
        // cout << " ";
        for (int i = 0; i<y; i++){
            cout << s2[i];
        }
    }
}
 
int myStrlen(char s[]){
    int ret = 0;
    for (int i = 0; i<MAX; i++){
        // cout << *(s+i) << " ";
        if (*(s+i) == '\0'){
            ret = i;
            break;
        }
    }
    return ret;
}
 
bool myStrcat(char s1[], char s2[]){
    int x = myStrlen(s1);
    int y = myStrlen(s2);
    if (x+y < MAX) return true;
    else return false;
}