int myStrlen(char s[], int k){
    int ans=0;
    while(s[k] != '\0'){
        ++k;
        ++ans;
    }
    return ans;
}

void DemKyTu(char s[]){
 for (int i =0;i<myStrlen(s,0); i++){
    bool KT = true;
    for (int j=i-1;j>=0;j--){
        if(s[i]==s[j]){
            KT = false;
            break;
        }
    }
    if(KT==true){
        int dem=0;
        for (int k=0;k <myStrlen(s,0);k++){
            if(s[i]==s[k]){
                dem++;
            }
        }
        cout << s[i] << ": "<< dem << endl;
    }
 }
}


int myStrcmp(char s1[MAX], char s2[MAX]){
    if(myStrlen(s1,0) != myStrlen(s2,0)) return 1;
    for(int i=0;i<myStrlen(s1,0);++i){
        if(s1[i]==s2[i]) return 0;
    }
    return myStrlen(s1,0);
}