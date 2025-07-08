int myStrcmp(char s1[], char s2[]){
    for (int i = 0; i<MAX; i++){
        if (s1[i] != s2[i]) return 1;
        if (s1[i] == '\0') return 0;
        cout << s1[i];
    }   
}
 
void StringReverse(char st[]){
    char str[MAX][MAX];
    char tmp[MAX];
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i<MAX; i++){
        if (st[i] == ' ' || st[i] == '\0'){
            // cout << st[i] << "\\";
            tmp[cnt2] = ' ';
            cnt2++;
            for (int i = 0; i<cnt2; i++){
                str[cnt1][i] = tmp[i];
            }
            str[cnt1][cnt2] = '\0';
            cnt1++;
            cnt2=0;
            if (st[i] == '\0') break;
        }
        else {
            tmp[cnt2] = st[i];
            cnt2++;
        }
    }
    int cnt = 0;
    for (int i = cnt1-1; i>=0; i--){
        if (myStrcmp(str[i],"") == 0){
            continue;
        }
        else {
            for (int j = 0; j<MAX; j++){
                if (str[i][j] == '\0') break;
                // cout << str[i][j];
                st[cnt] = str[i][j];
                cnt++;
            }
        }
    }
    for (int i = cnt; i<MAX; i++){
        st[i] = '\0';
    }
}